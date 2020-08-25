#pragma once
#include "Entities.h"
#include "game.h"
#include "Framework/timer.h"
#include "Framework/console.h"
class Enemy : public Entity
{
protected:
	double rate_of_fire;
	static int total_no_of_enemy;

	COORD EnemyPos;
public:
	Enemy(int x = 10, int y = 10);
	~Enemy();

	COORD get_enemy_coord(void);

	static void SetTotalEnemy(int SetTotalEn);
	static int GetTotalEnemy();

	void EVERYTHINGUPDATE();
};

