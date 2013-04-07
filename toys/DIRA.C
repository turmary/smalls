#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <string.h>
#define DEBUG
#include <assert.h>

typedef struct tagBootSector {
	unsigned char	jmp_order[3];
	unsigned char	oem[8];
	unsigned int	bytesPerSector;
	unsigned char	sectPerCluster;
	unsigned int	resSectors;
	unsigned char	nFats;
	unsigned int	nRootDir;
	unsigned int	nSectors;
	unsigned char	MID;
	unsigned int	sectPerFat;
	unsigned int	sectPerTrack;
	unsigned int	nHeads;
	unsigned long	nHidden;
	unsigned long	nSectorHuge;
	unsigned int	drive;
	unsigned char	extBoot;
	unsigned long	volid;
	unsigned char	vollabel[11];
	unsigned char	filesys[8];
	unsigned char	boot_order[450];
}bootSector[1];

/* FAT file system attribute bits					*/
#define	D_NORMAL	0		/* normal			*/
#define	D_RDONLY	0x01		/* read-only file		*/
#define	D_HIDDEN	0x02		/* hidden			*/
#define	D_SYSTEM	0x04		/* system			*/
#define	D_VOLID		0x08		/* volume id			*/
#define	D_DIR		0x10		/* subdir			*/
#define	D_ARCHIVE	0x20		/* archive bit			*/

/* FAT file name constants						*/
#define	FNAME_SIZE		8
#define	FEXT_SIZE		3

/* FAT deleted flag							*/
#define	DELETED		0xe5		/* if first char, delete file	*/

/* FAT cluster to physical conversion macros				*/
#define clus_add(cl_no)		((int) (((int) cl_no - 2L) \
					* (int) cluster_size \
					+ (int) data_start))

#define clus2phys(cl_no,cl_size,d_st)	((int) (((int) cl_no - 2L) \
					* (int) cl_size \
					+ (int) d_st))

/* Test for 16 bit or 12 bit FAT					*/
#define SIZEOF_CLST16	2
#define FAT_MAGIC	4086

#define ISFAT16(dpbp)	(((dpbp)->dpb_size)>FAT_MAGIC)
#define ISFAT12(dpbp)	(((dpbp)->dpb_size)<=FAT_MAGIC)

/* FAT file system directory entry					*/
typedef struct tagDirEntry {
	unsigned char			/* Filename			*/
		dir_name[FNAME_SIZE];
	unsigned char				/* Filename extension		*/
		dir_ext[FEXT_SIZE];
	unsigned char				/* File Attribute		*/
		dir_attrib;
	char	dir_reserved[10];	/* reserved			*/
	unsigned int
		dir_time;		/* Time file created/updated	*/
	unsigned int
		dir_date;		/*  Date file created/updated	*/
	unsigned int
		dir_start;		/* Starting cluster		*/
					/* 1st available = 2		*/
	unsigned long
		dir_size;		/* File size in bytes		*/
}DirEntry, *pDirEntry;

#define DIRENT_SIZE	32

/* FAT Time notation in the form of hhhh hmmm mmmd dddd			*/

#define TM_HOUR(t)	(((t)>>11)&0x1f)
#define TM_MIN(t)	(((t)>>5)&0x3f)
#define TM_DEC(t)	((t)&0x1f)

#define TM_ENCODE(h,m,d) ((((h&0x1f))<<11)|(((m)&0x3f)<<5)|((d)&0x1f))



/* FAT file date - takes the form of yyyy yyym mmmd dddd where physical	*/
/* year=1980+yyyyyy							*/

#define DT_YEAR(d)	(((d)>>9)&0x7f)
#define DT_MONTH(d)	(((d)>>5)&0x0f)
#define DT_DAY(d)	((d)&0x1f)

#define DT_ENCODE(m,d,y) ((((m)&0x0f)<<5)|((d)&0x1f)|(((y)&0x7f)<<9))

#define EPOCH_WEEKDAY	2	/* Tuesday (i. e.-  0 == Sunday)	*/
#define EPOCH_MONTH	1	/* January				*/
#define EPOCH_DAY	1	/* 1 for January 1			*/
#define EPOCH_YEAR	1980	/* for Tues 1-1-80 epoch		*/



bootSector gBootRec;

int getSectors(
	unsigned char nCount,
	unsigned int nCylin,
	unsigned char nHeader,
	unsigned char nSector,
	unsigned char far* buffer
) {
	struct SREGS sreg;
	union REGS reg;

	reg.h.al = nCount;
	reg.h.ah = 2;
	reg.h.cl = (unsigned char)((0x0300 & nCylin) >> 2) | (0x3F & nSector);
	reg.h.ch = (unsigned char)(nCylin & 0x00FF);
	reg.h.dh = nHeader;
        reg.h.dl = 0; /*0x80 + 'I' - 'C';*/
	reg.x.bx = FP_OFF(buffer);
	sreg.ds = _DS;
	sreg.es = FP_SEG(buffer);	/*don't use geninterrupt*/
	int86x(0x13, &reg, &reg, &sreg);
	return (int)reg.h.ah;

}

