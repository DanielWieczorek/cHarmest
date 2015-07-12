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

char errorMessageExpected[] = "Assert Failed. expected: ";
char errorMessageActual[] = " but was: ";

void assertString(char* file, unsigned int line){
	char* message = buildMessageFromList();
	CU_assertImplementation(result, line, message, file, "", CU_FALSE);
	free(message);
	clearMessageList();
}
void assertInteger(char* file, unsigned int line){
	char* message = buildMessageFromList();
	CU_assertImplementation(result, line, message, file, "", CU_FALSE);
	free(message);
	clearMessageList();
}
void assertPointer(char* file, unsigned int line){
	char* message = buildMessageFromList();
	CU_assertImplementation(result, line, message, file, "", CU_FALSE);
	free(message);
	clearMessageList();
}
