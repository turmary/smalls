	ifndef	??version
?debug	macro
	endm
	endif
	?debug	S "p8_1a.c"
_TEXT	segment	byte public 'CODE'
DGROUP	group	_DATA,_BSS
	assume	cs:_TEXT,ds:DGROUP,ss:DGROUP
_TEXT	ends
_DATA	segment word public 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public 'BSS'
b@	label	byte
b@w	label	word
	?debug	C E92AA54D330770385F31612E63
_BSS	ends
_TEXT	segment	byte public 'CODE'
;	?debug	L 1
_mputc	proc	near
	push	bp
	mov	bp,sp
;	?debug	L 2
	mov	dl,byte ptr [bp+4]
;	?debug	L 3
	mov	ah,2
;	?debug	L 4
 	int	 021H
@1:
;	?debug	L 5
	pop	bp
	ret	
_mputc	endp
_TEXT	ends
_BSS	segment word public 'BSS'
	db	11 dup (?)
_BSS	ends
_TEXT	segment	byte public 'CODE'
;	?debug	L 7
_i2str	proc	near
	push	bp
	mov	bp,sp
	sub	sp,4
	push	si
	push	di
	mov	di,word ptr [bp+4]
;	?debug	L 10
	xor	si,si
;	?debug	L 10
	mov	word ptr [bp-2],0
;	?debug	L 12
	or	di,di
	jge	@3
;	?debug	L 13
	mov	byte ptr DGROUP:b@[si],45
	inc	si
;	?debug	L 14
	inc	word ptr [bp-2]
;	?debug	L 15
	mov	ax,di
	neg	ax
	mov	di,ax
;	?debug	L 16
	jmp	short @4
@3:
;	?debug	L 16
	or	di,di
	jne	@5
;	?debug	L 17
	mov	byte ptr DGROUP:b@[si],48
	inc	si
@5:
@4:
	jmp	short @9
@8:
;	?debug	L 19
	mov	ax,di
	mov	bx,10
	cwd	
	idiv	bx
	add	dl,48
	mov	byte ptr DGROUP:b@[si],dl
	inc	si
;	?debug	L 20
	mov	ax,di
	mov	bx,10
	cwd	
	idiv	bx
	mov	di,ax
@7:
@9:
;	?debug	L 18
	or	di,di
	jne	@8
@6:
;	?debug	L 22
	mov	byte ptr DGROUP:b@[si],0
	dec	si
	jmp	short @10
@12:
;	?debug	L 24
	mov	al,byte ptr DGROUP:b@[si]
	mov	byte ptr [bp-3],al
;	?debug	L 25
	mov	bx,word ptr [bp-2]
	mov	al,byte ptr DGROUP:b@[bx]
	mov	byte ptr DGROUP:b@[si],al
	dec	si
;	?debug	L 26
	mov	al,byte ptr [bp-3]
	mov	bx,word ptr [bp-2]
	mov	byte ptr DGROUP:b@[bx],al
	inc	word ptr [bp-2]
@10:
;	?debug	L 23
	mov	ax,word ptr [bp-2]
	cmp	ax,si
	jl	@12
@11:
;	?debug	L 28
	mov	ax,offset DGROUP:b@
	jmp	short @2
@2:
;	?debug	L 29
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_i2str	endp
;	?debug	L 31
_print	proc	near
	push	bp
	mov	bp,sp
	push	si
;	?debug	L 34
	push	word ptr [bp+4]
	call	near ptr _i2str
	pop	cx
	mov	si,ax
	jmp	short @14
@16:
;	?debug	L 36
	mov	bx,si
	inc	si
	push	word ptr [bx]
	call	near ptr _mputc
	pop	cx
@14:
;	?debug	L 35
	cmp	byte ptr [si],0
	jne	@16
@15:
;	?debug	L 37
	xor	ax,ax
	jmp	short @13
@13:
;	?debug	L 38
	pop	si
	pop	bp
	ret	
_print	endp
;	?debug	L 40
_main	proc	near
	push	bp
	mov	bp,sp
	sub	sp,6
	push	si
	push	di
;	?debug	L 44
	mov	word ptr [bp-6],0
;	?debug	L 45
	mov	word ptr [bp-4],300
;	?debug	L 46
	mov	word ptr [bp-2],20
;	?debug	L 48
	mov	si,word ptr [bp-6]
	jmp	short @18
@20:
;	?debug	L 50
	mov	ax,si
	add	ax,-32
	mov	dx,5
	mul	dx
	mov	bx,9
	cwd	
	idiv	bx
	mov	di,ax
;	?debug	L 51
	push	si
	call	near ptr _print
	pop	cx
;	?debug	L 52
	mov	al,9
	push	ax
	call	near ptr _mputc
	pop	cx
;	?debug	L 53
	push	di
	call	near ptr _print
	pop	cx
;	?debug	L 54
	mov	al,13
	push	ax
	call	near ptr _mputc
	pop	cx
;	?debug	L 55
	mov	al,10
	push	ax
	call	near ptr _mputc
	pop	cx
;	?debug	L 56
	add	si,word ptr [bp-2]
@18:
;	?debug	L 49
	cmp	si,word ptr [bp-4]
	jle	@20
@19:
;	?debug	L 58
	xor	ax,ax
	jmp	short @17
@17:
;	?debug	L 59
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_main	endp
_TEXT	ends
	?debug	C E9
_DATA	segment word public 'DATA'
s@	label	byte
_DATA	ends
_TEXT	segment	byte public 'CODE'
_TEXT	ends
	public	_print
	public	_i2str
	public	_main
	public	_mputc
	end