/*		;
		; translate sector number to BIOS parameters
		;
*/

int getCHS(int nLogiSec, int* npCylin, int* npHeader, int* npSector)
/*		;
		; abs = sector                          offset in track
		;     + head * sectPerTrack             offset in cylinder
		;     + track * sectPerTrack * nHeads   offset in platter
		;
		; t1     = abs  /  sectPerTrack         (ax has t1)
		; sector = abs mod sectPerTrack         (cx has sector)
		;
		;
		; t1   = head + track * nHeads
		;
		; track = t1  /  nHeads                 (ax has track)
		; head  = t1 mod nHeads                 (dl has head)
		;
*/
{
	int t1 = nLogiSec / gBootRec->sectPerTrack;

	*npSector = nLogiSec % gBootRec->sectPerTrack + 1;
	*npHeader = t1 % gBootRec->nHeads;
	*npCylin = t1 / gBootRec->nHeads;
	return 0;
}

int getSectorByLogi (int nCount, int nLogiSec, unsigned char far* buffer) {
	int nCylin, nHeader, nSector;

	getCHS(nLogiSec, &nCylin, &nHeader, &nSector);
	assert (printf("\ngetSectorByLogi() LogicSec %d = C: %d H: %d S: %d\n",
	  nLogiSec, nCylin, nHeader, nSector));

	return getSectors(nCount, nCylin, nHeader, nSector, buffer);
}

int displayBootRec(){
		printf ("bytesPerSector=%u\n", gBootRec->bytesPerSector);
		gBootRec->oem[7] = 0;
		printf ("oem=%s\t\n", gBootRec->oem);
		printf ("sectPerCluster=%u\n", gBootRec->sectPerCluster);
		printf ("resSectors=%u\n", gBootRec->resSectors);
		printf ("nFats=%u\n", gBootRec->nFats);
		printf ("nRootDir=%u\n", gBootRec->nRootDir);
		printf ("nSectors=%u\n", gBootRec->nSectors);
		printf ("MID=0x%XH\n", gBootRec->MID);
		printf ("sectPerFat=%u\n", gBootRec->sectPerFat);
		printf ("sectPerTrack=%u\n", gBootRec->sectPerTrack);
		printf ("nHeads=%u\n", gBootRec->nHeads);
		printf ("nHidden=%lu\n", gBootRec->nHidden);
		printf ("nSectorHuge=%lu\n", gBootRec->nSectorHuge);
		printf ("drive=%u\n", gBootRec->drive);
		printf ("extBoot=%u\n", gBootRec->extBoot);
		printf ("volid=%lu\n", gBootRec->volid);
		*gBootRec->boot_order = 0;
		printf ("filesys=%s\t\n", gBootRec->filesys);
		*gBootRec->filesys = 0;
		printf ("vollabel=%s\t\n", gBootRec->vollabel);
	return 0;
}

int displayDirEntry(pDirEntry pRoot, int i) {
	int t;
	char szFileName[FNAME_SIZE+FEXT_SIZE+1];

		if (*(pRoot->dir_name) == DELETED || *(pRoot->dir_name) == 0x0)
			return 1;
		printf("\n    Directory %d \n", i);
		strncpy(szFileName, pRoot->dir_name, FNAME_SIZE+FEXT_SIZE);
		szFileName[FNAME_SIZE+FEXT_SIZE] = 0;
		printf("Name: %s\n", szFileName);
		t = pRoot->dir_attrib;
		printf("Attribute: %c%c%c%c%c%c%c\n",
		  (t == D_NORMAL) ? 'N': ' ',
		  (t & D_RDONLY) ? 'R': ' ',
		  (t & D_HIDDEN) ? 'H': ' ',
		  (t & D_SYSTEM) ? 'S': ' ',
		  (t & D_VOLID) ? 'L': ' ',
		  (t & D_DIR) ? 'D': ' ',
		  (t & D_ARCHIVE) ? 'A': ' ');
		t = pRoot->dir_time;
		printf("Time: %d:%d:%d\n", TM_HOUR(t), TM_MIN(t), 2 * TM_DEC(t));
		t = pRoot->dir_date;
		printf("Date: %d-%d-%d\n", 1980+DT_YEAR(t), DT_MONTH(t), DT_DAY(t));
		printf("Start Cluster: %u\n", pRoot->dir_start);
		printf("Size: %lu\n", pRoot->dir_size);
	return 0;
}

