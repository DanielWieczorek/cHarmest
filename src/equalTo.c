/*
 * equalTo.c
 *
 *  Created on: Jun 23, 2015
 *      Author: DWI
 */
#include "equalTo.h"
#include <stdio.h>
#include <string.h>

bool integerequalTo(int input) {
	storeDesiredInteger(input);
	result = actualInt == desiredInt;
	char desiredIntegerString[100];
	char actualIntegerString[100];
	sprintf(desiredIntegerString,"%d", desiredInt);
	sprintf(actualIntegerString,"%d", actualInt);
	addMessageToList(
			buildMessage("equalTo()", desiredIntegerString,
					actualIntegerString, result));
	return result;
}
bool pointerequalTo(void* input) {
	storeDesiredPointer(input);
	result = actualPointer == desiredPointer;

	char desiredPointerString[100];
	char actualPointerString[100];
	sprintf(desiredPointerString,"%p", desiredPointer);
	sprintf(actualPointerString,"%p", actualPointer);
	addMessageToList(
			buildMessage("equalTo()", desiredPointerString,
					actualPointerString, result));
	return result;
}

bool stringequalTo(char* input) {
	storeDesiredString(input);
	result = !strcmp(actualString, desiredString);
	addMessageToList(
			buildMessage("equalTo()", desiredString, actualString, result));
	return result;
}
