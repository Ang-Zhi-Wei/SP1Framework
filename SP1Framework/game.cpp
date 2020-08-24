// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include<stdio.h> 
#include "player.h"
#include "LevelMap.h"
#include "GlobalVar.h"
#include <Windows.h>
#include "mmsystem.h"
#include "Bullet.h"
#include "firehydrant.h"
using namespace std;
double  g_dElapsedTime;
double  g_dDeltaTime;
bool randomtext = false;
int k = 0;
int randomNO=0;
bool startingscreen = true;
bool soundcheck = true;
bool paused = false;
bool Levelselect = false;
bool loading = false;
bool Credits = false;
int level = -1;
bool Tutorial = false;
bool level1 = false;
bool level2 = false;
bool level3 = false;
bool level4 = false;
bool level1status = false;
bool level2status = false;
bool level3status = false;
bool level4status = false;
bool dadstatus = false;
bool momstatus = false;
bool Storytutorial = false;
int Text =  0;
int increaseY = 0;
int increaseX = 0;
int storyincreaseY[100] = { 0, };
int storyincreaseX[100] = { 0, };
int StoryText[100] = { 0, };
int storytime[100] = { 0, };
int Ammo = 100;
SKeyEvent g_skKeyEvent[K_COUNT];
SMouseEvent g_mouseEvent;
// Game specific variables here
SGameChar   g_sChar;
EGAMESTATES g_eGameState = S_SPLASHSCREEN; // initial state

// Console object
Console g_Console(80, 25, "SP1 Framework");

Bullet* Amount_ofbullet[256] = { nullptr,};



