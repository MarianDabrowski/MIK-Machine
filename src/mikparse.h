/**
 * Parsing input into as mik machine data and instructions
 */
#ifndef __MIKPARSE_H__
#define __MIKPARSE_H__

#include "mik.h"
#include "parsedexal.h"

/**
 * Parses the input and fills the mik machine, which is given as argument
 * @param mik8Machine
 */
void ParseInput(Mik8Machine *mik8Machine);

#endif /*__MIKPARSE_H__*/
