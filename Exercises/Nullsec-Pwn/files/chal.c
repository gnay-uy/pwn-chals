// gcc -o chal chal.c -Wl,-z,relro,-z,now -pie -fpie -fstack-protector-all

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    int opt = 0;
    while (1) {
        printf("> ");
        scanf("%d", &opt);
        if (opt == -1) exit(0);
        printf("> ");
        read(0, opt == 0 ? stdin : stdout, 0x80);
    }
}
