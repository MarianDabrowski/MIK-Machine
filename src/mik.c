#include <assert.h>
#include "mik.h"

Mik8Machine *NewMik8Machine()
{
    int i;
    Mik8Machine *mik = malloc(sizeof(Mik8Machine));
    assert(mik != NULL);
    for(i = 0; i < SIZE_OF_REGISTER; ++i) mik->machineRegister[i] = 0;
    for(i = 0; i < SIZE_OF_MEMORY; ++i){
        mik->machineMemory[i] = 0;
        mik->machineInstruction[i] = 0;
    }
    mik->currentInstruction = 0;

    return mik;
}