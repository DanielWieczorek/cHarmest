/*
 * global.h
 *
 *  Created on: Jun 23, 2015
 *      Author: DWI
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_
#include "memwatch.h"
typedef enum {
	false, true
} bool;

typedef char* string;
typedef int integer;
typedef void* pointer;

extern bool result;
extern char* prefix;

extern char* actualString;
extern int actualInt;
extern void* actualPointer;

extern char* desiredString;
extern int desiredInt;
extern void* desiredPointer;


#define storeActual(X) _Generic((X),                \
                         char*: storeActualString, \
                         int: storeActualInteger, \
                         default: storeActualPointer \
                         )(X)

#define storeDesired(X) _Generic((X),                \
                         char*: storeDesiredString, \
                         int: storeDesiredInteger, \
                         default: storeDesiredPointer \
                         )(X)
void storeDesiredString(char* input);
void storeDesiredInteger(int input);
void storeDesiredPointer(void* input);
void storeActualString(char* input);
void storeActualInteger(int input);
void storeActualPointer(void* input);

#endif /* GLOBAL_H_ */
