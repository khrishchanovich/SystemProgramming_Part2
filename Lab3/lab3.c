#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "to_char.h"
#include "to_morse.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [morse/char]\n", argv[0]);
        return 1;
    }
    
    if (strcmp(argv[1], "morse") == 0) {
        int ch;
        while ((ch = getchar()) != EOF) {
            to_morse(ch);
        }
    } else if (strcmp(argv[1], "char") == 0) {
        char morse[50];
        int index = 0;
        int ch;
        while ((ch = getchar()) != EOF) {
            if (ch == ' ' || ch == '\n') {
                morse[index] = '\0';
                to_char(morse);
                index = 0;
            } else {
                morse[index++] = ch;
            }
        }
    } else {
        fprintf(stderr, "Unknown option: %s\n", argv[1]);
        return 1;
    }
    
    return 0;
}
