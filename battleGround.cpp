#include "battleGround.h"

shop* sp;

void battleGround::fighter(player* p, monster* m)
{
	_p = p;
	_m = m;

	_p->Appear();
	cout << endl;
	_m->Appear();
	cout << endl << endl;
}

void battleGround::fight()
{

	int temp = 0;
	system("cls");
	_m->Appear();
	cout << endl;
	cout << "������ �����մϴ�." << endl << endl;
	_p->Appear();
	cout << endl;
	cout << endl;
	if (sp->checkSword() == 1)
	{
		temp = _p->GetAtk() + 5;
	}
	else if (sp->checkSword() == 2)
	{
		temp = _p->GetAtk() + 15;
	}
	else if (sp->checkSword() == 3)
	{
		temp = _p->GetAtk() + 50;
	}
	else if (sp->checkSword() == 4)
	{
		temp = _p->GetAtk() + 100;
	}
	else
	{
		temp = _p->GetAtk();
	}
	Sleep(1000);
	while (1)
	{
		int r = rand() % 10;

		cout << "�÷��̾��� ����!" << endl;
		_m->hitDamage(temp);
		if (_p->GetBetterAtk() == 2)
		{
			if (_p->GetPowerAtk() == 2)
			{
				cout << "�÷��̾��� �������!" << endl;
				_m->hitDamage(temp);
				Sleep(500);
			}
			else if (r < 4)
			{
				cout << "�÷��̾��� �쿬�� ���Ӱ���!" << endl;
				_m->hitDamage(temp); 
				Sleep(500);
			}
		}
		cout << "������ ���� ü��: " << _m->GetHp() << endl;
		cout << endl;
		if (_m->GetHp() < 1)
		{
			cout << "���Ϳ��Լ� �¸��߽��ϴ�!" << endl;
			break;
		}
		Sleep(1000);


		cout << "������ ����!" << endl;
		_p->hitDamage(_m->GetAtk());
		cout << "�÷��̾��� ���� ü��: " << _p->GetHp() << endl;
		cout << endl;
		if (_p->GetHp() < 1)
		{
			cout << "���Ϳ��� ���߽��ϴ�!" << endl;
			break;
		}
		Sleep(1000);
	}
	if (_m->GetHp() < 1)
	{
		cout << "������ ����ǰ�� ŉ��!" << endl;
		cout << _m->GetExp() << "�� ����ġ�� " << _m->GetGold() << "�� ���� �����!" << endl << endl;
		Sleep(2000);
		system("cls");
		_m->SetHp(_m->GetFullHp());
	}

}

battleGround::battleGround()
{
}


battleGround::~battleGround()
{
}
