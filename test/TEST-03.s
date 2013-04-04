	.file	"TEST-03.cpp"
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__I_arr
	.section	.dtors,"w"
	.align 4
	.long	__GLOBAL__D_arr
.globl _arr
	.data
	.align 4
_arr:
	.long	__ZN4Test4showEv
	.long	0
.lcomm __ZSt8__ioinit,16
	.section	.text$_ZN4Test4showEv,"x"
	.linkonce discard
	.align 2
.globl __ZN4Test4showEv
	.def	__ZN4Test4showEv;	.scl	2;	.type	32;	.endef
__ZN4Test4showEv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	addl	$__ZSt4cout, %eax
	movl	12(%eax), %eax
	testb	$64, %al
	jne	L5
	testb	$8, %al
	je	L4
L5:
	pushl	%edx
	pushl	$__ZSt4cout
	call	__ZNSolsEm
	jmp	L11
L4:
	pushl	%edx
	pushl	$__ZSt4cout
	call	__ZNSolsEl
L11:
	popl	%edx
	popl	%ecx
	movl	%eax, 8(%ebp)
	leave
	jmp	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.align 2
.globl _main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ebx
	pushl	%ebx
	call	___main
	movl	$20, -12(%ebp)
	movl	__ZSt4cout, %eax
	movl	_arr, %ebx
	movl	-12(%eax), %eax
	addl	$__ZSt4cout, %eax
	movl	12(%eax), %eax
	testb	$64, %al
	jne	L17
	testb	$8, %al
	je	L16
L17:
	pushl	$20
	pushl	$__ZSt4cout
	call	__ZNSolsEm
	jmp	L24
L16:
	pushl	$20
	pushl	$__ZSt4cout
	call	__ZNSolsEl
L24:
	popl	%edx
	popl	%ecx
	pushl	%eax
	call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	$0, (%esp)
	call	_time
	leal	-12(%ebp), %eax
	movl	%eax, -8(%ebp)
/APP
	movl	-8(%ebp), %eax
	movl	%eax, (%esp)
/NO_APP
	popl	%eax
	call	*%ebx
	movl	-4(%ebp), %ebx
	xorl	%eax, %eax
	leave
	ret
	.align 2
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	cmpl	$65535, %edx
	movl	%esp, %ebp
	pushl	%esi
	movl	%eax, %esi
	pushl	%ebx
	sete	%bl
	cmpl	$1, %eax
	sete	%al
	testb	%al, %bl
	je	L26
	pushl	$__ZSt8__ioinit
	call	__ZNSt8ios_base4InitC1Ev
	popl	%eax
L26:
	testl	%esi, %esi
	sete	%al
	testb	%al, %bl
	je	L25
	pushl	$__ZSt8__ioinit
	call	__ZNSt8ios_base4InitD1Ev
	popl	%esi
L25:
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.align 2
	.def	__GLOBAL__I_arr;	.scl	3;	.type	32;	.endef
__GLOBAL__I_arr:
	pushl	%ebp
	movl	$65535, %edx
	movl	%esp, %ebp
	popl	%ebp
	movl	$1, %eax
	jmp	__Z41__static_initialization_and_destruction_0ii
	.align 2
	.def	__GLOBAL__D_arr;	.scl	3;	.type	32;	.endef
__GLOBAL__D_arr:
	pushl	%ebp
	movl	$65535, %edx
	movl	%esp, %ebp
	popl	%ebp
	xorl	%eax, %eax
	jmp	__Z41__static_initialization_and_destruction_0ii
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEl;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEm;	.scl	2;	.type	32;	.endef
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
