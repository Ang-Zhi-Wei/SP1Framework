#pragma once
#include "game.h"
#include "Framework/console.h"
#include "GlobalVar.h"
#include "Entities.h"
class Bullet 
{
public:
	int x, y;

	char direction;

	Bullet(SGameChar& player, char direction);
	~Bullet();
	

	void  UpdateXandY(Console& console);
	void print();
	void ObjectCheck();
};

