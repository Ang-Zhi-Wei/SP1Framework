#include "Entities.h"
#include "game.h"
#include "firehydrant.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

Entity::Entity(int health, int dmg)
{
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

void Entity::updategame()
{

}
