// gcc -o chal chal.c

#include <stdio.h>
#include <unistd.h>
int main() {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	int targ = 0;
	puts("make targ == 0xDEADBEEF to win!");
	while (1) {
		printf("> ");
		read(0, &targ, 4);
		if (targ==0xDEADBEEF) {
			printf("good job! enjoy shell :)\n");
			execve("/bin/sh",0,0);
		}
	}
	return 0;
}
