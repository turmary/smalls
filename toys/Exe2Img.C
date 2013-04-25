/*	@FileName: Exe2Img.C 
	@Function: Convert a PE executable to a flat image file
	@Author:   Tary
	@Date:	   22:58 2007-8-24
	@Priciple: PE�ļ��ɶ���ڹ���, PE�ļ��еĽڽ�RawData,
		ֻҪ���������·��õ�image�ļ�����ȷλ�ü���
	@Usage:	   Format: ExeToImg [/verbose] [/nologo] file[.exe]
		/verbose	��ʾ��ϸ��Ϣ
		/nologo		����ʾlogo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int logo = 1;		/* ��ʾLogo */
int verbose = 0;	/* �����ϸ��Ϣ */
DWORD ImageBase;

typedef struct{
	size_t fsize;	/* �ļ���С */
	char *f;	/* �ļ�ȫ·�� */
	HANDLE hsrc;	/* �ļ���� */
	HANDLE hmap;	/* �ļ�ӳ���� */
	char *pmap;	/* ӳ�����ݻ�ָ�� */
}STRUCMAP;

typedef struct PE_HEADER_MAP {		/* PE�ļ�ͷ���� */
	DWORD signature;		/* 'PE'��� */
	IMAGE_FILE_HEADER _head;	/* PE�ļ�ͷ */
	IMAGE_OPTIONAL_HEADER opt_head; /* PE��ѡͷ */
	IMAGE_SECTION_HEADER section_header[1];	/* �ڱ� */
} peHeader;


/* ���ļ�ӳ��, ���Զ���д */
/* ����: ����0, ���򷵻�1   */
BOOL openmapf(STRUCMAP* ppemap) {
	/* �����Ĵ����봫������ppemap�ṹ�� */
	ppemap->hsrc = CreateFile(ppemap->f,
	  GENERIC_READ | GENERIC_WRITE,
	  0, NULL, OPEN_ALWAYS,
	  FILE_ATTRIBUTE_NORMAL, NULL);

	if (ppemap->hsrc == INVALID_HANDLE_VALUE) {
		printf("CreateFile() file %s error\n", ppemap->f);
		return 0;
	}

	/* ���ڲ����ڵ��ļ�,Ҫ��ȷ�ش����½��ļ��ĳߴ� */
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



/* ��srcָ����PE�ļ�ת��Ϊdstָ����image�ļ� */
/* ����: ����0, ���򷵻�1                    */
BOOL pe2img(char* src, char* dst) {
	STRUCMAP pemap;				/* PE�ļ���ӳ��ṹ */
	STRUCMAP imgmap;			/* img�ļ���ӳ��ṹ*/
	size_t ImgSize;				/* image�ļ���С */
	peHeader *header;			/* PE�ļ�ͷָ��  */
	IMAGE_DOS_HEADER *dos_head;		/* Ϊ�˲����ֳ����Ľṹ�� */		
	IMAGE_FILE_HEADER* filehead;		/* ����ΪPEͷ���������ּ� */
	IMAGE_OPTIONAL_HEADER* opthead;		/* DOSͷ��������ָ��      */
	IMAGE_SECTION_HEADER* sechead;		
	DWORD secoff, secsize, rawoff, lastoff; /* �ڵĲ���      */
	size_t SecNo;				/* �ڵ���Ŀ      */
	BOOL bret = 1;
	

	pemap.f = src;
	pemap.fsize = 0;
	if (!(bret = openmapf (&pemap))) {	/* ��PE�ļ�ӳ�� */
		goto l_exit;
	}

	dos_head = (IMAGE_DOS_HEADER *) pemap.pmap; /* �õ�DOSͷ */


	header = (peHeader *) ((char *) dos_head + dos_head->e_lfanew);	/* �õ�PE�ļ�ͷ */
	if (header->signature != 0x00004550) {				/* 'PE'����Ƿ���ȷ */
		printf("Error: %s is not a PE executable.\n", src);
		bret = 0;
		goto l_exit;
	}

	filehead = &header->_head;
	if (filehead->Machine != 0x14C) {				/* �Ƿ�����x86���� */
		printf("Warning: %s is not a 386 executable.\n", src);
	}

	opthead = &header->opt_head;
	ImageBase = opthead->ImageBase;
	/*printf("size of IMAGE_OPTIONAL_HEADER = %3X\n",
	  sizeof(IMAGE_OPTIONAL_HEADER));*/
	sechead = &header->section_header;				/* �ڱ�ָ�� */

	imgmap.f = dst;
	imgmap.fsize = opthead->SizeOfImage;	/* image�ļ���С���Կ�ѡͷ */
	if (!(bret = openmapf (&imgmap))) {	/* ��image�ļ�ӳ�� */
		goto l_exit;
	}

	SecNo = filehead->NumberOfSections;	/* �ڵ���Ŀ */
	if (SecNo == 0) {
		bret = 0;
		goto l_exit;
	}
	lastoff = 0;
	while (SecNo > 0) {				/* ��ÿ���ڽ��д��� */
		int i;

		secoff = sechead->VirtualAddress;	/* ����image�е�ƫ�� */
		secsize = sechead->SizeOfRawData;	/* ����PE�ļ��еĴ�С */
		rawoff = sechead->PointerToRawData;	/* ����PE�ļ��е�ƫ�� */
		if (verbose != 0) {
			printf("\nSection %s\n", sechead->Name);
		}
		if (secsize == 0) {
			continue;
		}
		if (verbose != 0 && (secoff-lastoff) > 0) {
			printf("\tPadding with %d 0s at offset %xh\n", secoff-lastoff, lastoff);
		}
		/* ��0����û�н����ݵĿն� */
		for (i = 0; i < secoff-lastoff; i++) {
			imgmap.pmap[lastoff + i] = '\0';
		}
		if (verbose != 0) {
			printf("\tCopying %d bytes to offset %xh\n", secsize, secoff);
		}
		/* ���ľ���һ��memcpy */
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


/* �������� */
int main(int argc, char**argv, char** envp) {
	int i18 = 0;		/* ��������ȷ�� */
	char* fsrc;		/* Դ�ļ�	*/
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
		strcat(fdst, ".img");			/* �õ�image�ļ��� */
		fsrc = argv[1];

		if (-1 == access(fsrc, 0)) {		/* �Ƿ��д�PE�ļ���Ȩ�� */
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
