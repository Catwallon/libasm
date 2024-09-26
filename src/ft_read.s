bits 64

section .text
  global ft_read
  extern __errno_location

ft_read:
  mov rax, 0 
  syscall
  cmp rax, 0
  jge return
  neg rax
  mov rbx, rax
  call __errno_location
  mov [rax], rbx
  mov rax, -1

return:
  ret