player play(&g_sChar);
bool storytimer(float time,float interval) {
    if (g_dElapsedTime >= time + interval) {
        return true;
    }
}
void actorandtextmovement(int startingx,int startingy,int endingx,int endingy,string text,string direction,int no,float speed,string type) {
    if (StoryText[no] == 0) {
        storytime[no] = g_dElapsedTime;
    }
    COORD C;
    if (storytimer(storytime[no], speed) == true) {
        if (direction == "LEFT") {
            storyincreaseX[no]-=1;
        }
        else if (direction == "RIGHT") {
            storyincreaseX[no]++;
        }
        else if (direction == "UP") {
            storyincreaseY[no] -= 1;
        }
        else if (direction == "DOWN") {
            storyincreaseY[no]++;
        }
        StoryText[no] = -1;
    }
    C.X = startingx + storyincreaseX[no];
    C.Y = startingy + storyincreaseY[no];
    if (endingx == NULL) {
        if (C.Y >= startingy && C.Y <= endingy &&direction=="DOWN") {
            if (text != "EMPTY") {
                g_Console.writeToBuffer(C, text, 0x8B);
            }
            else if (type == "ACTOR") {
                g_Console.writeToBuffer(C, char(1), 0x1A);
            }
        }
        else if (C.Y <= startingy && C.Y >= endingy && direction == "UP") {
            if (text != "EMPTY") {
                g_Console.writeToBuffer(C, text, 0x8B);
            }
            else if (type == "ACTOR") {
                g_Console.writeToBuffer(C, char(1), 0x1A);
            }
        }
    }
    else if (endingy == NULL) {
        if (C.X >= startingx && C.X <= endingx && direction=="RIGHT") {
            if (text != "EMPTY") {
                g_Console.writeToBuffer(C, text, 0x8B);
            }
            else if (type == "ACTOR") {
                g_Console.writeToBuffer(C, char(1), 0x1A);
            }
        }
        else if  (C.X <= startingx && C.X >= endingx && direction == "LEFT") {
            if (text != "EMPTY") {
                g_Console.writeToBuffer(C, text, 0x8B);
            }
            else if (type == "ACTOR") {
                g_Console.writeToBuffer(C, char(1), 0x1A);
            }
        }
    }
    if (StoryText[no] == 2) {
        StoryText[no]--;
    }
    StoryText[no]++;
}
void storytutorialskip(void) {
    if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        if (g_mouseEvent.mousePosition.X >= 76 && g_mouseEvent.mousePosition.X <= 80 && g_mouseEvent.mousePosition.Y == 0) {
            Tutorial = true;
            Storytutorial = false;
            soundcheck = true;
            for (int i = 0; i < 100; i++) {
                storyincreaseX[i] = -1;
                storyincreaseY[i] = -1;
            }
        }
    }
}
void storytutorial(void) {
    COORD C;
    //skip button
    C.X = 76;
    C.Y = 0;
    g_Console.writeToBuffer(C, "skip", 0x8B);
    //Actor
    if (storytimer(k, 0) == true) {
        //mainpeople
        actorandtextmovement(20, 7, NULL, 17, "EMPTY", "DOWN", 0, 2.0, "ACTOR");
        actorandtextmovement(19, 8, NULL, 18, "EMPTY", "DOWN", 1, 2.0, "ACTOR");
        actorandtextmovement(21, 8, NULL, 18, "EMPTY", "DOWN", 2, 2.0, "ACTOR");
        //randompeople
        actorandtextmovement(79, 6, 0, NULL, "EMPTY", "LEFT", 3, 1.0, "ACTOR");
    }
    if (storytimer(k, 6.0) == true) {
        actorandtextmovement(25, 10, NULL, 13, "Player:There's only one person here...","DOWN",4,2.0,"EMPTY");
    }
    if (storytimer(k, 12.0) == true) {
        actorandtextmovement(25, 13, NULL, 17, "Dad:Of Course,it's a ghost town we're exploring", "DOWN", 5, 2.0, "EMPTY");
    }
    if (storytimer(k, 22.0) == true) {
        actorandtextmovement(20, 17, 66, NULL, "EMPTY", "RIGHT", 6, 2.0, "ACTOR");
        actorandtextmovement(19, 18, 65, NULL, "EMPTY", "RIGHT", 7, 2.0, "ACTOR");
        actorandtextmovement(21, 18, 67, NULL, "EMPTY", "RIGHT", 8, 2.0, "ACTOR");
    }
    if (storytimer(k, 22.0) == true) {
        if (storytimer(k, 28.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player:Why are we even here?",0x8B);
        }
    }
    if (storytimer(k, 28.0) == true) {
        if (storytimer(k, 36.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Mum:Can't you be a little bit energetic?", 0x8B);
        }
    }
    if (storytimer(k, 36.0) == true) {
        if (storytimer(k, 42.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Mum:We haven't been going out for days", 0x8B);
        }
    }
    if (storytimer(k, 42.0) == true) {
        if (storytimer(k, 48.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Mum:This should be have been exciting for us!", 0x8B);
        }
    }
    if (storytimer(k, 48.0) == true) {
        if (storytimer(k, 56.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad:And when are you going to get a job?", 0x8B);
        }
    }
    if (storytimer(k, 56.0) == true) {
        if (storytimer(k, 62.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad:You've been lazying around this year...", 0x8B);
        }
    }
    if (storytimer(k, 62.0) == true) {
        if (storytimer(k, 68.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad:Watching whatever vtuber things you've been saying", 0x8B);
        }
    }
    if (storytimer(k, 68.0) == true) {
        if (storytimer(k, 72.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player:...", 0x8B);
        }
    }
    if (storytimer(k, 72.0) == true) {
        if (storytimer(k, 78.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player:I will get a job just give me some more time", 0x8B);
        }
    }
    if (storytimer(k, 78.0) == true) {
        if (storytimer(k, 84.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player:And don't forget what happened last time", 0x8B);
        }
    }
    if (storytimer(k, 84.0) == true) {
        if (storytimer(k, 90.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad:Oh right....that time....", 0x8B);
        }
    }
    if (storytimer(k, 90.0) == true) {
        if (storytimer(k, 96.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad:That Accident....", 0x8B);
        }
    }
    if (storytimer(k, 96.0) == true) {
        if (storytimer(k, 102.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad:You quit your firefighting job becaue of that", 0x8B);
        }
    }
    if (storytimer(k, 102.0) == true) {
        if (storytimer(k, 108.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad:I should have disowned you back then", 0x8B);
        }
    }
    if (storytimer(k, 108.0) == true) {
        if (storytimer(k, 116.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player:It wasn't like that!Back then was-", 0x8B);
        }
    }
    if (storytimer(k, 116.0) == true) {
        if (storytimer(k, 122.0) != true) {
            C.X = 65;
            C.Y = 0;
            g_Console.writeToBuffer(C, "BOOM!!", 0x1B);
        }
        
        //mom
        C.X = 65;
        C.Y = 18;
        g_Console.writeToBuffer(C, char(1), 0x1A);
        //dad
        C.X = 66;
        C.Y = 17;
        g_Console.writeToBuffer(C, char(1), 0x1A);
        //player
        C.X = 67;
        C.Y = 18;
        g_Console.writeToBuffer(C, char(1), 0x1A);
    }
    if (storytimer(k, 122.0) == true) {
        if (storytimer(k, 128.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player:Whats happening", 0x8B);
        }
    }
    if (storytimer(k, 128.0) == true) {
        actorandtextmovement(80, 6, 0, NULL, "EMPTY", "LEFT", 9, 0.5, "ACTOR");
    }
}
bool credittimer(int currenttime,float interval) {
    if (g_dElapsedTime >= currenttime + interval) {
        return true;
    }
}
void creditMovement(string text,int startingy,int xposition){
    if (Text == 0) {
        k = g_dElapsedTime;
    }
    COORD C;
    if (credittimer(k,1) == true) {
        increaseY++;
        Text=-1;
    }
    C.X = xposition;
    C.Y = startingy+increaseY;
    if (C.Y >= 0 && C.Y <= 25) {
        g_Console.writeToBuffer(C, text, 0x1A);
    }
    if (Text == 2) {
        Text--;
    }
    Text++;
}
void credittext() {
    creditMovement("Luke Ng", -8,37);
    creditMovement("Teo Jian Yong", -6,34);
    creditMovement("Lee Xie Loong",-4,34);
    creditMovement("Ang Zhi Wei", -2,35);
    creditMovement("Done By", 0,37);
}
void creditbackselect() {
    if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        if (g_mouseEvent.mousePosition.X >= 76 && g_mouseEvent.mousePosition.X <= 80 && g_mouseEvent.mousePosition.Y == 0) {
            startingscreen = true;
            Credits = false;
            increaseY = -1;
        }
    }
}
void randomdots(int g, int k) {
    COORD C;
    for (int i = g; i < g + 2; i++) {
        C.X = i;
        C.Y = k;
        g_Console.writeToBuffer(C, " ", 0x4A);
    }
}
void StartingEvents(void) {
    if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        if (g_mouseEvent.mousePosition.X >= 20 && g_mouseEvent.mousePosition.X <= 29 && g_mouseEvent.mousePosition.Y == 12) {
            startingscreen = false;
            Levelselect = true;
        }
        else if (g_mouseEvent.mousePosition.X >= 20 && g_mouseEvent.mousePosition.X <= 23 && g_mouseEvent.mousePosition.Y == 16) {
            g_bQuitGame = true;
        }
        else if (g_mouseEvent.mousePosition.X >= 20 && g_mouseEvent.mousePosition.X <= 26 && g_mouseEvent.mousePosition.Y == 14) {
            startingscreen = false;
            Credits = true;
        }
    }
}
void StartingGamescreen(void) {
    //entire screen blue
    COORD C;
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 80; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0x3A);
        }
    }
    //dots
    randomdots(2, 2);
    randomdots(3, 17);
    randomdots(17, 22);
    randomdots(75, 18);
    randomdots(43, 7);
    randomdots(50, 21);
    randomdots(17, 0);
    randomdots(4, 14);
    randomdots(64, 16);
    randomdots(72, 3);
    randomdots(67, 5);
    //border
    for (int i = 18; i < 32; i++) {
        for (int j = 9; j < 18; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0xBB);
        }
    }
    //Phlogiston
    C.X = 20;
    C.Y = 10;
    g_Console.writeToBuffer(C, "Phlogiston", 0x4A);
    //Story Mode
    C.Y += 2;
    g_Console.writeToBuffer(C, "Story Mode", 0x8B);
    //Credits
    C.Y += 2;
    g_Console.writeToBuffer(C, "Credits", 0x8B);
    //Exit
    C.Y += 2;
    g_Console.writeToBuffer(C, "Exit", 0x8B);
}
void createbottommiddle(int g) {
    COORD c;
    int k = 2;
    for (int i = g; i < g + 5; i++) {
        if (i < g + 3) {
            for (int j = 20 + k; j < 25; j++) {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", 0x5A);
            }
            if (k != 0) {
                k--;
            }
        }
        else {
            k++;
            for (int j = 20 + k; j < 25; j++) {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", 0x5A);
            }
        }
    }
}
void createtopmiddle(int g) {
    COORD c;
    int k = 2;
    for (int i = g; i < g + 5; i++) {
        if (i < g + 3) {
            for (int j = 0; j < 5 - k; j++) {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", 0x5A);
            }
            if (k != 0) {
                k--;
            }
        }
        else {
            k++;
            for (int j = 0; j < 5 - k; j++) {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", 0x5A);
            }
        }

    }
}
void loadingscreen(void) {
    PlaySound(NULL, 0, 0);
    srand(time(NULL));
    COORD c;
    if (randomtext == true) {
        randomNO = rand() % 4;
        randomtext = false;
    }
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 25; j++) {
            c.X = i;
            c.Y = j;
            g_Console.writeToBuffer(c, " ", 0xAA);
        }
    }
    int k = 0;
    //top left
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 5; i++) {
            if (i < 8 - j) {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", 0x4A);
            }
        }
    }
    //bottom left
    for (int i = 0; i < 5; i++) {
        for (int j = 17 + i; j < 25; j++) {
            c.X = i;
            c.Y = j;
            g_Console.writeToBuffer(c, " ", 0x4A);
        }
    }
    //top right
    for (int i = 75; i < 80; i++) {
        for (int j = 0; j < 4 + k; j++) {
            c.X = i;
            c.Y = j;
            g_Console.writeToBuffer(c, " ", 0x4A);
        }
        k++;
    }
    //bottom right
    k = 0;
    for (int i = 75; i < 80; i++) {
        for (int j = 21 - k; j < 25; j++) {
            c.X = i;
            c.Y = j;
            g_Console.writeToBuffer(c, " ", 0x4A);
        }
        k++;
    }
    //top middle
    createtopmiddle(9);
    createtopmiddle(16);
    createtopmiddle(23);
    createtopmiddle(30);
    createtopmiddle(37);
    createtopmiddle(44);
    createtopmiddle(51);
    createtopmiddle(58);
    createtopmiddle(65);
    //bottom middle
    createbottommiddle(8);
    createbottommiddle(16);
    createbottommiddle(23);
    createbottommiddle(30);
    createbottommiddle(37);
    createbottommiddle(44);
    createbottommiddle(51);
    createbottommiddle(58);
    createbottommiddle(65);
    c.X = 33;
    c.Y = g_Console.getConsoleSize().Y / 2;
    //loading bar
    g_Console.writeToBuffer(c, "Loading....", 0x03);
    //random text at bottom
    if (randomNO == 0) {
        c.X = 27;
        c.Y++;
        g_Console.writeToBuffer(c, "Imma firin my....water");
    }
    else if (randomNO == 1) {
        c.X = 21;
        c.Y++;
        g_Console.writeToBuffer(c, "Spacebar to shoot,arrow keys to move");
    }
    else if (randomNO == 2) {
        c.X = 7;
        c.Y++;
        g_Console.writeToBuffer(c, "Did you know?Phlogiston is created by four braindead Students? ");
    }
    else if (randomNO == 3) {
        c.X = 31;
        c.Y++;
        g_Console.writeToBuffer(c, "Welcome to hell!");
    }
}
void deathscreen(void) {

}
void victoryscreen(void) {

}
void credits(void) {
    COORD C;
    //turn entire border red
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 25; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0x4A);
        }
    }
    //pillars
    for (int i = 0; i < 25; i++) {
        C.X = 20;
        C.Y = i;
        g_Console.writeToBuffer(C, " ", 0x5A);
    }
    for (int i = 0; i < 25; i++) {
        C.X = 60;
        C.Y = i;
        g_Console.writeToBuffer(C, " ", 0x5A);
    }
    createbottommiddle(18);
    createbottommiddle(58);
    createtopmiddle(18);
    createtopmiddle(58);
    //back
    C.X = 76;
    C.Y = 0;
    g_Console.writeToBuffer(C, "Back", 0x8B);
}
void Ammunition(void) {
    COORD C;
    string Display;

    //border
    C.X = 0;
    C.Y = 24;

    if (g_skKeyEvent[K_SPACE].keyDown) {
        if (Ammo > 0) {
            Ammo--;
        }
  
    }
    Display = to_string(Ammo);
    g_Console.writeToBuffer(C, Display + "/100", 0x1A);

}
void levelEvents(void) {
    if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        if (g_mouseEvent.mousePosition.X >= 15 && g_mouseEvent.mousePosition.X <= 18 && g_mouseEvent.mousePosition.Y == 10) {
            Levelselect = false;
            startingscreen = true;
        }
        else if (g_mouseEvent.mousePosition.X >= 20 && g_mouseEvent.mousePosition.X <= 27 && g_mouseEvent.mousePosition.Y == 10) {
            Levelselect = false;
            Storytutorial = true;
            randomtext = true;
            loading = true;
            level = 0;
            k = g_dElapsedTime;
        }
    }
}
void levelselect(void) {
    COORD C;
    //turn entire screen gray
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 25; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0x7A);
        }
    }
    //background for buttons
    for (int i = 13; i < 63; i++) {
        C.X = i;
        C.Y = 9;
        g_Console.writeToBuffer(C, " ", 0xBB);
    }
    for (int i = 13; i < 63; i++) {
        C.X = i;
        C.Y = 10;
        g_Console.writeToBuffer(C, " ", 0xBB);
    }
    for (int i = 13; i < 63; i++) {
        C.X = i;
        C.Y = 11;
        g_Console.writeToBuffer(C, " ", 0xBB);
    }
    // random dots
    for (int i = 0; i < 2; i++) {
        C.X = 2 + i;
        C.Y = 3;
        g_Console.writeToBuffer(C, " ", 0x4a);
    }
    for (int i = 0; i < 2; i++) {
        C.X = 40 + i;
        C.Y = 1;
        g_Console.writeToBuffer(C, " ", 0x3a);
    }
    for (int i = 0; i < 2; i++) {
        C.X = 70 + i;
        C.Y = 13;
        g_Console.writeToBuffer(C, " ", 0x4a);
    }
    for (int i = 0; i < 2; i++) {
        C.X = 38 + i;
        C.Y = 18;
        g_Console.writeToBuffer(C, " ", 0x3a);
    }
    for (int i = 0; i < 2; i++) {
        C.X = 4 + i;
        C.Y = 13;
        g_Console.writeToBuffer(C, " ", 0x4a);
    }
    for (int i = 0; i < 2; i++) {
        C.X = 17 + i;
        C.Y = 17;
        g_Console.writeToBuffer(C, " ", 0x3a);
    }
    for (int i = 0; i < 2; i++) {
        C.X = 76 + i;
        C.Y = 23;
        g_Console.writeToBuffer(C, " ", 0x4a);
    }
    for (int i = 0; i < 2; i++) {
        C.X = 77 + i;
        C.Y = 5;
        g_Console.writeToBuffer(C, " ", 0x3a);
    }
    //Back
    C.X = 15;
    C.Y = 10;
    g_Console.writeToBuffer(C, "Back", 0x8B);
    //Tutorial
    C.X += 5;
    g_Console.writeToBuffer(C, "Tutorial", 0x8B);
    //Level 1
    C.X += 9;
    if (level1status == false) {
        g_Console.writeToBuffer(C, "      ", 0x8B);
    }
    else {
        g_Console.writeToBuffer(C, "Level 1", 0x8B);
    }
    //Level 2
    C.X += 8;
    if (level2status == false) {
        g_Console.writeToBuffer(C, "      ", 0x8B);
    }
    else {
        g_Console.writeToBuffer(C, "Level 2", 0x8B);
    }
    //Level 3
    C.X += 8;
    if (level3status == false) {
        g_Console.writeToBuffer(C, "      ", 0x8B);
    }
    else {
        g_Console.writeToBuffer(C, "Level 3", 0x8B);
    }
    //Level 4
    C.X += 8;
    if (level4status == false) {
        g_Console.writeToBuffer(C, "      ", 0x8B);
    }
    else {
        g_Console.writeToBuffer(C, "Level 4", 0x8B);
    }
}
void pauseEvents(void) {
    if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        if (g_mouseEvent.mousePosition.X >= 49 && g_mouseEvent.mousePosition.X <= 69 && g_mouseEvent.mousePosition.Y == 7) {
            Levelselect = true;
            paused = false;
            Tutorial = false;
            soundcheck = true;
        }
        else if (g_mouseEvent.mousePosition.X >= 55 && g_mouseEvent.mousePosition.X <= 62 && g_mouseEvent.mousePosition.Y == 15) {
            paused = false;
            soundcheck = true;
        }
    }
}
void pausemenu(void) {
    COORD C;
    //turns entire screen black
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 25; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0x1A);
        }
    }
    //half
    for (int i = 0; i < 41; i++) {
        for (int j = 0; j < 25; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0x3A);
        }
    }
    //border
    for (int i = 0; i < 80; i++) {
        C.X = i;
        C.Y = 0;
        g_Console.writeToBuffer(C, " ", 0x5A);
    }
    for (int i = 0; i < 80; i++) {
        C.X = i;
        C.Y = 24;
        g_Console.writeToBuffer(C, " ", 0x5A);
    }
    for (int i = 0; i < 25; i++) {
        C.X = 0;
        C.Y = i;
        g_Console.writeToBuffer(C, " ", 0x5A);
    }
    for (int i = 0; i < 25; i++) {
        C.X = 1;
        C.Y = i;
        g_Console.writeToBuffer(C, " ", 0x5A);
    }
    for (int i = 0; i < 80; i++) {
        C.X = 79;
        C.Y = i;
        g_Console.writeToBuffer(C, " ", 0x5A);
    }
    for (int i = 0; i < 80; i++) {
        C.X = 78;
        C.Y = i;
        g_Console.writeToBuffer(C, " ", 0x5A);
    }
    for (int i = 0; i < 25; i++) {
        C.X = 40;
        C.Y = i;
        g_Console.writeToBuffer(C, " ", 0x5A);
    }
    //p
    for (int i = 12; i < 16; i++) {
        for (int j = 5; j < 20; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0x4A);
        }
    }
    for (int i = 12; i < 27; i++) {
        for (int j = 5; j < 7; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0x4A);
        }
    }
    for (int i = 12; i < 27; i++) {
        for (int j = 9; j < 11; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0x4A);
        }
    }
    for (int i = 25; i < 29; i++) {
        for (int j = 5; j < 11; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0x4A);
        }
    }
    //button border
    for (int i = 47; i < 71; i++) {
        for (int j = 6; j < 9; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0xBB);
        }
    }
    for (int i = 53; i < 65; i++) {
        for (int j = 14; j < 17; j++) {
            C.X = i;
            C.Y = j;
            g_Console.writeToBuffer(C, " ", 0xBB);
        }
    }
    //Back to level select
    C.X = 49;
    C.Y = 7;
    g_Console.writeToBuffer(C, "Back To Level Select", 0x8B);
    //continue
    C.X = 55;
    C.Y += 8;
    g_Console.writeToBuffer(C, "Continue", 0x8B);
    //top middle
    createtopmiddle(38);
    //bottom middle
    createbottommiddle(38);


}
void healthbar(void) {
    COORD C;
    //border 
    for (int i = 0; i < 24; i++) {
        C.Y = 0;
        C.X = i;
        g_Console.writeToBuffer(C, " ", 0x9A);
    }
    for (int i = 0; i < 24; i++) {
        C.Y = 2;
        C.X = i;
        g_Console.writeToBuffer(C, " ", 0x9A);
    }
    for (int i = 0; i < 2; i++) {
        C.Y = 1;
        C.X = i;
        g_Console.writeToBuffer(C, " ", 0x9A);
    }
    for (int i = 22; i < 24; i++) {
        C.Y = 1;
        C.X = i;
        g_Console.writeToBuffer(C, " ", 0x9A);
    }
    //health bars
    //red
    for (int i = 2; i < 10; i++) {
        C.Y = 1;
        C.X = i;
        g_Console.writeToBuffer(C, " ", 0x4A);
    }
    //yellow
    for (int i = 10; i < 16; i++) {
        C.Y = 1;
        C.X = i;
        g_Console.writeToBuffer(C, " ", 0x6A);
    }
    //green
    for (int i = 16; i < 22; i++) {
        C.Y = 1;
        C.X = i;
        g_Console.writeToBuffer(C, " ", 0x2A);
    }
}
void CheckAndUpdate()
{
    for (int i = 0; i < 256; i++)
    {
        if (Amount_ofbullet[i] != nullptr)
        {
            Amount_ofbullet[i]->UpdateXandY(g_Console);
            if ( ((Amount_ofbullet[i]->x >= 79) || (Amount_ofbullet[i]->x < 0)) || ((Amount_ofbullet[i]->y >= 24) || (Amount_ofbullet[i]->y < 0)) )
            {
                delete Amount_ofbullet[i];
                Amount_ofbullet[i] = nullptr;
            }
        }
    }

}



