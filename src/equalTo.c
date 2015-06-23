/*
 * equalTo.c
 *
 *  Created on: Jun 23, 2015
 *      Author: DWI
 */
#include "equalTo.h"
#include <string.h>

bool integerequalTo(int input){
	storeDesiredInteger(input);
	result = actualInt == input;
	return result;
}
bool pointerequalTo(void* input){
	storeDesiredPointer(input);
	result = actualPointer == input;
	return result;
}


bool stringequalTo(char* input){
	storeDesiredString(input);
	result = !strcmp(actualString, input);
	return result;
}
