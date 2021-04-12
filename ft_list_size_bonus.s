section .text
	global _ft_list_size

	_ft_list_size:
		mov			rax, 1
		cmp 		rdi, 0
		je			null
		jmp			loop

	loop:
		mov			rdi, [rdi + 8]
		cmp 		rdi, 0
		je			end
		inc			rax
		jmp			loop

	end:
		ret

	null:
		mov			rax, 0
		ret