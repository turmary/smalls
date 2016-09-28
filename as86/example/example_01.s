! SYS_SIZE is the number of clicks (16 bytes) to be loaded.
SYSSIZE = 0x3000
SYSSEG   = 0x1000			! system loaded at 0x10000 (65536).
SETUPLEN = 4				! nr of setup-sectors
.globl begtext, begdata, begbss, endtext, enddata, endbss
.text
ENDSEG   = SYSSEG + SYSSIZE		! where to stop loading
sread:	.word 1+SETUPLEN	! sectors read of current track
bad_rt:	mov ax,#0
