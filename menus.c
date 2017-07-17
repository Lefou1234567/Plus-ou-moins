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

		printMainMenu();
		printErrorWrongChoice(choice);
		
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

		printDifficultMenu();
		printErrorWrongChoice(choice);
		
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
	
		printLevelMenu();
		printErrorWrongChoice(choice);
	
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

int endingMenu(const int isGameWon, const int difficult, const int level) {

	int choice = 0;

	printEndingMenu(isGameWon);
	choiceEndingMenu(&choice, isGameWon);
	endingMenuGoTo(choice, difficult, level, isGameWon);

	return 0;

}

int choiceEndingMenu(int* choice, const int isGameWon) {

	do {

		scanInteger(choice);	

	} while(!isChoiceEndingMenuRight(*choice, isGameWon));

	return 0;

}

int isChoiceEndingMenuRight(const int choice, const int isGameWon) {

	if(isGameWon) {
		
		if(choice >= 1 && choice <= 3)
			return 1;	
	
	} else {  
		
		if(choice >= 1 && choice <= 4)
			return 1;
	
	}

	printEndingMenu(isGameWon);
	printErrorWrongChoice(choice);

	return 0;

}

int endingMenuGoTo(const int choice, const int difficult, const int level, const int isGameWon) {

	if(isGameWon)
		endingMenuGoToIsGameWon(choice, difficult, level);

	else 
		endingMenuGoToIsNotGameWon(choice, difficult, level);

	return 0;

}

int endingMenuGoToIsGameWon(const int choice, const int difficult, const int level) {

	switch(choice) {

		case 1:
			difficultMenu();
			break;
		case 2:
			levelMenu(difficult);
			break;
		case 3:
			mainMenu();
			break;
		default :
			printErrorWrongChoice(choice);
			
			return 1;

		}


	return 0;

}

int endingMenuGoToIsNotGameWon(const int choice, const int difficult, const int level) {

	switch(choice) {
	
		case 1: 
			startStage(difficult, level);
			break;
		case 2:
			difficultMenu();
			break;
		case 3: 
			levelMenu(difficult);
			break;
		case 4:
			mainMenu();
			break;
		default:
			printErrorWrongChoice(choice);
				
			return 1;

		}


	return 0;

}

