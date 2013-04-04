	.file	"T07-03.cpp"
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
	.section .rdata,"dr"
_ZZN7OnlyOne10onlyMemberEvE12__FUNCTION__:
	.ascii "onlyMember\0"
	.text
	.align 2
.globl __ZN7OnlyOne10onlyMemberEv
	.def	__ZN7OnlyOne10onlyMemberEv;	.scl	2;	.type	32;	.endef
__ZN7OnlyOne10onlyMemberEv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$_ZZN7OnlyOne10onlyMemberEvE12__FUNCTION__, %eax
	popl	%ebp
	ret
	.section .rdata,"dr"
LC0:
	.ascii "onlyMember(\0"
LC1:
	.ascii ")\0"
	.text
	.align 2
.globl __ZN7OnlyOne10onlyMemberEi
	.def	__ZN7OnlyOne10onlyMemberEi;	.scl	2;	.type	32;	.endef
__ZN7OnlyOne10onlyMemberEi:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%eax, %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	__ZNSolsEi
	movl	$LC1, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$0, %eax
	leave
	ret
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
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
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
	movl	$___gxx_personality_sj0, -72(%ebp)
	movl	$LLSDA1421, -68(%ebp)
	leal	-64(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L18, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	call	___main
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -92(%ebp)
	call	__ZN7OnlyOneC1Ev
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__Z3_E_P7OnlyOne
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN7OnlyOne10onlyMemberEv
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	$1, -92(%ebp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	movl	$5, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN7OnlyOne10onlyMemberEi
	movl	%eax, -44(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -92(%ebp)
	call	__ZN7OnlyOneD1Ev
	movl	$0, -100(%ebp)
	jmp	L13
L18:
	leal	24(%ebp), %ebp
	movl	-88(%ebp), %eax
	movl	%eax, -108(%ebp)
L14:
	movl	-108(%ebp), %edx
	movl	%edx, -104(%ebp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$0, -92(%ebp)
	call	__ZN7OnlyOneD1Ev
	movl	-104(%ebp), %eax
	movl	%eax, -108(%ebp)
L16:
	movl	-108(%ebp), %edx
	movl	%edx, (%esp)
	movl	$-1, -92(%ebp)
	call	__Unwind_SjLj_Resume
L13:
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	-100(%ebp), %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"dr"
LLSDA1421:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1421-LLSDACSB1421
LLSDACSB1421:
	.uleb128 0x0
	.uleb128 0x0
LLSDACSE1421:
	.text
	.section	.text$_ZN7OnlyOneD1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZN7OnlyOneD1Ev
	.def	__ZN7OnlyOneD1Ev;	.scl	2;	.type	32;	.endef
__ZN7OnlyOneD1Ev:
L21:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6MemberD1Ev
	leave
	ret
L19:
	.section .rdata,"dr"
LC2:
	.ascii "Member Killed!\0"
	.section	.text$_ZN6MemberD1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZN6MemberD1Ev
	.def	__ZN6MemberD1Ev;	.scl	2;	.type	32;	.endef
__ZN6MemberD1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	leave
	ret
	.section	.text$_ZN7OnlyOneC1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZN7OnlyOneC1Ev
	.def	__ZN7OnlyOneC1Ev;	.scl	2;	.type	32;	.endef
__ZN7OnlyOneC1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN6MemberC1Ev
	leave
	ret
L28:
L27:
	.section .rdata,"dr"
LC3:
	.ascii "Member Created!\0"
	.section	.text$_ZN6MemberC1Ev,"x"
	.linkonce discard
	.align 2
.globl __ZN6MemberC1Ev
	.def	__ZN6MemberC1Ev;	.scl	2;	.type	32;	.endef
__ZN6MemberC1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSolsEPFRSoS_E
	leave
	ret
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
	.text
	.align 2
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	cmpl	$65535, 12(%ebp)
	jne	L34
	cmpl	$1, 8(%ebp)
	jne	L34
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
L34:
	cmpl	$65535, 12(%ebp)
	jne	L33
	cmpl	$0, 8(%ebp)
	jne	L33
	movl	$__ZSt8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitD1Ev
L33:
	leave
	ret
	.align 2
	.def	__GLOBAL__I__ZN7OnlyOne10onlyMemberEv;	.scl	3;	.type	32;	.endef
__GLOBAL__I__ZN7OnlyOne10onlyMemberEv:
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
	.long	__GLOBAL__I__ZN7OnlyOne10onlyMemberEv
	.text
	.align 2
	.def	__GLOBAL__D__ZN7OnlyOne10onlyMemberEv;	.scl	3;	.type	32;	.endef
__GLOBAL__D__ZN7OnlyOne10onlyMemberEv:
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
	.long	__GLOBAL__D__ZN7OnlyOne10onlyMemberEv
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNKSsixEj;	.scl	2;	.type	32;	.endef
	.def	__ZNKSs4sizeEv;	.scl	2;	.type	32;	.endef
