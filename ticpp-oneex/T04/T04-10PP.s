	.file	"T04-10.cpp"
	.text
	.align 2
	.def	__ZSt17__verify_groupingPKcjRKSs;	.scl	3;	.type	32;	.endef
__ZSt17__verify_groupingPKcjRKSs:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSs4sizeEv
	decl	%eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	decl	%eax
	movl	%eax, -12(%ebp)
	leal	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3minIjERKT_S2_S2_
	movl	(%eax), %eax
	movl	%eax, -8(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, -16(%ebp)
	movb	$1, -17(%ebp)
	movl	$0, -24(%ebp)
L2:
	movl	-24(%ebp), %eax
	cmpl	-8(%ebp), %eax
	jae	L5
	cmpb	$0, -17(%ebp)
	je	L5
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSsixEj
	movsbl	(%eax),%edx
	movl	8(%ebp), %eax
	addl	-24(%ebp), %eax
	movsbl	(%eax),%eax
	cmpl	%eax, %edx
	sete	%al
	movb	%al, -17(%ebp)
	leal	-16(%ebp), %eax
	decl	(%eax)
	leal	-24(%ebp), %eax
	incl	(%eax)
	jmp	L2
L5:
	cmpl	$0, -16(%ebp)
	je	L6
	cmpb	$0, -17(%ebp)
	je	L6
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSsixEj
	movsbl	(%eax),%edx
	movl	8(%ebp), %eax
	addl	-8(%ebp), %eax
	movsbl	(%eax),%eax
	cmpl	%eax, %edx
	sete	%al
	movb	%al, -17(%ebp)
	leal	-16(%ebp), %eax
	decl	(%eax)
	jmp	L5
L6:
	movl	$0, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNKSsixEj
	movsbl	(%eax),%edx
	movl	8(%ebp), %eax
	addl	-8(%ebp), %eax
	movsbl	(%eax),%eax
	cmpl	%eax, %edx
	jg	L8
	movzbl	-17(%ebp), %eax
	andl	$1, %eax
	movb	%al, -25(%ebp)
	jmp	L9
L8:
	movb	$0, -25(%ebp)
L9:
	movzbl	-25(%ebp), %eax
	movb	%al, -17(%ebp)
	movzbl	-17(%ebp), %eax
	leave
	ret
.lcomm __ZSt8__ioinit,16
	.align 2
.globl __Z3_A_i
	.def	__Z3_A_i;	.scl	2;	.type	32;	.endef
__Z3_A_i:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$0, %eax
	popl	%ebp
	ret
	.align 2
.globl __Z3_B_f
	.def	__Z3_B_f;	.scl	2;	.type	32;	.endef
__Z3_B_f:
	pushl	%ebp
	movl	%esp, %ebp
	fldz
	popl	%ebp
	ret
	.align 2
.globl __Z3_C_c
	.def	__Z3_C_c;	.scl	2;	.type	32;	.endef
__Z3_C_c:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	8(%ebp), %eax
	movb	%al, -1(%ebp)
	movl	$48, %eax
	leave
	ret
	.align 2
.globl __Z3_D_iPc
	.def	__Z3_D_iPc;	.scl	2;	.type	32;	.endef
__Z3_D_iPc:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.section .rdata,"dr"
_ZZN7OnlyOne10onlyMemberEvE12__FUNCTION__:
	.ascii "onlyMember\0"
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
LC2:
	.ascii "onlyMember\0"
LC3:
	.ascii "()\0"
	.text
	.align 2
.globl __ZN7OnlyOne10onlyMemberEv
	.def	__ZN7OnlyOne10onlyMemberEv;	.scl	2;	.type	32;	.endef
__ZN7OnlyOne10onlyMemberEv:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$124, %esp
	movl	$___gxx_personality_sj0, -84(%ebp)
	movl	$LLSDA1416, -80(%ebp)
	leal	-76(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L23, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcEC1Ev
	leal	-56(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$LC2, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$2, -104(%ebp)
	call	__ZNSsC1EPKcRKSaIcE
	leal	-40(%ebp), %eax
	movl	$LC3, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -104(%ebp)
	call	__ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_
	subl	$4, %esp
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$2, -104(%ebp)
	call	__ZNSsD1Ev
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	jmp	L14
L23:
	leal	24(%ebp), %ebp
	movl	-104(%ebp), %eax
	movl	-100(%ebp), %edx
	movl	%edx, -116(%ebp)
	cmpl	$1, %eax
	je	L19
L15:
	movl	-116(%ebp), %eax
	movl	%eax, -112(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -104(%ebp)
	call	__ZNSsD1Ev
	movl	-112(%ebp), %edx
	movl	%edx, -116(%ebp)
L17:
L19:
	movl	-116(%ebp), %eax
	movl	%eax, -120(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSaIcED1Ev
	movl	-120(%ebp), %edx
	movl	%edx, -116(%ebp)
L21:
	movl	-116(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -104(%ebp)
	call	__Unwind_SjLj_Resume
L14:
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	8(%ebp), %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret	$4
	.section	.gcc_except_table,"dr"
LLSDA1416:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1416-LLSDACSB1416
LLSDACSB1416:
	.uleb128 0x0
	.uleb128 0x0
	.uleb128 0x1
	.uleb128 0x0
LLSDACSE1416:
	.text
	.align 2
.globl __Z3_E_P7OnlyOne
	.def	__Z3_E_P7OnlyOne;	.scl	2;	.type	32;	.endef
__Z3_E_P7OnlyOne:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$0, %eax
	popl	%ebp
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC5:
	.ascii "hello\0"
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
	subl	$140, %esp
	andl	$-16, %esp
	movl	$0, %eax
	addl	$15, %eax
	addl	$15, %eax
	shrl	$4, %eax
	sall	$4, %eax
	movl	%eax, -124(%ebp)
	movl	-124(%ebp), %eax
	call	__alloca
	movl	$___gxx_personality_sj0, -84(%ebp)
	movl	$LLSDA1418, -80(%ebp)
	leal	-76(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L30, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	call	___main
	movl	$0, (%esp)
	call	__Z3_A_i
	movl	$0x00000000, %eax
	movl	%eax, (%esp)
	call	__Z3_B_f
	fstp	%st(0)
	movl	$48, (%esp)
	call	__Z3_C_c
	movl	$LC5, 4(%esp)
	movl	$1, (%esp)
	call	__Z3_D_iPc
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z3_E_P7OnlyOne
	leal	-56(%ebp), %edx
	leal	-25(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	movl	$-1, -104(%ebp)
	call	__ZN7OnlyOne10onlyMemberEv
	subl	$4, %esp
	leal	-56(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$1, -104(%ebp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	jmp	L27
L30:
	leal	24(%ebp), %ebp
	movl	-100(%ebp), %eax
	movl	%eax, -120(%ebp)
L26:
	movl	-120(%ebp), %edx
	movl	%edx, -116(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -104(%ebp)
	call	__ZNSsD1Ev
	movl	-116(%ebp), %eax
	movl	%eax, -120(%ebp)
L28:
	movl	-120(%ebp), %edx
	movl	%edx, (%esp)
	movl	$-1, -104(%ebp)
	call	__Unwind_SjLj_Resume
L27:
	leal	-56(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -104(%ebp)
	call	__ZNSsD1Ev
	movl	$0, -112(%ebp)
L25:
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	-112(%ebp), %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"dr"
LLSDA1418:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1418-LLSDACSB1418
LLSDACSB1418:
	.uleb128 0x0
	.uleb128 0x0
LLSDACSE1418:
	.text
	.section	.text$_ZSt3minIjERKT_S2_S2_,"x"
	.linkonce discard
	.align 2
.globl __ZSt3minIjERKT_S2_S2_
	.def	__ZSt3minIjERKT_S2_S2_;	.scl	2;	.type	32;	.endef
__ZSt3minIjERKT_S2_S2_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	(%eax), %eax
	cmpl	(%edx), %eax
	jae	L32
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	L31
L32:
	movl	8(%ebp), %eax
	movl	%eax, -4(%ebp)
L31:
	movl	-4(%ebp), %eax
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
	movl	$LLSDA1438, -36(%ebp)
	leal	-32(%ebp), %eax
	leal	-12(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L38, %edx
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
	jmp	L33
L38:
	leal	12(%ebp), %ebp
	movl	-56(%ebp), %eax
	movl	%eax, -72(%ebp)
L34:
	movl	-72(%ebp), %edx
	movl	%edx, -68(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -60(%ebp)
	call	__ZNSsD1Ev
	movl	-68(%ebp), %edx
	movl	%edx, -72(%ebp)
L36:
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -60(%ebp)
	call	__Unwind_SjLj_Resume
L33:
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
LLSDA1438:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1438-LLSDACSB1438
LLSDACSB1438:
	.uleb128 0x0
	.uleb128 0x0
LLSDACSE1438:
	.section	.text$_ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_PKS3_,"x"
	.linkonce discard
	.text
	.align 2
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	cmpl	$65535, 12(%ebp)
	jne	L40
	cmpl	$1, 8(%ebp)
	jne	L40
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
L40:
	cmpl	$65535, 12(%ebp)
	jne	L39
	cmpl	$0, 8(%ebp)
	jne	L39
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
L39:
	leave
	ret
	.align 2
	.def	__GLOBAL__I__Z3_A_i;	.scl	3;	.type	32;	.endef
__GLOBAL__I__Z3_A_i:
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
	.long	__GLOBAL__I__Z3_A_i
	.text
	.align 2
	.def	__GLOBAL__D__Z3_A_i;	.scl	3;	.type	32;	.endef
__GLOBAL__D__Z3_A_i:
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
	.long	__GLOBAL__D__Z3_A_i
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSs6appendEPKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1ERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNKSsixEj;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs4sizeEv;	.scl	2;	.type	32;	.endef
