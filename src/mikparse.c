//
// Created by marian on 6/29/17.
//

#include "mikparse.h"

void FillInstuctionArray(Mik8Machine *mik8Machine, int *instruction)
{
    int counter = 0, temp;
    char c = getchar();
    bool isNumber = false;
    while(c != EOF && c != SEPARATOR_SIGN) {
        while(c == NEW_LINE_SIGN || c == TAB_SIGN || c == BLANK_SPACE_SIGN) {
            c = getchar();
        }
        ungetc(c, stdin);
        isNumber = false;

        temp = ParseNumber(&isNumber);
        if(isNumber) {
            instruction[counter] = temp;
            counter++;
        }
        c = getchar();
    }
    mik8Machine->programCounter = counter;

    while(c != EOF && c != SEPARATOR_SIGN) {
        while(c == NEW_LINE_SIGN || c == TAB_SIGN || c == BLANK_SPACE_SIGN) {
            c = getchar();
        }
        ungetc(c, stdin);
        isNumber = false;

        temp = ParseNumber(&isNumber);
        if(isNumber) {
            instruction[counter] = temp;
            counter++;
        }
        c = getchar();
    }
}

void ParseInput(Mik8Machine *mik8Machine, int *instructions)
{
    FillArray(mik8Machine->rejestry, SIZE_OF_REJESTRY);
    FillArray(mik8Machine->memory, SIZE_OF_MEMORY);

}