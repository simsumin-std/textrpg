#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#include "map.h"

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3
#define ACTIVITY 4
#define BACK 5

using namespace std;

class _move
{
public:
	//void Lstart();
	//void Rstart();
	void gotOxy(int, int);
	int keyboard();


	_move();
	~_move();
};

