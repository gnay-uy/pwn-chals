// gcc -o chal chal.c -fstack-protector-all -Wl,-z,relro,-z,now -fpie -pie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char** buf_ptr = NULL;
int main() {
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  while (1) {
    char* buf = malloc(0x100);
    buf_ptr = &buf;
    int off = 0;
    printf("> ");
    scanf("%d", &off);
    printf("> ");
    read(0, *((char**)((char*)(&buf_ptr) + off)), 0x100);
  }

  _exit(1);
}
