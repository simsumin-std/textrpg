#include "monster.h"



void monster::Appear()
{
	cout << GetName() << "가(이) 출현했다" << endl;
	cout << "체력: " << GetHp() << endl;
	cout << "공격력: " << GetAtk() << endl;

}

void monster::hitDamage(int dmg)
{
	_hp -= dmg;
	cout << "몬스터가 " << dmg << "만큼 데미지를 입었다" << endl;
}

void monster::Die(string name)
{
	cout << name << "가/이 사망하였다." << endl;
	cout << "경험치: " << GetExp() << endl;
	cout << "돈: " << GetGold() << endl;
}

monster::monster()
{
}


monster::~monster()
{
}
