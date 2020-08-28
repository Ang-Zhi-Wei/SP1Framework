#include "Entities.h"



Entity::Entity()
{
	health = 5;
	dmg = 1;
	x = 10;
	y = 10;
	type = whatisit::Entity;
	alive = true;
}

Entity::~Entity()
{

}

Entity::Entity(int health, int dmg)
{
	this->health = health;
	this->dmg = dmg;
	x = 10;
	y = 10;
	type = whatisit::Entity;
	alive = true;
}



string Entity::Getname()
{
	return string();
}

COORD Entity::get_coord(void) {
	COORD c;
	c.X = x;
	c.Y = y;
	return c;
}

void Entity::EVERYTHINGUPDATE()
{

}

int Entity::Gethealth()
{
	return health;
}

void Entity::Sethealth(int health)
{
	this->health = health;
}

int Entity::Getdmg()
{
	return dmg;
}

void Entity::Setdmg(int dmg)
{
	this->dmg;
}

whatisit Entity::Gettype()
{
	return type;
}
