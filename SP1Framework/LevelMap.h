#pragma once
#include <string>
class LevelMap
{
private:
	const unsigned int HEIGHT = 25;
	const unsigned int WIDTH = 80;
	char MapArray[25][80];
public:
	 LevelMap();
	 void Load(void);
	 char LevelArray[80][25];
	 void TransferArray(void);
};

