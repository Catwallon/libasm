bits 64

section .text
  errno_location

ft_strcpy:
  xor rcx, rcx
 
loop:
  cmp byte [rsi + rcx], 0
  je return
  mov bl, [rsi + rcx]
  mov [rdi + rcx], bl 
  inc rcx
  jmp loop

return:
  mov byte [rdi + rcx], 0
  mov rax, rdi
  ret
