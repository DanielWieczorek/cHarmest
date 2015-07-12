/*
 * equalTo.h
 *
 *  Created on: Jun 23, 2015
 *      Author: DWI
 */

#ifndef EQUALTO_H_
#define EQUALTO_H_
#include "global.h"
#include "message.h"

#define equalTo(X) _Generic((X), \
        char*: stringequalTo, \
        int: integerequalTo, \
        default: pointerequalTo \
        )(X)

bool integerequalTo(int input);
bool pointerequalTo(void* input);
bool stringequalTo(char* input);

#endif /* EQUALTO_H_ */
