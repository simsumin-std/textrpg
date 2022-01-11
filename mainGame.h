#pragma once
#include "map.h"
#include "_move.h"

class mainGame
{
public:
	int gameStart();
	int showMenu();
	void showTitle();
	void showInfo();
	void showUi(int* x, int* y);
	mainGame();
	~mainGame();
};

