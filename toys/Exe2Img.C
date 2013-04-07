/*	@FileName: Exe2Img.C 
	@Function: Convert a PE executable to a flat image file
	@Author:   Tary
	@Date:	   22:58 2007-8-24
	@Priciple: PE文件由多个节构成, PE文件中的节叫RawData,
		只要将它们重新放置到image文件的正确位置即可
	@Usage:	   Format: ExeToImg [/verbose] [/nologo] file[.exe]
		/verbose	显示详细信息
		/nologo		不显示logo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int logo = 1;		/* 显示Logo */
int verbose = 0;	/* 输出详细信息 */
DWORD ImageBase;

typedef struct{
	size_t fsize;	/* 文件大小 */
	char *f;	/* 文件全路径 */
	HANDLE hsrc;	/* 文件句柄 */
	HANDLE hmap;	/* 文件映象句柄 */
	char *pmap;	/* 映象内容基指针 */
}STRUCMAP;

typedef struct PE_HEADER_MAP {		/* PE文件头构成 */
	DWORD signature;		/* 'PE'标记 */
	IMAGE_FILE_HEADER _head;	/* PE文件头 */
	IMAGE_OPTIONAL_HEADER opt_head; /* PE可选头 */
	IMAGE_SECTION_HEADER section_header[1];	/* 节表 */
} peHeader;


