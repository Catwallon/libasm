bits 64

section .text
  global ft_strdup
  extern ft_strlen
  extern malloc
  extern ft_strcpy

ft_strdup:
  call ft_strlen
  inc rax
  mov rbx, rdi
  mov rdi, rax
  call malloc
  cmp rax, 0
  je ret
  mov rdi, rax
  mov rsi, rbx
  call ft_strcpy

return:
  ret
