/*
 * assertThat.h
 *
 *  Created on: Jun 23, 2015
 *      Author: DWI
 */

#ifndef ASSERTTHAT_H_
#define ASSERTTHAT_H_
#include "message.h"

#define assertThat(input, matcher){\
	clearValues();\
	storeActual(input);\
	matcher;\
	charmestAssert(__FILE__,__LINE__);\
}


void charmestAssert(char* file, unsigned int line);

void assertString();
void assertInteger();
void assertPointer();

#endif /* ASSERTTHAT_H_ */
