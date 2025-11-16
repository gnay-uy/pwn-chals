// gcc -o chal chal.c -fstack-protector-none -Wl,-z,relro,-z,now -pie -fpie
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void win() {
    execve("/bin/sh",0,0);
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    signal(SIGSEGV, win);
    char buf[0x100];
    printf("i heard that if you shouted loud enough, you might get a shell... \n> ");
    read(0, buf, 0x1000);
    puts("i hope you shouted loud enough...!");
    return 0;

}
