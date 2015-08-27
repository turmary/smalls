; 1> move boot sector self to 8000:0000 and continue execute there
; 2> clear screen & display logo & reset disk
; 3> get the first secotr # of data file
; 4> display "Loading"
; 5> read kernel data to 4000:0000
; 6> repeat 5> until kernel data more than 64K
; 7> move kernel data from 4000:0000 to 0000:0000 length 64K * 4 bytes
; 8> jump to kernel entry point 0000:1000


PAGE  59,132


;DEBUG	EQU

IFDEF	DEBUG
BASE	EQU	0h
ELSE
BASE	EQU	100h
ENDIF


text		segment	byte public
		assume	cs:text, ds:text


		org	BASE

bootsctr	proc	far

start:
		jmp	short real_start
		nop



offoem		EQU	[oem - BASE]
offbytePSec	EQU	[bytePSec - BASE]
offresSecs	EQU	[resSecs - BASE]
offnFats	EQU	[nFats - BASE]
offnRootDir	EQU	[nRootDir - BASE]
offsecPFat	EQU	[secPFat - BASE]
offsecPtrck	EQU	[secPtrck - BASE]
offnHeads	EQU	[nHeads - BASE]
offnHidn	EQU	[nHidn - BASE]
offnHidnHigh	EQU	[nHidnHigh - BASE]
offnSecs	EQU	[nSecs - BASE]
offdrive	EQU	[drive - BASE]
offextBoot	EQU	[extBoot - BASE]
offvolid	EQU	[volid - BASE]
offvolabel	EQU	[volabel - BASE]
offfilesys	EQU	[filesys - BASE]
offKrnlSize	EQU	[KrnlSize - BASE]



offLogo		EQU	[Logo - BASE]
offDiskErr	EQU	[DiskErr - BASE]
offMsgLoad	EQU	[MsgLoad - BASE]
offMsgDot	EQU	[MsgDot - BASE]




oem		db	45h, 58h, 50h, 4Fh, 53h, 0C9h, 20h, 20h
bytePSec	db	00h, 02h, 01h
resSecs		db	01h, 00h
nFats		db	02h
nRootDir	db	0E0h, 00h, 40h
		db	0Bh,0F0h
secPFat		db	09h, 00h
secPtrck	db	12h, 00h
nHeads		db	02h, 00h
nHidn		db	2 dup (0)
nHidnHigh	db	2 dup (0)
nSecs		db	4 dup (0)
drive		db	0h, 0h
extBoot		db	29h
volid		db	00h, 00h, 00h, 00h
volabel		db	'NO NAME    '
filesys		db	'FAT12   '
KrnlSize	db	80h, 00h


;
;                       External Entry Point
;


real_start:
		cld				; Clear direction

		; set stack postion
		cli				; Disable interrupts
		mov	AX,9000h
		mov	SS,AX
		mov	SP,1000h
		sti				; Enable interrupts

		; move data from 0000:7c00 to 8000:0000 data length 200h bytes
		mov	AX,8000h
		mov	ES,AX
		xor	DI,DI			; Zero register

		mov	AX,7C0h
		mov	DS,AX
		xor	SI,SI			; Zero register

		mov	CX,100h

		rep	movsw			; Rep when cx >0 Mov [si] to es:[di]

		; jump to the new place
;*		jmp	far ptr loc_2		;*
		db	0EAh
		dw	offset new_start - BASE, 8000h	;  Fixup - byte match
			                        ;* No entry point to code


new_start:	mov	AX,8000h		; set new data segment to 8000h
		mov	DS,AX

		call	ClrScr

		; display logo
		lea	SI, word ptr ds:offLogo		; Load effective addr
		call	DispStr

		; reset disk
		mov	DL,byte ptr ds:offdrive
		xor	AX,AX			; Zero register
		int	13h			; Disk  dl=drive ?  ah=func 00h
						; al=return status

;*		pop	CS			; Dangerous-8088 only
		db	0Fh			;  Fixup - byte match

;*		cmp	byte ptr ds:3300h[DI],0C0h
		db	 82h,0BDh, 00h, 33h,0C0h	;  Fixup - byte match

		; find the first file data sectors
		; start = dx:ax = SecPerFat * nFats + nHidn + resSecs + 20 * nRootDir / bytePerSec
		mov	AL,byte ptr ds:offnFats
		mul	word ptr ds:offsecPFat		; dx:ax = SecPerFat * nFats
		add	AX,word ptr ds:offnHidn
		adc	DX,word ptr ds:offnHidnHigh
		add	AX,word ptr ds:offresSecs	; dx:ax=SecPerFat*nFats+nHidn+resSecs
		mov	CX,AX
		mov	AX,20h
		mul	word ptr ds:offnRootDir	; dx:ax = data * ax
		div	word ptr ds:offbytePSec	; ax,dxrem=dx:ax/data
		add	AX,CX
		
		; display 'Loading'
		lea	SI,word ptr ds:offMsgLoad		; Load effective addr
		call	DispStr


		; load file data to 4000:0000
		mov	BX,4000h
		mov	ES,BX

		; CL = start % SecPerTrack + 1
		xor	BX,BX			; Zero register
		div	word ptr ds:offsecPTrck	; ax,dxrem=dx:ax/data
		inc	DX
		mov	CL,DL

		; CH = cylinder = start / SecPerTrack / nHeads
		; DH = head = start / SecPerTrack % nHeads
		xor	DX,DX			; Zero register
		div	word ptr ds:offnHeads	; ax,dxrem=dx:ax/data
		mov	CH,AL
		mov	DH,DL

		; DL = drive
		; Read Sec # = SecPerTrack - (start % SecPerTrack) + 1
		mov	DL,byte ptr ds:offdrive
		mov	AX,word ptr ds:offsecPTrck
		sub	AL,CL
		inc	AL
