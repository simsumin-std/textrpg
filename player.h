#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "shop.h"

using namespace std;

class player
{
	int Hp;
	int maxHp;
	int Mp;
	int maxMp;
	int exp;
	int lev;
	int atk;
	int skillPoint;
	int betterPick;
	int powerPick;
	int betterHp;
	int powerHp;
	int betterAtk;
	int powerAtk;
	int betterStamina;
	int powerStamina;
public:
	void checkStat();
	void HpFull();
	void Appear();
	void hitDamage(int dmg);

	
	
	int GetExp() { return exp; }
	int GetSkillPoint() { return skillPoint; }
	int GetHp() { return Hp; }
	int GetmaxHp() { return maxHp; }
	int GetMp() { return Mp; }
	int GetmaxMp() { return maxMp; }
	int GetLev() { return lev; }
	int GetAtk() { return atk; }
	int GetBetterPick() { return betterPick; }
	int GetPowerPick() { return powerPick; }
	int GetBetterHp() { return betterHp ; }
	int GetPowerHp() { return powerHp ; }
	int GetBetterAtk() { return betterAtk ; }
	int GetPowerAtk() { return powerAtk ; }
	int GetBetterStamina() { return betterStamina ; }
	int GetPowerStamina() { return powerStamina ; }

	void SetBetterPick(int n) { betterPick = n; }
	void SetPowerPick(int n) { powerPick = n; }
	void SetBetterHp(int n) { betterHp = n; }
	void SetPowerHp(int n) { powerHp = n; }
	void SetBetterAtk(int n) { betterAtk = n; }
	void SetPowerAtk(int n) { powerAtk = n; }
	void SetBetterStamina(int n) { betterStamina = n; }
	void SetPowerStamina(int n) { powerStamina = n; }
	void SetExp(int n) { exp += n; }
	void SetSkillPoint(int n) { skillPoint += n; }
	void SetHp(int n) { Hp -= n; }
	void SetMaxHp(int n) { maxHp += n; }
	void SetHpFull() { Hp = maxHp; }
	void SetMp(int n) { Mp -= n; }
	void SetMaxMp(int n) { maxMp += n; }
	void SetMpFull() { Mp = maxMp; }
	void SetLev(int n) { lev = n; }
	void SetAtk(int n) { atk = n; }



	player();
	~player();
};

