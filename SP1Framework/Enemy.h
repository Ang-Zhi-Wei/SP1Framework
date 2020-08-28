#pragma once
#include "Framework/timer.h"
#include "Framework/console.h"
#include "Functions.h"
#include "Entities.h"

class EnemyBullet;

class Enemy : public Entity
{
protected:
	double rate_of_fire;
	static int total_no_of_enemy;
	double ctimer;
	EnemyBullet* EneBulletArray[256];

	COORD EnemyPos;
public:


	Enemy(int x = 10, int y = 10);
	~Enemy();

	COORD get_coord(void);


	static void SetTotalEnemy(int SetTotalEn);
	static int GetTotalEnemy();

	void EVERYTHINGUPDATE(void);

	void EnemyMakeBullet();
	void UpdateEnemyBullet();
};

