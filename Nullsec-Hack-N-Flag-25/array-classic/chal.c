// gcc -o chal chal.c -fstack-protector-all -Wl,-z,relro,-z,now -pie -fpie
#include <stdio.h>
#include <alloca.h>
#include <unistd.h>
#include <string.h>
#define ARRAY_MAX 128
#define WORD_LENGTH 8

void win() {
	execve("/bin/sh",0,0);
}
int main() {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	char* array;
	int idx=0;
	int rw=0;
	array = alloca(sizeof(char) * WORD_LENGTH * ARRAY_MAX);
	memset(array, 0, sizeof(char) * WORD_LENGTH * ARRAY_MAX);

	while (1) {
		printf("index?\n> ");
		scanf("%d", &idx);
		if (idx > ARRAY_MAX) _exit(1); // no oob access!!!
		printf("0 for read, anything else for write\n> ");
		scanf("%d", &rw);
		if (rw == 0) {
			write(1, array + (WORD_LENGTH * idx), WORD_LENGTH);
			puts(""); // newline for cleanliness
		} else {
			printf("> ");
			read(0, array + (WORD_LENGTH * idx), WORD_LENGTH);
		}
	}

	return 0;
}
