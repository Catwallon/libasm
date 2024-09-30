bits 64

section .text
  global ft_strcmp

ft_strcmp:

loop:
  mov al, [rdi]
  mov bl, [rsi]
  cmp al, 0
  je return
  cmp al, bl
  jne return
  inc rdi	
  inc rsi	
  jmp loop 

return:
  movzx rax, al
  movzx rbx, bl
  sub rax, rbx
  ret
