// gcc -o chal chal.c -Wl,-z,relro,-z,now -fpie -pie

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct proving_ground {
    char name[32];
    void* main_ref;
    char pad[8];
    char vuln[32];
};

void gifts() {
    static char gift[8] = "/bin/sh\x00";
    __asm__(
        "pop %rdi;"
        "ret;"
    );
    system("echo You're going to need to try harder than this...");
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    struct proving_ground field;
    strncpy(field.pad, "\x00\x00\x00\x00\x00\x00\x00\x00", 8);
    field.main_ref = &main;
    puts("To become a pwner, you must first know how to gain your bearings. ");
    puts("Time to prove yourself! ");
    printf("Let's start slow. What is your name? \n> ");
    read(0, field.name, 32);
    getchar();
    printf("Very well, %s. Now, let's see what you've got! \n> ", field.name);
    read(0, field.vuln, 2048);
    getchar();
    puts("I hope that worked out for you...");
    return 0;
}
