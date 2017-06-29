//
// Created by marian on 6/29/17.
//

#include "parsedexal.h"

/*KONWERTOWANIE LICZBY I WCZYTYWANIE DANYCH*/
/*
Funkcja wyszukuje odpowiednia wartosc elementu i jego baze przeksztalcenia
Pryjmuje 3 argumenty elemnt char (ch) na podstawie ktorego
bedzie ustawiona (value) wartosc i (base) baze
*/
void FindValueAndBase(char ch, int *value, int *base)
{
    if(ch >= '0' && ch <= '9'){
        *value = ch - '0';
        *base = 10;
    }
    else if(ch >= 'A' && ch <= 'P'){
        *value = ch - 'A';
        *base = SIZE_OF_REJESTRY;
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

int ParseNumber()
{
    char ch = getchar();
    int outputValue = 0, testingValue = 0, base = 0;
    while(DexalNumberChar(ch)) {
        FindValueAndBase(ch, &testingValue, &base);
        outputValue = outputValue * base + testingValue;
        ch = getchar();
    }
    ungetc(ch, stdin);
    return outputValue;
}

void FillArray(int *array, int size)
{
    int counter = 0;
    char c = getchar();
    while(c != EOF && c != SEPARATOR_SIGN) {
        while(c == NEW_LINE_SIGN || c == TAB_SIGN || c == BLANK_SPACE_SIGN) {
            c = getchar();
        }
        ungetc(c, stdin);
        array[counter] = ParseNumber();
        c = getchar();
    }
}
