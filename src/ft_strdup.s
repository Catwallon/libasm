bits 64

section .text
  global ft_strdup
  extern ft_strlen
  extern malloc
  extern ft_strcpy
  extern __errno_location

ft_strdup:
  call ft_strlen
  inc rax
  mov rbx, rdi
  mov rdi, rax
  call malloc
  cmp rax, 0
  jle error
  mov rdi, rax
  mov rsi, rbx
  call ft_strcpy
  ret

error:
  neg rax
  mov rbx, rax
  call __errno_location
  mov [rax], rbx
  mov rax, -1
  ret
