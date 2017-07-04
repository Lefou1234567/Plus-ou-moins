#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "printMenus.h"
#include "game.h"
#include "text.h"
#include "answer.h"
#include "error.h"

int mainMenu() {

	int choice = 0;

	printMainMenu();
	choiceMainMenu(&choice);
	mainMenuGoTo(choice);

	return 0;
}

int choiceMainMenu(int* choice) {
	
	do {
		scanInteger(choice);

	} while(!isChoiceMainMenuRight(*choice));
	
	printf("\n\n");

	return 0;
}

int isChoiceMainMenuRight(const int choice) {

	if(choice >= 1 && choice <= 2)
		return 1;
	else {
		printErrorWrongChoice(choice);
		printMainMenu();
		
		return 0;	
	}

} 

int mainMenuGoTo(const int choice) {

	if(!isChoiceMainMenuRight(choice)) {
		printErrorWrongChoice(choice);
		return 1;
	}

	if(choice == 1)
		difficultMenu();
	return 0;
}

int difficultMenu() {
	int choice = 0;	
	int difficult = 0;

	printDifficultMenu();
	choiceDifficultMenu(&choice);
	
	if(choice != 4)
		setDifficult(&difficult, choice);
	
	difficultMenuGoTo(difficult, choice);

	return 0;
}

int choiceDifficultMenu(int* choice) {
	
	do {
		scanInteger(choice);

	} while(!isChoiceDifficultMenuRight(*choice));

	printf("\n\n");

	return 0;
}

int isChoiceDifficultMenuRight(const int choice) {

	if(choice >= 1 && choice <= 4) 
		return 1;
	else {
		printErrorWrongChoice(choice);
		printDifficultMenu();
		
		return 0;
	}

}

int setDifficult(int* difficult, const int choice) {

	switch(choice) {
	
	case 1:
		*difficult = 1;
		break;
	case 2:
		*difficult = 2;
		break;
	case 3: 
		*difficult = 3;
		break;
	default :
		errorValueDifficult();

		return 1;
	}

	return 0;
}

int difficultMenuGoTo(const int difficult, const int choice) {

	if(choice == 4)
		mainMenu();
	else
		levelMenu(difficult);

	return 0;
}

int levelMenu(const int difficult) {
	int choice = 0;
	int level = 0;

	printLevelMenu();
	choiceLevelMenu(&choice);
	
	if(choice != 6)
		setLevel(&level, choice);

	levelMenuGoTo(difficult, level, choice);

	return 0;
}

int choiceLevelMenu(int* choice) {

	do {
		scanInteger(choice);

	} while(!isChoiceLevelMenuRight(*choice));

	printf("\n\n");	

	return 0;
}

int isChoiceLevelMenuRight(const int choice) {

	if(choice <= 6 && choice >= 1)
		return 1;
	else {
	
		printErrorWrongChoice(choice);
		printLevelMenu();
		return 0;
	}
}

int setLevel(int* level, const int choice) {
	
	switch (choice) {
	
	case 1 :
		*level = 0;
		break;
	case 2 :
		*level = 1;
		break;
	case 3 :
		*level = 2;
		break;
	case 4 :
		*level = 3;
		break;
	case 5 :
		*level = 4;
		break;
	default :
		errorValueLevel();	

		return 1;
	}

	return 0;
}

int levelMenuGoTo(const int difficult, const int level, const int choice) {

	if (choice == 6)
		difficultMenu();
	else 
		startStage(difficult, level);

	return 0;
}

