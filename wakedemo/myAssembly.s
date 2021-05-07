	.arch msp430g2553
	.p2align 1,0
	.text

jt:
	.word case0
	.word case1
	.word case2
	.global assembly_method

assembly_method:

	sub #2, r1
	mov #0, 0(r1)		;note = 0

	cmp #3, r12
	jhs end

	cmp #0, r12
	jl end

	add r12, r12
	mov jt(r12), r0

case0:
	mov #400, 0(r1)
	mov 0(r1), r12
	call #play_buzzer
	jmp end

case1:
	mov #500, 0(r1)
	mov 0(r1), r12
	call #play_buzzer
	jmp end

case2:
	mov #600, 0(r1)
	mov 0(r1), r12
	call #play_buzzer
	jmp end

end:
	add #2, r1
	pop r0
