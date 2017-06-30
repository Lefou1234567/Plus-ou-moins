#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "text.h"
#include "answer.h"

int mainMenu() {

	printMainMenu();
	

	return 0;
}

int printMainMenu() {
	
	printMenuSeparator(10);
	printMenuChoice("Nouvelle Partie", 1);
	printMenuChoice("Parametres", 2);
	printMenuChoice("Quitter", 3);
	printMenuSeparator(10);
	return 0;
}
