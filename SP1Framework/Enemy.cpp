#include "Enemy.h"
#include "game.h"
#include <iostream>
#include <string>
#include "EnemyBullet.h"



int Enemy::total_no_of_enemy = 0;

Enemy::Enemy(int x, int y)
{
	this->x = x;
	this->y = y;
	EnemyPos.X = x;
	EnemyPos.Y = y;
	health = 5;
	dmg = 1;
	type = whatisit::Enemy;
	ctimer = 0;

	rate_of_fire = 3.5;
	ctimer = fRand(0, rate_of_fire);

	for (int i = 0; i < 256; i++)
	{
		EneBulletArray[i] = nullptr;
	}
}

Enemy::~Enemy()
{
	for (int i = 0; i < 256; i++)
	{
		if (EneBulletArray[i] != nullptr)
		{
			delete EneBulletArray[i];
		}
	}
}

COORD Enemy::get_coord(void)
{
	return EnemyPos;
}

void Enemy::SetTotalEnemy(int SetTotalEn)
{
	total_no_of_enemy = SetTotalEn;
}

int Enemy::GetTotalEnemy()
{
	return total_no_of_enemy;
}

void Enemy::EVERYTHINGUPDATE(void)
{
	g_Console.writeToBuffer(EnemyPos.X, EnemyPos.Y - 1, to_string(health), 0x4A);

	if (alive != true)
	{
		return;
	}
	if (health <= 0)
	{
		alive = false;
	}

	g_Console.writeToBuffer(EnemyPos.X, EnemyPos.Y,char(1), 0x4A);
	UpdateEnemyBullet();
	ctimer += g_dDeltaTime;
	if (ctimer < 3.5)
		return;

	ctimer = 0;

	EnemyMakeBullet();

}

void Enemy::EnemyMakeBullet()
{
	for (int i = 0; i < 256; i++)
	{
		if (EneBulletArray[i] == nullptr)
		{
			EneBulletArray[i] = new EnemyBullet(EnemyPos.X, EnemyPos.Y, g_sChar.m_cLocation.X, g_sChar.m_cLocation.Y);
			return;
		}
	}
	for (int i = 0; i < 256; i++) //pushes 
	{
		if (i + 1 >= 256)
		{
			EneBulletArray[i] = nullptr;
		}
		else
		{
			EneBulletArray[i + 1] = EneBulletArray[i];
		}
	}
}

void Enemy::UpdateEnemyBullet()
{
	for (int i = 0; i < 256; i++)
	{
		if (EneBulletArray[i] != nullptr)
		{
			EneBulletArray[i]->EVERYTHINGUPDATE();

			if (((EneBulletArray[i]->Getx1() >= 79) || (EneBulletArray[i]->Getx1() < 0)) || ((EneBulletArray[i]->Gety1() >= 24) || (EneBulletArray[i]->Gety1() < 0)))
			{
				delete EneBulletArray[i];
				EneBulletArray[i] = nullptr;
			}
		}
	}
}

