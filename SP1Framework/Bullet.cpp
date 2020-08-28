#include "Bullet.h"
#include <iostream>
#include "game.h"
#include "Framework/console.h"
#include "Player.h"
using namespace std;




Bullet::Bullet(SGameChar& player, char direction)
{
	this->direction = direction;

	x = player.m_cLocation.X;
	y = player.m_cLocation.Y;
	
}

Bullet::~Bullet()
{

}

void Bullet::UpdateXandY(Console& console)
{
	if (direction == 'U')
	{
		y -= 1;
		ObjectCheck();
	}
	if (direction == 'D')
	{
		y += 1;
		ObjectCheck();
	}
	if (direction == 'L')
	{
		for (int i = 0; i < 2; i++) {
			x -= 1;
			ObjectCheck();
		}
	}
	if (direction == 'R')
	{
		for (int i = 0; i < 2; i++) {
			x += 1;
			ObjectCheck();
		}
	}
}

void Bullet::print()
{
	COORD c;

	c.X = x;
	c.Y = y;

	if (x >= 0 && x < 81 && y >= 0 && y < 26)
	{
		g_Console.writeToBuffer(c, "*", 0x3D);
	}
}

void Bullet::ObjectCheck() 
{
	for (int i = 0; i < 20; i++)
	{
		if (lvlmanager[i] == nullptr)
		{
			continue;
		}
		if (lvlmanager[i]->Gettype() == whatisit::Enemy)
		{
			if ((x == lvlmanager[i]->get_coord().X) && (y == lvlmanager[i]->get_coord().Y))
			{
				int finalhealth;
				finalhealth = lvlmanager[i]->Gethealth() - playerstats.Getdmg();
				lvlmanager[i]->Sethealth(finalhealth);
			}
		}
	}
}
