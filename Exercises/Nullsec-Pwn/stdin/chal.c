// gcc -o chal chal.c -no-pie -fno-pie

#include <stdio.h>
#include <unistd.h>

char buf[] = "You shouldn't see me get printed out... ";
int main() {
	char tmp[4];
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	puts("Now, change the string to anything you like");
	read(0, stdin, 0x100);
	puts("Moment of truth! You should see your string below...");
	puts("Affirm yes! Press ENTER");
	read(0, tmp, 1);
	puts(buf);
	return 0;
}
