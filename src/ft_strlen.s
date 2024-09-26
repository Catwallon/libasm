bits 64

section .text
  global ft_strlen

ft_strlen:
  xor rax, rax

loop:
  cmp byte [rdi + rax], 0
  je return
  inc rax
  jmp loop

return:
  ret
