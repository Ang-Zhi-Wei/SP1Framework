
#include "firehydrant.h"
int firehydrant::total_no_of_hydrant = 0;

firehydrant::firehydrant(int x, int y)
{
	position.X = x;
	position.Y = y;
}

firehydrant::~firehydrant()
{
	//left blank for now
}

void firehydrant::SetTotalHydrant(int SetTotalHr)
{
	total_no_of_hydrant = SetTotalHr;
}

int firehydrant::GetTotalHydrant()
{
	return total_no_of_hydrant;
}

void firehydrant::EVERYTHINGUPDATE()
{
	if ((g_sChar.m_cLocation.X == position.X && g_sChar.m_cLocation.Y == position.Y))
	{
		g_Console.writeToBuffer(position.X + 1, position.Y + 1, "Press R to refill", 0x8B);
		if (g_skKeyEvent[K_R].keyReleased)
		{
			Ammo = 100;
		}
	}
}

COORD firehydrant::get_coord(void) 
{
	return position;
}


