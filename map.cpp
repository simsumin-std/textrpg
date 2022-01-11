#include "map.h"

_move* mv = new _move;
shop* s = new shop;
player* pl = new player;

goblin* go = new goblin();
wolf* wo = new wolf();
orc* or = new orc();
monster* mo = new monster();

battleGround* arena = new battleGround();

void map::showMap()
{
	memcpy(tempMap, town, sizeof(tempMap));
	tempMap[7][20] = 3;
	int qCount = 0;
	int day = 0;
	int stamina = 0;
	int gCount = 0;
	int wCount = 0;
	int oCount = 0;
	while (1)
	{
		if (stamina == 72)
		{
			day++;
			stamina = 0;
		}
		system("cls");
		int h = 0;
		int w = 0;
		for (int h = 0; h < 15; h++)
		{
			for (int w = 0; w < 40; w++)
			{
				if (tempMap[h][w] == 0) //��
				{
					cout << " ";
				}
				else if (tempMap[h][w] == 1) //��
				{
					cout << "#";
				}
				else if (tempMap[h][w] == 3) //�÷��̾�
				{
					cout << "@";
				}
				else if (tempMap[h][w] == 4) //����
				{
					cout << "T";
				}
				else if (tempMap[h][w] == 9) //������
				{
					cout << "m";
				}
				else if (tempMap[h][w] == 10) //��
				{
					cout << "~";
				}
				else if (tempMap[h][w] == 5) //ö����
				{
					cout << "i";
				}
				else if (tempMap[h][w] == 6) //�ݱ���
				{
					cout << "g";
				}
				else if (tempMap[h][w] == 11) //����
				{
					cout << "S";
				}
				else if (tempMap[h][w] == 12) //����
				{
					cout << "C";
				}
				else if (tempMap[h][w] == 13) //�ǻ�
				{
					cout << "D";
				}
				else if (tempMap[h][w] == 21) //���
				{
					cout << "G";
				}
				else if (tempMap[h][w] == 22) //����
				{
					cout << "W";
				}
				else if (tempMap[h][w] == 23) //��ũ
				{
					cout << "O";
				}
			}
			cout << endl;
		}
		int i, j = 0;

		
		pl->checkStat();
		cout << endl << endl << day << "��/" << stamina*2 << "0��" << endl;
		//���üũ
		if (pl->GetHp() <= 0)
		{
			system("cls");
			cout << "GAME OVER"<<endl<<endl;
			Sleep(1000);
			//������, �� ���� �ʱ�ȭ
			cout << "��..." << endl;
			Sleep(1000);
			cout << "������..." << endl << endl;
			Sleep(1000);
			cout << "�ð�..." << endl << endl;
			Sleep(1000);
			mv->gotOxy(10, 10);
			cout << "�ƹ�Ű�� �Է��Ͻø� ����� �˴ϴ�.";
			qCount = 0;
			day = 0;
			stamina = 0;
			pl->SetExp(0);
			s->money(10);
			pl->SetHpFull();
			pl->SetMpFull();
			s->recall();
			memcpy(tempMap, town, sizeof(tempMap));
			tempMap[7][20] = 3;
		}
		int temp = mv->keyboard();
		srand(time(NULL));
		int r = 0;
		switch (temp)
		{
		case UP:
		{
			for (i = 0; i < 15; i++)
			{
				for (j = 0; j < 40; j++)
				{
					if (tempMap[i][j] == 3 && tempMap[i-1][j] == 0)
					{
						temp = tempMap[i][j];
						tempMap[i][j] = tempMap[i-1][j];
						tempMap[i-1][j] = temp;
						break;
					}
					//���Ϳ��� Ÿ��
					if (tempMap[8][1] == 3 && tempMap[7][1] == 4)
					{
						memcpy(tempMap, town, sizeof(tempMap));
						tempMap[8][37] = 3;
					}
					//Ÿ��� ����
					if (tempMap[8][38] == 3 && tempMap[7][38] == 4)
					{
						//����
						for (i = 0; i < 15; i++)
						{
							for (j = 0; j < 40; j++)
							{
								if (center[i][j] == 21 || center[i][j] == 22 || center[i][j] == 23)
								{
									center[i][j] = 0;
								}
							}
						}
						if (day < 11)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 10)
										{
											center[i][j] = 22;
										}
									}
								}
							}
						}
						else if (day < 21)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 30)
										{
											center[i][j] = 22;
										}
									}
								}
							}
						}
						else if (day < 31)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 5)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						else if (day < 41)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 40)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						else if (day < 51)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 5)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (r < 5)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						memcpy(tempMap, center, sizeof(tempMap));
						tempMap[7][2] = 3;
					}
					//���Ϳ��� ��
					if (tempMap[2][18] == 3 && tempMap[1][18] == 4)
					{
						memcpy(tempMap, farm, sizeof(tempMap));
						tempMap[12][18] = 3;
					}
					//���ο��� ����
					if (tempMap[2][19] == 3 && tempMap[1][19] == 4)
					{
						for (i = 0; i < 15; i++)
						{
							for (j = 0; j < 40; j++)
							{
								if (center[i][j] == 21 || center[i][j] == 22 || center[i][j] == 23)
								{
									center[i][j] = 0;
								}
							}
						}
						if (day < 11)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 10)
										{
											center[i][j] = 22;
										}
									}
								}
							}
						}
						else if (day < 21)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 30)
										{
											center[i][j] = 22;
										}
									}
								}
							}
						}
						else if (day < 31)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 5)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						else if (day < 41)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 40)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						else if (day < 51)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 5)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (r < 5)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						memcpy(tempMap, center, sizeof(tempMap));
						tempMap[12][19] = 3;
					}
				}
			}
		}
		break;
		case DOWN:
		{
			
			for (i = 0; i < 15; i++)
			{
				for (j = 0; j < 40; j++)
				{
					if (tempMap[i][j] == 3 && tempMap[i+1][j] == 0)
					{
						temp = tempMap[i][j];
						tempMap[i][j] = tempMap[i+1][j];
						tempMap[i+1][j] = temp;
						break;
					}
					if (tempMap[6][38] == 3 && tempMap[7][38] == 4)
					{
						for (i = 0; i < 15; i++)
						{
							for (j = 0; j < 40; j++)
							{
								if (center[i][j] == 21 || center[i][j] == 22 || center[i][j] == 23)
								{
									center[i][j] = 0;
								}
							}
						}
						if (day < 11)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 10)
										{
											center[i][j] = 22;
										}
									}
								}
							}
						}
						else if (day < 21)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 30)
										{
											center[i][j] = 22;
										}
									}
								}
							}
						}
						else if (day < 31)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 5)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						else if (day < 41)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 40)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						else if (day < 51)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 5)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (r < 5)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						memcpy(tempMap, center, sizeof(tempMap));
						tempMap[6][2] = 3;
					}
					if (tempMap[6][1] == 3 && tempMap[7][1] == 4) 
					{
						memcpy(tempMap, town, sizeof(tempMap));
						tempMap[6][37] = 3;
					}
					if (tempMap[12][19] == 3 && tempMap[13][19] == 4)
					{
						//���� ����
						for (i = 0; i < 15; i++)
						{
							for (j = 0; j < 40; j++)
							{
								if (mine[i][j] == 5)
								{
									mine[i][j] = 0;
								}
							}
						}
						for (i = 0; i < 15; i++)
						{
							for (j = 0; j < 40; j++)
							{
								if (mine[i][j] == 0)
								{
									r = rand() % 10;
										if (r < 2)
										{
											mine[i][j] = 5;
										}
										r = rand() % 10;
										if (mine[i][j] == 5 && r < 1)
										{
											mine[i][j] = 6;
										}
								}
							}
						}
						memcpy(tempMap, mine, sizeof(tempMap));
						tempMap[2][19] = 3;
					}
					if (tempMap[12][18] == 3 && tempMap[13][18] == 4)
					{
						for (i = 0; i < 15; i++)
						{
							for (j = 0; j < 40; j++)
							{
								if (center[i][j] == 21 || center[i][j] == 22 || center[i][j] == 23)
								{
									center[i][j] = 0;
								}
							}
						}
						if (day < 11)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 5)
										{
											center[i][j] = 22;
										}
									}
								}
							}
						}
						else if (day < 21)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 30)
										{
											center[i][j] = 22;
										}
									}
								}
							}
						}
						else if (day < 31)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 5)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						else if (day < 41)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 40)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						else if (day < 41)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 5)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (r < 5)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						memcpy(tempMap, center, sizeof(tempMap));
						tempMap[2][18] = 3;
					}
				}
				if (tempMap[i+1][j] == 3)
				{
					break;
				}
			}
		}
		break;
		case RIGHT:
		{
			for (i = 0; i < 15; i++)
			{
				for (j = 0; j < 40; j++)
				{
					if (tempMap[i][j] == 3 && tempMap[i][j+1] == 0)
					{
						temp = tempMap[i][j];
						tempMap[i][j] = tempMap[i][j+1];
						tempMap[i][j+1] = temp;
						break;
					}
					if (tempMap[7][37] == 3 && tempMap[7][38] == 4)
					{
						for (i = 0; i < 15; i++)
						{
							for (j = 0; j < 40; j++)
							{
								if (center[i][j] == 21 || center[i][j] == 22 || center[i][j] == 23)
								{
									center[i][j] = 0;
								}
							}
						}
						if (day < 11)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 5)
										{
											center[i][j] = 22;
										}
									}
								}
							}
						}
						else if (day < 21)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 30)
										{
											center[i][j] = 22;
										}
									}
								}
							}
						}
						else if (day < 31)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 5)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						else if (day < 41)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (center[i][j] == 5 && r < 40)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						else if (day < 41)
						{
							for (i = 0; i < 15; i++)
							{
								for (j = 20; j < 40; j++)
								{
									if (center[i][j] == 0)
									{
										r = rand() % 100;
										if (r < 5)
										{
											center[i][j] = 21;
										}
										r = rand() % 100;
										if (r < 5)
										{
											center[i][j] = 22;
										}
										r = rand() % 100;
										if (r < 10)
										{
											center[i][j] = 23;
										}
									}
								}
							}
						}
						memcpy(tempMap, center, sizeof(tempMap));
						tempMap[7][2] = 3;
					}
				}
			}
		}
		break;
		case LEFT:
		{
			for (i = 0; i < 15; i++)
			{
				for (j = 0; j < 40; j++)
				{
					if (tempMap[i][j] == 3 && tempMap[i][j - 1] == 0)
					{
						temp = tempMap[i][j];
						tempMap[i][j] = tempMap[i][j-1];
						tempMap[i][j-1] = temp;
						break;
					}
					if (tempMap[7][2] == 3 && tempMap[7][1] == 4)
					{
						memcpy(tempMap, town, sizeof(tempMap));
						tempMap[7][37] = 3;
					}
				}
			}
		}
		break;
		case BACK:
		{
			system("cls");
			int select;
			cout << "1. ����â 2. �κ��丮 3. ����Ʈ" << endl;
			cin >> select;
			if (select == 1)
			{
				pl->checkStat();//����
				cout << "��ų����Ʈ: " << pl->GetSkillPoint() << endl;
				if (s->checkSword() == 1)
				{
					cout << "���ݷ�: " << pl->GetAtk()<<" + 5";
				}
				else if (s->checkSword() == 2)
				{
					cout << "���ݷ�: " << pl->GetAtk()<<" + 15";
				}
				else if (s->checkSword() == 3)
				{
					cout << "���ݷ�: " << pl->GetAtk()<<" + 50";
				}
				else if (s->checkSword() == 4)
				{
					cout << "���ݷ�: " << pl->GetAtk()<<" + 100";
				}
				else
				{
					cout << "���ݷ�: " << pl->GetAtk();
				}
				if (pl->GetSkillPoint() > 0)
				{
					cout << "��ų�� �����ðڽ��ϱ�? �����̽��� or /";
					int skill = mv->keyboard();
					switch (skill)
					{
					case ACTIVITY:
					{
						system("cls");
						cout << "====��ų ���====" << endl;
						cout << "1.	betterPick" << endl << "2. powerPick" << endl;
						cout << "3.	betterHp" << endl << "4. powerHp" << endl;
						cout << "5.	betterAtk" << endl << "6. powerAtk" << endl;
						cout << "7.	betterStamina" << endl << "8. powerStamina" << endl;
						cout << "�Ŀ���ų���� ��ų����Ʈ 2���� �Ҹ�Ǹ� ���� �ܰ� ��ų�� �־�� ���氡���մϴ�.  ";
						
						
						cin >> select;
						if (pl->GetSkillPoint() > 0)
						{
							if (select == 1 && pl->GetBetterPick() == 1)
							{
								pl->SetSkillPoint(-1);
								pl->SetBetterPick(2);
							}
							else if (select == 3 && pl->GetBetterHp() == 1)
							{
								pl->SetSkillPoint(-1);
								pl->SetBetterHp(2);
								pl->SetMaxHp(20);
							}
							else if (select == 5 && pl->GetBetterAtk()== 1)
							{
								pl->SetSkillPoint(-1);
								pl->SetBetterAtk(2);
							}
							else if (select == 7 && pl->GetBetterStamina()== 1)
							{
								pl->SetSkillPoint(-1);
								pl->SetBetterStamina(2);
							}
						}
						else
						{
							cout << "��ų����Ʈ�� �����մϴ�";
						}
						if (pl->GetSkillPoint() > 1)
						{
							if (select == 2 && pl->GetBetterPick() == 2 && pl->GetPowerPick() == 1)
							{
								pl->SetSkillPoint(-2);
								pl->SetPowerPick(2);
							}
							else if (select == 4 && pl->GetBetterHp() == 2 && pl->GetPowerHp() == 1)
							{
								pl->SetSkillPoint(-2);
								pl->SetPowerHp(2);
								pl->SetMaxHp(30);
							}
							else if (select == 6 && pl->GetBetterAtk() == 2 && pl->GetPowerAtk() == 1)
							{
								pl->SetSkillPoint(-2);
								pl->SetPowerAtk(2);
							}
							else if (select == 8 && pl->GetBetterStamina() == 2 && pl->GetPowerStamina() == 1)
							{
								pl->SetSkillPoint(-2);
								pl->SetPowerStamina(2);
							}
						}
						else
						{
							cout << "���� ������ ä���� �ʾҰų� ��ų����Ʈ�� �����մϴ�." << endl;
						}
						Sleep(1000);
					}
					break;
					case BACK:
					{

					}
					break;
					}
				}
				Sleep(2000);
			}
			else if (select == 2)
			{
				s->showInven();//�κ�
			}
			else if (select == 3)
			{
				if (qCount == 2)
				{
					cout << "ö���� 5���� ���ش� ����!" << endl;
					Sleep(2000);
				}
				else if (qCount == 4)
				{
					cout << "��� 10������ ����!" << endl;
					cout << gCount << "/10����" << endl;
				}
				else if (qCount == 6)
				{
					cout << "���� 10������ ����!" << endl;
					cout << wCount << "/10����" << endl;
				}
				else if (qCount == 8)
				{
					cout << "��ũ 10������ ����!" << endl;
					cout << oCount << "/10����" << endl;
				}
				else
				{
					cout << "����Ʈ�� �����ϴ�.";
					Sleep(2000);
				}
			}
		}
		break;
		case ACTIVITY:
		{
			int select = 0;
			//����
			for (i = 0; i < 15; i++)
			{
				for (j = 0; j < 40; j++)
				{
					if (tempMap[i][j] == 3)
					{
						if (tempMap[i - 1][j] == 11 || tempMap[i][j + 1] == 11 || tempMap[i + 1][j] == 11 || tempMap[i][j - 1] == 11)
						{
							s->showShop();
							tempMap[i][j] = 0;
							tempMap[i][j + 3] = 3;
						}

					}
				}
			}
			//����
			for (i = 0; i < 15; i++)
			{
				for (j = 0; j < 40; j++)
				{
					if (tempMap[i][j] == 3)
					{
						if (tempMap[i - 1][j] == 12 || tempMap[i][j + 1] == 12 || tempMap[i + 1][j] == 12 || tempMap[i][j - 1] == 12)
						{
							system("cls");
							if (qCount == 0)
							{
								cout << "����: �츮 ������ ó�� �� �ʺ��ڰ� �ƴѰ�! ���� ���������� 100���� �ְڳ�." << endl;
								Sleep(3000);
								s->money(100);
								cout << "����: �������� ��̸� �����ؼ� ���꿡 ���°� �ּ��� �ɼ�.";
								Sleep(3000);
								qCount++;
							}
							else if (qCount == 1)
							{
									cout << "����: ���� �������� �� ��°�?" << endl;
									Sleep(3000);
									cout << "����: ������ ö���� 5���� ���ش� �ְ�, ���� �����̰� ưư�Ѱ� �ʿ��ؼ� ������." << endl;
									Sleep(3000);
									qCount++;	
							}
							else if (qCount == 2)
							{
								if (s->countIron(5) == 1)
								{
									cout << "����: ��! ����, ������ ��ʱ� 50���� �ְڳ�." << endl;
									Sleep(3000);
									s->money(200);
									cout << "����: �������� �̷� ���� �ִٸ� �� ��Ź�ϰڳ�." << endl << endl;
									cout << "����ġ�� [15]������ϴ�!";
									pl->SetExp(15);
									Sleep(3000);
									qCount++;
								}
								else
								{
									cout << "����: �����ΰ�? ��ٸ��� �ְڳ�." << endl;
									Sleep(3000);
								}
							}
							else if (qCount == 3)
							{
								cout << "����: ���� ������� �ؼ��̳�. �׷��� �׷��� ���" << endl;
								Sleep(3000);
								cout << "\t 10������ ����ֽðԳ�. ��ʴ� �ε��� �ϰڳ�.";
								Sleep(3000);
								gCount = 0;
								qCount++;
							}
							else if (qCount == 4)
							{
								if (gCount > 9)
								{
									cout << "��! ������� ���� ��ġ��� �°հ�?" << endl;
									Sleep(3000);
									cout << "���� ��ʱ� 150���ϼ�." << endl;
									s->money(150);
									cout << "����ġ�� [30]������ϴ�!";
									pl->SetExp(30);
									qCount++;
								}
								else
								{
									cout << "����: �����ΰ�? ��ٸ��� �ְڳ�." << endl;
									Sleep(3000);
								}
							}
							else if (qCount == 5 && day > 10)
							{
								cout << "����: ���� ������ ��ü���� �������� �ʾҳ�?" << endl;
								Sleep(3000);
								cout << "\t 10������ ����ֽðԳ�. ��ʴ� �ε��� �ϰڳ�.";
								Sleep(3000);
								wCount = 0;
								qCount++;
							}
							else if (qCount == 6)
							{
								if (wCount > 9)
								{
									cout << "��� ���� ������,,, ���� ū���̶� �Ͼ�� ������..." << endl;
									Sleep(3000);
									cout << "���� ��ʱ� 300���ϼ�." << endl;
									s->money(300);
									cout << "����ġ�� [50]������ϴ�!";
									pl->SetExp(50);
									qCount++;
								}
								else
								{
									cout << "����: �����ΰ�? ��ٸ��� �ְڳ�." << endl;
									Sleep(3000);
								}
							}
							else if (qCount == 7 && day > 30)
							{
								cout << "����: ū���̳� ��ũ���� ������ �´ٴ� �ҹ��� �ֳ�" << endl;
								Sleep(3000);
								cout << "\t ������ �������� 10������ ����ֽðԳ�. ��ʴ� �ε��� �ϰڳ�.";
								Sleep(3000);
								oCount = 0;
								qCount++;
							}
							else if (qCount == 8)
							{
								if (oCount > 9)
								{
									cout << "��ũ���� ���� �̷��Գ� ���ٴ�... ���� �������� ��û�ؾ߰ڳ�" << endl;
									Sleep(3000);
									cout << "���� ��ʱ� 500���ϼ�." << endl;
									s->money(500);
									cout << "����ġ�� [80]������ϴ�!";
									pl->SetExp(80);
									oCount++;
								}
								else
								{
									cout << "����: �����ΰ�? ��ٸ��� �ְڳ�." << endl;
									Sleep(3000);
								}
							}
							tempMap[i][j] = 0;
							tempMap[i][j - 3] = 3;
						}
					}
				}
			}
			//�ǻ�
			for (i = 0; i < 15; i++)
			{
				for (j = 0; j < 40; j++)
				{
					if (tempMap[i][j] == 3)
					{
						if (tempMap[i - 1][j] == 13 || tempMap[i][j + 1] == 13 || tempMap[i + 1][j] == 13 || tempMap[i][j - 1] == 13)
						{
							mv->gotOxy(42, 8);
							cout << "�ǻ�: ġ��� Hp ����Ʈ �� 3��.";
							mv->gotOxy(42, 9); 
							cout << "ġ��޳�? 1. �� 2. �ƴϿ�  ";
							cin >> select;
							if (select == 1)
							{
								if (pl->GetmaxHp() == pl->GetHp())
								{
									mv->gotOxy(42, 10);
									cout << "��ģ ���� ����." << endl;
								}
								else if (s->moneycheck(0) == 3)
								{
									mv->gotOxy(42, 10);
									cout << "���� ����. ġ�� �� �Ѵ�." << endl;
								}
								else
								{
									int temp = pl->GetmaxHp() - pl->GetHp();
									if (s->moneycheck(temp*3) == 1)
									{
										pl->SetHpFull();
										s->submoney(temp * 3);

										mv->gotOxy(42, 10);
										cout << "�Ϻ��� ġ���ߴ�. ����� " << temp * 3 << "���̴�." << endl;
									}
									if (s->moneycheck(temp*3) == 2)
									{
										temp = 0;
										while (1)
										{
											pl->SetHp(-1);
											s->submoney(3);
											temp += 1;
											if (s->moneycheck(0) == 3)
											{
												break;
											}
										}
										mv->gotOxy(42, 10);
										cout << "������ ġ���ߴ�. ����� " << temp * 3 << "���̴�." << endl;
									}
								}

							}
							else if (select == 2)
							{
								mv->gotOxy(42, 10);
								cout << "������ �Ͷ�." << endl;
							}
							Sleep(2000);
							tempMap[i][j] = 0;
							tempMap[i][j - 3] = 3;
						}

					}
				}
			}
			//ö��
			for (i = 0; i < 15; i++)
			{
				for (j = 0; j < 40; j++)
				{
					if (tempMap[i][j] == 3)
					{
						if (tempMap[i - 1][j] == 5)
						{
							if (pl->GetPowerPick() == 2)
							{
								tempMap[i - 1][j] = 0;
								pl->SetHp(s->iniron()-1);
							}
							else if (pl->GetBetterPick() == 2)
							{
								if (s->checkpick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->iniron()-1);
								}
							}
							else if (s->checkpick() == 1)
							{
								tempMap[i - 1][j] = 0;
								pl->SetHp(s->iniron());
							}
						}
						else if (tempMap[i][j + 1] == 5)
						{
							if (pl->GetPowerPick() == 2)
							{
								tempMap[i - 1][j] = 0;
								pl->SetHp(s->iniron() - 1);
							}
							else if (pl->GetBetterPick() == 2)
							{
								if (s->checkpick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->iniron() - 1);
								}
							}
							else if (s->checkpick() == 1)
							{
								tempMap[i][j + 1] = 0;
								pl->SetHp(s->iniron());
							}
						}
						else if (tempMap[i + 1][j] == 5)
						{
							if (pl->GetPowerPick() == 2)
							{
								tempMap[i - 1][j] = 0;
								pl->SetHp(s->iniron() - 1);
							}
							else if (pl->GetBetterPick() == 2)
							{
								if (s->checkpick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->iniron() - 1);
								}
							}
							else if (s->checkpick() == 1)
							{
								tempMap[i + 1][j] = 0;
								pl->SetHp(s->iniron());
							}
						}
						else if (tempMap[i][j - 1] == 5)
						{
							if (pl->GetPowerPick() == 2)
							{
								tempMap[i - 1][j] = 0;
								pl->SetHp(s->iniron() - 1);
							}
							else if (pl->GetBetterPick() == 2)
							{
								if (s->checkpick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->iniron() - 1);
								}
							}
							else if (s->checkpick() == 1)
							{
								tempMap[i][j - 1] = 0;
								pl->SetHp(s->iniron());
							}
						}

					}
				}
			}
			//�ݱ�
			for (i = 0; i < 15; i++)
			{
				for (j = 0; j < 40; j++)
				{
					if (tempMap[i][j] == 3)
					{
						if (tempMap[i - 1][j] == 6)
						{
							if (pl->GetPowerPick() == 2)
							{
								if (s->checkPick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->ingold()-2);
								}
							}
							else if (pl->GetBetterPick() == 2)
							{
								if (s->checkPick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->ingold() - 1);
								}
							}
							else if (s->checkPick() == 1)
							{
								tempMap[i - 1][j] = 0;
								pl->SetHp(s->ingold());
							}
						}
						else if (tempMap[i][j + 1] == 6)
						{
							if (pl->GetPowerPick() == 2)
							{
								if (s->checkPick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->ingold() - 2);
								}
							}
							else if (pl->GetBetterPick() == 2)
							{
								if (s->checkPick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->ingold() - 1);
								}
							}
							else if (s->checkPick() == 1)
							{
								tempMap[i][j + 1] = 0;
								pl->SetHp(s->ingold());
							}
						}
						else if (tempMap[i + 1][j] == 6)
						{
							if (pl->GetPowerPick() == 2)
							{
								if (s->checkPick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->ingold() - 2);
								}
							}
							else if (pl->GetBetterPick() == 2)
							{
								if (s->checkPick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->ingold() - 1);
								}
							}
							else if (s->checkPick() == 1)
							{
								tempMap[i + 1][j] = 0;
								pl->SetHp(s->ingold());
							}
						}
						else if (tempMap[i][j - 1] == 6)
						{
							if (pl->GetPowerPick() == 2)
							{
								if (s->checkPick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->ingold() - 2);
								}
							}
							else if (pl->GetBetterPick() == 2)
							{
								if (s->checkPick() == 1)
								{
									tempMap[i - 1][j] = 0;
									pl->SetHp(s->ingold() - 1);
								}
							}
							else if (s->checkPick() == 1)
							{
								tempMap[i][j - 1] = 0;
								pl->SetHp(s->ingold());
							}
						}

					}
				}
			}
			//����
			for (i = 0; i < 15; i++)
			{
				for (j = 0; j < 40; j++)
				{
					if (tempMap[i][j] == 3)
					{
						if (tempMap[i - 1][j] == 21 || tempMap[i][j + 1] == 21 || tempMap[i + 1][j] == 21 || tempMap[i][j - 1] == 21)
						{
							arena->fighter(pl, go);
							arena->fight();
							s->money(go->GetGold());
							pl->SetExp(go->GetExp());
							gCount++;
							if (tempMap[i - 1][j] == 21)
							{
								tempMap[i - 1][j] = 0;
							}
							else if (tempMap[i][j + 1] == 21)
							{
								tempMap[i][j + 1] = 0;
							}
							else if (tempMap[i+1][j] == 21)
							{
								tempMap[i+1][j] = 0;
							}
							else if (tempMap[i][j - 1] == 21)
							{
								tempMap[i][j - 1] = 0;
							}
						}
						else if (tempMap[i - 1][j] == 22 || tempMap[i][j + 1] == 22 || tempMap[i + 1][j] == 22 || tempMap[i][j - 1] == 22)
						{
							arena->fighter(pl, wo);
							arena->fight();
							s->money(wo->GetGold());
							pl->SetExp(wo->GetExp());
							wCount++;
							if (tempMap[i - 1][j] == 22)
							{
								tempMap[i - 1][j] = 0;
							}
							else if (tempMap[i][j + 1] == 22)
							{
								tempMap[i][j + 1] = 0;
							}
							else if (tempMap[i + 1][j] == 22)
							{
								tempMap[i + 1][j] = 0;
							}
							else if (tempMap[i][j - 1] == 22)
							{
								tempMap[i][j - 1] = 0;
							}
						}
						else if (tempMap[i - 1][j] == 23 || tempMap[i][j + 1] == 23 || tempMap[i + 1][j] == 23 || tempMap[i][j - 1] == 23)
						{
							arena->fighter(pl, or);
							arena->fight();
							s->money(or->GetGold());
							pl->SetExp(or->GetExp());
							oCount++;
							if (tempMap[i - 1][j] == 23)
							{
								tempMap[i - 1][j] = 0;
							}
							else if (tempMap[i][j + 1] == 23)
							{
								tempMap[i][j + 1] = 0;
							}
							else if (tempMap[i + 1][j] == 23)
							{
								tempMap[i + 1][j] = 0;
							}
							else if (tempMap[i][j - 1] == 23)
							{
								tempMap[i][j - 1] = 0;
							}
						}
					}
				}
			}

		}
		break;
		}
		if (pl->GetBetterStamina() == 2)
		{
			r = rand() % 10;
			if (pl->GetPowerStamina() == 2)
			{
				if (r > 5)
				{
					stamina++;
				}
			}
			else if (r > 2)
			{
				stamina++;
			}

		}
		else
		{
			stamina++;
		}

	}


}

