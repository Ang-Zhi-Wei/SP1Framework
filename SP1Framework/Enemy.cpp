#include "Enemy.h"
#include "game.h"

int Enemy::total_no_of_enemy = 0;

Enemy::Enemy(int x, int y)
{
	EnemyPos.X = x;
	EnemyPos.Y = y;
}

Enemy::~Enemy()
{
	//left blank for now
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

void Enemy::EVERYTHINGUPDATE()
{
	g_Console.writeToBuffer(EnemyPos.X + 1, EnemyPos.Y + 1, " ", 0x6C);
}
