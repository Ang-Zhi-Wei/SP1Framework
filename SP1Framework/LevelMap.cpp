#include "LevelMap.h"
#include <fstream>
#include <iostream>
#include "Framework\console.h"
#include "game.h"
using namespace std;
LevelMap::LevelMap()
{
}

void LevelMap::Load(void)
{

    ifstream fin;
    fin.open("Level1.txt");
    string line;

    //let's assume here the proper size of input Map
    for (unsigned int i = 0; i < HEIGHT; i++)
    {
        getline(fin, line);
        for (unsigned int j = 0; j < WIDTH; j++)
        {
            MapArray[i][j] = line[j];
        }
    }

    //let's assume here the proper size of input Map
}

void LevelMap::TransferArray(void)
{
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			LevelArray[i][j] = (char)MapArray[j][i];
		}
	}
}






