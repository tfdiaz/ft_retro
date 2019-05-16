#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <ctime>
#include "interfaces.hpp"
#include "Missile.hpp"
#include "player.hpp"

int	main()
{
	int 		direction;
	Interfaces* interfaces = new Interfaces(100, 30, 2, 15);
	initscr ();

	keypad (stdscr, TRUE);
	curs_set (0);
	noecho ();
	nodelay(stdscr,TRUE);
	srand (time(NULL));
	interfaces->startMessage();
	while ((direction = getch()) != 10)
	{
		if (direction== (int) 'q')
		{
			interfaces->setEnd(TRUE);
			break ;
		}
	}

	move(0, 0);
	erase();

	direction = 0;

	WINDOW	* gameWindow = newwin(30, 100, 1, 1);
	WINDOW	* infoWindow = newwin(5, 100, 32, 1);
	refresh();
	interfaces->gameWin(gameWindow);
	interfaces->infoWindow(infoWindow);
	interfaces->gameControl(gameWindow, infoWindow);
	erase();
	interfaces->endMessage();
	while ((direction = getch()) != 10)
	{
		if (direction == 10)
			break;
	}
	endwin();
	return (0);
}
