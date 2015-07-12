/*
 * message.h
 *
 *  Created on: Jul 12, 2015
 *      Author: DWI
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_
#include "global.h"

char* buildMessage(char* function, char* desired, char* actual, bool equal);
void addMessageToList(char* message);
void clearMessageList(void);
char* buildMessageFromList();
#endif /* MESSAGE_H_ */
