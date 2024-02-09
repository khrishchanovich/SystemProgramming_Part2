#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_morse(char s) {
    char symbol = toupper(s);
    
    if (symbol == 'A') printf(".- ");
    else if (symbol == 'B') printf("-... ");
    else if (symbol == 'C') printf("-.-. ");
    else if (symbol == 'D') printf("-.. ");
    else if (symbol == 'E') printf(". ");
    else if (symbol == 'F') printf("..-. ");
    else if (symbol == 'G') printf("--. ");
    else if (symbol == 'H') printf(".... ");
    else if (symbol == 'I') printf(".. ");
    else if (symbol == 'J') printf(".--- ");
    else if (symbol == 'K') printf("-.- ");
    else if (symbol == 'L') printf(".-.. ");
    else if (symbol == 'M') printf("-- ");
    else if (symbol == 'N') printf("-. ");
    else if (symbol == 'O') printf("--- ");
    else if (symbol == 'P') printf(".--. ");
    else if (symbol == 'Q') printf("--.- ");
    else if (symbol == 'R') printf(".-. ");
    else if (symbol == 'S') printf("... ");
    else if (symbol == 'T') printf("- ");
    else if (symbol == 'U') printf("..- ");
    else if (symbol == 'V') printf("...- ");
    else if (symbol == 'W') printf(".-- ");
    else if (symbol == 'X') printf("-..- ");
    else if (symbol == 'Y') printf("-.-- ");
    else if (symbol == 'Z') printf("--.. ");
    else if (symbol == '0') printf("----- ");
    else if (symbol == '1') printf(".---- ");
    else if (symbol == '2') printf("..--- ");
    else if (symbol == '3') printf("...-- ");
    else if (symbol == '4') printf("....- ");
    else if (symbol == '5') printf("..... ");
    else if (symbol == '6') printf("-.... ");
    else if (symbol == '7') printf("--... ");
    else if (symbol == '8') printf("---.. ");
    else if (symbol == '9') printf("----. ");
    else {
        printf(" ");
    }
}
