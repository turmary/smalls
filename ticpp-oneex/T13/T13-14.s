	.file	"T13-14.cpp"
.globl _g
	.bss
	.align 4
_g:
	.space 12
	.def	___main;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "new Widget\12\0"
LC1:
	.ascii "T13-14.cpp\0"
LC2:
	.ascii "(): 39\0"
LC3:
	.ascii "\12delete Widget\12\0"
LC4:
	.ascii "\12new Widget[25]\12\0"
LC5:
	.ascii "(): 44\0"
LC6:
	.ascii "\12delete []Widget\12\0"
LC7:
	.ascii "########### %d ##########\12\0"
LC8:
	.ascii "hello world!\0"
	.text
	.align 2
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$236, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	movl	%eax, -220(%ebp)
	movl	-220(%ebp), %eax
	call	__alloca
	movl	$___gxx_personality_sj0, -116(%ebp)
	movl	$LLSDA1096, -112(%ebp)
	leal	-108(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L40, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	call	___main
	movl	$LC0, (%esp)
	movl	$-1, -136(%ebp)
	call	_printf
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-56(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC1, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$6, -136(%ebp)
	call	__ZNSsC1EPKcRKSaIcE
	jmp	L3
L2:
	movl	-152(%ebp), %eax
	movl	%eax, -148(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	-148(%ebp), %edx
	movl	%edx, -152(%ebp)
L4:
	movl	-152(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -136(%ebp)
	call	__Unwind_SjLj_Resume
L3:
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	leal	-56(%ebp), %edx
	movl	$LC2, 8(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	$5, -136(%ebp)
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_
	subl	$4, %esp
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	movl	$4, -136(%ebp)
	call	__ZN6WidgetnwEjSs
	movl	%eax, -156(%ebp)
	movl	-156(%ebp), %edx
	movl	%edx, (%esp)
	call	__ZN6WidgetC1Ev
	movl	-156(%ebp), %eax
	movl	%eax, -60(%ebp)
	jmp	L7
L6:
	movl	-152(%ebp), %edx
	movl	%edx, -160(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -136(%ebp)
	call	__ZNSsD1Ev
	movl	-160(%ebp), %eax
	movl	%eax, -152(%ebp)
L8:
	jmp	L36
L7:
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$5, -136(%ebp)
	call	__ZNSsD1Ev
	movl	$LC3, (%esp)
	call	_printf
	movl	-60(%ebp), %edx
	movl	%edx, -164(%ebp)
	cmpl	$0, -164(%ebp)
	je	L11
	movl	-164(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6WidgetD1Ev
	movl	-164(%ebp), %edx
	movl	%edx, (%esp)
	call	__ZN6WidgetdlEPv
L11:
	movl	$LC4, (%esp)
	movl	$5, -136(%ebp)
	call	_printf
	leal	-56(%ebp), %edx
	movl	$LC5, 8(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_
	subl	$4, %esp
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$29, (%esp)
	movl	$3, -136(%ebp)
	call	__ZN6WidgetnaEjSs
	addl	$4, %eax
	movl	%eax, -168(%ebp)
	movl	-168(%ebp), %eax
	movl	$25, -4(%eax)
	movl	-168(%ebp), %eax
	movl	%eax, -172(%ebp)
	movl	$24, -176(%ebp)
L12:
	cmpl	$-1, -176(%ebp)
	jne	L15
	jmp	L17
L15:
	movl	-172(%ebp), %edx
	movl	%edx, (%esp)
	call	__ZN6WidgetC1Ev
	incl	-172(%ebp)
	decl	-176(%ebp)
	jmp	L12
L16:
L17:
	movl	-168(%ebp), %eax
	movl	%eax, -64(%ebp)
	jmp	L19
L18:
	movl	-152(%ebp), %edx
	movl	%edx, -180(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -136(%ebp)
	call	__ZNSsD1Ev
	movl	-180(%ebp), %eax
	movl	%eax, -152(%ebp)
L20:
	jmp	L36
L19:
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$5, -136(%ebp)
	call	__ZNSsD1Ev
	movl	$LC6, (%esp)
	call	_printf
	movl	-64(%ebp), %eax
	subl	$4, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	cmpl	$0, -64(%ebp)
	je	L23
	movl	-64(%ebp), %edx
	subl	$4, %edx
	movl	-64(%ebp), %eax
	movl	(%edx), %edx
	addl	%eax, %edx
	movl	%edx, -184(%ebp)
L24:
	movl	-184(%ebp), %edx
	cmpl	%edx, -64(%ebp)
	je	L25
	decl	-184(%ebp)
	movl	-184(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6WidgetD1Ev
	jmp	L24
L25:
	movl	-64(%ebp), %eax
	subl	$4, %eax
	movl	%eax, (%esp)
	movl	$5, -136(%ebp)
	call	__ZN6WidgetdaEPv
L23:
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-88(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC8, 4(%esp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$2, -136(%ebp)
	call	__ZNSsC1EPKcRKSaIcE
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$1, (%esp)
	movl	$1, -136(%ebp)
	call	__ZN6WidgetnwEjSs
	movl	%eax, -192(%ebp)
	movl	-192(%ebp), %edx
	movl	%edx, (%esp)
	call	__ZN6WidgetC1Ev
	movl	-192(%ebp), %eax
	movl	%eax, -188(%ebp)
	cmpl	$0, -188(%ebp)
	je	L29
	movl	-188(%ebp), %edx
	movl	%edx, (%esp)
	call	__ZN6WidgetD1Ev
	movl	-188(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6WidgetdlEPv
	jmp	L29
L40:
	leal	24(%ebp), %ebp
	movl	-136(%ebp), %edx
	movl	%edx, -208(%ebp)
	movl	-132(%ebp), %eax
	movl	%eax, -152(%ebp)
	cmpl	$1, -208(%ebp)
	je	L32
	cmpl	$2, -208(%ebp)
	je	L18
	cmpl	$3, -208(%ebp)
	je	L6
	cmpl	$4, -208(%ebp)
	je	L36
	cmpl	$5, -208(%ebp)
	je	L2
L28:
	movl	-152(%ebp), %edx
	movl	%edx, -196(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -136(%ebp)
	call	__ZNSsD1Ev
	movl	-196(%ebp), %eax
	movl	%eax, -152(%ebp)
L30:
	jmp	L32
L29:
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$2, -136(%ebp)
	call	__ZNSsD1Ev
	jmp	L33
L32:
	movl	-152(%ebp), %edx
	movl	%edx, -200(%ebp)
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	-200(%ebp), %eax
	movl	%eax, -152(%ebp)
L34:
	jmp	L36
L33:
	leal	-88(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L37
L36:
	movl	-152(%ebp), %edx
	movl	%edx, -204(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -136(%ebp)
	call	__ZNSsD1Ev
	movl	-204(%ebp), %eax
	movl	%eax, -152(%ebp)
L38:
	movl	-152(%ebp), %edx
	movl	%edx, (%esp)
	movl	$-1, -136(%ebp)
	call	__Unwind_SjLj_Resume
L37:
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -136(%ebp)
	call	__ZNSsD1Ev
	movl	$0, -144(%ebp)
L1:
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	-144(%ebp), %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"dr"
LLSDA1096:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1096-LLSDACSB1096
LLSDACSB1096:
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 0x1
	.uleb128 0x0
	.uleb128 0x2
	.uleb128 0x0
	.uleb128 0x3
	.uleb128 0x0
	.uleb128 0x4
	.uleb128 0x0
	.uleb128 0x5
	.uleb128 0x0
LLSDACSE1096:
	.text
	.section .rdata,"dr"
LC9:
	.ascii "Widget::delete[]\12\0"
	.section	.text$_ZN6WidgetdaEPv,"x"
	.linkonce discard
	.align 2
.globl __ZN6WidgetdaEPv
	.def	__ZN6WidgetdaEPv;	.scl	2;	.type	32;	.endef
__ZN6WidgetdaEPv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$LC9, (%esp)
	call	_printf
	cmpl	$0, 8(%ebp)
	je	L41
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L41:
	leave
	ret
	.section .rdata,"dr"
LC10:
	.ascii "Widget::new[]: %d bytes\12\0"
	.section	.text$_ZN6WidgetnaEjSs,"x"
	.linkonce discard
	.align 2
.globl __ZN6WidgetnaEjSs
	.def	__ZN6WidgetnaEjSs;	.scl	2;	.type	32;	.endef
__ZN6WidgetnaEjSs:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZN6Widget1vE, (%esp)
	call	__ZNSt6vectorISsSaISsEE9push_backERKSs
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Znaj
	leave
	ret
	.section .rdata,"dr"
LC11:
	.ascii "Widget::delete\12\0"
	.section	.text$_ZN6WidgetdlEPv,"x"
	.linkonce discard
	.align 2
.globl __ZN6WidgetdlEPv
	.def	__ZN6WidgetdlEPv;	.scl	2;	.type	32;	.endef
__ZN6WidgetdlEPv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$LC11, (%esp)
	call	_printf
	cmpl	$0, 8(%ebp)
	je	L45
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdaPv
L45:
	leave
	ret
	.section	.text$_ZN6WidgetD1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZN6WidgetD1Ev
	.def	__ZN6WidgetD1Ev;	.scl	2;	.type	32;	.endef
__ZN6WidgetD1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$126, (%esp)
	call	_putchar
	leave
	ret
	.section	.text$putchar,"x"
	.linkonce discard
	.align 2
.globl _putchar
	.def	_putchar;	.scl	2;	.type	32;	.endef
_putchar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	__imp___iob, %eax
	addl	$32, %eax
	decl	4(%eax)
	cmpl	$0, 4(%eax)
	js	L52
	movl	__imp___iob, %edx
	addl	$32, %edx
	movl	(%edx), %eax
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movb	%al, (%ecx)
	movzbl	(%ecx), %eax
	movzbl	%al, %eax
	movl	%eax, -4(%ebp)
	incl	(%edx)
	jmp	L53
L52:
	movl	__imp___iob, %eax
	addl	$32, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__flsbuf
	movl	%eax, -4(%ebp)
L53:
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZN6WidgetC1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZN6WidgetC1Ev
	.def	__ZN6WidgetC1Ev;	.scl	2;	.type	32;	.endef
__ZN6WidgetC1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$42, (%esp)
	call	_putchar
	leave
	ret
	.section .rdata,"dr"
LC12:
	.ascii "Widget::new: %d bytes\12\0"
	.section	.text$_ZN6WidgetnwEjSs,"x"
	.linkonce discard
	.align 2
.globl __ZN6WidgetnwEjSs
	.def	__ZN6WidgetnwEjSs;	.scl	2;	.type	32;	.endef
__ZN6WidgetnwEjSs:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZN6Widget1vE, (%esp)
	call	__ZNSt6vectorISsSaISsEE9push_backERKSs
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__Znaj
	leave
	ret
	.section	.text$_ZNSt6vectorISsSaISsEE9push_backERKSs,"x"
	.linkonce discard
	.align 2
.globl __ZNSt6vectorISsSaISsEE9push_backERKSs
	.def	__ZNSt6vectorISsSaISsEE9push_backERKSs;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISsSaISsEE9push_backERKSs:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	8(%ebp), %edx
	movl	4(%eax), %eax
	cmpl	8(%edx), %eax
	je	L57
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	call	__ZSt10_ConstructISsSsEvPT_RKT0_
	movl	8(%ebp), %eax
	addl	$4, 4(%eax)
	jmp	L56
L57:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6vectorISsSaISsEE3endEv
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6vectorISsSaISsEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPSsS1_EERKSs
L56:
	leave
	ret
	.section	.text$_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_,"x"
	.linkonce discard
	.align 2
.globl __ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_
	.def	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_;	.scl	2;	.type	32;	.endef
__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	$___gxx_personality_sj0, -40(%ebp)
	movl	$LLSDA1127, -36(%ebp)
	leal	-32(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L64, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -60(%ebp)
	call	__ZNSsC1ERKSs
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	$1, -60(%ebp)
	call	__ZNSs6appendEPKc
	jmp	L59
L64:
	leal	12(%ebp), %ebp
	movl	-56(%ebp), %eax
	movl	%eax, -72(%ebp)
L60:
	movl	-72(%ebp), %edx
	movl	%edx, -68(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -60(%ebp)
	call	__ZNSsD1Ev
	movl	-68(%ebp), %edx
	movl	%edx, -72(%ebp)
L62:
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -60(%ebp)
	call	__Unwind_SjLj_Resume
L59:
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	8(%ebp), %eax
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret	$4
	.section	.gcc_except_table,"dr"
LLSDA1127:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1127-LLSDACSB1127
LLSDACSB1127:
	.uleb128 0x0
	.uleb128 0x0
LLSDACSE1127:
	.section	.text$_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_,"x"
	.linkonce discard
	.section	.text$_ZSt10_ConstructISsSsEvPT_RKT0_,"x"
	.linkonce discard
	.align 2
.globl __ZSt10_ConstructISsSsEvPT_RKT0_
	.def	__ZSt10_ConstructISsSsEvPT_RKT0_;	.scl	2;	.type	32;	.endef
__ZSt10_ConstructISsSsEvPT_RKT0_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	movl	$___gxx_personality_sj0, -40(%ebp)
	movl	$LLSDA1146, -36(%ebp)
	leal	-32(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L72, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$4, (%esp)
	call	__ZnwjPv
	movl	%eax, -68(%ebp)
	cmpl	$0, -68(%ebp)
	je	L65
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -60(%ebp)
	call	__ZNSsC1ERKSs
	jmp	L65
L72:
	leal	12(%ebp), %ebp
	movl	-56(%ebp), %edx
	movl	%edx, -76(%ebp)
L68:
	movl	-76(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-68(%ebp), %edx
	movl	%edx, (%esp)
	call	__ZdlPvS_
	movl	-72(%ebp), %eax
	movl	%eax, -76(%ebp)
L70:
	movl	-76(%ebp), %edx
	movl	%edx, (%esp)
	movl	$-1, -60(%ebp)
	call	__Unwind_SjLj_Resume
L65:
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"dr"
LLSDA1146:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1146-LLSDACSB1146
LLSDACSB1146:
	.uleb128 0x0
	.uleb128 0x0
LLSDACSE1146:
	.section	.text$_ZSt10_ConstructISsSsEvPT_RKT0_,"x"
	.linkonce discard
	.section	.text$_ZdlPvS_,"x"
	.linkonce discard
	.align 2
.globl __ZdlPvS_
	.def	__ZdlPvS_;	.scl	2;	.type	32;	.endef
__ZdlPvS_:
L74:
	pushl	%ebp
	movl	%esp, %ebp
	popl	%ebp
	ret
L73:
	.section	.text$_ZnwjPv,"x"
	.linkonce discard
	.align 2
.globl __ZnwjPv
	.def	__ZnwjPv;	.scl	2;	.type	32;	.endef
__ZnwjPv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
L77:
L76:
	popl	%ebp
	ret
	.section	.text$_ZNSt6vectorISsSaISsEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPSsS1_EERKSs,"x"
	.linkonce discard
	.align 2
.globl __ZNSt6vectorISsSaISsEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPSsS1_EERKSs
	.def	__ZNSt6vectorISsSaISsEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPSsS1_EERKSs;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISsSaISsEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPSsS1_EERKSs:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$188, %esp
	movl	$___gxx_personality_sj0, -128(%ebp)
	movl	$LLSDA1147, -124(%ebp)
	leal	-120(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L95, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	8(%ebp), %eax
	movl	8(%ebp), %edx
	movl	4(%eax), %eax
	cmpl	8(%edx), %eax
	je	L80
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	$4, %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, (%esp)
	movl	$-1, -148(%ebp)
	call	__ZSt10_ConstructISsSsEvPT_RKT0_
	movl	8(%ebp), %eax
	addl	$4, 4(%eax)
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsC1ERKSs
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	$4, %eax
	movl	%eax, -48(%ebp)
	leal	-48(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-44(%ebp), %eax
	movl	%eax, (%esp)
	movl	$3, -148(%ebp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	$8, %eax
	movl	%eax, -56(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-52(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_
	movl	-44(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-52(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt13copy_backwardIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEdeEv
	movl	%eax, %edx
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSsaSERKSs
	jmp	L82
L81:
	movl	-160(%ebp), %eax
	movl	%eax, -156(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -148(%ebp)
	call	__ZNSsD1Ev
	movl	-156(%ebp), %edx
	movl	%edx, -160(%ebp)
L83:
	movl	-160(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -148(%ebp)
	call	__Unwind_SjLj_Resume
L82:
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -148(%ebp)
	call	__ZNSsD1Ev
	jmp	L79
L80:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -148(%ebp)
	call	__ZNKSt6vectorISsSaISsEE4sizeEv
	movl	%eax, -60(%ebp)
	cmpl	$0, -60(%ebp)
	je	L86
	movl	-60(%ebp), %eax
	addl	%eax, %eax
	movl	%eax, -164(%ebp)
	jmp	L87
L86:
	movl	$1, -164(%ebp)
L87:
	movl	-164(%ebp), %edx
	movl	%edx, -64(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -148(%ebp)
	call	__ZNSt12_Vector_baseISsSaISsEE11_M_allocateEj
	movl	%eax, -72(%ebp)
	leal	-72(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_
	movl	-68(%ebp), %eax
	movl	%eax, -76(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-84(%ebp), %eax
	movl	%eax, (%esp)
	movl	$2, -148(%ebp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_
	movl	-68(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-84(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_
	movl	%eax, -80(%ebp)
	movl	-80(%ebp), %eax
	movl	%eax, -76(%ebp)
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv
	movl	16(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	__ZSt10_ConstructISsSsEvPT_RKT0_
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEppEv
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, 4(%esp)
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_
	movl	-76(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-92(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_
	movl	%eax, -88(%ebp)
	movl	-88(%ebp), %eax
	movl	%eax, -76(%ebp)
	jmp	L88
L94:
L89:
	movl	-160(%ebp), %eax
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-76(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-68(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -148(%ebp)
	call	__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv
	movl	%eax, %edx
	movl	-64(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	(%edx), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Vector_baseISsSaISsEE13_M_deallocateEPSsj
	call	___cxa_rethrow
L95:
	leal	24(%ebp), %ebp
	movl	-148(%ebp), %edx
	movl	%edx, -184(%ebp)
	movl	-144(%ebp), %eax
	movl	%eax, -160(%ebp)
	cmpl	$1, -184(%ebp)
	je	L94
	cmpl	$2, -184(%ebp)
	je	L81
L90:
	movl	-160(%ebp), %edx
	movl	%edx, -168(%ebp)
	movl	$0, -148(%ebp)
	call	___cxa_end_catch
	movl	-168(%ebp), %eax
	movl	%eax, -160(%ebp)
L92:
	movl	-160(%ebp), %edx
	movl	%edx, (%esp)
	movl	$-1, -148(%ebp)
	call	__Unwind_SjLj_Resume
L88:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -148(%ebp)
	call	__ZNSt6vectorISsSaISsEE3endEv
	movl	%eax, -96(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt6vectorISsSaISsEE5beginEv
	movl	%eax, -100(%ebp)
	movl	-96(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-100(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_
	movl	8(%ebp), %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ecx), %eax
	subl	%edx, %eax
	sarl	$2, %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Vector_baseISsSaISsEE13_M_deallocateEPSsj
	movl	8(%ebp), %eax
	movl	%eax, -172(%ebp)
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv
	movl	(%eax), %eax
	movl	-172(%ebp), %edx
	movl	%eax, (%edx)
	movl	8(%ebp), %eax
	movl	%eax, -176(%ebp)
	leal	-76(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv
	movl	(%eax), %eax
	movl	-176(%ebp), %edx
	movl	%eax, 4(%edx)
	movl	8(%ebp), %eax
	movl	%eax, -180(%ebp)
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv
	movl	%eax, %edx
	movl	-64(%ebp), %eax
	sall	$2, %eax
	addl	(%edx), %eax
	movl	-180(%ebp), %edx
	movl	%eax, 8(%edx)
L79:
	leal	-152(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	addl	$188, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"dr"
	.align 4
LLSDA1147:
	.byte	0xff
	.byte	0x0
	.uleb128 LLSDATT1147-LLSDATTD1147
LLSDATTD1147:
	.byte	0x1
	.uleb128 LLSDACSE1147-LLSDACSB1147
LLSDACSB1147:
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 0x1
	.uleb128 0x1
	.uleb128 0x2
	.uleb128 0x0
LLSDACSE1147:
	.byte	0x1
	.byte	0x0
	.align 4
	.long	0
LLSDATT1147:
	.section	.text$_ZNSt6vectorISsSaISsEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPSsS1_EERKSs,"x"
	.linkonce discard
	.section	.text$_ZNSt6vectorISsSaISsEE3endEv,"x"
	.linkonce discard
	.align 2
.globl __ZNSt6vectorISsSaISsEE3endEv
	.def	__ZNSt6vectorISsSaISsEE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISsSaISsEE3endEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, 4(%esp)
	leal	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZNSt12_Vector_baseISsSaISsEE13_M_deallocateEPSsj,"x"
	.linkonce discard
	.align 2
.globl __ZNSt12_Vector_baseISsSaISsEE13_M_deallocateEPSsj
	.def	__ZNSt12_Vector_baseISsSaISsEE13_M_deallocateEPSsj;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISsSaISsEE13_M_deallocateEPSsj:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$0, 12(%ebp)
	je	L97
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISsE10deallocateEPSsj
L97:
	leave
	ret
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_,"x"
	.linkonce discard
	.align 2
.globl __ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_
	.def	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, (%eax)
	popl	%ebp
	ret
	.section	.text$_ZSt13copy_backwardIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_,"x"
	.linkonce discard
	.align 2
.globl __ZSt13copy_backwardIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_
	.def	__ZSt13copy_backwardIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_;	.scl	2;	.type	32;	.endef
__ZSt13copy_backwardIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movb	$0, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt37__copy_backward_input_normal_iteratorIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_11__true_type
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEdeEv,"x"
	.linkonce discard
	.align 2
.globl __ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEdeEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEdeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEdeEv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	popl	%ebp
	ret
	.section	.text$_ZNKSt6vectorISsSaISsEE4sizeEv,"x"
	.linkonce discard
	.align 2
.globl __ZNKSt6vectorISsSaISsEE4sizeEv
	.def	__ZNKSt6vectorISsSaISsEE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorISsSaISsEE4sizeEv:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6vectorISsSaISsEE5beginEv
	movl	%eax, -8(%ebp)
	leal	-8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSt6vectorISsSaISsEE3endEv
	movl	%eax, -12(%ebp)
	leal	-12(%ebp), %eax
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxmiIPKSsS2_St6vectorISsSaISsEEEENS_17__normal_iteratorIT_T1_E15difference_typeERKS9_RKNS6_IT0_S8_EE
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.section	.text$_ZNSt12_Vector_baseISsSaISsEE11_M_allocateEj,"x"
	.linkonce discard
	.align 2
.globl __ZNSt12_Vector_baseISsSaISsEE11_M_allocateEj
	.def	__ZNSt12_Vector_baseISsSaISsEE11_M_allocateEj;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISsSaISsEE11_M_allocateEj:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$0, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISsE8allocateEjPKv
	leave
	ret
	.section	.text$_ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_,"x"
	.linkonce discard
	.align 2
.globl __ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_
	.def	__ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_;	.scl	2;	.type	32;	.endef
__ZSt18uninitialized_copyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movb	$0, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_12__false_type
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv,"x"
	.linkonce discard
	.align 2
.globl __ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEppEv,"x"
	.linkonce discard
	.align 2
.globl __ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEppEv
	.def	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEppEv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEppEv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	addl	$4, (%eax)
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.section	.text$_ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_,"x"
	.linkonce discard
	.align 2
.globl __ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_
	.def	__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movb	$0, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt13__destroy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_12__false_type
	leave
	ret
	.section	.text$_ZNSt6vectorISsSaISsEE5beginEv,"x"
	.linkonce discard
	.align 2
.globl __ZNSt6vectorISsSaISsEE5beginEv
	.def	__ZNSt6vectorISsSaISsEE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISsSaISsEE5beginEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZN9__gnu_cxx13new_allocatorISsE10deallocateEPSsj,"x"
	.linkonce discard
	.align 2
.globl __ZN9__gnu_cxx13new_allocatorISsE10deallocateEPSsj
	.def	__ZN9__gnu_cxx13new_allocatorISsE10deallocateEPSsj;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISsE10deallocateEPSsj:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	leave
	ret
	.section	.text$_ZSt37__copy_backward_input_normal_iteratorIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_11__true_type,"x"
	.linkonce discard
	.align 2
.globl __ZSt37__copy_backward_input_normal_iteratorIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_11__true_type
	.def	__ZSt37__copy_backward_input_normal_iteratorIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_11__true_type;	.scl	2;	.type	32;	.endef
__ZSt37__copy_backward_input_normal_iteratorIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_11__true_type:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$36, %esp
	leal	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv
	movl	%eax, %ebx
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv
	movl	%eax, %edx
	movb	$0, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	(%ebx), %eax
	movl	%eax, 4(%esp)
	movl	(%edx), %eax
	movl	%eax, (%esp)
	call	__ZSt38__copy_backward_output_normal_iteratorIPSsN9__gnu_cxx17__normal_iteratorIS0_St6vectorISsSaISsEEEEET0_T_S8_S7_11__true_type
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	addl	$36, %esp
	popl	%ebx
	popl	%ebp
	ret
	.section	.text$_ZNKSt6vectorISsSaISsEE5beginEv,"x"
	.linkonce discard
	.align 2
.globl __ZNKSt6vectorISsSaISsEE5beginEv
	.def	__ZNKSt6vectorISsSaISsEE5beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorISsSaISsEE5beginEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	leal	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEC1ERKS2_
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZNKSt6vectorISsSaISsEE3endEv,"x"
	.linkonce discard
	.align 2
.globl __ZNKSt6vectorISsSaISsEE3endEv
	.def	__ZNKSt6vectorISsSaISsEE3endEv;	.scl	2;	.type	32;	.endef
__ZNKSt6vectorISsSaISsEE3endEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -8(%ebp)
	leal	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEC1ERKS2_
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZN9__gnu_cxxmiIPKSsS2_St6vectorISsSaISsEEEENS_17__normal_iteratorIT_T1_E15difference_typeERKS9_RKNS6_IT0_S8_EE,"x"
	.linkonce discard
	.align 2
.globl __ZN9__gnu_cxxmiIPKSsS2_St6vectorISsSaISsEEEENS_17__normal_iteratorIT_T1_E15difference_typeERKS9_RKNS6_IT0_S8_EE
	.def	__ZN9__gnu_cxxmiIPKSsS2_St6vectorISsSaISsEEEENS_17__normal_iteratorIT_T1_E15difference_typeERKS9_RKNS6_IT0_S8_EE;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxmiIPKSsS2_St6vectorISsSaISsEEEENS_17__normal_iteratorIT_T1_E15difference_typeERKS9_RKNS6_IT0_S8_EE:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEE4baseEv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEE4baseEv
	movl	(%eax), %edx
	movl	(%ebx), %eax
	subl	%edx, %eax
	sarl	$2, %eax
	addl	$4, %esp
	popl	%ebx
	popl	%ebp
	ret
	.section	.text$_ZN9__gnu_cxx13new_allocatorISsE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
.globl __ZN9__gnu_cxx13new_allocatorISsE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorISsE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISsE8allocateEjPKv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	12(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	ret
	.section	.text$_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_12__false_type,"x"
	.linkonce discard
	.align 2
.globl __ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_12__false_type
	.def	__ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_12__false_type;	.scl	2;	.type	32;	.endef
__ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_12__false_type:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	movl	$___gxx_personality_sj0, -44(%ebp)
	movl	$LLSDA1187, -40(%ebp)
	leal	-36(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L126, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
L116:
	leal	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$2, -64(%ebp)
	call	__ZN9__gnu_cxxneIPSsSt6vectorISsSaISsEEEEbRKNS_17__normal_iteratorIT_T0_EESA_
	testb	%al, %al
	je	L117
	leal	8(%ebp), %edx
	movl	%edx, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEdeEv
	movl	%eax, -76(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEdeEv
	movl	-76(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt10_ConstructISsSsEvPT_RKT0_
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEppEv
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEppEv
	jmp	L116
L117:
	movl	-16(%ebp), %eax
	movl	%eax, -72(%ebp)
	jmp	L115
L125:
L120:
	movl	-80(%ebp), %edx
	movl	%edx, (%esp)
	call	___cxa_begin_catch
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -64(%ebp)
	call	__ZSt8_DestroyIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_
	call	___cxa_rethrow
L126:
	leal	12(%ebp), %ebp
	movl	-64(%ebp), %eax
	movl	-60(%ebp), %edx
	movl	%edx, -80(%ebp)
	cmpl	$1, %eax
	je	L125
L121:
	movl	-80(%ebp), %eax
	movl	%eax, -84(%ebp)
	movl	$0, -64(%ebp)
	call	___cxa_end_catch
	movl	-84(%ebp), %edx
	movl	%edx, -80(%ebp)
L123:
	movl	-80(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -64(%ebp)
	call	__Unwind_SjLj_Resume
L115:
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	-72(%ebp), %eax
	addl	$92, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"dr"
	.align 4
LLSDA1187:
	.byte	0xff
	.byte	0x0
	.uleb128 LLSDATT1187-LLSDATTD1187
LLSDATTD1187:
	.byte	0x1
	.uleb128 LLSDACSE1187-LLSDACSB1187
LLSDACSB1187:
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 0x1
	.uleb128 0x1
LLSDACSE1187:
	.byte	0x1
	.byte	0x0
	.align 4
	.long	0
LLSDATT1187:
	.section	.text$_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEES6_ET0_T_S8_S7_12__false_type,"x"
	.linkonce discard
	.section	.text$_ZSt13__destroy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_12__false_type,"x"
	.linkonce discard
	.align 2
.globl __ZSt13__destroy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_12__false_type
	.def	__ZSt13__destroy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_12__false_type;	.scl	2;	.type	32;	.endef
__ZSt13__destroy_auxIN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEEEvT_S7_12__false_type:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
L128:
	leal	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxxneIPSsSt6vectorISsSaISsEEEEbRKNS_17__normal_iteratorIT_T0_EESA_
	testb	%al, %al
	je	L127
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEdeEv
	movl	%eax, (%esp)
	call	__ZSt8_DestroyISsEvPT_
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEppEv
	jmp	L128
L127:
	leave
	ret
	.section	.text$_ZSt38__copy_backward_output_normal_iteratorIPSsN9__gnu_cxx17__normal_iteratorIS0_St6vectorISsSaISsEEEEET0_T_S8_S7_11__true_type,"x"
	.linkonce discard
	.align 2
.globl __ZSt38__copy_backward_output_normal_iteratorIPSsN9__gnu_cxx17__normal_iteratorIS0_St6vectorISsSaISsEEEEET0_T_S8_S7_11__true_type
	.def	__ZSt38__copy_backward_output_normal_iteratorIPSsN9__gnu_cxx17__normal_iteratorIS0_St6vectorISsSaISsEEEEET0_T_S8_S7_11__true_type;	.scl	2;	.type	32;	.endef
__ZSt38__copy_backward_output_normal_iteratorIPSsN9__gnu_cxx17__normal_iteratorIS0_St6vectorISsSaISsEEEEET0_T_S8_S7_11__true_type:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	leal	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv
	movl	(%eax), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt19__copy_backward_auxIPSsS0_ET0_T_S2_S1_
	movl	%eax, -8(%ebp)
	leal	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEEC1ERKS1_
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEC1ERKS2_,"x"
	.linkonce discard
	.align 2
.globl __ZN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEC1ERKS2_
	.def	__ZN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEC1ERKS2_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEEC1ERKS2_:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, (%eax)
	popl	%ebp
	ret
	.section	.text$_ZNK9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEE4baseEv,"x"
	.linkonce discard
	.align 2
.globl __ZNK9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEE4baseEv
	.def	__ZNK9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEE4baseEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx17__normal_iteratorIPKSsSt6vectorISsSaISsEEE4baseEv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.section	.text$_ZN9__gnu_cxxneIPSsSt6vectorISsSaISsEEEEbRKNS_17__normal_iteratorIT_T0_EESA_,"x"
	.linkonce discard
	.align 2
.globl __ZN9__gnu_cxxneIPSsSt6vectorISsSaISsEEEEbRKNS_17__normal_iteratorIT_T0_EESA_
	.def	__ZN9__gnu_cxxneIPSsSt6vectorISsSaISsEEEEbRKNS_17__normal_iteratorIT_T0_EESA_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxxneIPSsSt6vectorISsSaISsEEEEbRKNS_17__normal_iteratorIT_T0_EESA_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv
	movl	%eax, %ebx
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNK9__gnu_cxx17__normal_iteratorIPSsSt6vectorISsSaISsEEE4baseEv
	movl	%eax, %edx
	movl	(%ebx), %eax
	cmpl	(%edx), %eax
	setne	%al
	movzbl	%al, %eax
	addl	$4, %esp
	popl	%ebx
	popl	%ebp
	ret
	.section	.text$_ZSt8_DestroyISsEvPT_,"x"
	.linkonce discard
	.align 2
.globl __ZSt8_DestroyISsEvPT_
	.def	__ZSt8_DestroyISsEvPT_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyISsEvPT_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsD1Ev
	leave
	ret
	.section	.text$_ZSt19__copy_backward_auxIPSsS0_ET0_T_S2_S1_,"x"
	.linkonce discard
	.align 2
.globl __ZSt19__copy_backward_auxIPSsS0_ET0_T_S2_S1_
	.def	__ZSt19__copy_backward_auxIPSsS0_ET0_T_S2_S1_;	.scl	2;	.type	32;	.endef
__ZSt19__copy_backward_auxIPSsS0_ET0_T_S2_S1_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt24__copy_backward_dispatchIPSsS0_12__false_typeE4copyES0_S0_S0_
	leave
	ret
	.section	.text$_ZNSt24__copy_backward_dispatchIPSsS0_12__false_typeE4copyES0_S0_S0_,"x"
	.linkonce discard
	.align 2
.globl __ZNSt24__copy_backward_dispatchIPSsS0_12__false_typeE4copyES0_S0_S0_
	.def	__ZNSt24__copy_backward_dispatchIPSsS0_12__false_typeE4copyES0_S0_S0_;	.scl	2;	.type	32;	.endef
__ZNSt24__copy_backward_dispatchIPSsS0_12__false_typeE4copyES0_S0_S0_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt19__iterator_categoryIPSsENSt15iterator_traitsIT_E17iterator_categoryERKS2_
	movb	%al, -1(%ebp)
	movb	$0, 12(%esp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt15__copy_backwardIPSsS0_ET0_T_S2_S1_St26random_access_iterator_tag
	leave
	ret
	.section	.text$_ZSt19__iterator_categoryIPSsENSt15iterator_traitsIT_E17iterator_categoryERKS2_,"x"
	.linkonce discard
	.align 2
.globl __ZSt19__iterator_categoryIPSsENSt15iterator_traitsIT_E17iterator_categoryERKS2_
	.def	__ZSt19__iterator_categoryIPSsENSt15iterator_traitsIT_E17iterator_categoryERKS2_;	.scl	2;	.type	32;	.endef
__ZSt19__iterator_categoryIPSsENSt15iterator_traitsIT_E17iterator_categoryERKS2_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movzbl	-1(%ebp), %eax
	leave
	ret
	.section	.text$_ZSt15__copy_backwardIPSsS0_ET0_T_S2_S1_St26random_access_iterator_tag,"x"
	.linkonce discard
	.align 2
.globl __ZSt15__copy_backwardIPSsS0_ET0_T_S2_S1_St26random_access_iterator_tag
	.def	__ZSt15__copy_backwardIPSsS0_ET0_T_S2_S1_St26random_access_iterator_tag;	.scl	2;	.type	32;	.endef
__ZSt15__copy_backwardIPSsS0_ET0_T_S2_S1_St26random_access_iterator_tag:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	subl	%edx, %eax
	sarl	$2, %eax
	movl	%eax, -4(%ebp)
L140:
	cmpl	$0, -4(%ebp)
	jle	L141
	leal	12(%ebp), %eax
	subl	$4, (%eax)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	16(%ebp), %eax
	subl	$4, (%eax)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSsaSERKSs
	leal	-4(%ebp), %eax
	decl	(%eax)
	jmp	L140
L141:
	movl	16(%ebp), %eax
	leave
	ret
	.text
	.align 2
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	movl	$___gxx_personality_sj0, -68(%ebp)
	movl	$LLSDA1200, -64(%ebp)
	leal	-60(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L150, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	cmpl	$65535, 12(%ebp)
	jne	L144
	cmpl	$1, 8(%ebp)
	jne	L144
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISsEC1Ev
	leal	-40(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$_g, (%esp)
	movl	$1, -88(%ebp)
	call	__ZNSt6vectorISsSaISsEEC1ERKS0_
	jmp	L146
L150:
	leal	24(%ebp), %ebp
	movl	-84(%ebp), %eax
	movl	%eax, -100(%ebp)
L145:
	movl	-100(%ebp), %edx
	movl	%edx, -96(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISsED1Ev
	movl	-96(%ebp), %eax
	movl	%eax, -100(%ebp)
L147:
	movl	-100(%ebp), %edx
	movl	%edx, (%esp)
	movl	$-1, -88(%ebp)
	call	__Unwind_SjLj_Resume
L146:
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISsED1Ev
L144:
	cmpl	$65535, 12(%ebp)
	jne	L143
	cmpl	$0, 8(%ebp)
	jne	L143
	movl	$_g, (%esp)
	movl	$-1, -88(%ebp)
	call	__ZNSt6vectorISsSaISsEED1Ev
L143:
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	addl	$108, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"dr"
LLSDA1200:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1200-LLSDACSB1200
LLSDACSB1200:
	.uleb128 0x0
	.uleb128 0x0
LLSDACSE1200:
	.text
	.section	.text$_ZNSaISsED1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZNSaISsED1Ev
	.def	__ZNSaISsED1Ev;	.scl	2;	.type	32;	.endef
__ZNSaISsED1Ev:
L153:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISsED2Ev
	leave
	ret
L156:
L151:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISsED2Ev,"x"
	.linkonce discard
	.align 2
.globl __ZN9__gnu_cxx13new_allocatorISsED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISsED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISsED2Ev:
L161:
	pushl	%ebp
	movl	%esp, %ebp
	popl	%ebp
	ret
L158:
	.section	.text$_ZNSt6vectorISsSaISsEEC1ERKS0_,"x"
	.linkonce discard
	.align 2
.globl __ZNSt6vectorISsSaISsEEC1ERKS0_
	.def	__ZNSt6vectorISsSaISsEEC1ERKS0_;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISsSaISsEEC1ERKS0_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Vector_baseISsSaISsEEC2ERKS0_
	leave
	ret
L164:
L163:
	.section	.text$_ZNSt12_Vector_baseISsSaISsEEC2ERKS0_,"x"
	.linkonce discard
	.align 2
.globl __ZNSt12_Vector_baseISsSaISsEEC2ERKS0_
	.def	__ZNSt12_Vector_baseISsSaISsEEC2ERKS0_;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISsSaISsEEC2ERKS0_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Vector_baseISsSaISsEE12_Vector_implC1ERKS0_
	leave
	ret
L167:
L166:
	.section	.text$_ZNSt12_Vector_baseISsSaISsEE12_Vector_implC1ERKS0_,"x"
	.linkonce discard
	.align 2
.globl __ZNSt12_Vector_baseISsSaISsEE12_Vector_implC1ERKS0_
	.def	__ZNSt12_Vector_baseISsSaISsEE12_Vector_implC1ERKS0_;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISsSaISsEE12_Vector_implC1ERKS0_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISsEC2ERKS_
	movl	8(%ebp), %eax
	movl	$0, (%eax)
	movl	8(%ebp), %eax
	movl	$0, 4(%eax)
	movl	8(%ebp), %eax
	movl	$0, 8(%eax)
	leave
	ret
L170:
L169:
	.section	.text$_ZNSaISsEC2ERKS_,"x"
	.linkonce discard
	.align 2
.globl __ZNSaISsEC2ERKS_
	.def	__ZNSaISsEC2ERKS_;	.scl	2;	.type	32;	.endef
__ZNSaISsEC2ERKS_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISsEC2ERKS1_
	leave
	ret
L173:
L175:
L172:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISsEC2ERKS1_,"x"
	.linkonce discard
	.align 2
.globl __ZN9__gnu_cxx13new_allocatorISsEC2ERKS1_
	.def	__ZN9__gnu_cxx13new_allocatorISsEC2ERKS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISsEC2ERKS1_:
L178:
	pushl	%ebp
	movl	%esp, %ebp
	popl	%ebp
	ret
L177:
	.section	.text$_ZNSaISsEC1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZNSaISsEC1Ev
	.def	__ZNSaISsEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSaISsEC1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISsEC2Ev
	leave
	ret
L181:
L183:
L180:
	.section	.text$_ZN9__gnu_cxx13new_allocatorISsEC2Ev,"x"
	.linkonce discard
	.align 2
.globl __ZN9__gnu_cxx13new_allocatorISsEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorISsEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorISsEC2Ev:
L186:
	pushl	%ebp
	movl	%esp, %ebp
	popl	%ebp
	ret
L185:
	.section	.text$_ZNSt6vectorISsSaISsEED1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZNSt6vectorISsSaISsEED1Ev
	.def	__ZNSt6vectorISsSaISsEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt6vectorISsSaISsEED1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	$___gxx_personality_sj0, -40(%ebp)
	movl	$LLSDA1203, -36(%ebp)
	leal	-32(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L195, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	movl	$1, -60(%ebp)
	call	__ZSt8_DestroyIPSsEvT_S1_
	jmp	L191
L195:
	leal	12(%ebp), %ebp
	movl	-56(%ebp), %eax
	movl	%eax, -72(%ebp)
L190:
	movl	-72(%ebp), %edx
	movl	%edx, -68(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -60(%ebp)
	call	__ZNSt12_Vector_baseISsSaISsEED2Ev
	movl	-68(%ebp), %eax
	movl	%eax, -72(%ebp)
L192:
	movl	-72(%ebp), %edx
	movl	%edx, (%esp)
	movl	$-1, -60(%ebp)
	call	__Unwind_SjLj_Resume
L191:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -60(%ebp)
	call	__ZNSt12_Vector_baseISsSaISsEED2Ev
L188:
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"dr"
LLSDA1203:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1203-LLSDACSB1203
LLSDACSB1203:
	.uleb128 0x0
	.uleb128 0x0
LLSDACSE1203:
	.section	.text$_ZNSt6vectorISsSaISsEED1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt12_Vector_baseISsSaISsEED2Ev,"x"
	.linkonce discard
	.align 2
.globl __ZNSt12_Vector_baseISsSaISsEED2Ev
	.def	__ZNSt12_Vector_baseISsSaISsEED2Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISsSaISsEED2Ev:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$76, %esp
	movl	$___gxx_personality_sj0, -40(%ebp)
	movl	$LLSDA1144, -36(%ebp)
	leal	-32(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L203, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	8(%ebp), %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ecx), %eax
	subl	%edx, %eax
	sarl	$2, %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -60(%ebp)
	call	__ZNSt12_Vector_baseISsSaISsEE13_M_deallocateEPSsj
	jmp	L199
L203:
	leal	12(%ebp), %ebp
	movl	-56(%ebp), %eax
	movl	%eax, -72(%ebp)
L198:
	movl	-72(%ebp), %edx
	movl	%edx, -68(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Vector_baseISsSaISsEE12_Vector_implD1Ev
	movl	-68(%ebp), %eax
	movl	%eax, -72(%ebp)
L200:
	movl	-72(%ebp), %edx
	movl	%edx, (%esp)
	movl	$-1, -60(%ebp)
	call	__Unwind_SjLj_Resume
L199:
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt12_Vector_baseISsSaISsEE12_Vector_implD1Ev
L196:
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	addl	$76, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"dr"
LLSDA1144:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1144-LLSDACSB1144
LLSDACSB1144:
	.uleb128 0x0
	.uleb128 0x0
LLSDACSE1144:
	.section	.text$_ZNSt12_Vector_baseISsSaISsEED2Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt12_Vector_baseISsSaISsEE12_Vector_implD1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZNSt12_Vector_baseISsSaISsEE12_Vector_implD1Ev
	.def	__ZNSt12_Vector_baseISsSaISsEE12_Vector_implD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt12_Vector_baseISsSaISsEE12_Vector_implD1Ev:
L206:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaISsED2Ev
	leave
	ret
L209:
L204:
	.section	.text$_ZNSaISsED2Ev,"x"
	.linkonce discard
	.align 2
.globl __ZNSaISsED2Ev
	.def	__ZNSaISsED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaISsED2Ev:
L213:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx13new_allocatorISsED2Ev
	leave
	ret
L216:
L211:
	.section	.text$_ZSt8_DestroyIPSsEvT_S1_,"x"
	.linkonce discard
	.align 2
.globl __ZSt8_DestroyIPSsEvT_S1_
	.def	__ZSt8_DestroyIPSsEvT_S1_;	.scl	2;	.type	32;	.endef
__ZSt8_DestroyIPSsEvT_S1_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movb	$0, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt13__destroy_auxIPSsEvT_S1_12__false_type
	leave
	ret
	.section	.text$_ZSt13__destroy_auxIPSsEvT_S1_12__false_type,"x"
	.linkonce discard
	.align 2
.globl __ZSt13__destroy_auxIPSsEvT_S1_12__false_type
	.def	__ZSt13__destroy_auxIPSsEvT_S1_12__false_type;	.scl	2;	.type	32;	.endef
__ZSt13__destroy_auxIPSsEvT_S1_12__false_type:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
L220:
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	je	L219
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt8_DestroyISsEvPT_
	addl	$4, 8(%ebp)
	jmp	L220
L219:
	leave
	ret
	.text
	.align 2
	.def	__GLOBAL__I_g;	.scl	3;	.type	32;	.endef
__GLOBAL__I_g:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__I_g
	.text
	.align 2
	.def	__GLOBAL__D_g;	.scl	3;	.type	32;	.endef
__GLOBAL__D_g:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$65535, 4(%esp)
	movl	$0, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__D_g
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	___cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	___cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	__ZNSsaSERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSs6appendEPKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1ERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZdaPv;	.scl	2;	.type	32;	.endef
	.def	__Znaj;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	__flsbuf;	.scl	2;	.type	32;	.endef
