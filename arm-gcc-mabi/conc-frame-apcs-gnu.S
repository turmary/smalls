	.file	"conc.c"
	.global	bssvar
	.bss
	.align	2
	.type	bssvar, %object
	.size	bssvar, 4
bssvar:
	.space	4
	.global	globalvar
	.data
	.align	2
	.type	globalvar, %object
	.size	globalvar, 4
globalvar:
	.word	1
	.global	us
	.align	1
	.type	us, %object
	.size	us, 2
us:
	.short	2
	.global	uc
	.type	uc, %object
	.size	uc, 1
uc:
	.byte	3
	.text
	.align	2
	.global	con
	.type	con, %function
con:
	@ args = 0, pretend = 0, frame = 4
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	sub	sp, sp, #4
	ldr	r3, .L2
.LPIC0:
	add	r3, pc, r3
	str	r0, [fp, #-16]
	ldr	r2, [fp, #-16]
	and	r2, r2, #256
	ldr	r1, .L2+4
	ldr	r3, [r3, r1]
	ldr	r3, [r3, #0]
	and	r3, r2, r3
	mov	r0, r3
	ldmib	sp, {fp, sp, pc}
.L3:
	.align	2
.L2:
	.word	_GLOBAL_OFFSET_TABLE_-(.LPIC0+8)
	.word	globalvar(GOT)
	.size	con, .-con
	.ident	"GCC: (Sourcery G++ Lite 2010.09-51) 4.5.1"
