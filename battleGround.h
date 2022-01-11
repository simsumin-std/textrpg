#pragma once
#include "player.h"
#include "monster.h"
#include "shop.h"
#include "map.h"

class battleGround 
{
private:

public:
player* _p;
monster* _m;

void fighter(player* p, monster* m);
void fight();
	

	battleGround();
	~battleGround();
};

