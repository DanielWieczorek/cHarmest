/*
 * global.c
 *
 *  Created on: Jun 23, 2015
 *      Author: DWI
 */
#include "global.h"

 bool result;

 char* actualString;
 int actualInt;
 void* actualPointer;

 char* desiredString;
 int desiredInt;
 void* desiredPointer;

void storeDesiredString(char* input){
	desiredString = input;
}

void storeDesiredInteger(int input){
	desiredInt = input;
}

void storeDesiredPointer(void* input){
	desiredPointer = input;
}

void storeActualString(char* input){
	actualString = input;
}

void storeActualInteger(int input){
	actualInt = input;
}
void storeActualPointer(void* input){
	actualPointer = input;
}

void clearValues(){
	result = false;

	actualString = "";
	actualInt = 0;
	actualPointer = NULL;

	desiredString = "";
	desiredInt = 0;
	desiredPointer = NULL;
}
