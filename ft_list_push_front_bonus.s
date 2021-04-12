extern _malloc

section .text
	global _ft_list_push_front
	global _ft_create_elem

	_ft_create_elem:
		push		rdi
		mov			rdi, 16
		call		_malloc
		pop			rdi
		mov			[rax], rdi
		mov	byte	[rax + 8], 0
		ret

	_ft_list_push_front:
		cmp			rdi, 0
		je			end
		push		rdi
		mov			rdi, rsi
		call		_ft_create_elem
		pop			rdi
		mov			rcx, [rdi]
		mov			[rax + 8], rcx
		mov			[rdi], rax
		ret

	end:
		ret