// gcc -o chal chal.c -fstack-protector-all -fpie -Wl,-z,relro,-z,now
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win() {
    system("cat flag.txt");
    return;
}

struct note {
    char buf[32];
    void(*check)(char[32]);
};

void check(char buf[32]) {
    if (strlen(buf) < 31) {
        printf("your note is too short :(\n");
        return;
    }

    printf("your note is valid\n");
}

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    struct note* notes[5] = {NULL};
    int count = 0;
    int opt = 0;
    while (1) 
    {
        printf("1. make a new note\n2. submit a note\n3. edit a note\n4. read a note\n0. exit\n");
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                struct note* note = (struct note*)malloc(sizeof(struct note));
                printf("write note content\n");
                scanf("%s", note->buf);
                note->check = check;

                int idx = 0;
                printf("choose index (0-4)\n");
                scanf("%d", &idx);
                if (idx < 0 || idx > 4) {
                    return 0;
                }

                notes[idx] = note;
                break;
            }
            
            case 2: {
                int idx = 0;
                printf("choose index (0-4)\n");
                scanf("%d", &idx);
                if (idx < 0 || idx > 4) {
                    return 0;
                }

                struct note* note = notes[idx];
                if (note == NULL) return 0;
                
                note->check(note->buf);
                break;
            }

            case 3: {
                int idx = 0;
                printf("choose index (0-4)\n");
                scanf("%d", &idx);
                if (idx < 0 || idx > 4) {
                    return 0;
                }

                struct note* note = notes[idx];
                if (note == NULL) return 0;
                printf("enter content\n");
                scanf("%s", note->buf); 
                break;
            }

            case 4: {
                int idx = 0;
                printf("choose index (0-4)\n");
                scanf("%d", &idx);
                if (idx < 0 || idx > 4) {
                    return 0;
                }

                struct note* note = notes[idx];
                if (note == NULL) return 0;

                printf("note:\n");
                puts(note->buf);
                printf("\n");
                break;
            }
        
            case 0: default: return -1;
        }
    }
    return 0;
}
