#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "menus.h"
#include "text.h"
#include "answer.h"
#include "error.h"

int main(int argc, char *argv[]) {

	printTitle1("Bienvenue dans le jeu du plus ou du moins !");
	startGame();
	printEndingMessage();
	return 0;
}
