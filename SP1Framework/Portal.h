#pragma once
class Portal
{
private:
	int positionx;
	int positiony;
public:
	Portal();
	~Portal();
	int GetPositionY();
	int GetPositionX();
	void SetPositionY(int y);
	void SetPositionX(int x);
};

