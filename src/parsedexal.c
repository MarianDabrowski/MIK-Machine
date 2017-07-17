#include "parsedexal.h"

void FindValueAndBase(char ch, int *value, int *base)
{
    if(ch >= '0' && ch <= '9'){
        *value = ch - '0';
        *base = 10;
    }
    else if(ch >= 'A' && ch <= 'P'){
        *value = ch - 'A';
        *base = SIZE_OF_REGISTER;
    }
    else if(ch >= 'Q' && ch <= 'X'){
        *value = ch - 'Q';
        *base = 8;
    }
    else if(ch >= 'Y' && ch <= 'Z'){
        if(ch == 'Y') *value = 1;
        else *value = 0;
        *base = 2;
    }
}

int ParseNumber(bool *isNumber)
{
    char ch = getchar();
    int outputValue = 0, testingValue = 0, base = 0;
    while(DexalNumberChar(ch)) {
        FindValueAndBase(ch, &testingValue, &base);
        outputValue = outputValue * base + testingValue;
        *isNumber = true;
        ch = getchar();
    }
    ungetc(ch, stdin);
    return outputValue;
}

int FillUntilSeparator(int *array, int size, int startingPosition) {
    int counter = startingPosition, temp;
    char c = getchar();
    bool isNumber;

    while(c != SEPARATOR_SIGN && c != EOF && counter < size) {
        while(c == NEW_LINE_SIGN || c == TAB_SIGN || c == BLANK_SPACE_SIGN) {
            c = getchar();
        }
        ungetc(c, stdin);
        isNumber = false;

        temp = ParseNumber(&isNumber);
        if(isNumber) {
            array[counter] = temp;
            counter++;
        }
        if(isNumber) c = getchar();
    }
    return counter;
}
