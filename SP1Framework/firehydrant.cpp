#include "firehydrant.h"
#include "Framework/console.h"
#include "game.h"
int firehydrant::total_no_of_hydrant = 0;

firehydrant::firehydrant(int x, int y)
{
	position.X = x;
	position.Y = y;
	g_Console.writeToBuffer(position, "FH", 0x7A);

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


