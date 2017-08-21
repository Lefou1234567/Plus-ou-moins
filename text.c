#include <stdio.h>
#include <stdlib.h>
#include "text.h"
#include "error.h"
#include "answer.h"

int printTitle1(char* text) {

	printf("\n\t\t");
	printStars(5);
	printf(" %s ", text);
	printStars(5);
	printf("\n\n");	

	return 0;

}

int printFirstProgramSeparator() {

	int numberOfSeparators = 85;

	printf("\n\n\n[");

	for(int i = 0; i < numberOfSeparators; i++) 
		printf("-");

	printf("]\n\n\n");

	return 0;

}

int printLastProgramSeparator() {

	int numberOfSeparators = 62;

	printf("\n\n[");

	for(int i = 0; i < numberOfSeparators; i++)
		printf("-");

	printf("]\n\n\n\n");

	return 0;

}

int printFirstGameSeparator() {

	int separatorLength = 67;
	int separatorHeight = 2;
	
	printf("\n\n");

	for(int i = 0; i < separatorHeight; i++) {
		
		for(int a = 0; a < separatorLength; a++) 
			printf("~");
		
		printf("\n");
	}
		
	printf("\n");
	
	return 0;

}

int printLastGameSeparator() {

	int separatorLength = 67;
	int separatorHeight = 2;
	
	printf("\n");

	for(int i = 0; i < separatorHeight; i++) {
		
		for(int a = 0; a < separatorLength; a++) 
			printf("~");
		
		printf("\n");
	}
	
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
			printText("C'est trop petit !");
		else
			printText("C'est trop grand !");
	
		printf("Reessayez !");
	
		if(isUnlimitedTry)
			printf(" (essai %d)\n\n", numberOfTry);
		else 
			printf(" (il reste %d essais)\n\n", maxTry - numberOfTry);
	}

	return 0;

}

int printText(char* text) {
	
	printf("\n%s\n\n", text);

	return 0;

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

int printBeginingMessage() {

	printf("\n\n");
	printTitle1("Bienvenue dans le jeu du plus ou du moins !");
	printf("\n\n");
	pause();

	return 0;

}

int printEndingMessage() {
	
	printTitle1("Merci d'avoir joue !");
	printf("\n\n");
	
	return 0;

}

int printErrorVariable(char* variableName) {

	printError("", 0);
	printf("La valeur de \"%s\" n'est pas aux normes !\n", variableName);

	return 0;

}

int printError(char* error, int printLine) {
	
	printf("ERREUR : %s", error);
	
	if(printLine)
		printf("\n");

	return 0;

}

int printScore(const int isGameWon, const int difficult, const int level, const int trysNumber, const int secretNumber) {

	if(isGameWon) {

		if(level == 0) {

			printText("Bravo !\nVous avez termine le mode entrainement\nN'hesitez pas a essayer avec un autre niveau !");
			printf("Nombre d'essais : %d\n\n", trysNumber);
		
		} else if(level == 4 && difficult == 3) {

			printText("Felicitations !\nVous avez termine le mode le plus dure du jeu !");
			printf("Nombre d'essais : %d !!!!\n\n", trysNumber);
		
		} else {
			
			printText("Bravo !\nVous avez gagne.\nPourquoi ne pas reessayer avec differents parametres ?");
			printf("Nombre d'essais : %d\n\n", trysNumber);
		}
	
	} else {

		printText("Dommage...\nVous avez use de tous vos essais...\nPourquoi ne pas reessayer ?");
		printf("Le nombre secret etait %d.\n\n", secretNumber);

	}

	pause();

	return 0;

}

int pause() {

	char pauseVariable[100];

	printText("Entrez un caractere pour continuer...");
	scanString(pauseVariable);
	
	return 0;

}

