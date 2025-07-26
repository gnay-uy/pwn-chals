// gcc -o chal chal.c 
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    char *buf = mmap(0, 0x100, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    read(0, buf, 0x100);
    ((void(*)(void))buf)();
    munmap(buf, 0x100);
    return 0;
}
