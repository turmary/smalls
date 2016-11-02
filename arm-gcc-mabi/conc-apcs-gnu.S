	.file	"conc.c"
	.text
	.align	2
	.global	con
	.type	con, %function
con:
	@ args = 0, pretend = 0, frame = 4
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #4
	str	r0, [fp, #-4]
	ldr	r3, [fp, #-4]
	and	r3, r3, #256
	mov	r0, r3
	add	sp, fp, #0
	ldmfd	sp!, {fp}
	bx	lr
	.size	con, .-con
	.ident	"GCC: (Sourcery G++ Lite 2010.09-51) 4.5.1"