int initDiskArg(){
	return getSectors(1, 0, 0, 1, (unsigned char far*)gBootRec);
}

int getFirstFAT(char far* buffer)
/* Logic Sectors of First FAT */
{
	int nLogiSec = gBootRec->resSectors, nCount, nCylin, nHeader, nSector;

	getCHS(nLogiSec, &nCylin, &nHeader, &nSector);
	assert (printf("\nLogicSec %d = C: %d H: %d S: %d\n",
	  nLogiSec, nCylin, nHeader, nSector));

	assert(printf("\npFATBuf Buffer Size=%d \n",
	  gBootRec->sectPerFat*gBootRec->bytesPerSector));
	nCount = gBootRec->sectPerFat;
	return getSectors(nCount, nCylin, nHeader, nSector, (unsigned char far*)buffer);
}

int getRootDir(char far* buffer)
/* Logic Sector of Root Directory */
{
	int nCount, nCylin, nHeader, nSector;
	int nLogiSec = gBootRec->resSectors + gBootRec->nFats * gBootRec->sectPerFat;

	assert(printf("\npRootSec Buffer Size=%d \n", gBootRec->nRootDir * DIRENT_SIZE));
	assert(printf("\nRead Root Dir %d Sectors\n",
	  gBootRec->nRootDir * DIRENT_SIZE / gBootRec->bytesPerSector));

	nCount = gBootRec->nRootDir * DIRENT_SIZE / gBootRec->bytesPerSector;
	getCHS(nLogiSec, &nCylin, &nHeader, &nSector);

	return getSectors(nCount,
	  nCylin, nHeader, nSector, (unsigned char far*)buffer);
}

int main(){
	int i = 0, nRet;
	unsigned char far*pFATBuf = NULL, pFileBuf[513];
	pDirEntry pRootSec = NULL;

	clrscr();
	if(!(i = initDiskArg())) {
		displayBootRec();
		assert(getch());
	} else {
		assert(printf ("Read Sector Error %d!\n", i));
		exit (1);
	}
	assert(printf("\nBootSector Struct Size=%d\n", sizeof(struct tagBootSector)));

	pFATBuf = (char*)calloc(gBootRec->sectPerFat, gBootRec->bytesPerSector);
	if(!getFirstFAT(pFATBuf)){
		assert(printf("\nRead FAT OK!\n"));
	}

	pRootSec = (pDirEntry)calloc(gBootRec->nRootDir, DIRENT_SIZE);
	if(!(i = getRootDir((unsigned char far*)pRootSec))){
		assert(printf("\nRead Root Dir OK!\n"));
	} else {
		assert(printf("\nError %d Read Root Dir!\n", i));
	}

	assert(printf("\ncoreleft=%u Bytes\n", coreleft()));

	for(i = 0; i < gBootRec->nRootDir; ++i) {
		if (displayDirEntry(pRootSec+i, i))
			continue;
		assert(printf("%d %i", gBootRec->nRootDir, i));
		assert(getch());
	}


#define CHAR2LONG(addr)   (*(unsigned long*)(addr))
#define CLUS_POS(pFAT, t) ( ((unsigned int)t & 0x1) ? \
  (( CHAR2LONG(&pFAT[t*3/2]) & 0xFFF0) >> 4) : \
   ( CHAR2LONG(&pFAT[t*3/2]) & 0x0FFF) )


	/*for (i = 2; i < 2048*3/2; i++){
		printf(" %02XH", pFATBuf[i]);
	}

	printf("\n");
	for (i = 2; i < 2048; i++){
		printf("FAT[%d] = \t%03lXH\n", i, CLUS_POS(pFATBuf, i));
		if (CLUS_POS(pFATBuf, i) >= 0xFF0)
			printf("File End %d\n", i);
	}*/

#define cluster_size (gBootRec->sectPerCluster)
#define data_start (gBootRec->resSectors + \
  gBootRec->nFats * gBootRec->sectPerFat + \
  gBootRec->nRootDir * DIRENT_SIZE / gBootRec->bytesPerSector)
	printf ("File DirA.C\n");
	for (i = 292; (unsigned)i < 0xFF0; i = (int)CLUS_POS(pFATBuf, i)) {
		printf("\nLogic Sector %03X\n", (unsigned)i);
		nRet = getSectorByLogi(1, clus_add(i), (unsigned char far*)pFileBuf);
		if (nRet) {
			printf("Read File Error %d \n", nRet);
			break;
		}
		pFileBuf[512] = 0;
		printf("%s\n", pFileBuf);
		assert(getch());
	}
	assert(printf("cluster_size=%d\n", cluster_size));
	assert(printf("data_start=%d\n", data_start));
	assert(printf("clus_add(%d)=%u\n", 2, clus_add(2)));

	free(pFATBuf);
	free(pRootSec);
	getch();
	return 0;
}
