// gcc -o chal chal.c

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	srand(time(NULL));
	unsigned int targ = rand();
	unsigned int chk = targ >> 16;
	puts("while keeping the higher bits intact, change the lower bits to BEEF :)");
	while (1) {
		printf("> ");
		read(0, &targ, 4);
		if ((targ&0xffff)==0xbeefu && (targ>>16)==chk) {
			printf("good job! enjoy shell :)\n");
			execve("/bin/sh",0,0);
		}
	}
	return 0;
}
