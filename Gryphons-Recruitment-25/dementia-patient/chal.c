// gcc -o chal chal.c -fpie -pie -Wl,-z,relro,-z,now

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void win() {
    system("cat flag.txt");
    _exit(1);
}

void lose() {
    printf("the divines DO NOT SMILE UPON YOU :skull: x6\n");
    _exit(1);
}

struct pwnme {
    char name[128];
    void (*fptr)();
};

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    struct pwnme* goal = malloc(sizeof(struct pwnme));
    goal->fptr = lose;
    char* buf = malloc(128);
    while (1) {
        printf("1. change my name\n2. call upon divine beings for a flag\n3. recall my name\n> ");
        scanf("%127s", buf);
        if (!strcmp(buf, "1")) {
            printf("what's your new name? \n> ");
            scanf("%s", goal->name);
        } else if (!strcmp(buf, "2")) {
            printf("fingers crossed!\n");
            goal->fptr();
        } else if (!strcmp(buf, "3")) {
            printf("how forgetful! here you are: ");
            printf(goal->name);
            printf("\n");
        } else { _exit(0); }
    }
    _exit(0);
}
