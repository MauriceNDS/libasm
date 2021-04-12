section .text
	global _ft_strcmp

	_ft_strcmp:
		mov			al, [rdi]
		mov			dl, [rsi]
		cmp			al, dl
		jne			end
		cmp			al, 0
		je			end
		inc			rdi
		inc			rsi
		jmp			_ft_strcmp

	end:
		movzx		rdx, dl
		movzx		rax, al
		sub			rax, rdx
		ret