#include "mikexecute.h"

void showString(int *A)
{
    int i = 0;
    while(A[i] != 0){
        putchar(A[i]);
        i++;
    }
}

void printArrStdErr(int *A, int n)
{
    int i;
    for(i = 0; i < n; ++i) fprintf(stderr, "%d ", A[i]);
    fprintf(stderr, "\n");
}

void coreDump(Mik8Machine *mik8Machine)
{
    printArrStdErr(mik8Machine->machineRegister, SIZE_OF_REGISTER);
    fputc('%', stderr);
    printArrStdErr(mik8Machine->machineMemory, SIZE_OF_MEMORY);
    fputc('%', stderr);
    printArrStdErr(mik8Machine->machineInstruction, mik8Machine->currentInstruction);
    fputc('%', stderr);
    printArrStdErr(mik8Machine->machineInstruction + mik8Machine->currentInstruction,
                   SIZE_OF_MEMORY - mik8Machine->currentInstruction);
    fputc('%', stderr);
    fputc('\n',stderr);
}

/*0*/
void divide(Mik8Machine *mik, int *args)
{
    int temp_c = mik->machineRegister[args[2]], temp_b;
    int next_index = mod(args[0] + 1, SIZE_OF_REGISTER);
    if(temp_c != 0){
        temp_b = mik->machineRegister[args[1]];
        mik->machineRegister[args[0]] = temp_b / temp_c;
        mik->machineRegister[next_index] = temp_b % temp_c;
    }
}

void push(Mik8Machine *mik, int *args)
{
    --mik->machineRegister[args[0]];
    mik->machineRegister[args[0]] = mod(mik->machineRegister[args[0]], SIZE_OF_MEMORY);
    mik->machineMemory[mik->machineRegister[args[0]]] = mik->machineRegister[args[1]];
}

void halt(Mik8Machine *mik, int *args)
{
    exit(mik->machineRegister[args[0]]);
}

/*1*/
void returnFunction(Mik8Machine *mik, int *args)
{
    int temp_c = mik->currentInstruction;
    mik->currentInstruction = mik->machineMemory[mik->machineRegister[args[0]]];
    mik->machineRegister[args[0]] =
            mod(mik->machineRegister[args[0]] + mik->machineRegister[args[2]] + 1,
                SIZE_OF_MEMORY);

    mik->machineRegister[args[1]] = temp_c;
}

void pop(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[1]] = mik->machineMemory[mik->machineRegister[args[0]]];
    mik->machineRegister[args[0]] += 1;
    mik->machineRegister[args[0]] = mod(mik->machineRegister[args[0]], SIZE_OF_MEMORY);
}

void return_from_subroutine(Mik8Machine *mik, int *args)
{
    int temp_c = mik->currentInstruction;
    mik->currentInstruction = mik->machineRegister[args[2]];
    mik->machineRegister[args[0]] = temp_c;
}

/*2*/
void compare(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] = (mik->machineRegister[args[1]]
                              < mik->machineRegister[args[2]]) ? 1 : 0;
}

void shiftLeft(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] = mik->machineRegister[args[1]] << 1;
    mik->machineRegister[args[0]] = mod(mik->machineRegister[args[0]], SIZE_OF_MEMORY);
}

/*3*/
void subtract(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] =
            mod(mik->machineRegister[args[1]] - mik->machineRegister[args[2]], SIZE_OF_MEMORY);
}

void shiftRight(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] = mik->machineRegister[args[1]] >> 1;
}

/*4*/
void loadIndexed(Mik8Machine *mik, int *args)
{
    int index = mod(mik->machineRegister[args[1]] + mik->machineRegister[args[2]],
                    SIZE_OF_MEMORY);
    mik->machineRegister[args[0]] = mik->machineMemory[index];
}

void add(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] = mod(mik->machineRegister[args[1]] +
                                 mik->machineRegister[args[2]], SIZE_OF_MEMORY);
}

/*5*/
void storeIndexed(Mik8Machine *mik, int *args)
{
    int index = mod(mik->machineRegister[args[1]] + mik->machineRegister[args[2]],
                    SIZE_OF_MEMORY);
    mik->machineMemory[index] = mik->machineRegister[args[0]];
}

void bitwiseOr(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] = mik->machineRegister[args[1]] | mik->machineRegister[args[2]];
}

/*6*/
void multiply(Mik8Machine *mik, int *args)
{
    int temp = mik->machineRegister[args[1]] * mik->machineRegister[args[2]];
    int index_next = mod(args[0] + 1, SIZE_OF_REGISTER);
    mik->machineRegister[args[0]] = temp % SIZE_OF_MEMORY;
    mik->machineRegister[index_next] = temp / SIZE_OF_MEMORY;
}

void bitwiseAnd(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] = mik->machineRegister[args[1]] & mik->machineRegister[args[2]];
}

/*7*/
void callIndexed(Mik8Machine *mik, int *args)
{
    int temp_pc = mik->currentInstruction;
    mik->currentInstruction = mod(mik->machineMemory[mik->machineRegister[args[1]] + mik->machineRegister[args[2]]], SIZE_OF_MEMORY);
    mik->machineRegister[args[0]] = temp_pc;
}

void bitwiseExclusiveOr(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] = mik->machineRegister[args[1]] ^ mik->machineRegister[args[2]];
}

/*8*/
void jumpIfZero(Mik8Machine *mik, int *args)
{
    if(mik->machineRegister[args[0]] == 0)
        mik->currentInstruction = args[1] * SIZE_OF_REGISTER + args[2];
}

