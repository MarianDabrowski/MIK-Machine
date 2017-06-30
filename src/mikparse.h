//
// Created by marian on 6/29/17.
//

#ifndef MIK8_MIKPARSE_H
#define MIK8_MIKPARSE_H

#include "mik.h"
#include "parsedexal.h"

void FillInstuctionArray(Mik8Machine *mik8Machine, int *instruction);

void ParseInput(Mik8Machine *mik8Machine, int *instructions);

#endif //MIK8_MIKPARSE_H
