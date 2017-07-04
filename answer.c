#include <stdio.h>
#include <stdlib.h>
#include "answer.h"
#include "error.h"

int scanInteger(int* integer) {
	
	printf("> ");
	scanf("%d", integer);
	
	return 0;	
}

int scanString(char* string) {

	printf("> ");
	scanf("%s", string);

	return 0;
}