void MakesBullet()
{
    for (int i = 0; i < 256; i++)
    {
        if (Amount_ofbullet[i] == nullptr)
        {
            Amount_ofbullet[i] = new Bullet(g_sChar, play.GetDirection());
            return;
        }
    }
    for (int i = 0; i < 256; i++) //pushes 
    {
        if (i + 1 >= 256)
        {
            Amount_ofbullet[i] = nullptr;
        }
        else
        {
            Amount_ofbullet[i + 1] = Amount_ofbullet[i];
        }
    }
}



//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init( void )
{
    // Set precision for floating point output
    g_dElapsedTime = 0.0;    

    // sets the initial state for the game
    g_eGameState = S_SPLASHSCREEN;

    g_sChar.m_cLocation.X = g_Console.getConsoleSize().X / 2;
    g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y / 2;
    g_sChar.m_bActive = true;
    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");

    // remember to set your keyboard handler, so that your functions can be notified of input events
    g_Console.setKeyboardHandler(keyboardHandler);
    g_Console.setMouseHandler(mouseHandler);
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Get all the console input events
//            This function sets up the keyboard and mouse input from the console.
//            We will need to reset all the keyboard status, because no events will be sent if no keys are pressed.
//
//            Remember to set the handlers for keyboard and mouse events.
//            The function prototype of the handler is a function that takes in a const reference to the event struct
//            and returns nothing. 
//            void pfKeyboardHandler(const KEY_EVENT_RECORD&);
//            void pfMouseHandlerconst MOUSE_EVENT_RECORD&);
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput( void )
{
    // resets all the keyboard events
    memset(g_skKeyEvent, 0, K_COUNT * sizeof(*g_skKeyEvent));
    // then call the console to detect input from user
    g_Console.readConsoleInput();    
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the keyboard input. Whenever there is a keyboard event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            The KEY_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any keyboard event in the Splashscreen state
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent - reference to a key event struct
// Output   : void
//--------------------------------------------------------------
void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent)
{    
    switch (g_eGameState)
    {
    case S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case S_GAME: gameplayKBHandler(keyboardEvent); // handle gameplay keyboard event 
        break;
    }
}

//--------------------------------------------------------------
// Purpose  : This is the handler for the mouse input. Whenever there is a mouse event, this function will be called.
//            Ideally, you should pass the key event to a specific function to handle the event.
//            This is because in some states, some keys would be disabled. Hence, to reduce your code complexity, 
//            it would be wise to split your keyboard input handlers separately.
//            
//            For the mouse event, if the mouse is not moved, no event will be sent, hence you should not reset the mouse status.
//            However, if the mouse goes out of the window, you would not be able to know either. 
//
//            The MOUSE_EVENT_RECORD struct has more attributes that you can use, if you are adventurous enough.
//
//            In this case, we are not handling any mouse event in the Splashscreen state
//            
// Input    : const MOUSE_EVENT_RECORD& mouseEvent - reference to a mouse event struct
// Output   : void
//--------------------------------------------------------------
void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{    
    switch (g_eGameState)
    {
    case S_SPLASHSCREEN: // don't handle anything for the splash screen
        break;
    case S_GAME: gameplayMouseHandler(mouseEvent); // handle gameplay mouse event
        break;
    }
}

//--------------------------------------------------------------
// Purpose  : This is the keyboard handler in the game state. Whenever there is a keyboard event in the game state, this function will be called.
//            
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//--------------------------------------------------------------
void gameplayKBHandler(const KEY_EVENT_RECORD& keyboardEvent)
{
    // here, we map the key to our enums
    EKEYS key = K_COUNT;
    switch (keyboardEvent.wVirtualKeyCode)
    {
    case VK_UP: key = K_UP; break;
    case VK_DOWN: key = K_DOWN; break;
    case VK_LEFT: key = K_LEFT; break; 
    case VK_RIGHT: key = K_RIGHT; break; 
    case VK_SPACE: key = K_SPACE; break;
    case VK_ESCAPE: key = K_ESCAPE; break; 
    case 'R': key = K_R; break;
    }
    // a key pressed event would be one with bKeyDown == true
    // a key released event would be one with bKeyDown == false
    // if no key is pressed, no event would be fired.
    // so we are tracking if a key is either pressed, or released
    if (key != K_COUNT)
    {
        g_skKeyEvent[key].keyDown = keyboardEvent.bKeyDown;
        g_skKeyEvent[key].keyReleased = !keyboardEvent.bKeyDown;
    }    
}

//--------------------------------------------------------------
// Purpose  : This is the mouse handler in the game state. Whenever there is a mouse event in the game state, this function will be called.
//            
//            If mouse clicks are detected, the corresponding bit for that mouse button will be set.
//            mouse wheel, 
//            
// Input    : const KEY_EVENT_RECORD& keyboardEvent
// Output   : void
//--------------------------------------------------------------
void gameplayMouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)
{
    if (mouseEvent.dwEventFlags & MOUSE_MOVED) // update the mouse position if there are no events
    {
        g_mouseEvent.mousePosition = mouseEvent.dwMousePosition;
    }
    g_mouseEvent.buttonState = mouseEvent.dwButtonState;
    g_mouseEvent.eventFlags = mouseEvent.dwEventFlags;
}
void LoadingScreenWait2(int g,int time) {
    if (g_dElapsedTime > time + g) {
        loading = false;
        k = g_dElapsedTime;
        //put all my in and outs here for xl
    }
}
//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;

    switch (g_eGameState)
    {
        case S_SPLASHSCREEN :
            splashScreenWait(); // game logic for the splash screen
            break;
        case S_GAME: 
            if (loading == true) {
                LoadingScreenWait2(k,5);//number represents how long the loading screen time is depending on how long 
                for (int i = 0; i < 20; i++) {
                    lvlmanager[i] = nullptr;
                }
                if (level < 0) {
                    break;
                }
                for (int i = 0; i < 20; i++) {
                    lvlmanager[i] = lvl_array[level][i];
                    //int level;
                }

                //the entities and stuff load
            }
            else {
                updateGame(); // gameplay logic when we are in the game
            }
            break;
    }
}

