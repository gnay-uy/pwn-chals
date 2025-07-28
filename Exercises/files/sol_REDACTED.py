from pwn import *

context.terminal = ['tmux', 'splitw', '-h']
context.log_level = 'debug'
elf = context.binary = ELF("./chal")
libc = ELF("./libc.so.6")
ld = ELF("./ld-linux-x86-64.so.2")

p = process([ld.path, '--library-path', '.', elf.path])
gdb.attach(p)

def stdin(buf):
    p.sendlineafter(b'> ', b'0')
    # p.send(buf)
    p.sendafter(b'> ', buf)

def stdout(buf):
    p.sendlineafter(b'> ', b'1')
    # p.send(buf)
    p.sendafter(b'> ', buf)

def write(addr, buf):
    # TODO: implement
    return 0

def read(addr):
    # TODO: implement
    return 0

# TODO: win 

p.interactive()
