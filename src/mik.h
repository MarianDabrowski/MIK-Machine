//
// Created by marian on 6/29/17.
//

#ifndef MIK8_MIK_H
#define MIK8_MIK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_OF_REJESTRY 16
#define SIZE_OF_MEMORY 256
#define SEPARATOR_SIGN '%'
#define NEW_LINE_SIGN '\n'
#define TAB_SIGN '\t'
#define BLANK_SPACE_SIGN ' '
#define CORE_DUMP 0
#define GET_INT 1
#define PUT_INT 2
#define GET_CHAR 3
#define PUT_CHAR 4
#define PUT_STRING 5

struct Mik8Machine {
    int rejestry[SIZE_OF_REJESTRY];
    int memory[SIZE_OF_MEMORY];
    int args[3];
    int programCounter;
};

typedef struct Mik8Machine Mik8Machine;

Mik8Machine *NewMik8Machine();

#endif //MIK8_MIK_H
