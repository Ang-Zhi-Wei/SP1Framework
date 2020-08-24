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
	}
	if (direction == 'D')
	{
		y += 1;
	}
	if (direction == 'L')
	{
		x -= 2;
	}
	if (direction == 'R')
	{
		x += 2;
	}
}

void Bullet::print()
{
	COORD c;

	c.X = x;
	c.Y = y;

	if (x >= 0 && x < 80 && y >= 0 && y < 25)
	{
		g_Console.writeToBuffer(c, "*", 0x3D);
	}
}
