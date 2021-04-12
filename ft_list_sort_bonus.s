section .text
    global _ft_list_sort

    _ft_list_sort:
        push        rdi
        cmp         rdi, 0
        je          exit
        mov         rdx, [rdi]
        mov         r8, rsi
        jmp         loopo

    next:
        mov         rdx, [rdx + 8]
        jmp         loopo

    loopo:
        cmp         rdx, 0
        je          exit
        mov         rcx, rdx
        jmp         loopi

    loopi:
        mov         rcx, [rcx + 8]
        cmp         rcx, 0
        je          next
        mov         rdi, [rdx]
        mov         rsi, [rcx]
        push        rdi
        push        rsi
        push        rdx
        push        rcx
        push        r8
        call        r8
        pop         r8
        pop         rcx
        pop         rdx
        pop         rsi
        pop         rdi
        cmp         rax, 0
        jg          swap
        jmp         loopi

    swap:
        mov         r9, [rcx]
        mov         r10, [rdx]
        mov         [rcx], r10
        mov         [rdx], r9
        jmp         loopo
		
    exit:
        pop         rdi
        ret