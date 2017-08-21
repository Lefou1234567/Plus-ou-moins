all: game.s
	echo "Compilation terminee !"

game.s: answer.o game.o main.o menus.o printMenus.o error.o text.o
	gcc answer.o game.o main.o menus.o printMenus.o error.o text.o -o game.s

answer.o: answer.c answer.h error.h
	gcc -c -O3 answer.c

game.o: game.c game.h menus.h text.h answer.h error.h
	gcc -c -O3 game.c

main.o: main.c game.h menus.h text.h answer.h error.h
	gcc -c -O3 main.c

menus.o: menus.c menus.h printMenus.h game.h text.h answer.h error.h
	gcc -c -O3 menus.c

printMenus.o: printMenus.c printMenus.h text.h error.h
	gcc -c -O3 printMenus.c

error.o: error.c error.h  text.h
	gcc -c -O3 error.c

text.o: text.c text.h error.h answer.h
	gcc -c -O3 text.c
	
clean: 
	rm *~; rm .*~
