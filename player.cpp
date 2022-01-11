#include "player.h"



void player::checkStat()
{

		if (GetExp() > (((GetLev() + 2) * 10)/2)-1)
		{
			SetExp(-(((GetLev() + 2) * 10) / 2));
			SetLev(GetLev() + 1);
			if (GetLev() % 2 == 0)
			{
				SetSkillPoint(1);
				SetMaxMp(5);
			}
			SetMaxHp(5);
			SetHpFull();
			SetMpFull();
		}
	

	cout << "레벨: " << GetLev() << endl;
	cout << "경험치: " << GetExp() << "/"<< ((GetLev() + 2) * 10) / 2 << endl;
	cout << "체력: " << GetHp() << "/" << GetmaxHp() << endl;
	cout << "마나: " << GetMp() << "/" << GetmaxMp() << endl;
	
}

void player::HpFull()
{
	SetHpFull();
}

void player::Appear()
{
	cout << "플레이어의 스탯창" << endl;
	cout << "레벨: " << GetLev() << endl;
	cout << "경험치: " << GetExp() << "/" << ((GetLev() + 2) * 10) / 2 << endl;
	cout << "체력: " << GetHp() << "/" << GetmaxHp() << endl;
	cout << "마나: " << GetMp() << "/" << GetmaxMp() << endl;

}

void player::hitDamage(int dmg)
{
	Hp -= dmg;
	cout << "플레이어가 " << dmg << "만큼 데미지를 입었다" << endl;
}




player::player()
{
	Mp = 10;
	Hp = 10;
	maxHp = 10;
	maxMp = 10;
	exp = 0;
	lev = 1;
	atk = 5;
	skillPoint = 0;
	betterPick = false;
	powerPick = false;
	betterHp = false;
	powerHp = false;
	betterAtk = false;
	powerAtk = false;
	betterStamina = false;
	powerStamina = false;
	
}


player::~player()
{
}
