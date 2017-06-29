/*
 * Implementation of MIK machine in C
 * Main Aim:
 *         1) to reimplement the MIK machine using structures and more advance
 *            structres
 *         2) to divide the program into libraries so that it is easier to follow
 *            the process
 *         3) use function pointers
 *         4) learn how to use make
 *
 * Date: 29.June 2017
 * Author: Marian Dabrowski
*/

#include "mik.h"
#include "parsedexal.h"

int main(void)
{
    int a;
    char c = '-';
    printf("AAAAAA\n");
    while(c != EOF) {
        a = ParseNumber();
        printf("%d\n", a);
        c = getchar();
    }

    return 0;
}