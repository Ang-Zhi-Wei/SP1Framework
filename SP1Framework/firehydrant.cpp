
#include "firehydrant.h"
int firehydrant::total_no_of_hydrant = 0;

firehydrant::firehydrant(int x, int y)
{
	position.X = x;
	position.Y = y;

}

firehydrant::~firehydrant()
{
}

void firehydrant::SetTotalHydrant(int SetTotalHr)
{
	total_no_of_hydrant = SetTotalHr;
}

int firehydrant::GetTotalHydrant()
{
	return total_no_of_hydrant;
}

void firehydrant::updategame()
{
	if ((g_sChar.m_cLocation.X == position.X && g_sChar.m_cLocation.Y == position.Y))
	{
		if (g_skKeyEvent[K_R].keyDown)
		{

		}
	}
}

COORD firehydrant::get_coord(void) {
	return position;
}