void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 5.0) // wait for 8 seconds to switch to game mode, else do nothing
        g_eGameState = S_GAME;
}

void updateGame()       // gameplay logic
{
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
                        // sound can be played here too.

}

void moveCharacter()
{    
    // Updating the location of the character based on the key release
    // providing a beep sound whenver we shift the character
    if (g_skKeyEvent[K_UP].keyDown && g_sChar.m_cLocation.Y > 0)
    {
        //Beep(1440, 30);
        g_sChar.m_cLocation.Y--;
        play.SetDirection('U');
    }
    if (g_skKeyEvent[K_LEFT].keyDown && g_sChar.m_cLocation.X > 0)
    {
        //Beep(1440, 30);
        g_sChar.m_cLocation.X--;
        play.SetDirection('L');
    }
    if (g_skKeyEvent[K_DOWN].keyDown && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
    {
        //Beep(1440, 30);
        g_sChar.m_cLocation.Y++;   
        play.SetDirection('D');
    }
    if (g_skKeyEvent[K_RIGHT].keyDown && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
    {
        //Beep(1440, 30);
        g_sChar.m_cLocation.X++;    
        play.SetDirection('R');
    }
    if (g_skKeyEvent[K_SPACE].keyDown)
    {
        /*g_sChar.m_bActive = !g_sChar.m_bActive;*/
        if ((Ammo != 0) || (Ammo > 0))
        {
            MakesBullet();
        }
    }


   
}
void processUserInput()
{
    // pause the game if player hits the escape key
    if (g_skKeyEvent[K_ESCAPE].keyReleased) {
        paused = true;
        PlaySound(NULL, 0, 0);
    }
}
void renderdadlevel() {

}
void rendermomlevel() {

}
void renderLevel3() {

}
void renderLevel2() {

}
void renderLevel1() {
    for (int i = 0; i < 20; i++) {
        if (lvlmanager[i] != nullptr) {
            COORD obj_curr = lvlmanager[i]->get_coord();

            g_Console.writeToBuffer(obj_curr, " ", 0x4C);
        }

    }
}
void renderTutorial()
{
    LevelMap TutorialLevel;
    TutorialLevel.LoadLevel1();
    TutorialLevel.TransferArray();
    // Set up sample colours, and output shadings
    const char colors[] = {
        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x0F,0xF7, 0xFF,0x7C,0xA2,0xAA,
        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6,0xC0,
    };
    // 0x1C No colour
    // 0x2C Green
    // 0x3C Light Blue
    // 0x4C Red
    // 0x5C Purple
    // 0x6C Yellow
    // 0x7C Gray
    // 0x8C Reddish Pink with gray border
    // 0x9C Reddish Pink with blue border
    // 0x1D No colour
    // 0x2D Green
    // 0x3D Light Blue
    // 0xFF White
    COORD c;
    LevelMap Level1;
    // Checking for Symbol


    for (int i = 0; i < 80; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            // Black -> '*' -> Walls
            if (TutorialLevel.LevelArray[i][j] == 'x')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[5]);
            }
            // Gray -> '@'
            if (TutorialLevel.LevelArray[i][j] == '.')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[8]);
            }
            // White -> '#'
            if (TutorialLevel.LevelArray[i][j] == '#')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[7]);
            }
            // Green -> '&'
            if (TutorialLevel.LevelArray[i][j] == '*')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[10]);
            }
        }
    }

    for (int i = 0; i < 20; i++) {
        if (lvlmanager[i] != nullptr) {
            COORD obj_curr = lvlmanager[i]->get_coord();

            g_Console.writeToBuffer(obj_curr, " ", 0x4C);
        }

    }
}
//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
    clearScreen();      // clears the current screen and draw from scratch 
    switch (g_eGameState)
    {
    case S_SPLASHSCREEN:
        renderSplashScreen();
        break;
    case S_GAME:
        if (paused == true) {
            pausemenu();
            pauseEvents();
        }
        else if (Levelselect == true) {
            if (soundcheck == true) {
                PlaySound(TEXT("435378__kojiro-miura__mission-of-a-little-elf.wav"), NULL, SND_ASYNC | SND_LOOP);
                soundcheck = false;
            }
            levelselect();
            levelEvents();
        }
        else if (loading == true) {
            loadingscreen();
        }
        else if (Credits == true) {
            credits();
            creditbackselect();
            credittext();
        }
        else if (Storytutorial == true) {
            renderTutorial();
            storytutorial();
            storytutorialskip();
        }
        else if (startingscreen == true) {
            if (soundcheck == true) {
                PlaySound(TEXT("435378__kojiro-miura__mission-of-a-little-elf.wav"), NULL, SND_ASYNC | SND_LOOP);
                soundcheck = false;
            }
            StartingGamescreen();
            StartingEvents();
        }
        else if (Tutorial == true || level1 == true || level2 == true || level3 == true || level4 == true) {
            if (soundcheck == true) {
                PlaySound(TEXT("414214__sirkoto51__anime-fight-music-loop-1.wav"), NULL, SND_ASYNC | SND_LOOP);
                soundcheck = false;
            }
            renderGame();
            Ammunition();
            healthbar();
            renderFramerate();      // renders debug information, frame rate, elapsed time, etc
            renderInputEvents();    // renders status of input events
            for (int i = 0; i < 20; i++)
            {
                if (lvlmanager[i] != nullptr)
                {
                    lvlmanager[i]->EVERYTHINGUPDATE();
                }
            }
        }
        break;
    }

    renderToScreen();       // dump the contents of the buffer to the screen, one frame worth of game
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x1F);
}

