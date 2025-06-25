# pwn-chals
collection of pwn chals i've authored for practice and/or for ctfs

## what will i put here?
- chal src (chal.c)
- chal bin (chal)
- libc (libc.so.6)
- ld (ld-linux-x86-64.so.2)
- docker (Dockerfile)
- start script (start.sh)
- sol writeup (sol.md)

## how do i use this?
1. ensure that you have `docker`, and that you are on a x64 linux machine or wsl
2. simply run `./start.sh` and your challenge will be ready for you at `nc 127.0.0.1 5000`
3. if your `libc` is different from the one provided, you can use the given `ld` or patch the challenge
4. avoid reading `sol.md` unless you really really can't solve it! these are meant for practicing, so i've withheld all solution scripts
5. when you're done with the challenge, simply run `docker ps` and `docker stop` the relevant container id
6. happy pwning!

## i'm new! where do i start?
**welcome to pwn!** you would want to get some tooling first, before doing anything. here are some tools you would find helpful:
- [pwntools](https://docs.pwntools.com/en/stable/)
- [one_gadget](https://github.com/david942j/one_gadget)
- [ROPgadget](https://github.com/JonathanSalwan/ROPgadget)
- [pwninit](https://github.com/io12/pwninit)
- **any flavour of gdb** *(pick one!)*
    - [pwndbg](https://github.com/pwndbg/pwndbg)
    - [bata-gef](https://github.com/bata24/gef)
    - [gef](https://github.com/hugsy/gef)

your next step would be to learn the **basics of pwn**. [this](https://ir0nstone.gitbook.io/notes/binexp/stack) set of notes are a good starting point to learn stack exploitation!

## too easy, i know all these!
**congrats!** you're probably far better than i am, and wouldn't benefit from these resources. perhaps find some [upcoming ctfs](https://ctftime.org/event/list/upcoming) and grind them?
