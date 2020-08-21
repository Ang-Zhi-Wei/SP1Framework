
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

COORD firehydrant::get_coord(void) {
	return position;
}


