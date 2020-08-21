#pragma once
#include <string>
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
};

