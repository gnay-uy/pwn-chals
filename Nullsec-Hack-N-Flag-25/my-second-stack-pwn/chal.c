// gcc -o chal chal.c -Wl,-z,relro,-z,now -no-pie -fno-pie 

#include <stdio.h>
#include <unistd.h>

void vuln() {
    char buf[32];
    printf("> ");
    read(0, buf, 41);
    return;
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    char name[0x80] = {0};
    printf("what is your name? \n> ");
    read(0, name, 0x7f);
    printf("hello, %s... you've learnt a lot, now put it all together!\n", name);
    vuln();
    return 0;
}
