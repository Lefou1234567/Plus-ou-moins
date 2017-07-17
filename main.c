#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "menus.h"
#include "text.h"
#include "answer.h"
#include "error.h"

int main(int argc, char *argv[]) {

	printFirstProgramSeparator();
	printBeginingMessage();
	startGame();
	printEndingMessage();
	printLastProgramSeparator();

	return 0;

}

