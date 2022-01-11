#include "shop.h"

player* p = new player;
map* m = new map;
iron* ir = new iron;
gold* go = new gold;

normalSword* ns = new normalSword;
magicSword* ms = new magicSword;
fireSword* fs = new fireSword;
goldenSword* gs = new goldenSword;

normalArmor* na = new normalArmor;
magicArmor* ma = new magicArmor;
goldenArmor* ga = new goldenArmor;

normalhoe* nh = new normalhoe;
normalpick* np = new normalpick;
magicpick* mp = new magicpick;




void shop::showShop()
{
		
		int select = 0;
		bool inshop = true;
		int count = 0;
		vector<item*>::iterator iter;
		string same = "내복";
		string same1 = "기본갑옷";
		string same2 = "마법갑옷";

		while (inshop)
		{
			system("cls");
			iMoney = 10000;
			cout << "상점에 온걸 환영합니다." << endl << "어떤 종류로 구매하시겠습니까?" << endl << endl;
			cout << "소지금: " << iMoney << endl;
			cout << "1. 무기" << endl;
			cout << "2. 방어구" << endl;
			cout << "3. 도구" << endl;
			cout << "4. 판매" << endl;
			cout << "5.-------상점 나가기--------" << endl;

			cin >> select;
				if (select == 1)
				{
					system("cls");
					cout << "소지금: " << iMoney << endl;
					cout << "====무기====" << endl;
					cout << "1. " << ns->_name << ": " << ns->price << "원이며, 데미지는: " << ns->option << "입니다." << endl;
					cout << "2. " << ms->_name << ": " << ms->price << "원이며, 데미지는: " << ms->option << "입니다." << endl;
					cout << "3. " << fs->_name << ": " << fs->price << "원이며, 데미지는: " << fs->option << "입니다." << endl;
					cout << "4. " << gs->_name << ": " << gs->price << "원이며, 데미지는: " << gs->option << "입니다." << endl;
					cin >> select;
					if (select > 0 && select < 5)
					{
						if (select == 1 && iMoney >= ns->price)
						{
							if (ns->get == true)
							{
								cout << "이미 있는 장비입니다" << endl;
								Sleep(1000);
							}
							else
							{
								ns->get = true;
								iMoney -= ns->price;
								cout << "기본검 구입완료" << endl;
								
								Sleep(1000);
								itemIn.push_back(ns);
							}
						}
						else if (select == 2 && iMoney >= ms->price)
						{
							if (ms->get == true)
							{
								cout << "이미 있는 장비입니다" << endl;
								Sleep(1000);
							}
							else
							{
								ms->get = true;
								iMoney -= ms->price;
								cout << "마법검 구입완료" << endl;
								Sleep(1000);
								itemIn.push_back(ms);
							}
						}
						else if (select == 3 && iMoney >= fs->price)
						{
							if (fs->get == true)
							{
								cout << "이미 있는 장비입니다" << endl;
								Sleep(1000);
							}
							else
							{
								fs->get = true;
								iMoney -= fs->price;
								cout << "불의 검 구입완료" << endl;
								Sleep(1000);
								itemIn.push_back(fs);
							}
						}
						else if (select == 4 && iMoney >= gs->price)
						{
							if (gs->get == true)
							{
								cout << "이미 있는 장비입니다" << endl;
								Sleep(1000);
							}
							else
							{
								gs->get = true;
								iMoney -= gs->price;
								cout << "황금검 구입완료" << endl;
								Sleep(1000);
								itemIn.push_back(gs);
							}
						}
						else
						{
							cout << "돈이 부족합니다!" << endl;
							Sleep(1000);
						}
					}
				}
				else if (select == 2)
				{
					system("cls");
					cout << "소지금: " << iMoney << endl;
					cout << "====방어구====" << endl;
					cout << "1. " << na->_name << ": " << na->price << "원이며, 방어력은: " << na->option << "입니다." << endl;
					cout << "2. " << ma->_name << ": " << ma->price << "원이며, 방어력은: " << ma->option << "입니다." << endl;
					cout << "3. " << ga->_name << ": " << ga->price << "원이며, 방어력은: " << ga->option << "입니다." << endl;
					cin >> select;
					if (select > 0 && select < 4)
					{
						if (select == 1 && iMoney >= na->price)
						{
							if (na->get == true)
							{
								cout << "이미 있는 장비입니다" << endl;
								Sleep(1000);
							}
							else
							{
								na->get = true;
								iMoney -= na->price;
								m->playerHp(na->option);
								cout << "내복 구입완료" << endl;
								Sleep(1000);
								itemIn.push_back(na);
							}
						}
						else if (select == 2 && iMoney >= ma->price)
						{
							if (ma->get == true)
							{
								cout << "이미 있는 장비입니다" << endl;
								Sleep(1000);
							}
							else
							{
								ma->get = true;
								iMoney -= ma->price;
								m->playerHp(ma->option);
								cout << "기본갑옷 구입완료" << endl;
								Sleep(1000);
								itemIn.push_back(ma);
							}
						}
						else if (select == 3 && iMoney >= ga->price)
						{
							if (ga->get == true)
							{
								cout << "이미 있는 장비입니다" << endl;
								Sleep(1000);
							}
							else
							{
								ga->get = true;
								iMoney -= ga->price;
								m->playerHp(ga->option);
								cout << "마법갑옷 구입완료" << endl;
								Sleep(1000);
								itemIn.push_back(ga);
							}
						}
						else
						{
							cout << "돈이 부족합니다!" << endl;
							Sleep(1000);
						}
					}
				}
				else if (select == 3)
				{
				system("cls");
				cout << "소지금: " << iMoney << endl;
				cout << "====도구====" << endl;
				cout << "1. " << nh->_name << ": " << nh->price << "원입니다." << endl;
				cout << "2. " << np->_name << ": " << np->price << "원입니다." << endl;
				cout << "3. " << mp->_name << ": " << mp->price << "원입니다." << endl;
				cin >> select;
				if (select > 0 && select < 4)
				{
					if (select == 1 && iMoney >= nh->price)
					{
						if (nh->get == true)
						{
							cout << "이미 있는 장비입니다" << endl;
							Sleep(1000);
						}
						else
						{
							nh->get = true;
							iMoney -= nh->price;
							cout << "기본괭이 구입완료" << endl;
							Sleep(1000);
							itemIn.push_back(nh);
						}
					}
					else if (select == 2 && iMoney >= np->price)
					{
						if (np->get == true)
						{
							cout << "이미 있는 장비입니다" << endl;
							Sleep(1000);
						}
						else
						{
							np->get = true;
							iMoney -= np->price;
							cout << "기본곡괭이 구입완료" << endl;
							Sleep(1000);
							itemIn.push_back(np);
						}
					}
					else if (select == 3 && iMoney >= mp->price)
					{
						if (mp->get == true)
						{
							cout << "이미 있는 장비입니다" << endl;
							Sleep(1000);
						}
						else
						{
							mp->get = true;
							iMoney -= mp->price;
							cout << "마법곡괭이 구입완료" << endl;
							Sleep(1000);
							itemIn.push_back(mp);
						}
					}
					else
					{
						cout << "돈이 부족합니다!" << endl;
						Sleep(1000);
					}
				}
				}
				else if (select == 4)
				{
					
					system("cls");
					cout << "====판매====" << endl;
					cout << "1.장비 2. 광석" << endl;
					cin >> select;
					if (select == 1)
					{
						cout << "====장비====" << endl;
						cout << "가격은 구매가의 절반에 팔립니다."<<endl;

						
						iter = itemIn.begin();

						for (iter; iter != itemIn.end(); iter++)
						{
							count++;
							cout << count << ". " << (*iter)->_name << ": " << (*iter)->price/2 << "원" << endl;

						}
						cin >> select;
						if (select < 1)
						{
							cout << "비어있는 칸입니다.";
							Sleep(1000);
						}
						else if (select > count)
						{
							cout << "비어있는 칸입니다.";
							Sleep(1000);
						}
						else
						{
							iter = itemIn.begin() + select - 1;
							(*iter)->get = false;
							iMoney += (*iter)->price / 2;
							if ((*iter)->_name == same)
							{
								m->playerHp(-5);
							}
							else if ((*iter)->_name == same1)
							{
								m->playerHp(-15);
							}
							else if ((*iter)->_name == same2)
							{
								m->playerHp(-50);
							}
							itemIn.erase(itemIn.begin() + select - 1);
							
						}
					}
					else if (select == 2)
					{
						
						cout << endl << "====광석====" << endl;
						cout << "1." << ir->_name << ": " << ir->count << "개/" << ir->price << "원에 판매" << endl;
						cout << "2." << go->_name << ": " << go->count << "개/" << go->price << "원에 판매" << endl;
						cin >> select;
						if (select == 1 && ir->count > 0)
						{
							cout << "몇개를 판매하시겠습니까?" << endl;
							cin >> select;
							if (ir->count >= select)
							{
								ir->count -= select;
								iMoney = iMoney + (ir->price * select);
								cout << (ir->price * select) << "원어치 판매했습니다.";
							}
							else
							{
								cout << "값이 정확하지 않습니다." << endl;
							}

						}
						if (select == 2 && go->count > 0)
						{
							cout << "몇개를 판매하시겠습니까?" << endl;
							cin >> select;
							if (go->count >= select)
							{
								go->count -= select;
								iMoney = iMoney + (go->price * select);
								cout << (go->price * select) << "원어치 판매했습니다.";
							}
							else
							{
								cout << "값이 정확하지 않습니다." << endl;
							}

						}

						Sleep(1000);
					}
				}
				else if (select == 5)
				{
					inshop = false;
				}
			}

		
}

