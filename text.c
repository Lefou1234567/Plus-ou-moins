#include <stdio.h>
#include <stdlib.h>
#include "text.h"

int printTitle1(char* text) {

	printf("\n\t");
	printStars(5);
	printf("%s", text);
	printStars(5);
	printf("\n\n");	

	return 0;
}

int printStars(int numberOfStars) {

	for(int i = 0; i < numberOfStars; i++) 
		printf("*");

	return 0;
}

int printMenuSeparator(int numberOfCaracteres) {

	for(int i = 0; i < numberOfCaracteres; i++) 
		printf("#");
	printf("\n");
	return 0;

}

int printMenuChoice(char* text, int number) {

	printf("%d.%s\n", number, text);

	return 0;
}