/*9*/
void jumpIfNotZero(Mik8Machine *mik, int *args)
{
    if(mik->machineRegister[args[0]] != 0)
        mik->currentInstruction = args[1] * SIZE_OF_REGISTER + args[2];
}

/*10*/
void callSubroutine(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] = mik->currentInstruction;
    mik->currentInstruction = args[1] * SIZE_OF_REGISTER + args[2];
}

/*11*/
void call(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] = mod(--mik->machineRegister[args[0]], SIZE_OF_MEMORY);
    mik->machineMemory[mik->machineRegister[args[0]]] = mik->currentInstruction;
    mik->currentInstruction = args[1] * SIZE_OF_REGISTER + args[2];
}

/*12*/
void loadRegister(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] = mik->machineMemory[args[1] * SIZE_OF_REGISTER + args[2]];
}

/*13*/
void storeRegister(Mik8Machine *mik, int *args)
{
    mik->machineMemory[args[1] * SIZE_OF_REGISTER + args[2]] =
            mik->machineRegister[args[0]];
}

/*14*/
void loadConstant(Mik8Machine *mik, int *args)
{
    mik->machineRegister[args[0]] = args[1] * SIZE_OF_REGISTER + args[2];
}

/*15*/
void systemCall(Mik8Machine *mik, int *args)
{
    int bc = args[1] * SIZE_OF_REGISTER + args[2];
    int temp_a;
    int next_index = mod(args[0] + 1, SIZE_OF_REGISTER);
    switch(bc){

        case CORE_DUMP: /* 0 */
            temp_a = mik->currentInstruction;
            mik->currentInstruction = args[0];
            coreDump(mik);
            mik->currentInstruction = temp_a;
            break;

        case GET_INT: /* 1 */
            if(scanf("%d", &temp_a) != 1) mik->machineRegister[next_index] = 0;
            else{
                mik->machineRegister[next_index] = 1;
                /*
                dokonanie operaacji mod jest konieczne bo wartosc
                moze byc z poza zakresu [0:255]
                */
                mik->machineRegister[args[0]] = mod(temp_a, SIZE_OF_MEMORY);
            }
            break;

        case PUT_INT: /* 2 */
            printf("%d", mik->machineRegister[args[0]]);
            break;

        case GET_CHAR: /* 3 */
            temp_a = getchar();
            if(temp_a == EOF) mik->machineRegister[next_index] = 0;
            else{
                mik->machineRegister[next_index] = 1;
                mik->machineRegister[args[0]] = mod(temp_a, SIZE_OF_MEMORY);
            }
            break;

        case PUT_CHAR: /* 4 */
            putchar(mik->machineRegister[args[0]]);
            break;

        case PUT_STRING: /* 5 */
            showString(&mik->machineMemory[mik->machineRegister[args[0]]]);
            break;

        default:
            /*nic nie rób */
            break;
    }
}

/*This functions are implemented so that function pointers could be used*/
void function0(Mik8Machine *mik, int *args)
{
    if(args[1] != args[2]) divide(mik, args);
    else if(args[0] != args[1] && args[1] == args[2]) push(mik, args);
    else halt(mik, args);
}

void function1(Mik8Machine *mik, int *args)
{
    if(args[0] != args[1] && args[0] != args[2]) returnFunction(mik, args);
    else if(args[0] == args[1]) return_from_subroutine(mik, args);
    else pop(mik, args);
}

void function2(Mik8Machine *mik, int *args)
{
    if(args[1] != args[2]) compare(mik, args);
    else shiftLeft(mik, args);
}

void function3(Mik8Machine *mik, int *args)
{
    if(args[1] != args[2]) subtract(mik, args);
    else shiftRight(mik, args);
}

void function4(Mik8Machine *mik, int *args)
{
    if(args[1] <= args[2]) loadIndexed(mik, args);
    else add(mik, args);
}

void function5(Mik8Machine *mik, int *args)
{
    if(args[1] <= args[2]) storeIndexed(mik, args);
    else bitwiseOr(mik, args);
}

void function6(Mik8Machine *mik, int *args)
{
    if(args[1] <= args[2]) multiply(mik, args);
    else bitwiseAnd(mik, args);
}

void function7(Mik8Machine *mik, int *args)
{
    if(args[1] <= args[2]) callIndexed(mik, args);
    else bitwiseExclusiveOr(mik, args);
}

void getParameters(Mik8Machine *mik, int *f_code, int *args)
{
    *f_code = (mik->machineInstruction[mik->currentInstruction] >> 12);
    args[0] = (mik->machineInstruction[mik->currentInstruction] >> 8 & 15);
    args[1] = (mik->machineInstruction[mik->currentInstruction] >> 4 & 15);
    args[2] = (mik->machineInstruction[mik->currentInstruction] & 15);
}

void interpret(Mik8Machine *mik)
{
    int func, args[3] = {0};
    /*function array*/
    void (*functinons[SIZE_OF_REGISTER])(Mik8Machine*,int*)=
            {function0, function1, function2, function3, function4, function5,
             function6, function7, jumpIfZero, jumpIfNotZero,
             callSubroutine, call, loadRegister, storeRegister,
             loadConstant, systemCall};

    mik->currentInstruction = mod(mik->currentInstruction, SIZE_OF_MEMORY);
    /*works until halt*/
    while(true){
        getParameters(mik, &func, args);
        mik->currentInstruction = mod(mik->currentInstruction + 1, SIZE_OF_MEMORY);
        functinons[func](mik, args);
    }
}