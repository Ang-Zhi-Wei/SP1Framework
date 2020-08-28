#include "Portal.h"

Portal::Portal()
{
	
}

Portal::~Portal()
{
	//nothing
}

int Portal::GetPositionY()
{
	return positiony;
}

int Portal::GetPositionX()
{
	return positionx;
}

void Portal::SetPositionY(int y)
{
	positiony = y;
}

void Portal::SetPositionX(int x)
{
	positionx = x;
}