void shop::showInven()
{
	vector<item*>::iterator iter;
	iter = itemIn.begin();
	int count = 0;
	
	for (iter; iter != itemIn.end(); iter++)
	{
		count++;
		cout << count << ". " << (*iter)->_name << endl;
	}
	cout << endl << "====광석====" << endl;
	cout << "1." << ir->_name << ": " << ir->count << endl;
	cout << "2." << go->_name << ": " << go->count << endl;
	cout << "소지금: " << iMoney << endl;
	Sleep(1000);
}

int shop::iniron()
{
	ir->count += 1;
	return 1;
}

int shop::ingold()
{
	go->count += 1;
	return 2;
}

int shop::checkpick()
{
	srand(time(NULL));
	if (mp->get == true)
	{
	return 1;
	}
	else if (np->get == true)
	{
		int temp = rand() % 10;
		if (temp > 5)
		{
			return 1;
		}
	}
}

int shop::checkPick()
{
	if (mp->get == true)
	{
		int temp = rand() % 10;
		if (temp > 5)
		{
			return 1;
		}
	}
}

void shop::money(int num)
{
	iMoney += num;
}

void shop::submoney(int num)
{
	iMoney -= num;
}

int shop::moneycheck(int num)
{
	if (num < iMoney)
	{
		return 1;
	}
	else if (num > iMoney)
	{
		return 2;
	}
	else if (iMoney < 1)
	{
		return 3;
	}
}

//퀘스트용
int shop::countIron(int num)
{
	if (ir->count >= num)
	{
		return 1;
	}
	return 0;
}

void shop::recall()
{
	ns->get = false;
	ms->get = false;
	fs->get = false;
	gs->get = false;

	na->get = false;
	ma->get = false;
	ga->get = false;

	nh->get = false;
	np->get = false;
	mp->get = false;

	ir->count = 0;
	go->count = 0;
}

int shop::checkSword()
{
	if (gs->get == true)
	{
		return 4;
	}
	else if (fs->get == true)
	{
		return 3;
	}
	else if (ms->get == true)
	{
		return 2;
	}
	else if (ns->get == true)
	{
		return 1;
	}
}

int shop::checkArmor()
{

	if (ga->get == true)
	{
		return 3;
	}
	else if (ma->get == true)
	{
		return 2;
	}
	else if (na->get == true)
	{
		return 1;
	}
	

}




shop::shop()
{
}


shop::~shop()
{
}
