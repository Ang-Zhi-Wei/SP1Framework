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
	 void LoadTutorialLevel(void);
	 char LevelArray[80][25]{};
	 void LoadLevel1(void);
     void LoadLevel2(void);
	 void LoadLevel3(void);
	 void LoadLevel4DadStage(void);
	 void LoadLevelMomStage(void);
	 void TransferArray();
};

