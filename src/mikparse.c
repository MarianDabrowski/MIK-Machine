#include "mikparse.h"

void ParseInput(Mik8Machine *mik8Machine)
{
    char c, a, b;
    FillUntilSeparator(mik8Machine->machineRegister, SIZE_OF_REGISTER, 0);
    c = getchar(); b = getchar(); a = getchar();
    ungetc(a, stdin); ungetc(b, stdin);
    if((a == SEPARATOR_SIGN && b == SEPARATOR_SIGN &&
            c == SEPARATOR_SIGN) || (c != SEPARATOR_SIGN)) ungetc(c, stdin);

    FillUntilSeparator(mik8Machine->machineMemory, SIZE_OF_MEMORY, 0);

    c = getchar();
    if(c != SEPARATOR_SIGN) ungetc(c, stdin);

    mik8Machine->currentInstruction =
            FillUntilSeparator(mik8Machine->machineInstruction, SIZE_OF_MEMORY, 0);
    c = getchar();
    if(c != SEPARATOR_SIGN) ungetc(c, stdin);

    FillUntilSeparator(mik8Machine->machineInstruction, SIZE_OF_MEMORY,
                        mik8Machine->currentInstruction);
    c = getchar();
    if(c != SEPARATOR_SIGN) ungetc(c, stdin);
}