	.file	"PassingBigStructures.cpp"
.globl _B
	.bss
	.align 32
_B:
	.space 108
.globl _B2
	.align 32
_B2:
	.space 108
	.text
.globl __Z6bigfun3Big
	.def	__Z6bigfun3Big;	.scl	2;	.type	32;	.endef
__Z6bigfun3Big:
LFB0:
	pushl	%ebp
LCFI0:
	movl	%esp, %ebp
LCFI1:
	pushl	%edi
LCFI2:
	pushl	%esi
LCFI3:
	pushl	%ebx
LCFI4:
	movl	$100, 112(%ebp)
	movl	8(%ebp), %edx
	leal	12(%ebp), %ebx
	movl	$27, %eax
	movl	%edx, %edi
	movl	%ebx, %esi
	movl	%eax, %ecx
	rep movsl
	movl	8(%ebp), %eax
	popl	%ebx
LCFI5:
	popl	%esi
LCFI6:
	popl	%edi
LCFI7:
	leave
LCFI8:
	ret	$4
LFE0:
	.def	___main;	.scl	2;	.type	32;	.endef
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1:
	leal	4(%esp), %ecx
LCFI9:
	andl	$-16, %esp
LCFI10:
	pushl	-4(%ecx)
LCFI11:
	pushl	%ebp
LCFI12:
	movl	%esp, %ebp
LCFI13:
	pushl	%edi
LCFI14:
	pushl	%esi
LCFI15:
	pushl	%ebx
LCFI16:
	pushl	%ecx
LCFI17:
	subl	$248, %esp
LCFI18:
	call	___main
	leal	-136(%ebp), %eax
	movl	%eax, -140(%ebp)
	leal	4(%esp), %edx
	movl	$_B, %ebx
	movl	$27, %eax
	movl	%edx, %edi
	movl	%ebx, %esi
	movl	%eax, %ecx
	rep movsl
	movl	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z6bigfun3Big
	subl	$4, %esp
	movl	$_B2, %edx
	leal	-136(%ebp), %ebx
	movl	$27, %eax
	movl	%edx, %edi
	movl	%ebx, %esi
	movl	%eax, %ecx
	rep movsl
	movl	$0, %eax
	leal	-16(%ebp), %esp
	addl	$0, %esp
	popl	%ecx
LCFI19:
	popl	%ebx
LCFI20:
	popl	%esi
LCFI21:
	popl	%edi
LCFI22:
	leave
	leal	-4(%ecx), %esp
LCFI23:
	ret
LFE1:
