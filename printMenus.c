#include <stdio.h>
#include <stdlib.h>
#include "printMenus.h"
#include "text.h"
#include "error.h"

int printMainMenu() {
	int lengthOfSeparators = 18;
	int choiceNumber = 1;

	printFirstMenuSeparator(lengthOfSeparators);
	printMenuChoice("Nouvelle Partie", choiceNumber++);
	printMenuChoice("Quitter", choiceNumber++);
	printLastMenuSeparator(lengthOfSeparators);

	return 0;
}

int printDifficultMenu() {
	int lengthOfSeparators = 35;
	int choiceNumber = 1;

	printFirstMenuSeparator(lengthOfSeparators);
	printMenuChoice("Facile \t: entre 0 et 100.", choiceNumber++);
	printMenuChoice("Moyen \t: entre 0 et 1000.", choiceNumber++);
	printMenuChoice("Difficile \t: entre 0 et 10000.", choiceNumber++);
	printMenuChoiceCancel(choiceNumber++);
	printLastMenuSeparator(lengthOfSeparators);
	
	return 0;
}

int printLevelMenu() {
	int lengthOfSeparators = 39;
	int choiceNumber = 1;

	printFirstMenuSeparator(lengthOfSeparators);
	printMenuChoice("Entrainement \t: essaies illimites.", choiceNumber++);
	printMenuChoice("Niveau * \t: essaies limites a 20.", choiceNumber++);
	printMenuChoice("Niveau ** \t: essaies limites a 15.", choiceNumber++);
	printMenuChoice("Niveau *** \t: essaies limites a 10.", choiceNumber++);
	printMenuChoice("Niveau **** \t: essaies limites a 5.", choiceNumber++);
	printMenuChoiceCancel(choiceNumber++);
	printLastMenuSeparator(lengthOfSeparators);
	
	return 0;
}

int printFirstMenuSeparator(int numberOfCaracteres) {
	printf("\n\n");

	for(int i = 0; i < numberOfCaracteres; i++)
		printf("#");
	printf("\n");

	return 0; 
}

int printLastMenuSeparator(int numberOfCaracteres) {

	for(int i = 0; i < numberOfCaracteres; i++)
		printf("#");
	printf("\n\n");

	return 0;
}

int printMenuChoiceCancel(const int choiceNumber) {

	printf("\n");
	printMenuChoice("Retour", choiceNumber);

	return 0;
}

int printMenuChoice(char* text, const int number) {

	printf("%d.%s\n", number, text);

	return 0;
}

