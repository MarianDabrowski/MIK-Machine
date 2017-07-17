/**
 * Parsing dexal numbers into integers in form of numbers
 */
#ifndef __PARSEDEXAL_H__
#define __PARSEDEXAL_H__

#include "mik.h"

/**
 * Finds value and base for a given character value and stores their
 * values in pointers
 * @param ch
 * @param value
 * @param base
 */
void FindValueAndBase(char ch, int *value, int *base);

/**
 * Parses a number, if there was no number to be parsed it
 * provides this information in the boolean pointer
 * @param isNumber
 * @return parsed number
 */
int ParseNumber(bool *isNumber);

/**
 * Checks if a character value is a part of a dexal number
 * @param c
 * @return is it a part of a dexal number
 */
static inline bool DexalNumberChar(char c)
{
    return ((c != SEPARATOR_SIGN) && (c != NEW_LINE_SIGN) &&
            (c != TAB_SIGN) && (c != BLANK_SPACE_SIGN) && (c != EOF));
}

/**
 * Fills an array until it reaches a separator and returns the
 * number of elements it has filled
 * @param array
 * @param size
 * @param startingPosition
 * @return
 */
int FillUntilSeparator(int *array, int size, int startingPosition);

#endif /*__PARSEDEXAL_H__*/
