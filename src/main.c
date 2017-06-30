/*
 * Implementation of MIK machine in C
 * Main Aim:
 *         1) to reimplement the MIK machine using structures and more advance
 *            structures
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
    int a, i = 1;
    char c = '-';
    printf("AAAAAA\n");
    while(c != EOF) {
        a = ParseNumber();
        printf("%d: %d\n",i, a);
        ++i;
        c = getchar();
    }

    return 0;
}