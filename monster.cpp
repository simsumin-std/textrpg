#include "monster.h"



void monster::Appear()
{
	cout << GetName() << "��(��) �����ߴ�" << endl;
	cout << "ü��: " << GetHp() << endl;
	cout << "���ݷ�: " << GetAtk() << endl;

}

void monster::hitDamage(int dmg)
{
	_hp -= dmg;
	cout << "���Ͱ� " << dmg << "��ŭ �������� �Ծ���" << endl;
}

void monster::Die(string name)
{
	cout << name << "��/�� ����Ͽ���." << endl;
	cout << "����ġ: " << GetExp() << endl;
	cout << "��: " << GetGold() << endl;
}

monster::monster()
{
}


monster::~monster()
{
}
