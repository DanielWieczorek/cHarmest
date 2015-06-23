/*
 * assertThat.c
 *
 *  Created on: Jun 23, 2015
 *      Author: DWI
 */

#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "global.h"
#include "string.h"
#include "CUnit/Basic.h"

void assertString(){
	char errorMessageExpected[] = "Assert Failed. expected: ";
	char errorMessageActual[] = " but was: ";
	char* combinedMessage = calloc(strlen(errorMessageExpected) + strlen(errorMessageActual) + strlen(actualString) + strlen(desiredString), 1);
	sprintf(combinedMessage, "%s%s%s%s",errorMessageExpected, actualString, errorMessageActual, desiredString);
	CU_assertImplementation(result, __LINE__, combinedMessage, __FILE__, "", CU_FALSE);
	free(combinedMessage);
}
void assertInteger(){
	char errorMessageExpected[] = "Assert Failed. expected: ";
	char errorMessageActual[] = " but was: ";
	char* combinedMessage = calloc(strlen(errorMessageExpected) + strlen(errorMessageActual) + 100 + 100, 1);
	sprintf(combinedMessage, "%s%d%s%d",errorMessageExpected, actualInt, errorMessageActual, desiredInt);
	CU_assertImplementation(result, __LINE__, combinedMessage, __FILE__, "", CU_FALSE);
	free(combinedMessage);
}
void assertPointer(){
	char errorMessageExpected[] = "Assert Failed. expected: ";
	char errorMessageActual[] = " but was: ";
	char* combinedMessage = calloc(strlen(errorMessageExpected) + strlen(errorMessageActual) + 10 + 10, 1);
	sprintf(combinedMessage, "%s%p%s%p",errorMessageExpected, actualPointer, errorMessageActual, desiredPointer);
	CU_assertImplementation(result, __LINE__, combinedMessage, __FILE__, "", CU_FALSE);
	free(combinedMessage);
}
