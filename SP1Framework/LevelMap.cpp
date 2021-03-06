#include "LevelMap.h"
#include <fstream>
#include <iostream>
#include "Framework\console.h"
#include "game.h"
using namespace std;
LevelMap::LevelMap()
{
}
// Tutorial Level
void LevelMap::LoadTutorialLevel(void)
{
    ifstream fin;
    fin.open("TutorialLevel.txt");
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

void LevelMap::LoadLevel2(void)
{
    ifstream fin;
    fin.open("Level2.txt");
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
void LevelMap::LoadLevel1(void)
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
}
void LevelMap::LoadLevel3(void)
{
    ifstream fin;
    fin.open("Level3.txt");

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
}

void LevelMap::LoadLevel4MomStage(void)
{
    ifstream fin;
    fin.open("Level4BossLevelMomStage.txt");
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
}
void LevelMap::LoadLevel4DadStage(void)
{
    ifstream fin;
    fin.open("Level4BossLevelDadStage.txt");
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
}


// Places each char into LevelArray
void LevelMap::TransferArray()
{
    for (unsigned int i = 0; i < 80 ; i++)
    {
        
        for (unsigned int j = 0; j < 25; j++)
        {
            LevelArray[i][j] = MapArray[j][i];
        }
    }
}








