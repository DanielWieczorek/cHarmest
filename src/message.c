/*
 * message.c
 *
 *  Created on: Jul 12, 2015
 *      Author: DWI
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "message.h"

char* concat(const char* first, const char* second);
size_t getStringLength(const char* string);
char* concatAll(const uint32_t num, ...);

typedef struct node {
    char* message;
    struct node* next;
} Node;

Node* list = NULL;
void appendNodeToList(Node* newNode);
void addMessageToList(char* message){
	Node* newNode = calloc(sizeof(Node),1);
	newNode->message = message;
	appendNodeToList(newNode);
}
void clearMessageList(void){
	Node* previousNode = NULL;
	Node* currentNode = list;
	while(currentNode){
		previousNode = currentNode;
		currentNode = currentNode ->next;
		if(previousNode){
			free(previousNode->message);
			previousNode->next = NULL;
			free(previousNode);
		}
	}
	list = NULL;
}
char* buildMessageFromList(){
	char* message = NULL;
	char* messageTemp = NULL;
	Node* currentNode = list;

	while(currentNode){

		messageTemp = concatAll(3,message, currentNode->message,"\n");
		if (message)
			free(message);
		message = messageTemp;

		currentNode = currentNode -> next;
	}

	return message;
}

void appendNodeToList(Node* newNode){
	Node* lastNode = list;
	while(lastNode && lastNode->next)
		lastNode = lastNode ->next;
	if(lastNode)
		lastNode->next = newNode;
	else
		list = newNode;
}

char* buildMessage(char* function, char* desired, char* actual, bool equal){
	size_t stringSize = strlen(function)+2+strlen(desired)+4+strlen(actual)+1;
	char* result = calloc(stringSize,1);
	if(equal == true)
		sprintf(result,"%s: %s == %s",function, desired, actual);
	else
		sprintf(result,"%s: %s != %s",function, desired, actual);
	return result;
}


/**
 * @brief concatenates the first num strings (char *) that are given via the parameter list.
 *
 * A string at a new address will be returned. So an assignment will be necessary.
 * the given number is expected to be correct. Errors or crashes may occur otherwise.
 * If strings are NULL they are ignored
 *
 * @param num number of strings to concatenate
 * @param ... the list of strings
 *
 * @return a new pointer to the concatenation of the first num strings.
 */
char* concatAll(const uint32_t num, ...){
	va_list argp;
	char* result = NULL;
	char *temp = NULL;
	char *temp2 = NULL;
	unsigned int i = 0;
	va_start(argp, num);
	for(i=0;i<num;i++){
		temp = va_arg(argp, char *);
		temp2 = result;
		result = concat(result,temp);
		if(temp2)
			free(temp2);
	}
	va_end(argp);
	return result;
}

/**
 * @brief concatenates two strings (char *) that are given via the parameter list.
 *
 * A string at a new address will be returned. So an assignment will be necessary.
 * If one of the string is NULL it will be ignored.
 *
 * @param first string the result starts with
 * @param second string that is appended to first
 *
 * @return a new pointer to the concatenation of the first num strings. If parameters are null an empty string is returned. If the allocation of the memory fails NULL is returned.
 */
char* concat(const char* first, const char* second){
	int targetLen =  getStringLength(first) + getStringLength(second) + 1;
	char *target = calloc(targetLen,sizeof(char));
	if(target != NULL){
		if(first != NULL)
			strcat(target,first);
		if(second != NULL)
			strcat(target,second);
	}
	return target;
}

/**
 * @brief Wrapper for strlen that does not crash on NULL
 *
 * returns the result of strlen(string) if the input string is not null. 0 is returned otherwise.
 *
 * @param string the string the length is calculated of.
 * @returns 0 if the input is NULL, strlen(string) otherwise.
 *
 */
size_t getStringLength(const char* string){
	return string != NULL ? strlen(string) : 0;
}
