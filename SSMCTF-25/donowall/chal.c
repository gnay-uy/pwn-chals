// gcc -o chal chal.c -fstack-protector -Wl,-z,relro,-z,now
#include <stdio.h>
#include <string.h>
int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    char buf[32];
    while (1) {
        printf("what do you say to the wall?\n> ");
        scanf("%s", buf);
        if (strcmp(buf, "bye")==0) return 0;
        printf("the wall says: ");
        printf(buf);
        printf("\n");
    }
    return 0;
}
