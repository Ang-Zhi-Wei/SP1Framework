#include "Enemy.h"
#include "game.h"
#include <iostream>
#include <string>


int Enemy::total_no_of_enemy = 0;

Enemy::Enemy(int x, int y)
{
	EnemyPos.X = x;
	EnemyPos.Y = y;
	ctimer = 0;

	rate_of_fire = 3;
	ctimer = fRand(0, rate_of_fire);
}

Enemy::~Enemy()
{
	
}

COORD Enemy::get_enemy_coord(void)
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
	g_Console.writeToBuffer(EnemyPos.X + 1, EnemyPos.Y + 1, " ", 0x6C);
	ctimer += g_dDeltaTime;
	if (ctimer < 3)
		return;

	ctimer = 0;

	g_Console.writeToBuffer(EnemyPos.X + 1, EnemyPos.Y + 1, "PEWPEWPEW", 0x8B);
}

