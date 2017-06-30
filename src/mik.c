//
// Created by marian on 6/29/17.
//


#include <assert.h>
#include "mik.h"

Mik8Machine *NewMik8Machine()
{
    Mik8Machine *mik = malloc(sizeof(Mik8Machine));
    assert(mik != NULL);
    int i;
    for(i = 0; i < SIZE_OF_REJESTRY; ++i) mik->rejestry[i] = 0;
    for(i = 0; i < SIZE_OF_MEMORY; ++i) mik->memory[i] = 0;
    for(i = 0; i < 3; ++i) mik->args[i] = 0;
    mik->programCounter = 0;

    return mik;
}