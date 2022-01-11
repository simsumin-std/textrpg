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


		//���� ����
		if (selectI == 0)
		{
			while (1)
			{
				m0->showMap();
				//m0->mapLoop(0);
				Sleep(1000);
			}
		}
		//���� ����
		else if (selectI == 1)
		{
			showInfo();
		}
		else if (selectI == 2)
		{
			cout << "�����մϴ�" << endl;
			break;
		}
		system("cls");
	}
	
	/*
	int select = _getch(); // ���͸� ������

	cout << select << endl; // \r �� �ش��ϴ� 13 �� ��µ˴ϴ�.
	//4:52 5:53 6:54 8: 56
	*/
	return 0;
}

int mainGame::showMenu()
{

	
	int x = 15;
	int y = 15;
	m->gotOxy(x - 2, y);
	cout << "> ���� ����";
	m->gotOxy(x, y+1);
	cout << "���� ����";
	m->gotOxy(x, y+2);
	cout << "���� ����";
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
	cout << "������ �� �������� ������  ���� �� �Ρ���  ��!" << endl;
	m->gotOxy(10, 11);
	cout << "������ �� �������� ������    �� �� ��  ��  ũ!" << endl;
}

void mainGame::showInfo()
{
	system("cls");
	cout << endl << endl;
	cout << "\t\t [���۹�]" << endl;
	cout << "\t\t �̵� : W, A, S, D" << endl;
	cout << "\t\t ����/Ȱ�� : SPACE��" << endl;
	cout << "\t\t �޴�/��� : /(?Ű)" << endl << endl;

	cout << "\t\t ���� : ö������ ü�� 1�Ҹ�, �ݱ����� ü�� 2�Ҹ�" <<endl << "�⺻��� : ö���� 50%, ������� : ö���� 100%, �ݱ��� 50%" << endl;
	cout << "\t\t ���� : �ڵ���Ʋ, �ڽ��� ���¸� �� �˰� �ο���!" << endl;
	cout << "\t\t tip: ���� ���� ���� ������ ����˴ϴ�" << endl;
	cout << "\t\t tip: �׷��� ���� �̸��� �ߺ��� �ƴ϶�� �����ԱⰡ �����մϴ�!" << endl;

	
	//���� ����
	cout << "���θ޴��� ���÷��� ���Ű�� ��������." << endl;

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