void map::playerHp(int num)
{
	pl->SetMaxHp(num);
}

/*
void map::mapLoop(int mapT)
{
	int x, y;
	char temp;

	bool play = true;

	if (mapT = 0)
	{
		memcpy(tempMap, town, sizeof(tempMap));
	}
	else if (mapT = 1)
	{
		memcpy(tempMap, mine, sizeof(tempMap));
	}
	else if (mapT = 2)
	{
		memcpy(tempMap, farm, sizeof(tempMap));
	}
	else if (mapT = 3)
	{
		memcpy(tempMap, center, sizeof(tempMap));
	}
	showMap(&x, &y);
	

	while (play) 
	{
		

		switch (_m->keyboard())
		{
		case UP:
		{
			//temp = tempMap[x - 1][y];
			//if (temp == '0')
//			{
				move(&x, &y, 0, -1);
//			}

			
		}
		break;
		case DOWN:
		{
			move(&x, &y, 0, 1);
		}
		break;
		case RIGHT:
		{
			move(&x, &y, 1, 0);
		}
		break;
		case LEFT: 
		{
			move(&x, &y, -1, 0);
		}
		break;
		case BACK:
		{
			//�޴�
		}
		}
	}
}*/

/*
char map::mapObj()
{
	
	return 0;
}

void map::move(int*, int*, int, int)
{
		_m->gotOxy(*x, *y);
		cout << " ";

		gotOxy(*x + _x, *y + _y);
		cout << "@";

		*x += _x;
		*y += _y;
	
}*/

map::map()
{
}


map::~map()
{
}
