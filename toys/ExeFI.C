#include <stdio.h>
#include <stdlib.h>

#define WORD	unsigned short
#define LONG	unsigned long
typedef struct tagIMAGE_DOS_HEADER {      /* DOS .EXE header */
    WORD   e_magic;                     /* Magic number */
    WORD   e_cblp;                      /* Bytes on last page of file */
    WORD   e_cp;                        /* Pages in file */
    WORD   e_crlc;                      /* Relocations */
    WORD   e_cparhdr;                   /* Size of header in paragraphs */
    WORD   e_minalloc;                  /* Minimum extra paragraphs needed */
    WORD   e_maxalloc;                  /* Maximum extra paragraphs needed */
    WORD   e_ss;                        /* Initial (relative) SS value */
    WORD   e_sp;                        /* Initial SP value */
    WORD   e_csum;                      /* Checksum */
    WORD   e_ip;                        /* Initial IP value */
    WORD   e_cs;                        /* Initial (relative) CS value */
    WORD   e_lfarlc;                    /* File address of relocation table */
    WORD   e_ovno;                      /* Overlay number */
    WORD   e_res[4];                    /* Reserved words */
    WORD   e_oemid;                     /* OEM identifier (for e_oeminfo) */
    WORD   e_oeminfo;                   /* OEM information; e_oemid specific */
    WORD   e_res2[10];                  /* Reserved words */
    LONG   e_lfanew;                    /* File address of new exe header */
} IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

/*	get struct member offset
	STRUC	----  struct type pointer variable
	FIELD ----  struct member			*/
#define FIELD_OFF(STRUC, FIELD) ((char*)&(STRUC -> FIELD) - ((char*)STRUC))

int disp_exe_info(PIMAGE_DOS_HEADER pdh) {
	LONG lsize;

	printf("%02XH:%s\t\t%04XH\n", FIELD_OFF(pdh, e_magic), "File Type ", pdh->e_magic);
	printf("%02XH:%s\t\t%u\n", FIELD_OFF(pdh, e_cblp), "Size % 512", pdh->e_cblp);
	printf("%02XH:%s\t%u\n", FIELD_OFF(pdh, e_cp), "Size/512 + 1", pdh->e_cp);
	printf("%02XH:%s\t\t%u\n", FIELD_OFF(pdh, e_crlc), "Reloc Size", pdh->e_crlc);
	printf("%02XH:%s\t%u\n", FIELD_OFF(pdh, e_cparhdr), "Head Size/16 ", pdh->e_cparhdr);
	printf("%02XH:%s\t%04XH\n", FIELD_OFF(pdh, e_minalloc), "Min Extra/16", pdh->e_minalloc);
	printf("%02XH:%s\t%04XH\n", FIELD_OFF(pdh, e_maxalloc), "Max Extra/ 16", pdh->e_maxalloc);
	printf("%02XH:%s\t\t%04XH\n", FIELD_OFF(pdh, e_ss), "Init SS val", pdh->e_ss);
	printf("%02XH:%s\t\t%04XH\n", FIELD_OFF(pdh, e_sp), "Init SP val", pdh->e_sp);
	printf("%02XH:%s\t\t%u\n", FIELD_OFF(pdh, e_csum), "Check sum", pdh->e_csum);
	printf("%02XH:%s\t\t%04XH\n", FIELD_OFF(pdh, e_ip), "Init IP val", pdh->e_ip);
	printf("%02XH:%s\t\t%04XH\n", FIELD_OFF(pdh, e_cs), "Init CS val", pdh->e_cs);
	printf("%02XH:%s\t\t%04XH\n", FIELD_OFF(pdh, e_lfarlc), "& of Reloc", pdh->e_lfarlc);
	printf("%02XH:%s\t\t%u\n", FIELD_OFF(pdh, e_ovno), "Overlay #", pdh->e_ovno);
	printf("%02XH:%s\t\t%04X %04X %04X %04XH\n", FIELD_OFF(pdh, e_res), "Reserved DW",
	  pdh->e_res[0], pdh->e_res[1], pdh->e_res[2], pdh->e_res[3]);
	printf("%02XH:%s\t\t%u\n", FIELD_OFF(pdh, e_oemid), "OEM id", pdh->e_cblp);
	printf("%02XH:%s\t\t%04XH\n", FIELD_OFF(pdh, e_oeminfo), "OEM info", pdh->e_magic);
	printf("%02XH:%s\t\t%08LX\n", FIELD_OFF(pdh, e_lfanew), "New File &", pdh->e_lfanew);

	lsize = ((LONG)pdh->e_cp - 1) * 512 + (LONG)pdh->e_cblp;
	printf("\nOther Info getted\n");
	printf("File Size %lu(K) %lu(B) %08LX\n", lsize/1024, lsize, lsize);
	return 0;
}

int disp_reloc_list(FILE* fp, PIMAGE_DOS_HEADER pdh) {
	WORD i = 0;
	WORD* wp;

	printf("\n # ---\tSEG :OFF(hex)\tOFF(file)\n");
	wp = (WORD*)calloc(pdh->e_crlc, sizeof(WORD) * 2);
	fseek(fp, pdh->e_lfarlc, SEEK_SET);
	fread(wp, sizeof(WORD)*2, pdh->e_crlc, fp);
	for (i = 0; i < pdh->e_crlc; i++){
		printf("%02XH---\t%04X:%04XH\t%05X\n", i, wp[2*i+1], wp[2*i],
		  ((pdh->e_cparhdr + wp[2*i+1]) << 4) + wp[2*i]);
	}
	return 0;
}

int usage(void) {
	printf("Use to view the dos exe file header info!\n");
	printf("Usage:\tEXEFI filename\n");
	return 0;
}

int main(int argc, char* argv[]) {
	int iret;
	FILE* fp;
	IMAGE_DOS_HEADER exeheader[1];

	if (argc != 2) {
		usage();
		exit(1);
	}
	if (!(fp = fopen(argv[1], "rb"))){
		printf("open file %s error!\n", argv[1]);
		exit(2);
	}
	fseek(fp, 0, SEEK_CUR);
	iret = fread(exeheader, sizeof(IMAGE_DOS_HEADER), 1, fp);
	if (iret < 1) {
		printf("read file %s error!\n", argv[1]);
		exit(3);
	}
	disp_exe_info(exeheader);
	printf("\nView relocation table?\n");
	iret = getchar();
	if ('y' == iret || 'Y' == iret)
		disp_reloc_list(fp, exeheader);
	fclose(fp);
	return 0;
}
