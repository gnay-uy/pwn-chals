from pwn import *

context.log_level='debug'
elf=context.binary=ELF("./chal")
p=process(elf.path)
targ=0x0000000000404040

# payload goes here!
fs = FileStructure()
print(p.recvall(timeout=1))
p.sendlineafter(b'ENTER\n', b'')
