// gcc -o chal chal.c -O0 -fno-pie -no-pie -fstack-protector
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void win() { system("cat flag.txt"); }

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    char buf[32];
    FILE* note = fopen("notes.txt", "w");
    printf("set your title\n> ");
    scanf("%s", note);
    printf("write your note\n> ");
    scanf("%32s", buf);
    fprintf(note, "%s", buf);
    puts(NULL);
}
