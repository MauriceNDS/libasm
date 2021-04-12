extern _free

section .text
	global _ft_list_remove_if

	_ft_list_remove_if:
		push	rdi
		cmp		rdi, 0
		je		exit
		mov		r8, [rdi]
		mov		r9, rsi
		mov		r10, 0

	seeker:					; loop
		cmp		r8, 0
		je		exit
		mov		rdi, [r8]
		mov		rsi, r9
		push	r8
		push	r9
		push	r10
		push	r11
		push	rcx
		push	rdx
		push	rsi
		push	rdi
		call	rdx
		pop		rdi
		pop		rsi
		pop		rdx
		pop		rcx
		pop		r11
		pop		r10
		pop		r9
		pop		r8
		cmp		rax, 0
		je		remove
		mov		r10, r8
		mov		r8, [r8 + 8]
		jmp		seeker

	remove:					; delete a node in between of two other nodes
		mov		rdi, [r8]
		push	r8
		push	r9
		push	r10
		push	r11
		push	rcx
		push	rdx
		push	rsi
		push	rdi
		call	rcx
		pop		rdi
		pop		rsi
		pop		rdx
		pop		rcx
		pop		r11
		pop		r10
		pop		r9
		pop		r8
		cmp		r10, 0
		je		update_begin
		mov		r11, [r8 + 8]
		mov		[r10 + 8], r11
		mov		rdi, r8
		push	r8
		push	r9
		push	r10
		push	r11
		push	rcx
		push	rdx
		push	rsi
		push	rdi
		call	_free
		pop		rdi
		pop		rsi
		pop		rdx
		pop		rcx
		pop		r11
		pop		r10
		pop		r9
		pop		r8
		mov		r8, r11
		jmp		seeker


	update_begin:			; delete first node
		pop		rdi
		mov		r11, [r8 + 8]
		mov		[rdi], r11
		push	rdi
		mov		rdi, r8
		push	r8
		push	r9
		push	r10
		push	r11
		push	rcx
		push	rdx
		push	rsi
		push	rdi
		call	_free
		pop		rdi
		pop		rsi
		pop		rdx
		pop		rcx
		pop		r11
		pop		r10
		pop		r9
		pop		r8
		mov		r8, r11
		jmp		seeker
	exit:
		pop		rdi
		ret