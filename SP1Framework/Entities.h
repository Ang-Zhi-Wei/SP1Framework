#pragma once
#include <string>
#include <Windows.h>
#include "game.h"
#include <iostream>

using namespace std;

enum class whatisit
{
	Entity,
	Enemy,
	firehydrant
};

class Entity
{

protected:
	int x, y, health, dmg;

	whatisit type;
public:

	bool alive;

	Entity();
	~Entity();
	Entity(int health, int dmg);

	string Getname();
	virtual COORD get_coord(void);
	virtual void EVERYTHINGUPDATE();
	

	int Gethealth();
	void Sethealth(int health);

	int Getdmg();
	void Setdmg(int dmg);


	whatisit Gettype();
};


