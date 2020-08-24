#pragma once
#include <string>
#include <Windows.h>
#include "game.h"
using namespace std;
class Entity
{
protected:
	string name;
	int x, y, health, dmg;


public:
	Entity();
	~Entity();
	Entity(int health, int dmg);

	string Getname();
	virtual COORD get_coord(void);
	virtual void EVERYTHINGUPDATE();
};

