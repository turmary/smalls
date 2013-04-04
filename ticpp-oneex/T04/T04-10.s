	.file	"T04-10.c"
	.text
.globl __A_
	.def	__A_;	.scl	2;	.type	32;	.endef
__A_:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$0, %eax
	popl	%ebp
	ret
.globl __B_
	.def	__B_;	.scl	2;	.type	32;	.endef
__B_:
	pushl	%ebp
	movl	%esp, %ebp
	fldz
	popl	%ebp
	ret
.globl __C_
	.def	__C_;	.scl	2;	.type	32;	.endef
__C_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	8(%ebp), %eax
	movb	%al, -1(%ebp)
	movl	$48, %eax
	leave
	ret
.globl __D_
	.def	__D_;	.scl	2;	.type	32;	.endef
__D_:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC3:
	.ascii "hello\0"
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	call	__alloca
	call	___main
	movl	$0, (%esp)
	call	__A_
	movl	$0x00000000, %eax
	movl	%eax, (%esp)
	call	__B_
	fstp	%st(0)
	movl	$48, (%esp)
	call	__C_
	movl	$LC3, 4(%esp)
	movl	$1, (%esp)
	call	__D_
	movl	$0, %eax
	leave
	ret
