#pragma once
#include <string>
#include "Position.h"
using namespace std;
class Entity : public Position
{
protected:
	string name;
	int health, dmg;

public:
	Entity();
	~Entity();
	Entity(int x, int y);

	string Getname();
};

