#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>

#include "item.h"
#include "iron.h"
#include "gold.h"
#include "normalSword.h"
#include "magicSword.h"
#include "fireSword.h"
#include "goldenSword.h"
#include "normalArmor.h"
#include "magicArmor.h"
#include "goldenArmor.h"
#include "normalhoe.h"
#include "normalpick.h"
#include "magicpick.h"
#include "map.h"

#include "player.h"
using namespace std;
class shop
{

public:
	void showShop();
	void showInven();
	int iniron();
	int ingold();
	int checkpick();
	int checkPick();
	void money(int num);
	void submoney(int num);
	int moneycheck(int num);
	int countIron(int num);
	void recall();
	int iMoney = 0;
	int checkSword();
	int checkArmor();
	vector<item*> itemIn;

	shop();
	~shop();
};

