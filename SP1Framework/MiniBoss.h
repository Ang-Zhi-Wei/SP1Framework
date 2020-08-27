#pragma once
#include "Entities.h"
#include "Entities.h"
#include "game.h"
#include "Framework/timer.h"
#include "Framework/console.h"
#include "game.h"
#include "Functions.h"
#include <iostream>
#include "EnemyBullet.h"
#include "MiniBossBullet.h"
class MiniBoss : public Entity
{
protected: 
	double miniboss_rate_of_fire;
	static int total_no_of_miniboss;
	double minibossctimer;
	MiniBossBullet* MiniBossBulletArray[256];

	COORD MiniBossPos;
public:
	MiniBoss(int x = 10, int y = 10);
	~MiniBoss();

	COORD get_miniboss_coord(void);


	static void SetTotalBoss(int SetTotalMini);
	static int GetTotalBoss();

	void EVERYTHINGUPDATE(void);

	void BossMakeBullet();
	void UpdateBossBullet();
};

