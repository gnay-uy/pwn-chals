// gcc -o chal -Wl,-z,relro,-z,now -fno-pie -no-pie chal.c
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler() {
    char* buf = alloca(0x20);
    int off = 0;
    while (1) {
        printf("off\n> ");
        scanf("%d", &off);
        if (off<0) break;
        printf("write\n> ");
        read(0, buf+off, 0x100);
    }
    return;
}

int main() {
    char* str = "glhf lol\n";
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    signal(SIGSEGV, handler); 
    write(1, str, sizeof(str)+1);
    (*(char*)0)++;
    exit(0);
}
