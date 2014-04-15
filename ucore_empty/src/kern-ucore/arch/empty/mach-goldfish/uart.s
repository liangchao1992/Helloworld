	.cpu arm7tdmi
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"mb9bf506r_uart.c"
	.text
	.align	2
	.global	uart_init
	.type	uart_init, %function
uart_init:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	stmfd	sp!, {r4, r5}
	ldr	r2, .L2
	ldr	r3, [r2, #8]
	orr	r3, r3, #6
	str	r3, [r2, #8]
	ldr	r5, [r2, #1564]
	ldr	r3, .L2+4
	ldr	ip, .L2+8
	orr	r5, r5, #64
	mov	r4, #1
	mov	r1, #0
	mov	r0, #3
	str	r5, [r2, #1564]
	strb	r4, [r3]
	strb	r1, [r3, #1]
	strh	ip, [r3, #12]	@ movhi
	strb	r1, [r3, #4]
	strb	r0, [r3, #1]
	ldmfd	sp!, {r4, r5}
	bx	lr
.L3:
	.align	2
.L2:
	.word	1073950720
	.word	1073971200
	.word	346
	.size	uart_init, .-uart_init
	.align	2
	.global	uart_sendchar
	.type	uart_sendchar, %function
uart_sendchar:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r2, .L10
.L6:
	ldrb	r3, [r2, #5]	@ zero_extendqisi2
	tst	r3, #2
	ldr	r3, .L10
	beq	.L6
	strh	r0, [r3, #8]	@ movhi
	mov	r2, r3
.L8:
	ldrb	r3, [r2, #5]	@ zero_extendqisi2
	tst	r3, #2
	beq	.L8
	bx	lr
.L11:
	.align	2
.L10:
	.word	1073971200
	.size	uart_sendchar, .-uart_sendchar
	.align	2
	.global	uart_recvchar
	.type	uart_recvchar, %function
uart_recvchar:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	ldr	r2, .L15
.L14:
	ldrb	r3, [r2, #5]	@ zero_extendqisi2
	tst	r3, #4
	ldr	r3, .L15
	beq	.L14
	ldrh	r0, [r3, #8]
	and	r0, r0, #255
	bx	lr
.L16:
	.align	2
.L15:
	.word	1073971200
	.size	uart_recvchar, .-uart_recvchar
	.ident	"GCC: (GNU Tools for ARM Embedded Processors) 4.8.3 20131129 (release) [ARM/embedded-4_8-branch revision 205641]"
