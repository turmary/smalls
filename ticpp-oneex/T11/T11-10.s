	.file	"T11-10.cpp"
	.text
	.align 2
.globl __Z4funci
	.def	__Z4funci;	.scl	2;	.type	32;	.endef
__Z4funci:
	pushl	%ebp
	movl	%esp, %ebp
	incl	8(%ebp)
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.align 2
.globl __Z9func_charc
	.def	__Z9func_charc;	.scl	2;	.type	32;	.endef
__Z9func_charc:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	8(%ebp), %eax
	movb	%al, -1(%ebp)
	movsbl	-1(%ebp),%eax
	leave
	ret
	.align 2
.globl __Z8func_inti
	.def	__Z8func_inti;	.scl	2;	.type	32;	.endef
__Z8func_inti:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.align 2
.globl __Z10func_floatf
	.def	__Z10func_floatf;	.scl	2;	.type	32;	.endef
__Z10func_floatf:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	flds	8(%ebp)
	fnstcw	-2(%ebp)
	movzwl	-2(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -4(%ebp)
	fldcw	-4(%ebp)
	fistpl	-8(%ebp)
	fldcw	-2(%ebp)
	movl	-8(%ebp), %eax
	leave
	ret
	.align 2
.globl __Z11func_doubled
	.def	__Z11func_doubled;	.scl	2;	.type	32;	.endef
__Z11func_doubled:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	fldl	8(%ebp)
	fnstcw	-2(%ebp)
	movzwl	-2(%ebp), %eax
	orw	$3072, %ax
	movw	%ax, -4(%ebp)
	fldcw	-4(%ebp)
	fistpl	-8(%ebp)
	fldcw	-2(%ebp)
	movl	-8(%ebp), %eax
	leave
	ret
	.align 2
.globl __Z2dfi
	.def	__Z2dfi;	.scl	2;	.type	32;	.endef
__Z2dfi:
	pushl	%ebp
	movl	%esp, %ebp
	fildl	8(%ebp)
	popl	%ebp
	ret
.globl _gd
	.data
	.align 8
_gd:
	.long	-858993459
	.long	1077497036
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
LC4:
	.long	1717986918
	.long	1077503590
	.text
	.align 2
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
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	call	__alloca
	call	___main
	movl	$99, (%esp)
	call	__Z9func_charc
	movl	$5, (%esp)
	call	__Z8func_inti
	movl	$0x40200000, %eax
	movl	%eax, (%esp)
	call	__Z10func_floatf
	fldl	LC4
	fstpl	(%esp)
	call	__Z11func_doubled
	fldl	_gd
	fstpl	-8(%ebp)
	movl	$2, (%esp)
	call	__Z2dfi
	fstpl	-8(%ebp)
	movl	$3, (%esp)
	call	__Z4funci
	leave
	ret
