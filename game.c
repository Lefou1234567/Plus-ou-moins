#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "menus.h"
#include "text.h"
#include "answer.h"
#include "error.h"

int startGame() {

	srand(time(NULL));
	mainMenu();
	
	return 0;

}

int startStage(const int difficult, const int level) {

	int secretNumber = 0;
	int maxTrysNumber = 0;
	int isUnlimitedTrys = 0;
	int trysNumber = 0;
	int answer = 0;
	int isSecretNumberBigger = 0;
	int isGameWon = 0;

	setGameVariables(&secretNumber, difficult, &isUnlimitedTrys, &maxTrysNumber, level);
	printFirstGameSeparator();

	do {

		printGameIndications(isSecretNumberBigger, trysNumber, maxTrysNumber, isUnlimitedTrys);
		updateVariables(&trysNumber, &answer, &isSecretNumberBigger, secretNumber);

	} while (isGamePlaying(answer, secretNumber, &isGameWon, isUnlimitedTrys, trysNumber, maxTrysNumber));
	
	printLastGameSeparator();
	printScore(isGameWon, difficult, level, trysNumber, secretNumber);
	endingMenu(isGameWon, difficult, level);
	
	return 0;

}

int setGameVariables(int* secretNumber, const int difficult, int* isUnlimitedTrys, int* maxTrysNumber, const int level) {

	setSecretNumber(secretNumber, difficult);
	setMaxTryNumber(isUnlimitedTrys, maxTrysNumber, level);
	
	return 0;

}

int setSecretNumber(int* secretNumber, const int difficult) {

	int maxNumber = 0;
	int minNumber = 0;

	setMaxNumber(&maxNumber, difficult);
	*secretNumber = (rand() % (maxNumber - minNumber + 1)) + minNumber;

	return 0;

}

int setMaxNumber(int* maxNumber, const int difficult) {
	
	switch (difficult) {

		case 1 :
			*maxNumber = 100;
			break;
		case 2 : 
			*maxNumber = 1000;
			break;
		case 3 : 	
			*maxNumber = 10000;
			break;
		default :
			errorValueDifficult();
			return 1;
	}

	return 0;

}

int setMaxTryNumber(int* isUnlimitedTrys, int* maxTrysNumber, const int level) {

	switch(level) {
	
		case 0 :
			*isUnlimitedTrys = 1;
			break;
		case 1 :
			*maxTrysNumber = 20;
			break;
		case 2 :
			*maxTrysNumber = 15;
			break;
		case 3 :
			*maxTrysNumber = 10;
			break;
		case 4 :
			*maxTrysNumber = 5;
			break;
		default :
			errorValueLevel();
	
			return 1;
	}
	
	return 0;

}

int isGamePlaying(const int answer, const int secretNumber, int* isGameWon, const int isUnlimitedTrys, const int trysNumber, const int maxTryNumber) {

	if(isAnswerRight(answer, secretNumber)) {
		
		*isGameWon = 1;	

		return 0;

	}
	
	
	if(areAllTrysUsed(trysNumber, maxTryNumber, isUnlimitedTrys)) {
	
		*isGameWon = 0;
	
		return 0;

	}


	return 1;

}

int isAnswerRight(const int answer, const int secretNumber) {

	if(answer == secretNumber)
		return 1;
	
	return 0;

}

int areAllTrysUsed(const int trysNumber, const int maxTryNumber, const int isUnlimitedTrys) {

	if(isUnlimitedTrys)
		return 0;
	else if(trysNumber < maxTryNumber)
		return 0;

	return 1;

}

int updateVariables(int* trysNumber, int* answer, int* isSecretNumberBigger, const int secretNumber) {

	scanInteger(answer);
	*trysNumber += 1;
	setIsBiggerVariable(isSecretNumberBigger, secretNumber, *answer);

	return 0;

}

int setIsBiggerVariable(int* isSecretNumberBigger, const int secretNumber, const int answer) {

	if(secretNumber < answer)
		*isSecretNumberBigger = 0;

	else
		*isSecretNumberBigger = 1;

	return 0;

}

