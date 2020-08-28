#pragma once
#include "Entities.h"
#include "Functions.h"
#include "Framework/console.h"
#include "game.h"
#include <iostream>
#include "GlobalVar.h"
class MiniBossBullet : public Entity
{
protected:
	int x1m, y1m, x2m, y2m, Dxm, Dym, Sxm, Sym, Rm, Dm;

public:
	MiniBossBullet(int x1m, int y1m, int x2m, int y2m);
	~MiniBossBullet();

	void EVERYTHINGUPDATE();
	void simulatedirectionminiboss();

	void Setx1m(int x1m);
	int Getx1m();

	void Sety1m(int y1m);
	int Gety1m();

	void ObjectCheck();
};

