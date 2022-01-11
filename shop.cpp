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
		string same = "����";
		string same1 = "�⺻����";
		string same2 = "��������";

		while (inshop)
		{
			system("cls");
			iMoney = 10000;
			cout << "������ �°� ȯ���մϴ�." << endl << "� ������ �����Ͻðڽ��ϱ�?" << endl << endl;
			cout << "������: " << iMoney << endl;
			cout << "1. ����" << endl;
			cout << "2. ��" << endl;
			cout << "3. ����" << endl;
			cout << "4. �Ǹ�" << endl;
			cout << "5.-------���� ������--------" << endl;

			cin >> select;
				if (select == 1)
				{
					system("cls");
					cout << "������: " << iMoney << endl;
					cout << "====����====" << endl;
					cout << "1. " << ns->_name << ": " << ns->price << "���̸�, ��������: " << ns->option << "�Դϴ�." << endl;
					cout << "2. " << ms->_name << ": " << ms->price << "���̸�, ��������: " << ms->option << "�Դϴ�." << endl;
					cout << "3. " << fs->_name << ": " << fs->price << "���̸�, ��������: " << fs->option << "�Դϴ�." << endl;
					cout << "4. " << gs->_name << ": " << gs->price << "���̸�, ��������: " << gs->option << "�Դϴ�." << endl;
					cin >> select;
					if (select > 0 && select < 5)
					{
						if (select == 1 && iMoney >= ns->price)
						{
							if (ns->get == true)
							{
								cout << "�̹� �ִ� ����Դϴ�" << endl;
								Sleep(1000);
							}
							else
							{
								ns->get = true;
								iMoney -= ns->price;
								cout << "�⺻�� ���ԿϷ�" << endl;
								
								Sleep(1000);
								itemIn.push_back(ns);
							}
						}
						else if (select == 2 && iMoney >= ms->price)
						{
							if (ms->get == true)
							{
								cout << "�̹� �ִ� ����Դϴ�" << endl;
								Sleep(1000);
							}
							else
							{
								ms->get = true;
								iMoney -= ms->price;
								cout << "������ ���ԿϷ�" << endl;
								Sleep(1000);
								itemIn.push_back(ms);
							}
						}
						else if (select == 3 && iMoney >= fs->price)
						{
							if (fs->get == true)
							{
								cout << "�̹� �ִ� ����Դϴ�" << endl;
								Sleep(1000);
							}
							else
							{
								fs->get = true;
								iMoney -= fs->price;
								cout << "���� �� ���ԿϷ�" << endl;
								Sleep(1000);
								itemIn.push_back(fs);
							}
						}
						else if (select == 4 && iMoney >= gs->price)
						{
							if (gs->get == true)
							{
								cout << "�̹� �ִ� ����Դϴ�" << endl;
								Sleep(1000);
							}
							else
							{
								gs->get = true;
								iMoney -= gs->price;
								cout << "Ȳ�ݰ� ���ԿϷ�" << endl;
								Sleep(1000);
								itemIn.push_back(gs);
							}
						}
						else
						{
							cout << "���� �����մϴ�!" << endl;
							Sleep(1000);
						}
					}
				}
				else if (select == 2)
				{
					system("cls");
					cout << "������: " << iMoney << endl;
					cout << "====��====" << endl;
					cout << "1. " << na->_name << ": " << na->price << "���̸�, ������: " << na->option << "�Դϴ�." << endl;
					cout << "2. " << ma->_name << ": " << ma->price << "���̸�, ������: " << ma->option << "�Դϴ�." << endl;
					cout << "3. " << ga->_name << ": " << ga->price << "���̸�, ������: " << ga->option << "�Դϴ�." << endl;
					cin >> select;
					if (select > 0 && select < 4)
					{
						if (select == 1 && iMoney >= na->price)
						{
							if (na->get == true)
							{
								cout << "�̹� �ִ� ����Դϴ�" << endl;
								Sleep(1000);
							}
							else
							{
								na->get = true;
								iMoney -= na->price;
								m->playerHp(na->option);
								cout << "���� ���ԿϷ�" << endl;
								Sleep(1000);
								itemIn.push_back(na);
							}
						}
						else if (select == 2 && iMoney >= ma->price)
						{
							if (ma->get == true)
							{
								cout << "�̹� �ִ� ����Դϴ�" << endl;
								Sleep(1000);
							}
							else
							{
								ma->get = true;
								iMoney -= ma->price;
								m->playerHp(ma->option);
								cout << "�⺻���� ���ԿϷ�" << endl;
								Sleep(1000);
								itemIn.push_back(ma);
							}
						}
						else if (select == 3 && iMoney >= ga->price)
						{
							if (ga->get == true)
							{
								cout << "�̹� �ִ� ����Դϴ�" << endl;
								Sleep(1000);
							}
							else
							{
								ga->get = true;
								iMoney -= ga->price;
								m->playerHp(ga->option);
								cout << "�������� ���ԿϷ�" << endl;
								Sleep(1000);
								itemIn.push_back(ga);
							}
						}
						else
						{
							cout << "���� �����մϴ�!" << endl;
							Sleep(1000);
						}
					}
				}
				else if (select == 3)
				{
				system("cls");
				cout << "������: " << iMoney << endl;
				cout << "====����====" << endl;
				cout << "1. " << nh->_name << ": " << nh->price << "���Դϴ�." << endl;
				cout << "2. " << np->_name << ": " << np->price << "���Դϴ�." << endl;
				cout << "3. " << mp->_name << ": " << mp->price << "���Դϴ�." << endl;
				cin >> select;
				if (select > 0 && select < 4)
				{
					if (select == 1 && iMoney >= nh->price)
					{
						if (nh->get == true)
						{
							cout << "�̹� �ִ� ����Դϴ�" << endl;
							Sleep(1000);
						}
						else
						{
							nh->get = true;
							iMoney -= nh->price;
							cout << "�⺻���� ���ԿϷ�" << endl;
							Sleep(1000);
							itemIn.push_back(nh);
						}
					}
					else if (select == 2 && iMoney >= np->price)
					{
						if (np->get == true)
						{
							cout << "�̹� �ִ� ����Դϴ�" << endl;
							Sleep(1000);
						}
						else
						{
							np->get = true;
							iMoney -= np->price;
							cout << "�⺻��� ���ԿϷ�" << endl;
							Sleep(1000);
							itemIn.push_back(np);
						}
					}
					else if (select == 3 && iMoney >= mp->price)
					{
						if (mp->get == true)
						{
							cout << "�̹� �ִ� ����Դϴ�" << endl;
							Sleep(1000);
						}
						else
						{
							mp->get = true;
							iMoney -= mp->price;
							cout << "������� ���ԿϷ�" << endl;
							Sleep(1000);
							itemIn.push_back(mp);
						}
					}
					else
					{
						cout << "���� �����մϴ�!" << endl;
						Sleep(1000);
					}
				}
				}
				else if (select == 4)
				{
					
					system("cls");
					cout << "====�Ǹ�====" << endl;
					cout << "1.��� 2. ����" << endl;
					cin >> select;
					if (select == 1)
					{
						cout << "====���====" << endl;
						cout << "������ ���Ű��� ���ݿ� �ȸ��ϴ�."<<endl;

						
						iter = itemIn.begin();

						for (iter; iter != itemIn.end(); iter++)
						{
							count++;
							cout << count << ". " << (*iter)->_name << ": " << (*iter)->price/2 << "��" << endl;

						}
						cin >> select;
						if (select < 1)
						{
							cout << "����ִ� ĭ�Դϴ�.";
							Sleep(1000);
						}
						else if (select > count)
						{
							cout << "����ִ� ĭ�Դϴ�.";
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
						
						cout << endl << "====����====" << endl;
						cout << "1." << ir->_name << ": " << ir->count << "��/" << ir->price << "���� �Ǹ�" << endl;
						cout << "2." << go->_name << ": " << go->count << "��/" << go->price << "���� �Ǹ�" << endl;
						cin >> select;
						if (select == 1 && ir->count > 0)
						{
							cout << "��� �Ǹ��Ͻðڽ��ϱ�?" << endl;
							cin >> select;
							if (ir->count >= select)
							{
								ir->count -= select;
								iMoney = iMoney + (ir->price * select);
								cout << (ir->price * select) << "����ġ �Ǹ��߽��ϴ�.";
							}
							else
							{
								cout << "���� ��Ȯ���� �ʽ��ϴ�." << endl;
							}

						}
						if (select == 2 && go->count > 0)
						{
							cout << "��� �Ǹ��Ͻðڽ��ϱ�?" << endl;
							cin >> select;
							if (go->count >= select)
							{
								go->count -= select;
								iMoney = iMoney + (go->price * select);
								cout << (go->price * select) << "����ġ �Ǹ��߽��ϴ�.";
							}
							else
							{
								cout << "���� ��Ȯ���� �ʽ��ϴ�." << endl;
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
	cout << endl << "====����====" << endl;
	cout << "1." << ir->_name << ": " << ir->count << endl;
	cout << "2." << go->_name << ": " << go->count << endl;
	cout << "������: " << iMoney << endl;
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

//����Ʈ��
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
