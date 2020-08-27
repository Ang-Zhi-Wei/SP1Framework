#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->x2 = x2;

	this->y1 = y1;
	this->y2 = y2;

	Dx = x2 - x1;
	Dy = y2 - y1;

	Sx = Sign(Dx);
	Sy = Sign(Dy);

	Dx = abs(Dx);
	Dy = abs(Dy);

	D = max(Dx, Dy);
	R = D / 2;
}

EnemyBullet::~EnemyBullet()
{
	//left blank for now
}

void EnemyBullet::EVERYTHINGUPDATE()
{
	if ((x1 <= 79) || x1 > 0 || (y1 <= 24) || y1 > 0)
	{
		g_Console.writeToBuffer(x1, y1, "*", 0x8B);
	}
	simulatedirection();

}

void EnemyBullet::simulatedirection()
{
	if (Dx > Dy)
	{
		x1 += Sx; R += Dy;
		if (R >= Dx)
		{
			y1 += Sy;
			R -= Dx; //# Diagonal move
		}
	}
	else
	{
		y1 += Sy;
		R += Dx;

		if (R >= Dy)
		{
			x1 += Sx;
			R -= Dy;//# Diagonal move
		}
	}

}

void EnemyBullet::Setx1(int x1)
{
	this->x1;
}

int EnemyBullet::Getx1()
{
	return x1;
}

void EnemyBullet::Sety1(int y1)
{
	this->y1;
}

int EnemyBullet::Gety1()
{
	return y1;
}

