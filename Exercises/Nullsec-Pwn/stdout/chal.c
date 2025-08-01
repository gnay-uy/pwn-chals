// gcc -o chal chal.c -no-pie -fno-pie

#include <stdio.h>
#include <unistd.h>

char string[] = "Try and leak me!";
int main() {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	puts("Give it a shot, leak that string!");
	read(0, stdout, 0x100);
	puts("You should see the string leaked here!");
	return 0;
}
