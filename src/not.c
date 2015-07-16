/*
 * not.c
 *
 *  Created on: Jun 23, 2015
 *      Author: DWI
 */

#include "not.h"
#include <string.h>
#include <stdio.h>

bool not(bool previousResult) {
	result = !previousResult;

	char desiredBoolString[100];
	char actualBoolString[100];
	sprintf(desiredBoolString,"%s", previousResult ? "true" : "false");
	sprintf(actualBoolString,"%s", result ? "true" : "false");
	addMessageToList(
			buildMessage("not()", desiredBoolString, actualBoolString, result));

	return result;
}
