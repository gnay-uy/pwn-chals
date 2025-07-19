// gcc -o chal chal.c -Wl,-z,relro,-z,now -fno-pie -no-pie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ALLOC_SIZE 32

int main() {
    setbuf(stdin,0);
    setbuf(stdout,0);
    static unsigned long long pigs_flying = 0;
    char* chunks[16] = {NULL};
    int choice = 0;
    int idx = 0;
    while (1) {
        printf("> ");
        scanf("%d", &choice);
        switch (choice) {
            case 0: default:
                goto sanity_check;
            case 1: 
                printf("> ");
                scanf("%d", &idx);
                if (idx < 0 || idx >= 16) break;
                chunks[idx] = malloc(ALLOC_SIZE);
                printf("the tap drips: %p\n", chunks[idx]);
                break;
            case 2: 
                printf("> ");
                scanf("%d", &idx);
                if (idx < 0 || idx >= 16) break;
                free(chunks[idx]);
                break;
            case 3:
                printf("> ");
                scanf("%d", &idx);
                if (idx < 0 || idx >= 16 || chunks[idx]==NULL) break;
                printf("> ");
                scanf("%31s", chunks[idx]);
                break;
        }
    }

sanity_check:
    if (pigs_flying == 1) {
        system("cat flag.txt");
    } else {
        printf("huh? everything seems to be in place...\n");
    }
    _exit(0);
}
