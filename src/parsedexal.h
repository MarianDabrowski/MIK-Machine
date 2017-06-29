//
// Created by marian on 6/29/17.
//

#ifndef MIK8_PARSEDEXAL_H
#define MIK8_PARSEDEXAL_H

#include "mik.h"

void FindValueAndBase(char ch, int *value, int *base);

int ParseNumber();

void FillArray(int *aray, int size);

static inline bool DexalNumberChar(char c)
{
    return ((c != SEPARATOR_SIGN) && (c != NEW_LINE_SIGN) &&
            (c != TAB_SIGN) && (c != BLANK_SPACE_SIGN) && (c != EOF));
}


#endif //MIK8_PARSEDEXAL_H
