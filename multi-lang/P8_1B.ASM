	ifndef	??version
?debug	macro
	endm
$comm	macro	name,dist,size,count
	comm	dist name:BYTE:count*size
	endm
	else
$comm	macro	name,dist,size,count
	comm	dist name[size]:BYTE:count
	endm
	endif
	?debug	S "p8_1a.c"
	?debug	C E932A319330770385F31612E63
_TEXT	segment byte public 'CODE'
_TEXT	ends
DGROUP	group	_DATA,_BSS
	assume	cs:_TEXT,ds:DGROUP
_DATA	segment word public 'DATA'
d@	label	byte
d@w	label	word
_DATA	ends
_BSS	segment word public 'BSS'
b@	label	byte
b@w	label	word
_BSS	ends
_TEXT	segment byte public 'CODE'
   ;	
   ;	void mputc(char c){
   ;	
	assume	cs:_TEXT
_mputc	proc	near
	push	bp
	mov	bp,sp
   ;	
   ;		asm	MOV	DL, c;
   ;	
		MOV		DL, [bp+4]
   ;	
   ;		asm	MOV	AH, 2;
   ;	
		MOV		AH, 2
   ;	
   ;		asm	INT	21H;
   ;	
		INT		21H
   ;	
   ;	}
   ;	
	pop	bp
	ret	
_mputc	endp
_TEXT	ends
_BSS	segment word public 'BSS'
	db	11 dup (?)
_BSS	ends
_TEXT	segment byte public 'CODE'
   ;	
   ;	char* i2str(int t){
   ;	
	assume	cs:_TEXT
_i2str	proc	near
	push	bp
	mov	bp,sp
	sub	sp,2
	push	si
	push	di
	mov	cx,word ptr [bp+4]
   ;	
   ;		static char st[11];
   ;		char k;
   ;		int i = 0, j = 0;
   ;	
	xor	si,si
	xor	di,di
   ;	
   ;	
   ;		if(0 > t){
   ;	
	or	cx,cx
	jge	short @2@86
   ;	
   ;			st[i++] = '-';
   ;	
	mov	byte ptr DGROUP:b@w+0[si],45
	inc	si
   ;	
   ;			j++;
   ;	
	inc	di
   ;	
   ;			t = -t;
   ;	
	mov	ax,cx
	neg	ax
	mov	cx,ax
   ;	
   ;		}else if(0 == t)
   ;	
	jmp	short @2@142
@2@86:
	or	cx,cx
	jne	short @2@142
   ;	
   ;			st[i++] = '0';
   ;	
	mov	byte ptr DGROUP:b@w+0[si],48
	inc	si
@2@142:
	jmp	short @2@198
@2@170:
   ;	
   ;		for(;0 != t;){
   ;			st[i++] = t % 10 + '0';
   ;	
	mov	ax,cx
	mov	bx,10
	cwd	
	idiv	bx
	add	dl,48
	mov	byte ptr DGROUP:b@w+0[si],dl
	inc	si
   ;	
   ;			t /= 10;
   ;	
	mov	bx,10
	mov	ax,cx
	cwd	
	idiv	bx
	mov	cx,ax
@2@198:
	or	cx,cx
	jne	short @2@170
   ;	
   ;		}
   ;		st[i--] = '\0';
   ;	
	mov	byte ptr DGROUP:b@w+0[si],0
	dec	si
	jmp	short @2@282
@2@254:
   ;	
   ;		while(j < i){
   ;			k = st[i];
   ;	
	mov	al,byte ptr DGROUP:b@w+0[si]
	mov	byte ptr [bp-1],al
   ;	
   ;			st[i--] = st[j];
   ;	
	mov	al,byte ptr DGROUP:b@w+0[di]
	mov	byte ptr DGROUP:b@w+0[si],al
	dec	si
   ;	
   ;			st[j++] = k;
   ;	
	mov	al,byte ptr [bp-1]
	mov	byte ptr DGROUP:b@w+0[di],al
	inc	di
@2@282:
	cmp	di,si
	jl	short @2@254
   ;	
   ;		}
   ;		return st;
   ;	
	mov	ax,offset DGROUP:b@w+0
	jmp	short @2@338
@2@338:
   ;	
   ;	}
   ;	
	pop	di
	pop	si
	mov	sp,bp
	pop	bp
	ret	
