// gcc -o chal chal.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	puts("Exercise 1: Sending Lines");
	char buf[32];

	puts("Send \"DEADBEEF\" in here!");
	printf("> ");
	scanf("%31s", buf);
	if (strcmp(buf, "DEADBEEF")) {
		puts("You got it wrong, try again.");
		exit(0);
	}

	puts("Exercise 2: Sending without lines");
	puts("Write nulls over the string.");
	printf("> ");
	read(0, buf, 32);
	for (int i = 0; i < 32; i++) {
		if (buf[i] != NULL) {
			puts("You got it wrong, try again.");
			exit(0);
		}
	}

	puts("Exercise 3: Sending numbers");
	puts("Change this number to 0x6942069420");
	printf("> ");
	long long val;
	read(0, &val, sizeof(long long));
	if (val != 0x6942069420) {
		puts("You got it wrong, try again.");
		exit(0);
	}

	puts("Good job!");
	return 0;
}
