#pragma once
#include <iostream>
#include <string>

using namespace std;
class monster
{
private:

	int _hp;
	int _fullhp;
	string _name;
	int _exp;
	int _gold;
	int _atk;
public:
	inline string GetName() { return _name; };
	inline void SetName(string v) { _name = v; };
	inline int GetAtk() { return _atk; };
	inline void SetAtk(int v) { _atk = v; };
	inline int GetHp() { return _hp; };
	inline void SetHp(int v) { _hp = v; };
	inline int GetFullHp() { return _fullhp; };
	inline void SetFullHp(int v) { _fullhp = v; };
	inline int GetExp() { return _exp; };
	inline void SetExp(int v) { _exp = v; };
	inline int GetGold() { return _gold; };
	inline void SetGold(int v) { _gold = v; };

	void Appear();
	void hitDamage(int dmg);
	void Die(string name);

	monster();
	~monster();
};

