// gcc -o chal chal.c -pie -fpie -Wl,-z,relro,-z,now,--section-start,.onlywinners=0x11111

#include <stdio.h>
#include <unistd.h>

void __attribute__((section(".onlywinners"))) win() {
	execve("/bin/sh",0,0);
}

long vuln() {
	static long res = (long)&win;
	char buf[32];
	printf("hack me!\n > ");
	read(0, buf, 0x1000);
	return (long)&res;
}

int main() {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	puts("welcome to your first overflow challenge! your goal is to return to win, good luck!");
	vuln();
	return 0;
}
