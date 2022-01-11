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
	cout << "전투를 시작합니다." << endl << endl;
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

		cout << "플레이어의 공격!" << endl;
		_m->hitDamage(temp);
		if (_p->GetBetterAtk() == 2)
		{
			if (_p->GetPowerAtk() == 2)
			{
				cout << "플레이어의 더블어택!" << endl;
				_m->hitDamage(temp);
				Sleep(500);
			}
			else if (r < 4)
			{
				cout << "플레이어의 우연한 연속공격!" << endl;
				_m->hitDamage(temp); 
				Sleep(500);
			}
		}
		cout << "몬스터의 현재 체력: " << _m->GetHp() << endl;
		cout << endl;
		if (_m->GetHp() < 1)
		{
			cout << "몬스터에게서 승리했습니다!" << endl;
			break;
		}
		Sleep(1000);


		cout << "몬스터의 공격!" << endl;
		_p->hitDamage(_m->GetAtk());
		cout << "플레이어의 현재 체력: " << _p->GetHp() << endl;
		cout << endl;
		if (_p->GetHp() < 1)
		{
			cout << "몬스터에게 당했습니다!" << endl;
			break;
		}
		Sleep(1000);
	}
	if (_m->GetHp() < 1)
	{
		cout << "몬스터의 전리품을 흭득!" << endl;
		cout << _m->GetExp() << "의 경험치와 " << _m->GetGold() << "의 돈을 얻었다!" << endl << endl;
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
