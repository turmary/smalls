	.file	"clock.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Delay for three seconds\12\0"
LC1:
	.ascii "Done!\12\0"
	.align 4
LC2:
	.ascii "Time to do %ld empty loops is \0"
LC4:
	.ascii "%2.1f seconds\12\0"
	.align 8
LC3:
	.long	0
	.long	1083129856
	.text
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	call	__alloca
	call	___main
	movl	$600000000, -4(%ebp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$3000, (%esp)
	call	_sleep
	movl	$LC1, (%esp)
	call	_printf
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	call	_clock
	movl	%eax, -8(%ebp)
L2:
	leal	-4(%ebp), %eax
	decl	(%eax)
	cmpl	$-1, -4(%ebp)
	je	L3
	jmp	L2
L3:
	call	_clock
	movl	%eax, -12(%ebp)
	movl	-8(%ebp), %edx
	movl	-12(%ebp), %eax
	subl	%edx, %eax
	pushl	%eax
	fildl	(%esp)
	leal	4(%esp), %esp
	fldl	LC3
	fdivrp	%st, %st(1)
	fstpl	-24(%ebp)
	fldl	-24(%ebp)
	fstpl	4(%esp)
	movl	$LC4, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	ret
.globl _sleep
	.def	_sleep;	.scl	2;	.type	32;	.endef
_sleep:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	call	_clock
	addl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
L5:
	call	_clock
	cmpl	-4(%ebp), %eax
	jge	L4
	jmp	L5
L4:
	leave
	ret
	.def	_clock;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
