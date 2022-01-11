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
				if (tempMap[h][w] == 0) //땅
				{
					cout << " ";
				}
				else if (tempMap[h][w] == 1) //벽
				{
					cout << "#";
				}
				else if (tempMap[h][w] == 3) //플레이어
				{
					cout << "@";
				}
				else if (tempMap[h][w] == 4) //텔포
				{
					cout << "T";
				}
				else if (tempMap[h][w] == 9) //나뭇잎
				{
					cout << "m";
				}
				else if (tempMap[h][w] == 10) //물
				{
					cout << "~";
				}
				else if (tempMap[h][w] == 5) //철광석
				{
					cout << "i";
				}
				else if (tempMap[h][w] == 6) //금광석
				{
					cout << "g";
				}
				else if (tempMap[h][w] == 11) //상점
				{
					cout << "S";
				}
				else if (tempMap[h][w] == 12) //촌장
				{
					cout << "C";
				}
				else if (tempMap[h][w] == 13) //의사
				{
					cout << "D";
				}
				else if (tempMap[h][w] == 21) //고블린
				{
					cout << "G";
				}
				else if (tempMap[h][w] == 22) //늑대
				{
					cout << "W";
				}
				else if (tempMap[h][w] == 23) //오크
				{
					cout << "O";
				}
			}
			cout << endl;
		}
		int i, j = 0;

		
		pl->checkStat();
		cout << endl << endl << day << "일/" << stamina*2 << "0분" << endl;
		//사망체크
		if (pl->GetHp() <= 0)
		{
			system("cls");
			cout << "GAME OVER"<<endl<<endl;
			Sleep(1000);
			//아이템, 돈 전부 초기화
			cout << "돈..." << endl;
			Sleep(1000);
			cout << "아이템..." << endl << endl;
			Sleep(1000);
			cout << "시간..." << endl << endl;
			Sleep(1000);
			mv->gotOxy(10, 10);
			cout << "아무키나 입력하시면 재시작 됩니다.";
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
					//센터에서 타운
					if (tempMap[8][1] == 3 && tempMap[7][1] == 4)
					{
						memcpy(tempMap, town, sizeof(tempMap));
						tempMap[8][37] = 3;
					}
					//타운에서 센터
					if (tempMap[8][38] == 3 && tempMap[7][38] == 4)
					{
						//몬스터
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
					//센터에서 팜
					if (tempMap[2][18] == 3 && tempMap[1][18] == 4)
					{
						memcpy(tempMap, farm, sizeof(tempMap));
						tempMap[12][18] = 3;
					}
					//마인에서 센터
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
						//랜덤 광석
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
			cout << "1. 정보창 2. 인벤토리 3. 퀘스트" << endl;
			cin >> select;
			if (select == 1)
			{
				pl->checkStat();//정보
				cout << "스킬포인트: " << pl->GetSkillPoint() << endl;
				if (s->checkSword() == 1)
				{
					cout << "공격력: " << pl->GetAtk()<<" + 5";
				}
				else if (s->checkSword() == 2)
				{
					cout << "공격력: " << pl->GetAtk()<<" + 15";
				}
				else if (s->checkSword() == 3)
				{
					cout << "공격력: " << pl->GetAtk()<<" + 50";
				}
				else if (s->checkSword() == 4)
				{
					cout << "공격력: " << pl->GetAtk()<<" + 100";
				}
				else
				{
					cout << "공격력: " << pl->GetAtk();
				}
				if (pl->GetSkillPoint() > 0)
				{
					cout << "스킬을 찍으시겠습니까? 스페이스바 or /";
					int skill = mv->keyboard();
					switch (skill)
					{
					case ACTIVITY:
					{
						system("cls");
						cout << "====스킬 목록====" << endl;
						cout << "1.	betterPick" << endl << "2. powerPick" << endl;
						cout << "3.	betterHp" << endl << "4. powerHp" << endl;
						cout << "5.	betterAtk" << endl << "6. powerAtk" << endl;
						cout << "7.	betterStamina" << endl << "8. powerStamina" << endl;
						cout << "파워스킬들은 스킬포인트 2개씩 소모되며 이전 단계 스킬이 있어야 습득가능합니다.  ";
						
						
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
							cout << "스킬포인트가 부족합니다";
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
							cout << "전제 조건을 채우지 않았거나 스킬포인트가 부족합니다." << endl;
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
				s->showInven();//인벤
			}
			else if (select == 3)
			{
				if (qCount == 2)
				{
					cout << "철광석 5개를 구해다 주자!" << endl;
					Sleep(2000);
				}
				else if (qCount == 4)
				{
					cout << "고블린 10마리를 잡자!" << endl;
					cout << gCount << "/10마리" << endl;
				}
				else if (qCount == 6)
				{
					cout << "늑대 10마리를 잡자!" << endl;
					cout << wCount << "/10마리" << endl;
				}
				else if (qCount == 8)
				{
					cout << "오크 10마리를 잡자!" << endl;
					cout << oCount << "/10마리" << endl;
				}
				else
				{
					cout << "퀘스트가 없습니다.";
					Sleep(2000);
				}
			}
		}
		break;
		case ACTIVITY:
		{
			int select = 0;
			//상점
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
			//촌장
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
								cout << "촌장: 우리 마을에 처음 온 초보자가 아닌가! 정착 지원금으로 100원을 주겠네." << endl;
								Sleep(3000);
								s->money(100);
								cout << "촌장: 상점에서 곡괭이를 구매해서 광산에 가는게 최선일 걸세.";
								Sleep(3000);
								qCount++;
							}
							else if (qCount == 1)
							{
									cout << "촌장: 정착 지원금은 잘 썼는가?" << endl;
									Sleep(3000);
									cout << "촌장: 간단히 철광석 5개만 구해다 주게, 요즘 지팡이가 튼튼한게 필요해서 말이지." << endl;
									Sleep(3000);
									qCount++;	
							}
							else if (qCount == 2)
							{
								if (s->countIron(5) == 1)
								{
									cout << "촌장: 오! 고맙네, 간단히 사례금 50원을 주겠네." << endl;
									Sleep(3000);
									s->money(200);
									cout << "촌장: 다음에도 이런 일이 있다면 또 부탁하겠네." << endl << endl;
									cout << "경험치를 [15]얻었습니다!";
									pl->SetExp(15);
									Sleep(3000);
									qCount++;
								}
								else
								{
									cout << "촌장: 아직인가? 기다리고 있겠네." << endl;
									Sleep(3000);
								}
							}
							else if (qCount == 3)
							{
								cout << "촌장: 요즘 고블린들이 극성이네. 그래서 그런데 고블린" << endl;
								Sleep(3000);
								cout << "\t 10마리만 잡아주시게나. 사례는 두둑히 하겠네.";
								Sleep(3000);
								gCount = 0;
								qCount++;
							}
							else if (qCount == 4)
							{
								if (gCount > 9)
								{
									cout << "오! 고블린들을 벌써 해치우고 온겐가?" << endl;
									Sleep(3000);
									cout << "여기 사례금 150원일세." << endl;
									s->money(150);
									cout << "경험치를 [30]얻었습니다!";
									pl->SetExp(30);
									qCount++;
								}
								else
								{
									cout << "촌장: 아직인가? 기다리고 있겠네." << endl;
									Sleep(3000);
								}
							}
							else if (qCount == 5 && day > 10)
							{
								cout << "촌장: 요즘 늑대의 개체수가 증가하지 않았나?" << endl;
								Sleep(3000);
								cout << "\t 10마리만 잡아주시게나. 사례는 두둑히 하겠네.";
								Sleep(3000);
								wCount = 0;
								qCount++;
							}
							else if (qCount == 6)
							{
								if (wCount > 9)
								{
									cout << "고블린 다음 늑대라니,,, 뭔가 큰일이라도 일어날거 같구먼..." << endl;
									Sleep(3000);
									cout << "여기 사례금 300원일세." << endl;
									s->money(300);
									cout << "경험치를 [50]얻었습니다!";
									pl->SetExp(50);
									qCount++;
								}
								else
								{
									cout << "촌장: 아직인가? 기다리고 있겠네." << endl;
									Sleep(3000);
								}
							}
							else if (qCount == 7 && day > 30)
							{
								cout << "촌장: 큰일이네 오크들이 마을로 온다는 소문이 있네" << endl;
								Sleep(3000);
								cout << "\t 마을에 오기전에 10마리만 잡아주시게나. 사례는 두둑히 하겠네.";
								Sleep(3000);
								oCount = 0;
								qCount++;
							}
							else if (qCount == 8)
							{
								if (oCount > 9)
								{
									cout << "오크들이 이제 이렇게나 많다니... 성에 지원군을 요청해야겠네" << endl;
									Sleep(3000);
									cout << "여기 사례금 500원일세." << endl;
									s->money(500);
									cout << "경험치를 [80]얻었습니다!";
									pl->SetExp(80);
									oCount++;
								}
								else
								{
									cout << "촌장: 아직인가? 기다리고 있겠네." << endl;
									Sleep(3000);
								}
							}
							tempMap[i][j] = 0;
							tempMap[i][j - 3] = 3;
						}
					}
				}
			}
			//의사
			for (i = 0; i < 15; i++)
			{
				for (j = 0; j < 40; j++)
				{
					if (tempMap[i][j] == 3)
					{
						if (tempMap[i - 1][j] == 13 || tempMap[i][j + 1] == 13 || tempMap[i + 1][j] == 13 || tempMap[i][j - 1] == 13)
						{
							mv->gotOxy(42, 8);
							cout << "의사: 치료는 Hp 포인트 당 3원.";
							mv->gotOxy(42, 9); 
							cout << "치료받나? 1. 예 2. 아니요  ";
							cin >> select;
							if (select == 1)
							{
								if (pl->GetmaxHp() == pl->GetHp())
								{
									mv->gotOxy(42, 10);
									cout << "다친 곳이 없다." << endl;
								}
								else if (s->moneycheck(0) == 3)
								{
									mv->gotOxy(42, 10);
									cout << "돈이 없다. 치료 못 한다." << endl;
								}
								else
								{
									int temp = pl->GetmaxHp() - pl->GetHp();
									if (s->moneycheck(temp*3) == 1)
									{
										pl->SetHpFull();
										s->submoney(temp * 3);

										mv->gotOxy(42, 10);
										cout << "완벽히 치료했다. 비용은 " << temp * 3 << "원이다." << endl;
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
										cout << "적절히 치료했다. 비용은 " << temp * 3 << "원이다." << endl;
									}
								}

							}
							else if (select == 2)
							{
								mv->gotOxy(42, 10);
								cout << "아프면 와라." << endl;
							}
							Sleep(2000);
							tempMap[i][j] = 0;
							tempMap[i][j - 3] = 3;
						}

					}
				}
			}
			//철광
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
			//금광
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
			//몬스터
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
			//메뉴
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