void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    g_Console.flushBufferToConsole();
}

void renderSplashScreen()  // renders the splash screen
{
    COORD c;
        //turns entire screen gray
        for (int i = 0; i < 80; i++) {
            for (int j = 0; j < 25; j++) {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", 0x7A);
            }
        }
        int k = 0;
        //top left
        for (int j = 0; j < 8; j++) {
            for (int i = 0; i < 5; i++) {
                if (i < 8 - j) {
                    c.X = i;
                    c.Y = j;
                    g_Console.writeToBuffer(c, " ", 0x5A);
                }
            }
        }
        //bottom left
        for (int i = 0; i < 5; i++) {
            for (int j = 17 + i; j < 25; j++) {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", 0x5A);
            }
        }
        //top right
        for (int i = 75; i < 80; i++) {
            for (int j = 0; j < 4 + k; j++) {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", 0x5A);
            }
            k++;
        }
        //bottom right
        k = 0;
        for (int i = 75; i < 80; i++) {
            for (int j = 21 - k; j < 25; j++) {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", 0x5A);
            }
            k++;
        }
    //top middle
    createtopmiddle(9);
    createtopmiddle(16);
    createtopmiddle(23);
    createtopmiddle(30);
    createtopmiddle(37);
    createtopmiddle(44);
    createtopmiddle(51);
    createtopmiddle(58);
    createtopmiddle(65);
    //bottom middle
    createbottommiddle(8);
    createbottommiddle(16);
    createbottommiddle(23);
    createbottommiddle(30);
    createbottommiddle(37);
    createbottommiddle(44);
    createbottommiddle(51);
    createbottommiddle(58);
    createbottommiddle(65);
    c.X = 28;
    c.Y = g_Console.getConsoleSize().Y / 2;
    //Text
    g_Console.writeToBuffer(c, "Enter the gates of hell", 0x03);
   
}

