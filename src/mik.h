/**
 * Defining the mik machine
 */
#ifndef __MIK_H__
#define __MIK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_OF_REGISTER 16
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

/**
 * Structure that represents the Mik machine
 */
struct Mik8Machine {
    int machineRegister[SIZE_OF_REGISTER];
    int machineMemory[SIZE_OF_MEMORY];
    int machineInstruction[SIZE_OF_MEMORY];
    int currentInstruction;
};

typedef struct Mik8Machine Mik8Machine;

/**
 * Creates a new Mik machine with all values each 0
 * @return a new Mik8Machine
 */
Mik8Machine *NewMik8Machine();

#endif /*__MIK_H__*/
