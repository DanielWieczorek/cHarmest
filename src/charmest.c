/*
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
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
bool result;

#define assertThat(input, matcher){\
	store(input);\
	matcher;\
	printf("%s\n", result ? "true" : "false");\
}




bool stringequalTo(char* input){
	result = !strcmp(actualString, input);
	return result;
}
bool integerequalTo(int input){
	result = actualInt == input;
	return result;
}
bool pointerequalTo(void* input){
	result = actualPointer == input;
	return result;
}

bool not(bool previousResult){
	result = !previousResult;
	return result;
}

void stringstore(char* input){
	actualString = input;
}

void integerstore(int input){
	actualInt = input;
}
void pointerstore(void* input){
	actualPointer = input;
}
#define equalTo(X) _Generic((X),                \
                         char*: stringequalTo, \
                         int: integerequalTo, \
                         default: pointerequalTo \
                         )(X)


#define store(X) _Generic((X),                \
                         char*: stringstore, \
                         int: integerstore, \
                         default: pointerstore \
                         )(X)

int main(void) {
	char* string1 = "foo";
	char* string2 = "bar";

	assertThat( string1, not(equalTo(string1)));
	assertThat( string1, not(equalTo(string2)));
	assertThat( string1, equalTo(string1));
	assertThat( 11, equalTo(11));
	assertThat( 11, equalTo(13));
	return EXIT_SUCCESS;
}
