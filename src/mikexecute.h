/**
 * Defining all necessary program function so that
 * the mik machine can execute a program
 */

#ifndef __MIKEXECUTE_H__
#define __MIKEXECUTE_H__

#include "mik.h"

/**
 * Calculates the correct value of a % b
 * @param a integer
 * @param b integer
 * @return correct a % b
 */
static inline int mod(int a, int b)
{
    while(a < 0) a += b;
    return a % b;
}

void showString(int *A);

void printArrStdErr(int *A, int n);

/**
 * Displays the current machine state on stderr
 * @param mik8Machine
 */
void coreDump(Mik8Machine *mik8Machine);

/*0*/
void divide(Mik8Machine *mik, int *args);

void push(Mik8Machine *mik, int *args);

void halt(Mik8Machine *mik, int *args);

/*1*/
void returnFunction(Mik8Machine *mik, int *args);

void pop(Mik8Machine *mik, int *args);

void return_from_subroutine(Mik8Machine *mik, int *args);

/*2*/
void compare(Mik8Machine *mik, int *args);

void shiftLeft(Mik8Machine *mik, int *args);

/*3*/
void subtract(Mik8Machine *mik, int *args);

void shiftRight(Mik8Machine *mik, int *args);

/*4*/
void loadIndexed(Mik8Machine *mik, int *args);

void add(Mik8Machine *mik, int *args);

/*5*/
void storeIndexed(Mik8Machine *mik, int *args);

void bitwiseOr(Mik8Machine *mik, int *args);

/*6*/
void multiply(Mik8Machine *mik, int *args);

void bitwiseAnd(Mik8Machine *mik, int *args);

/*7*/
void callIndexed(Mik8Machine *mik, int *args);

void bitwiseExclusiveOr(Mik8Machine *mik, int *args);

/*8*/
void jumpIfZero(Mik8Machine *mik, int *args);

/*9*/
void jumpIfNotZero(Mik8Machine *mik, int *args);

/*10*/
void callSubroutine(Mik8Machine *mik, int *args);

/*11*/
void call(Mik8Machine *mik, int *args);

/*12*/
void loadRegister(Mik8Machine *mik, int *args);

/*13*/
void storeRegister(Mik8Machine *mik, int *args);

/*14*/
void loadConstant(Mik8Machine *mik, int *args);

/*15*/
void systemCall(Mik8Machine *mik, int *args);

void function0(Mik8Machine *mik, int *args);

void function1(Mik8Machine *mik, int *args);

void function2(Mik8Machine *mik, int *args);

void function3(Mik8Machine *mik, int *args);

void function4(Mik8Machine *mik, int *args);

void function5(Mik8Machine *mik, int *args);

void function6(Mik8Machine *mik, int *args);

void function7(Mik8Machine *mik, int *args);

/**
 * Gets function parameters and stores them in f_code and args array
 * @param mik Mik8Machine
 * @param f_code function code
 * @param args arguments
 */
void getParameters(Mik8Machine *mik, int *f_code, int *args);

/**
 * Interprets all the mik machine commands
 * @param mik Mik8Machine
 */
void interpret(Mik8Machine *mik);

#endif /*__MIKEXECUTE_H__*/