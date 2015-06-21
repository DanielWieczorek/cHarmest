/*
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "CUnit/Basic.h"
typedef enum {
	false, true
} bool;

typedef char* string;
typedef int integer;
typedef void* pointer;

bool result = false;
char* prefix;

char* actualString;
int actualInt;
void* actualPointer;

char* desiredString;
int desiredInt;
void* desiredPointer;

bool result;

#define assertThat(input, matcher){\
	storeActual(input);\
	matcher;\
	charmestAssert(input);\
}


void storeDesiredString(char* input){
	desiredString = input;
}

void storeDesiredInteger(int input){
	desiredInt = input;
}

void storeDesiredPointer(void* input){
	desiredPointer = input;
}


bool stringequalTo(char* input){
	storeDesiredString(input);
	result = !strcmp(actualString, input);
	return result;
}
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

bool not(bool previousResult){
	result = !previousResult;
	return result;
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




#define equalTo(X) _Generic((X), \
        char*: stringequalTo, \
        int: integerequalTo, \
        default: pointerequalTo \
        )(X)

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

#define charmestAssert(X) _Generic((X),                \
                         char*: assertString, \
                         int: assertInteger, \
                         default: assertPointer \
                         )()

void test(void)
{
	char* string1 = "foo";
	char* string2 = "bar";

	assertThat( string1, not(equalTo(string1)));
	assertThat( string1, not(equalTo(string2)));
	assertThat( string1, equalTo(string1));
	assertThat( 11, equalTo(11));
	assertThat( 11, equalTo(13));
}

int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", NULL, NULL);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if (NULL == CU_add_test(pSuite, "test()", test))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