/* 打开文件映射, 可以读或写 */
/* 出错: 返回0, 否则返回1   */
BOOL openmapf(STRUCMAP* ppemap) {
	/* 参数的传入与传出均在ppemap结构中 */
	ppemap->hsrc = CreateFile(ppemap->f,
	  GENERIC_READ | GENERIC_WRITE,
	  0, NULL, OPEN_ALWAYS,
	  FILE_ATTRIBUTE_NORMAL, NULL);

	if (ppemap->hsrc == INVALID_HANDLE_VALUE) {
		printf("CreateFile() file %s error\n", ppemap->f);
		return 0;
	}

	/* 对于不存在的文件,要正确地传入新建文件的尺寸 */
	if (ppemap->fsize == 0)
		ppemap->fsize = GetFileSize(ppemap->hsrc, NULL);
	ppemap->hmap = CreateFileMapping(ppemap->hsrc, 
	  NULL, PAGE_READWRITE, 0, ppemap->fsize, NULL);
	if (ppemap->hmap == INVALID_HANDLE_VALUE) {
		printf("CreateFileMapping() file %s error\n", ppemap->f);
		return 0;
	}
	/*printf("size %d\n", ppemap->fsize); */

	ppemap->pmap = MapViewOfFile(ppemap->hmap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

	CloseHandle(ppemap->hmap);
	CloseHandle(ppemap->hsrc);
	if (ppemap->pmap == NULL) {
		printf("MapViewOfFile() return %8X error\n", ppemap->pmap);
		return 0;
	}
	return 1;
}



/* 将src指定的PE文件转换为dst指定的image文件 */
/* 出错: 返回0, 否则返回1                    */
BOOL pe2img(char* src, char* dst) {
	STRUCMAP pemap;				/* PE文件的映象结构 */
	STRUCMAP imgmap;			/* img文件的映象结构*/
	size_t ImgSize;				/* image文件大小 */
	peHeader *header;			/* PE文件头指针  */
	IMAGE_DOS_HEADER *dos_head;		/* 为了不出现长长的结构域 */		
	IMAGE_FILE_HEADER* filehead;		/* 主里为PE头的三个部分及 */
	IMAGE_OPTIONAL_HEADER* opthead;		/* DOS头都定义了指针      */
	IMAGE_SECTION_HEADER* sechead;		
	DWORD secoff, secsize, rawoff, lastoff; /* 节的参数      */
	size_t SecNo;				/* 节的数目      */
	BOOL bret = 1;
	

	pemap.f = src;
	pemap.fsize = 0;
	if (!(bret = openmapf (&pemap))) {	/* 打开PE文件映象 */
		goto l_exit;
	}

	dos_head = (IMAGE_DOS_HEADER *) pemap.pmap; /* 得到DOS头 */


	header = (peHeader *) ((char *) dos_head + dos_head->e_lfanew);	/* 得到PE文件头 */
	if (header->signature != 0x00004550) {				/* 'PE'标记是否正确 */
		printf("Error: %s is not a PE executable.\n", src);
		bret = 0;
		goto l_exit;
	}

	filehead = &header->_head;
	if (filehead->Machine != 0x14C) {				/* 是否用于x86机器 */
		printf("Warning: %s is not a 386 executable.\n", src);
	}

	opthead = &header->opt_head;
	ImageBase = opthead->ImageBase;
	/*printf("size of IMAGE_OPTIONAL_HEADER = %3X\n",
	  sizeof(IMAGE_OPTIONAL_HEADER));*/
	sechead = &header->section_header;				/* 节表指针 */

	imgmap.f = dst;
	imgmap.fsize = opthead->SizeOfImage;	/* image文件大小来自可选头 */
	if (!(bret = openmapf (&imgmap))) {	/* 打开image文件映象 */
		goto l_exit;
	}

	SecNo = filehead->NumberOfSections;	/* 节的数目 */
	if (SecNo == 0) {
		bret = 0;
		goto l_exit;
	}
	lastoff = 0;
	while (SecNo > 0) {				/* 对每个节进行处理 */
		int i;

		secoff = sechead->VirtualAddress;	/* 节在image中的偏移 */
		secsize = sechead->SizeOfRawData;	/* 节在PE文件中的大小 */
		rawoff = sechead->PointerToRawData;	/* 节在PE文件中的偏移 */
		if (verbose != 0) {
			printf("\nSection %s\n", sechead->Name);
		}
		if (secsize == 0) {
			continue;
		}
		if (verbose != 0 && (secoff-lastoff) > 0) {
			printf("\tPadding with %d 0s at offset %xh\n", secoff-lastoff, lastoff);
		}
		/* 用0添充没有节内容的空洞 */
		for (i = 0; i < secoff-lastoff; i++) {
			imgmap.pmap[lastoff + i] = '\0';
		}
		if (verbose != 0) {
			printf("\tCopying %d bytes to offset %xh\n", secsize, secoff);
		}
		/* 核心就是一句memcpy */
		memcpy(&imgmap.pmap[secoff], &pemap.pmap[rawoff], secsize);
		lastoff = secoff + secsize;
		sechead++;
		SecNo--;
	}

l_exit:
	UnmapViewOfFile(imgmap.pmap);
	UnmapViewOfFile(pemap.pmap);
	return bret;
}


/* 处理参数 */
int main(int argc, char**argv, char** envp) {
	int i18 = 0;		/* 参数不正确吗 */
	char* fsrc;		/* 源文件	*/
	char fdst[MAX_PATH];

	if (argc > 1 && *(argv[1] + 0) == '/') {
		while (*argv[1] == '/') {
			if (!strcmp(&argv[1][1], "nologo"))
				logo = 0;
			else if (!strcmp(&argv[1][1], "verbose"))
				verbose = 1;
			argv++;
			argc--;
		}
	}
	if (argc == 1) {
		i18 = 1;
	}
	if (logo) {
		printf("ExeToImg 1.1 Copyright (C) 1998, Expos Corp.\n");
		printf("Recode by Tary (23:16 2007-8-24).\n");
	}
	if (verbose) {
		printf("verbose option is specified\n");
	}
	if (i18) {
		printf("Format: ExeToImg [/verbose] [/nologo] file[.exe]\n");
		return EXIT_FAILURE;
	} else {
		if (!(fsrc = strrchr(argv[1], '\\')))
			fsrc = argv[1];
		strcpy(fdst, argv[1]);
		if (!strrchr(fsrc, '.')) {
			strcat(fsrc, ".exe");
		} else {
			*(fsrc = strrchr(fdst, '.')) = '\0';
		}
		strcat(fdst, ".img");			/* 得到image文件句 */
		fsrc = argv[1];

		if (-1 == access(fsrc, 0)) {		/* 是否有打开PE文件的权限 */
			printf("Error: %s does not exist.\n", fsrc);
			return EXIT_FAILURE;
		}

		if (pe2img(fsrc, fdst)) {		/* That's all */
			printf("OK: converted %s to %s\n", fsrc, fdst);
			return EXIT_SUCCESS;
		}
		
	}
	return EXIT_FAILURE;
}

