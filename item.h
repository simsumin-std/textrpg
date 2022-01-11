#pragma once
#include <iostream>
#include <string>

using namespace std;

class item
{
public:
	int count;
	int price;
	int option;
	bool get = false;
	string _name;


	item();
	~item();
};

