// gcc -o chal chal.c -fstack-protector-all -Wl,-z,relro,-z,now -pie -fpie

#include <stdio.h>
#include <stdlib.h>

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    long long sz;
    long long off;
    long long dat;
    printf("alloc size? \n> ");
    scanf("%lld", &sz);
    printf("offset? \n> ");
    scanf("%lld", &off);
    printf("increment? \n> ");
    scanf("%lld", &dat);
    long long* buf = malloc(sz);
    *(long long*)((char*)buf+off) += dat;
    puts(NULL);
}