read_sectors:
		mov	AH,2
		int	13h			; Disk  dl=drive ?  ah=func 02h
						;  read sectors to memory es:bx
						;   al=#,ch=cyl,cl=sectr,dh=head
		jc	read_error			; Jump if carry Set


		; display '.' to view read data a time
		lea	SI,word ptr ds:offMsgDot	; Load effective addr
		call	DispStr

		; 0x80 <= al then jump
		; because 0x80 * 512 (one secotr) = 64K = KrnlSize
		xor	AH,AH			; Zero register
		sub	word ptr ds:offKrnlSize,AX
		jle	read_comp		; Jump if < or =

		; ES += AX + 20h * AL
		; 20h = 200h (byte per sector) / 10h (bytes per segment part)
		mov	BL,20h			; ' '
		mul	BL			; ax = 20h * al
		mov	BX,ES
		add	AX,BX
		mov	ES,AX
		xor	BX,BX			; Zero register

		add	CH,DH			; cylinder += heads
		xor	DH,1			; reverse head
		mov	CL,1			; sector no 1

		; ax = min (SecPerTrack, 0x80)
		mov	AX,word ptr ds:offsecPTrck
		cmp	AX,word ptr ds:offKrnlSize
		jbe	read_sectors		; Jump if below or =
		mov	AX,word ptr ds:offKrnlSize
		jmp	short read_sectors

		; if there more than 64K then goto here
read_comp:
		mov	AL,0Ch
		mov	DX,3F2h
		out	DX,AL			; port 3F2h, dsk0 contrl output

		cli				; Disable interrupts

		; move data from 4000:0000 to 0000:0000 length 64K * 4 bytes
		mov	AX,4000h
		mov	DS,AX
		mov	AX,0
		mov	ES,AX
		mov	BX,4
move_kernel:
		xor	SI,SI			; Zero register
		xor	DI,DI			; Zero register
		mov	CX,8000h
		rep	movsw			; Rep when cx >0 Mov [si] to es:[di]

		dec	BX
		jz	jmp_kernel		; Jump if zero

		; DS += 1000h
		; ES += 1000h
		mov	AX,DS
		add	AX,1000h
		mov	DS,AX
		mov	AX,ES
		add	AX,1000h
		mov	ES,AX
		jmp	short move_kernel

		;jmp to the kernel entry point 1000:0000
jmp_kernel:
		xor	AX,AX			; Zero register
		mov	DS,AX
;*		jmp	far ptr 0000:1000	;*
		db	0EAh
		dw	1000h, 0		;  Fixup - byte match


		; so we press any key then restart
read_error:
		lea	SI,word ptr ds:offDiskErr		; Load effective addr
		call	DispStr
		xor	AX,AX			; Zero register
		int	16h			; Keyboard i/o  ah=function 00h
						;  get keybd char in al, ah=scan
		int	19h			; Bootstrap loader

bootsctr	endp


;  SUBROUTINE


ClrScr		proc	near
		mov	AX,0600h
		mov	BH,7
		xor	CX,CX			; Zero register
		mov	DX,1850h
		int	10h			; Video display   ah=functn 06h
						;  scroll up, al=lines
						;   bh=attrib, cx+dx=window size
		mov	AH,2
		xor	BH,BH			; Zero register
		xor	DX,DX			; Zero register
		int	10h			; Video display   ah=functn 02h
						;  set cursor location in dx
		retn
ClrScr		endp



; SUBROUTINE DispStr
;	Display a string pointed by reg DI
;	the string must be zero end


DispStr		proc	near
		push	AX
		push	BX
		mov	AH,0Eh
		mov	BX,7
disp_8:
		lodsb				; String [si] to al
		or	AL,AL			; Zero ?
		jz	disp_9			; Jump if zero
		int	10h			; Video display   ah=functn 0Eh
						;  write char al, teletype mode
		jmp	short disp_8
disp_9:
		pop	BX
		pop	AX
		retn
DispStr		endp



Logo		db	'Boot Loader 1.1 (64KB)', 0Ah, 0Dh
;		db	'Copyright (C) 1999, Expose corp.', 0Ah, 0Dh
		db	'Recode by tary', 0Ah, 0Ah, 0Dh, 0
DiskErr		db	'Disk Error.', 0Ah, 0Dh
		db	'Replace the disk and press a key.', 0Ah, 0Dh, 0
MsgLoad		db	'Loading', 0
MsgDot		db	'.', 0

		org	2FEH
		db	55h,0AAh

text		ends



		end	start
