/*
 * assertThat.h
 *
 *  Created on: Jun 23, 2015
 *      Author: DWI
 */

#ifndef ASSERTTHAT_H_
#define ASSERTTHAT_H_


#define assertThat(input, matcher){\
	storeActual(input);\
	matcher;\
	charmestAssert(input);\
}

#define assertThat(input, matcher){\
	storeActual(input);\
	matcher;\
	charmestAssert(input);\
}

#define charmestAssert(X) _Generic((X),                \
                         char*: assertString, \
                         int: assertInteger, \
                         default: assertPointer \
                         )()

void assertString();
void assertInteger();
void assertPointer();

#endif /* ASSERTTHAT_H_ */
