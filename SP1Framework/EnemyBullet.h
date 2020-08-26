#pragma once
#include "Entities.h"
#include "Functions.h"
#include "Framework/console.h"
#include "game.h"
#include <iostream>
class EnemyBullet : public Entity
{
protected:
	int x1, y1, x2, y2, Dx, Dy, Sx, Sy, R, D;

public:
	EnemyBullet(int x1, int y1, int x2, int y2);
	~EnemyBullet();

	void EVERYTHINGUPDATE();
	void simulatedirection();

	void Setx1(int x1);
	int Getx1();

	void Sety1(int y1);
	int Gety1();
};

