#include "MiniBoss.h"
#include "game.h"
#include <iostream>
#include <string>
#include "MiniBossBullet.h"

int MiniBoss::total_no_of_miniboss = 0;

MiniBoss::MiniBoss(int x, int y)
{
	MiniBossPos.X = x;
	MiniBossPos.Y = y;
	minibossctimer = 0;
	health = 20;
	dmg = 3;
	type = whatisit::Enemy;

	miniboss_rate_of_fire = 1;
	minibossctimer = fRand(0, miniboss_rate_of_fire);

	for (int i = 0; i < 256; i++)
	{
		MiniBossBulletArray[i] = nullptr;
	}
}

MiniBoss::~MiniBoss()
{
	for (int i = 0; i < 256; i++)
	{
		if (MiniBossBulletArray[i] != nullptr)
		{
			delete MiniBossBulletArray[i];
		}
	}
}

COORD MiniBoss::get_coord(void)
{
	return MiniBossPos;
}

void MiniBoss::SetTotalBoss(int SetTotalMini)
{
	total_no_of_miniboss = SetTotalMini;
}

int MiniBoss::GetTotalBoss()
{
	return total_no_of_miniboss;
}

void MiniBoss::EVERYTHINGUPDATE(void)
{
	//g_Console.writeToBuffer(MiniBossPos.X, MiniBossPos.Y - 5, to_string(health), 0x4A);
	g_Console.writeToBuffer(MiniBossPos.X, MiniBossPos.Y - 5, to_string(int(type)), 0x4A);

	if (alive != true)
	{
		return;
	}
	if (health <= 0)
	{
		alive = false;
		total_no_of_miniboss--;
	}

	g_Console.writeToBuffer(MiniBossPos.X, MiniBossPos.Y, char(1), 0x64);
	UpdateBossBullet();
	minibossctimer += g_dDeltaTime;
	if (minibossctimer < 1)
		return;

	minibossctimer = 0;

	BossMakeBullet();
}

void MiniBoss::BossMakeBullet()
{
	for (int i = 0; i < 256; i++)
	{
		if (MiniBossBulletArray[i] == nullptr)
		{
			MiniBossBulletArray[i] = new MiniBossBullet(MiniBossPos.X, MiniBossPos.Y, g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
			return;
		}
	}
	for (int i = 0; i < 256; i++) //pushes 
	{
		if (i + 1 >= 256)
		{
			MiniBossBulletArray[i] = nullptr;
		}
		else
		{
			MiniBossBulletArray[i + 1] = MiniBossBulletArray[i];
		}
	}
}

void MiniBoss::UpdateBossBullet()
{
	for (int i = 0; i < 256; i++)
	{
		if (MiniBossBulletArray[i] != nullptr)
		{
			MiniBossBulletArray[i]->EVERYTHINGUPDATE();

			if (((MiniBossBulletArray[i]->Getx1m() >= 79) || (MiniBossBulletArray[i]->Getx1m() < 0)) || ((MiniBossBulletArray[i]->Gety1m() >= 24) || (MiniBossBulletArray[i]->Gety1m() < 0)))
			{
				delete MiniBossBulletArray[i];
				MiniBossBulletArray[i] = nullptr;
			}
		}
	}
}
