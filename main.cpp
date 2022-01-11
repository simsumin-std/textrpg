#include <iostream>

#include "mainGame.h"

using namespace std;

int main()
{
	mainGame* mg = new mainGame;
	mg->gameStart();
	delete mg;

	return 0;
}