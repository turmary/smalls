	.file	"conc.c"
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
	str	r0, [fp, #-16]
	ldr	r3, [fp, #-16]
	and	r3, r3, #256
	mov	r0, r3
	ldmib	sp, {fp, sp, pc}
	.size	con, .-con
	.ident	"GCC: (Sourcery G++ Lite 2010.09-51) 4.5.1"
