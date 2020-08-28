#include "MiniBossBullet.h"

MiniBossBullet::MiniBossBullet(int x1m, int y1m, int x2m, int y2m)
{
	this->x1m = x1m;
	this->x2m = x2m;

	this->y1m = y1m;
	this->y2m = y2m;

	Dxm = x2m - x1m;
	Dym = y2m - y1m;

	Sxm = Sign(Dxm);
	Sym = Sign(Dym);

	Dxm = abs(Dxm);
	Dym = abs(Dym);

	Dm = max(Dxm, Dym);
	Rm = Dm / 2;
}

MiniBossBullet::~MiniBossBullet()
{
}

void MiniBossBullet::EVERYTHINGUPDATE()
{
	if ((x1m <= 80) || x1m > 0 || (y1m <= 25) || y1m > 0)
	{
		g_Console.writeToBuffer(x1m, y1m, "*", 0x4A);
	}
	simulatedirectionminiboss();
	ObjectCheck();
}

void MiniBossBullet::simulatedirectionminiboss()
{
	if (Dxm > Dym)
	{
		x1m += Sxm; Rm += Dym;
		if (Rm >= Dxm)
		{
			y1m += Sym;
			Rm -= Dxm; //# Diagonal move
		}
	}
	else
	{
		y1m += Sym;
		Rm += Dxm;

		if (Rm >= Dym)
		{
			x1m += Sxm;
			Rm -= Dym;//# Diagonal move
		}
	}

}

void MiniBossBullet::Setx1m(int x1m)
{
	this->x1m;
}

int MiniBossBullet::Getx1m()
{
	return x1m;
}

void MiniBossBullet::Sety1m(int y1)
{
	this->y1m;
}

int MiniBossBullet::Gety1m()
{
	return y1m;
}

void MiniBossBullet::ObjectCheck()
{

	if ((x1m == g_sChar.m_cLocation.X) && (y1m == g_sChar.m_cLocation.Y))
	{
		int finalhealth;
		finalhealth = playerstats.Gethealth() - 3;
		playerstats.Sethealth(finalhealth);
	}

}
