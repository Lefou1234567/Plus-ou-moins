#include <stdio.h>
#include <stdlib.h>
#include "text.h"
#include "error.h"

int printTitle1(char* text) {

	printf("\n\t");
	printStars(5);
	printf(" %s ", text);
	printStars(5);
	printf("\n\n");	

	return 0;
}

int printGameIndications(const int isSecretNumberBigger, const int numberOfTry, const int maxTry, const int isUnlimitedTry) {

	if(numberOfTry == 0) {
		printTitle1("Et le jeu commence !");
		printText("Essayez de trouver le nombre secret !");
	}

	else {
	
		if(isSecretNumberBigger)
			printText("C'est trop grand !");
		else
			printText("C'est trop petit !");
	
		printf("Ressayez !");
	
		if(isUnlimitedTry)
			printf(" (essai %d)\n", numberOfTry);
		else 
			printf(" (il reste %d essais)\n\n", maxTry - numberOfTry);
	}
	return 0;
}

int printText(char* text) {
	
	printf("\n%s\n\n", text);

}

int printStars(int numberOfStars) {

	for(int i = 0; i < numberOfStars; i++) 
		printf("*");

	return 0;
}

int printErrorWrongChoice(const int choice) {

	printf("\n%d n'est pas une reponse attendue !\n\n", choice);

	return 0;
}

int printEndingMessage() {
	
	printTitle1("Merci d'avoir joue !");
	return 0;
}

int printErrorVariable(char* variableName) {

	printError("", 0);
	printf("La valeur de \"%s\" n'est pas aux normes !\n", variableName);
}

int printError(char* error, int printLine) {
	
	printf("ERREUR : %s", error);
	
	if(printLine)
		printf("\n");

}