_i2str	endp
   ;	
   ;	int print(int n){
   ;	
	assume	cs:_TEXT
_print	proc	near
	push	bp
	mov	bp,sp
	push	si
   ;	
   ;		char* p;
   ;	
   ;		p = i2str(n);
   ;	
	push	word ptr [bp+4]
	call	near ptr _i2str
	pop	cx
	mov	si,ax
	jmp	short @3@86
@3@58:
   ;	
   ;		while(*p)
   ;			mputc(*p++);
   ;	
	mov	bx,si
	inc	si
	mov	al,byte ptr [bx]
	push	ax
	call	near ptr _mputc
	pop	cx
@3@86:
	cmp	byte ptr [si],0
	jne	short @3@58
   ;	
   ;		return 0;
   ;	
	xor	ax,ax
	jmp	short @3@142
@3@142:
   ;	
   ;	}
   ;	
	pop	si
	pop	bp
	ret	
_print	endp
   ;	
   ;	int main(){
   ;	
	assume	cs:_TEXT
_main	proc	far	;near
        PUSH    DS
        MOV     AX, 0
        PUSH    AX
	push	bp
	mov	bp,sp
        sub     sp,12
	push	si
   ;	
   ;		int fahr, celsius;
   ;		int lower, upper, step;
   ;	
   ;		lower = 0;
   ;	
	mov	word ptr [bp-4],0
   ;	
   ;		upper = 300;
   ;	
	mov	word ptr [bp-6],300
   ;	
   ;		step = 20;
   ;	
	mov	word ptr [bp-8],20
   ;	
   ;	
   ;		fahr = lower;
   ;	
	mov	si,word ptr [bp-4]
	jmp	short @4@86
@4@58:
   ;	
   ;		while(fahr <= upper) {
   ;			celsius = 5 * (fahr - 32) / 9;
   ;	
	mov	ax,si
	add	ax,65504
	mov	dx,5
	imul	dx
	mov	bx,9
	cwd	
	idiv	bx
	mov	word ptr [bp-2],ax
   ;	
   ;			print(fahr);
   ;	
	push	si
	call	near ptr _print
	pop	cx
   ;	
   ;			mputc('\t');
   ;	
	mov	al,9
	push	ax
	call	near ptr _mputc
	pop	cx
   ;	
   ;			print(celsius);
   ;	
	push	word ptr [bp-2]
	call	near ptr _print
	pop	cx
   ;	
   ;			mputc(13);
   ;	
	mov	al,13
	push	ax
	call	near ptr _mputc
	pop	cx
   ;	
   ;			mputc('\n');
   ;	
	mov	al,10
	push	ax
	call	near ptr _mputc
	pop	cx
   ;	
   ;			fahr += step;
   ;	
	add	si,word ptr [bp-8]
@4@86:
	cmp	si,word ptr [bp-6]
	jle	short @4@58
   ;	
   ;		}
   ;		return 0;
   ;	
	xor	ax,ax
	jmp	short @4@142
@4@142:
   ;	
   ;	}
   ;	
	pop	si
	mov	sp,bp
	pop	bp
        ret
        ;MOV     AX, 4C00H
        ;INT     21H
_main	endp
	?debug	C E9
_TEXT	ends
_DATA	segment word public 'DATA'
s@	label	byte
_DATA	ends
_TEXT	segment byte public 'CODE'
_TEXT	ends
	public	_main
	public	_print
	public	_i2str
	public	_mputc
_s@	equ	s@
        end     _main
