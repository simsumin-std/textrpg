#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#include "mainGame.h"

using namespace std;
map* m0 = new map;
_move* m = new _move;

int mainGame::gameStart()
{
	char selectC = ' ';
	int selectI = 0;
	int i = 0;
	int j = 0;
	system("mode con cols = 50 lines = 40");

	while (1)
	{
		showTitle();
		selectI = showMenu();
		system("cls");


		//게임 시작
		if (selectI == 0)
		{
			while (1)
			{
				m0->showMap();
				//m0->mapLoop(0);
				Sleep(1000);
			}
		}
		//게임 정보
		else if (selectI == 1)
		{
			showInfo();
		}
		else if (selectI == 2)
		{
			cout << "종료합니다" << endl;
			break;
		}
		system("cls");
	}
	
	/*
	int select = _getch(); // 엔터를 누르면

	cout << select << endl; // \r 에 해당하는 13 이 출력됩니다.
	//4:52 5:53 6:54 8: 56
	*/
	return 0;
}

int mainGame::showMenu()
{

	
	int x = 15;
	int y = 15;
	m->gotOxy(x - 2, y);
	cout << "> 게임 시작";
	m->gotOxy(x, y+1);
	cout << "게임 정보";
	m->gotOxy(x, y+2);
	cout << "게임 종료";
	while (1)
	{

		int temp = m->keyboard();
		if (temp == 0)
		{
			if (y > 15)
			{
				m->gotOxy(x - 2, y);
				cout << " ";
				m->gotOxy(x - 2, --y);
				cout << ">";
			}
		}
		else if (temp == 2)
		{
			if (y < 17)
			{
				m->gotOxy(x - 2, y);
				cout << " ";
				m->gotOxy(x - 2, ++y);
				cout << ">";
			}
		}
		else if (temp == 4)
		{
			return y - 15;
			break;
		}
	}
}

void mainGame::showTitle()
{
	system("cls");
	m->gotOxy(10, 10);
	cout << "┌─┐ │ ├─┤│ └┬─  ─┐ │ 로　그  　!" << endl;
	m->gotOxy(10, 11);
	cout << "└─┘ ├ └─┘│ ─┴─    │ │ 라  이  크!" << endl;
}

void mainGame::showInfo()
{
	system("cls");
	cout << endl << endl;
	cout << "\t\t [조작법]" << endl;
	cout << "\t\t 이동 : W, A, S, D" << endl;
	cout << "\t\t 선택/활동 : SPACE바" << endl;
	cout << "\t\t 메뉴/취소 : /(?키)" << endl << endl;

	cout << "\t\t 광산 : 철광석은 체력 1소모, 금광석은 체력 2소모" <<endl << "기본곡괭이 : 철광석 50%, 마법곡괭이 : 철광석 100%, 금광석 50%" << endl;
	cout << "\t\t 전투 : 자동배틀, 자신의 상태를 잘 알고 싸우자!" << endl;
	cout << "\t\t tip: 장비는 제일 좋은 것으로 착용됩니다" << endl;
	cout << "\t\t tip: 그러나 방어구는 이름이 중복이 아니라면 겹쳐입기가 가능합니다!" << endl;

	
	//게임 설명
	cout << "메인메뉴로 가시려면 취소키를 누르세요." << endl;

	while (1)
	{
		if (m->keyboard() == BACK)
		{
			break;
		}
	}
}






mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}
