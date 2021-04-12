section .text
	global _ft_strcpy

	_ft_strcpy:
		mov			rax, 0
		jmp			loop

	loop:
		cmp byte	[rsi + rax], 0
		je			end
		mov			rdx, [rsi + rax]
		mov			[rdi + rax], rdx
		inc			rax
		jmp			loop

	end:
		mov			rdx, [rsi + rax]
		mov			[rdi + rax], rdx
		mov			rax, rdi
		ret