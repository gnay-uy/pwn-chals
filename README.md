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
