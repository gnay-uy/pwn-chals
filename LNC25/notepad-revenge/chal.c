// gcc -o chal chal.c -fstack-protector-all -Wl,-z,relro,-z,now -pie -fpie

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PAGE_SIZE 0x50
#define MAX_PAGES 100000


void print_menu() {
    puts("welcome to my new and improved notepad!");
    puts("1. create notepad");
    puts("2. write to page");
    puts("3. save note and quit");
}

void win() {
    system("/bin/sh");
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    printf("here's a free win function: %p\n", win);
    char* notepad = NULL;
    int opt;
    int pages;
    int page_write;
    int offset_write;
    while (1) {
        print_menu();
        printf("enter opt \n> ");
        scanf("%d", &opt);
     
        switch (opt) {
            case 1:
                if (notepad != NULL) puts(NULL);
                printf("how many pages will your notepad have? \n> ");
                scanf("%d", &pages);
                if (pages < 0 || pages > MAX_PAGES) puts(NULL);
                notepad = malloc(pages * PAGE_SIZE);
                break;

            case 2:
                if (notepad == NULL) puts(NULL);
                printf("which page do you want to write to? \n> ");
                scanf("%d", &page_write);
                if (page_write < 0) puts(NULL);
                printf("any offset you wish to add? \n> ");
                scanf("%d", &offset_write);
                if (offset_write < 0) puts(NULL);
                printf("write what you want \n> ");
                scanf("%32s", notepad + (page_write * PAGE_SIZE) + offset_write);
                break;

            case 3: default:
                _exit(0);
        }
    }
    _exit(0);
}