void renderGame()
{
    if (Tutorial == true) {
        renderTutorial();// renders the map to the buffer first

    }
    else if (level1 == true) {
        renderLevel1();

    }
    else if (level2 == true) {
        renderLevel2();

    }
    else if (level3 == true) {
        renderLevel3();

    }
    else if (level4 == true) {
        if (momstatus == true) {
            rendermomlevel();
        }
        else if (dadstatus == true) {
            renderdadlevel();
        }

    }

    CheckAndUpdate();
    renderCharacter();  // renders the character into the buffer
    renderInputEvents();
}


void renderCharacter()
{
    // Draw the location of the character
    WORD charColor = 0xC3;
    if (g_sChar.m_bActive)
    {
        charColor = 0xA1;
    }
    g_Console.writeToBuffer(g_sChar.m_cLocation, (char)1, charColor);
}

void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / g_dDeltaTime << "fps";
    c.X = g_Console.getConsoleSize().X - 9;
    c.Y = 0;
    //g_Console.writeToBuffer(c, ss.str());

    // displays the elapsed time
    ss.str("");
    ss << g_dElapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
   // g_Console.writeToBuffer(c, ss.str(), 0x59);
}

// this is an example of how you would use the input events
void renderInputEvents()
{
    // keyboard events
    COORD startPos = {50, 2};
    std::ostringstream ss;
    std::string key;
    for (int i = 0; i < K_COUNT; ++i)
    {
        ss.str("");
        switch (i)
        {
        case K_UP: key = "UP";
            break;
        case K_DOWN: key = "DOWN";
            break;
        case K_LEFT: key = "LEFT";
            break;
        case K_RIGHT: key = "RIGHT";
            break;
        case K_SPACE: key = "SPACE";
            break;
        case K_R: key = "RELOAD";
            break;
        default: continue;
        }
        if (g_skKeyEvent[i].keyDown)
            ss << key << " pressed";
        else if (g_skKeyEvent[i].keyReleased)
            ss << key << " released";
        else
            ss << key << " not pressed";

        COORD c = { startPos.X, startPos.Y + i };
      //  g_Console.writeToBuffer(c, ss.str(), 0x17);
    }

    // mouse events    
    ss.str("");
    ss << "Mouse position (" << g_mouseEvent.mousePosition.X << ", " << g_mouseEvent.mousePosition.Y << ")";
    g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y, ss.str(), 0x5A);
   // g_Console.writeToBuffer(g_mouseEvent.mousePosition, ss.str(), 0x59);
    ss.str("");
    switch (g_mouseEvent.eventFlags)
    {
    case 0:
        if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {

            ss.str("Left Button Pressed");
           // g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 1, ss.str(), 0x59);
        }
        else if (g_mouseEvent.buttonState == RIGHTMOST_BUTTON_PRESSED)
        {
            ss.str("Right Button Pressed");
           // g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 2, ss.str(), 0x59);
        }
        else
        {
            ss.str("Some Button Pressed");
          //  g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 3, ss.str(), 0x59);
        }
        break;
    case DOUBLE_CLICK:
        ss.str("Double Clicked");
      //  g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 4, ss.str(), 0x59);
        break;        
    case MOUSE_WHEELED:
        if (g_mouseEvent.buttonState & 0xFF000000)
            ss.str("Mouse wheeled down");
        else
            ss.str("Mouse wheeled up");
       // g_Console.writeToBuffer(g_mouseEvent.mousePosition.X, g_mouseEvent.mousePosition.Y + 5, ss.str(), 0x59);
        break;
    default:        
        break;
    }
    
}



