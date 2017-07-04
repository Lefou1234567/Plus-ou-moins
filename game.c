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

	setSecretNumber(&secretNumber, difficult);

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
