
#include "_move.h"

map* _m = new map;
/*
void _move::Lstart()
{
		system("cls");
		cout << "게임을 시작하시겠습니까?" << endl;
		cout << "\t>Y / N \t ";
		return;
}

void _move::Rstart()
{
		system("cls");
		cout << "게임을 시작하시겠습니까?" << endl;
		cout << " \t Y / N<\t ";
		return;
}*/

void _move::gotOxy(int x, int y)
{
	HANDLE consolHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consolHandle, pos);
}

int _move::keyboard()
{
	char temp = _getch();

	if (temp == 'W' || temp == 'w')
	{
		return UP;
	}
	else if (temp == 'A' || temp == 'a')
	{
		return LEFT;
	}
	else if (temp == 'S' || temp == 's')
	{
		return DOWN;
	}
	else if (temp == 'D' || temp == 'd')
	{
		return RIGHT;
	}
	else if (temp == ' ')
	{
		return ACTIVITY;
	}
	else if (temp == '/')
	{
		return BACK;
	}
	else
	{
		keyboard();
	}
}



_move::_move()
{
}


_move::~_move()
{
}
