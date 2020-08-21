#pragma once
#include <string>
class LevelMap
{
private:
	char MapArray[25][80]{};
	const unsigned int HEIGHT = 25;
	const unsigned int WIDTH = 80;
public:
	 LevelMap();
	 void Load(void);
	 char LevelArray[80][25];
	 void TransferArray();
};

