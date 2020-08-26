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
bool Tutorialstatus = true;
bool level1status = true;
bool level2status = true;
bool level3status = true;
bool level4status = true;
bool dadstatus = false;
bool momstatus = false;
bool Storytutorial = false;
bool Storylevel1 = false;
bool resetvalues = false;
int Text =  0;
int increaseY = 0;
int increaseX = 0;
int storyincreaseY[100] = { 0, };
int storyincreaseX[100] = { 0, };
int StoryText[100] = { 0, };
int storytime[100] = { 0, };
int Ammo = 100;
LevelMap Level;
SKeyEvent g_skKeyEvent[K_COUNT];
SMouseEvent g_mouseEvent;
const char colors[] = {
        char(0x1A), char(0x2A), char(0x91), char(0x4D), char(0x5E),
        char(0x0F), char(0xF7), char(0xFF), char(0x7C), char(0xA2),
        char(0xAA), char(0xA1), char(0xB2), char(0xC3), char(0xD4),
        char(0xE5), char(0xF6), char(0xC0), char(0x88), char(0xC4),
        char(0xF7), char(0x6E), char(0x66)
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
// Game specific variables here
SGameChar   g_sChar;
EGAMESTATES g_eGameState = S_SPLASHSCREEN; // initial state

// Console object
Console g_Console(80, 25, "SP1 Framework");

Bullet* Amount_ofbullet[256] = { nullptr,};



player play(&g_sChar);
bool storytimer(float time,float interval) {
    if (int(g_dElapsedTime) >= unsigned long long (time) + unsigned long long (interval)) {
        return true;
    }
    return false;
}
void actorandtextmovement(int startingx,int startingy,int endingx,int endingy,string text,string direction,int no,float speed,string type) {
    if (StoryText[no] == 0) {
        storytime[no] = int (g_dElapsedTime);
    }
    COORD C;
    if (storytimer(float(storytime[no]), speed) == true) {
        if (direction == "LEFT") {
            storyincreaseX[no]--;
        }
        else if (direction == "RIGHT") {
            storyincreaseX[no]++;
        }
        else if (direction == "UP") {
            storyincreaseY[no]--;
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
                g_Console.writeToBuffer(C, char(1), 0xA1);
            }
            else if (type == "ENEMY") {
                g_Console.writeToBuffer(C, char(1), 0x4A);
            }
            else if (type == "ANTAGONIST") {
                g_Console.writeToBuffer(C, char(1), 0x64);
            }
            else if (type == "PROTAGONIST") {
                g_Console.writeToBuffer(C, char(1), 0x5A);
            }
        }
        else if (C.Y <= startingy && C.Y >= endingy && direction == "UP") {
            if (text != "EMPTY") {
                g_Console.writeToBuffer(C, text, 0x8B);
            }
            else if (type == "ACTOR") {
                g_Console.writeToBuffer(C, char(1), 0xA1);
            }
            else if (type == "ENEMY") {
                g_Console.writeToBuffer(C, char(1), 0x4A);
            }
            else if (type == "ANTAGONIST") {
                g_Console.writeToBuffer(C, char(1), 0x64);
            }
            else if (type == "PROTAGONIST") {
g_Console.writeToBuffer(C, char(1), 0x5A);
            }
        }
    }
    if (endingy == NULL) {
        if (C.X >= startingx && C.X <= endingx && direction == "RIGHT") {
            if (text != "EMPTY") {
                g_Console.writeToBuffer(C, text, 0x8B);
            }
            else if (type == "ACTOR") {
                g_Console.writeToBuffer(C, char(1), 0xA1);
            }
            else if (type == "ENEMY") {
                g_Console.writeToBuffer(C, char(1), 0x4A);
            }
            else if (type == "ANTAGONIST") {
                g_Console.writeToBuffer(C, char(1), 0x64);
            }
            else if (type == "PROTAGONIST") {
                g_Console.writeToBuffer(C, char(1), 0x5A);
            }
        }
        else if (C.X <= startingx && C.X >= endingx && direction == "LEFT") {
            if (text != "EMPTY") {
                g_Console.writeToBuffer(C, text, 0x8B);
            }
            else if (type == "ACTOR") {
                g_Console.writeToBuffer(C, char(1), 0xA1);
            }
            else if (type == "ENEMY") {
                g_Console.writeToBuffer(C, char(1), 0x4A);
            }
            else if (type == "ANTAGONIST") {
                g_Console.writeToBuffer(C, char(1), 0x64);
            }
            else if (type == "PROTAGONIST") {
                g_Console.writeToBuffer(C, char(1), 0x5A);
            }
        }
    }
    if (StoryText[no] == 2) {
        StoryText[no]--;
    }
    StoryText[no]++;
}
void storybuttonskip(void) {
    if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        if (g_mouseEvent.mousePosition.X >= 76 && g_mouseEvent.mousePosition.X <= 80 && g_mouseEvent.mousePosition.Y == 0) {
            if (Storylevel1 == true) {
                Storylevel1 = false;
                level1 = true;
            }
            else if (Storytutorial == true) {
                Storytutorial = false;
                Tutorial = true;
            }
            soundcheck = true;
            for (int i = 0; i < 100; i++) {
                storyincreaseX[i] = 0;
                storyincreaseY[i] = 0;
                storytime[i] = 0;
                StoryText[i] = 0;
            }
        }
    }
}
void storylevel1(void) {
    COORD C;
    //skip button
    C.X = 76;
    C.Y = 0;
    g_Console.writeToBuffer(C, "Skip", 0x8B);
    if (storytimer(k, 0) == true) {
        actorandtextmovement(80, 17, 60, NULL, "EMPTY", "LEFT", 0, 0.5, "PROTAGONIST");
    }
    if (storytimer(k, 4) == true) {
        if (storytimer(k, 8) != true) {
            C.X = 50;
            C.Y = 3;
            g_Console.writeToBuffer(C, char(1), 0x5A);
            C.Y = 2;
            g_Console.writeToBuffer(C, "Mom?Dad?", 0x8B);
        }
    }
    if (storytimer(k, 9) == true) {
        if (storytimer(k, 13) != true) {
            C.X = 55;
            C.Y = 23;
            g_Console.writeToBuffer(C, char(1), 0x5A);
            C.Y = 22;
            g_Console.writeToBuffer(C, "Not here either", 0x8B);
        }
    }
    if (storytimer(k, 14) == true) {
        C.X = 45;
        C.Y = 13;
        g_Console.writeToBuffer(C, char(1), 0x5A);
        C.Y = 12;
        g_Console.writeToBuffer(C, "Ah ****,here we go again", 0x8B);
        C.X = 10;
        C.Y = 3;
        g_Console.writeToBuffer(C, char(1), 0x4A);
        C.X = 17;
        C.Y = 18;
        g_Console.writeToBuffer(C, char(1), 0x4A);
        C.X = 23;
        C.Y = 8;
        g_Console.writeToBuffer(C, char(1), 0x4A);
        C.X = 20;
        C.Y = 14;
        g_Console.writeToBuffer(C, char(1), 0x4A);
    }
    if (storytimer(k, 20) == true){
        Storylevel1 = false;
        level1 = true;
        soundcheck = true;
        for (int i = 0; i < 100; i++) {
            storyincreaseX[i] = 0;
            storyincreaseY[i] = 0;
            storytime[i] = 0;
            StoryText[i] = 0;
        }
    }
}
void storytutorial(void) {
    COORD C;
    //skip button
    C.X = 76;
    C.Y = 0;
    g_Console.writeToBuffer(C, "Skip", 0x8B);
    //Actor
    if (storytimer(float(k), 0) == true) {
        //mainpeople
        actorandtextmovement(20, 7, NULL, 17, "EMPTY", "DOWN", 0, 2.0, "ACTOR");
        actorandtextmovement(19, 8, NULL, 18, "EMPTY", "DOWN", 1, 2.0, "ACTOR");
        actorandtextmovement(21, 8, NULL, 18, "EMPTY", "DOWN", 2, 2.0, "PROTAGONIST");
        //randompeople
        actorandtextmovement(0, 6, 80, NULL, "EMPTY", "RIGHT", 3, 1.0, "ACTOR");
    }
    if (storytimer(float(k), 6.0) == true) {
        actorandtextmovement(25, 10, NULL, 13, "Player:There's only one person here...","DOWN",4,2.0,"EMPTY");
    }
    if (storytimer(float(k), 12.0) == true) {
        actorandtextmovement(25, 13, NULL, 17, "Dad:Of Course,it's a ghost town we're exploring", "DOWN", 5, 2.0, "EMPTY");
    }
    if (storytimer(float(k), 22.0) == true) {
        actorandtextmovement(20, 17, 66, NULL, "EMPTY", "RIGHT", 6, 2.0, "ACTOR");
        actorandtextmovement(19, 18, 65, NULL, "EMPTY", "RIGHT", 7, 2.0, "ACTOR");
        actorandtextmovement(21, 18, 67, NULL, "EMPTY", "RIGHT", 8, 2.0, "PROTAGONIST");
    }
    if (storytimer(float(k), 22.0) == true) {
        if (storytimer(float(k), 28.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player:Why are we even here?",0x8B);
        }
    }
    if (storytimer(float(k), 28.0) == true) {
        if (storytimer(float(k), 36.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Mum:Can't you be a little bit energetic?", 0x8B);
        }
    }
    if (storytimer(float(k), 36.0) == true) {
        if (storytimer(float(k), 42.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Mum:We haven't been going out for days", 0x8B);
        }
    }
    if (storytimer(float(k), 42.0) == true) {
        if (storytimer(float(k), 48.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Mum:This should have been exciting for us!", 0x8B);
        }
    }
    if (storytimer(float(k), 48.0) == true) {
        if (storytimer(float(k), 56.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad: And when are you going to get a job?", 0x8B);
        }
    }
    if (storytimer(float(k), 56.0) == true) {
        if (storytimer(float(k), 62.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad: You've been lazying around this year...", 0x8B);
        }
    }
    if (storytimer(float(k), 62.0) == true) {
        if (storytimer(float(k), 68.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad: Watching whatever vtuber things you've been saying", 0x8B);
        }
    }
    if (storytimer(float(k), 68.0) == true) {
        if (storytimer(float(k), 72.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player: ...", 0x8B);
        }
    }
    if (storytimer(float(k), 72.0) == true) {
        if (storytimer(float(k), 78.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player: I will get a job just give me some more time.", 0x8B);
        }
    }
    if (storytimer(float(k), 78.0) == true) {
        if (storytimer(float(k), 84.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player: And don't forget what happened last time...", 0x8B);
        }
    }
    if (storytimer(float(k), 84.0) == true) {
        if (storytimer(float(k), 90.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad: Oh right...that time...", 0x8B);
        }
    }
    if (storytimer(float(k), 90.0) == true) {
        if (storytimer(float(k), 96.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad: That Accident...", 0x8B);
        }
    }
    if (storytimer(float(k), 96.0) == true) {
        if (storytimer(float(k), 102.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad:You quit your firefighting job because of that", 0x8B);
        }
    }
    if (storytimer(float(k), 102.0) == true) {
        if (storytimer(float(k), 108.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Dad: I should have disowned you back then...", 0x8B);
        }
    }
    if (storytimer(float(k), 108.0) == true) {
        if (storytimer(float(k), 116.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player: It wasn't like that! Back then was-", 0x8B);
        }
    }
    if (storytimer(float(k), 116.0) == true) {
        if (storytimer(float(k), 122.0) != true) {
            C.X = 65;
            C.Y = 0;
            g_Console.writeToBuffer(C, "BOOM!!", 0x1B);
        }
        
        //mom
        if (storytimer(float(k), 148.0) != true) {
            C.X = 65;
            C.Y = 18;
            g_Console.writeToBuffer(C, char(1), 0xA1);
            //dad
            C.X = 66;
            C.Y = 17;
            g_Console.writeToBuffer(C, char(1), 0xA1);
            //player
            C.X = 67;
            C.Y = 18;
            g_Console.writeToBuffer(C, char(1), 0x5A);
        }
    }
    if (storytimer(float(k), 122.0) == true) {
        if (storytimer(float(k), 128.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Player: Whats happening?", 0x8B);
        }
    }
    if (storytimer(float(k), 128.0) == true) {
        actorandtextmovement(80, 6, 0, NULL, "EMPTY", "LEFT", 9, 0.5, "ACTOR");
        actorandtextmovement(69, 5, 0, NULL, "Help me!!!!!","LEFT",10, 0.5, "EMPTY");
    }
    if (storytimer(float(k), 132.0) == true) {
        actorandtextmovement(80, 6, 0, NULL, "EMPTY", "LEFT", 11, 0.5, "ENEMY");
        actorandtextmovement(65, 5, 0, NULL, "GET BACK HERE!!!", "LEFT", 12, 0.5, "EMPTY");
    }
    if (storytimer(float(k), 138.0) == true) {
        if (storytimer(float(k), 146.0) != true) {
            C.X = 25;
            C.Y = 21;
            g_Console.writeToBuffer(C, "Mum:What....",0x8B);
        }
    }
    if (storytimer(float(k), 146.0) == true) {
        actorandtextmovement(0, 17, 64, NULL, "EMPTY", "RIGHT", 13, 0.5, "ANTAGONIST");
    }
    if (storytimer(float(k), 148.0) == true) {
        if (storytimer(float(k), 157.0) != true) {
            C.X = 0;
            C.Y = 17;
            g_Console.writeToBuffer(C, "Mum:AH!!!!", 0x8B);
            C.Y = 18;
            g_Console.writeToBuffer(C, "Dad:AH!!!!", 0x8B);
            C.X = 67;
            C.Y = 19;
            g_Console.writeToBuffer(C, "Mum!Dad!", 0x8B);
            C.X = 67;
            C.Y = 18;
            g_Console.writeToBuffer(C, char(1), 0x5A);
        }
    }
    if (storytimer(float(k), 157.0) == true) {
        actorandtextmovement(67, 18, 40, NULL, "EMPTY", "LEFT", 14, 0.5, "PROTAGONIST");
    }
    if (storytimer(float(k), 158.0) == true) {
        //enemies
        C.X = 36;
        C.Y = 16;
        g_Console.writeToBuffer(C, char(1), 0x4A);
        C.X = 34;
        C.Y = 19;
        g_Console.writeToBuffer(C, char(1), 0x4A);
        C.X = 36;
        C.Y = 18;
        g_Console.writeToBuffer(C, char(1), 0x4A);
        if (storytimer(float(k), 166.5) != true) {
            C.X = 40;
            C.Y = 18;
            g_Console.writeToBuffer(C, char(1), 0x5A);
            C.X = 20;
            C.Y = 22;
            g_Console.writeToBuffer(C, "Dammit!Who are you guys?!Some weird fire monster?", 0x8B);
        }
    }
    if (storytimer(float(k), 166.0) == true) {
        actorandtextmovement(40, 18, 50, NULL, "EMPTY", "RIGHT", 15, 0.5, "PROTAGONIST");
    }
    if (storytimer(float(k), 167.0)==true){
        if (storytimer(float(k), 173.0) != true) {
            C.X = 50;
            C.Y = 18;
            g_Console.writeToBuffer(C, char(1), 0x5A);
            C.X = 20;
            C.Y = 22;
            g_Console.writeToBuffer(C, "Somehow there's a fire extinguisher here,looks like it work", 0x8B);
        }  
    }
    if (storytimer(float(k), 173.0) == true) {
        if (storytimer(float(k), 179.0) != true) {
            C.X = 50;
            C.Y = 18;
            g_Console.writeToBuffer(C, char(1), 0x5A);
            C.X = 20;
            C.Y = 22;
            g_Console.writeToBuffer(C, "Looks like they are heading to the forest,but these guys....", 0x8B);
        }
    }
    if (storytimer(float(k), 179.0) == true) {
        Tutorial = true;
        Storytutorial = false;
        soundcheck = true;
        for (int i = 0; i < 100; i++) {
            storyincreaseX[i] = 0;
            storyincreaseY[i] = 0;
            storytime[i] = 0;
            StoryText[i] = 0;
        }
    }
}
bool credittimer(int currenttime,float interval) {
    if (int(g_dElapsedTime) >= unsigned long long (currenttime) + unsigned long long (interval)) {
        return true;
    }
    return false;
}
void creditMovement(string text,int startingy,int xposition){
    if (Text == 0) {
        k = int(g_dElapsedTime);
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
    srand((unsigned int)time(NULL));
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
    g_Console.writeToBuffer(C, "Ammo:" + Display + "/100", 0x1A);

}
void levelEvents(void) {
    if (g_mouseEvent.buttonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        if (g_mouseEvent.mousePosition.X >= 15 && g_mouseEvent.mousePosition.X <= 18 && g_mouseEvent.mousePosition.Y == 10) {
            Levelselect = false;
            startingscreen = true;
        }
        else if (level4status == true && g_mouseEvent.mousePosition.X >= 52 && g_mouseEvent.mousePosition.X <= 59 && g_mouseEvent.mousePosition.Y == 10) {
            Levelselect = false;
            level4 = true;
        }
        else if (level3status == true && g_mouseEvent.mousePosition.X >= 45 && g_mouseEvent.mousePosition.X <= 52 && g_mouseEvent.mousePosition.Y == 10) {
            Levelselect = false;
            level3 = true;
        }
        else if (level2status == true && g_mouseEvent.mousePosition.X >= 37 && g_mouseEvent.mousePosition.X <= 44 && g_mouseEvent.mousePosition.Y == 10) {
            Levelselect = false;
            level2 = true;
        }
        else if (level1status == true && g_mouseEvent.mousePosition.X >= 29 && g_mouseEvent.mousePosition.X <= 36 && g_mouseEvent.mousePosition.Y == 10) {
            Levelselect = false;
            Storylevel1 = true;
            randomtext = true;
            loading = true;
            k = int(g_dElapsedTime);
        }
        else if (g_mouseEvent.mousePosition.X >= 20 && g_mouseEvent.mousePosition.X <= 27 && g_mouseEvent.mousePosition.Y == 10) {
            Levelselect = false;
            Storytutorial = true;
            randomtext = true;
            loading = true;
            level = 0;
            k = int(g_dElapsedTime);
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
            level1 = false;
            level2 = false;
            level3 = false;
            level4 = false;
            soundcheck = true;
            resetvalues = true;
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
    C.X = 0;
    C.Y = 23;
    g_Console.writeToBuffer(C, "Health:/", 0x4A);
    //if health...............
   
}
void CheckAndUpdate()
{
    for (int i = 0; i < 256; i++)
    {
        if (Amount_ofbullet[i] != nullptr)
        {
            Amount_ofbullet[i]->UpdateXandY(g_Console);
            if (Level.LevelArray[Amount_ofbullet[i]->x][Amount_ofbullet[i]->y] != 'x' )
            {
                Amount_ofbullet[i]->print();
            }
            if ( ((Amount_ofbullet[i]->x >= 79) || (Amount_ofbullet[i]->x < 0)) || ((Amount_ofbullet[i]->y >= 24) || (Amount_ofbullet[i]->y < 0)) || Level.LevelArray[Amount_ofbullet[i]->x][Amount_ofbullet[i]->y] == 'x')
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

    g_sChar.m_cLocation.X = 73;
    g_sChar.m_cLocation.Y = 16;
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
    if (g_dElapsedTime > unsigned long long(time) + unsigned long long (g)) {
        loading = false;
        k = int(g_dElapsedTime);
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
        if (Level.LevelArray[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y-1] != 'x')
        g_sChar.m_cLocation.Y--;
        play.SetDirection('U');
    }
    if (g_skKeyEvent[K_LEFT].keyDown && g_sChar.m_cLocation.X > 0)
    {
        //Beep(1440, 30);
        if (Level.LevelArray[g_sChar.m_cLocation.X-1][g_sChar.m_cLocation.Y] != 'x')
        g_sChar.m_cLocation.X--;
        play.SetDirection('L');
    }
    if (g_skKeyEvent[K_DOWN].keyDown && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
    {
        //Beep(1440, 30);
        if (Level.LevelArray[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y+1] != 'x')
        g_sChar.m_cLocation.Y++;   
        play.SetDirection('D');
    }
    if (g_skKeyEvent[K_RIGHT].keyDown && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
    {
        //Beep(1440, 30);
        if (Level.LevelArray[g_sChar.m_cLocation.X+1][g_sChar.m_cLocation.Y] != 'x')
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
void renderLevel1() {
    Level.LoadLevel2();
    Level.TransferArray();
    for (int i = 0; i < 20; i++) {
        if (lvlmanager[i] != nullptr) {
            COORD obj_curr = lvlmanager[i]->get_coord();

            g_Console.writeToBuffer(obj_curr, " ", 0x4C);
        }

    }
    for (int i = 0; i < 80; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            if (Level.LevelArray[i][j] == ',')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, ",", colors[1]);
            }
            if (Level.LevelArray[i][j] == '~')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, "~", colors[2]);
            }
            if (Level.LevelArray[i][j] == '*')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, "'", colors[10]);
            }
        }
    }
}
void renderTutorial()
{
    
    Level.LoadLevel1();
    Level.TransferArray();
    // Checking for Symbol


    for (int i = 0; i < 80; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            // Black -> '*' -> Walls
            if (Level.LevelArray[i][j] == 'x')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[5]);
            }
            // Gray -> '@'
            if (Level.LevelArray[i][j] == '.')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[8]);
            }
            // White -> '#'
            if (Level.LevelArray[i][j] == '#')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[7]);
            }
            // Green -> '&'
            if (Level.LevelArray[i][j] == '*')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[10]);
            }
            if (Level.LevelArray[i][j] == '&')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[19]);
            }
            if (Level.LevelArray[i][j] == '%')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[18]);
            }
            if (Level.LevelArray[i][j] == '$')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[20]);
            }
            if (Level.LevelArray[i][j] == '+')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[22]);
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
void renderLevel2()
{

    Level.LoadLevel3();
    Level.TransferArray();
    // Set up sample colours, and output shadings
    const char colors[] = {
        char(0x1A), char(0x2B), char(0x3C), char(0x4D), char(0x5E), char(0x0F),char(0xF7), char(0xFF),char(0x7C),char(0xA2),char(0xAA),
        char(0xA1), char(0xB2), char(0xC3), char(0xD4), char(0xE5), char(0xF6),char(0xC0), char(0xE), char(0x6E), char(0x6C),
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
            if (Level.LevelArray[i][j] == 'x')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[5]);
            }
            // Gray -> '@'
            // Green -> '*'
            if (Level.LevelArray[i][j] == '*')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[7]);
            }
            // White (yellow) -> '#'
            if (Level.LevelArray[i][j] == '.')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[8]);
            }
            // Green -> '&'
            if (Level.LevelArray[i][j] == '#')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[10]);
            }
            //brown
            if (Level.LevelArray[i][j] == '+')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[20]);
            }
            if (Level.LevelArray[i][j] == '~')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[10]);
            }
            if (Level.LevelArray[i][j] == '%')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[18]);
            }
            if (Level.LevelArray[i][j] == '&')

            if (Level.LevelArray[i][j] == '=')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[19]);
            }
            if (Level.LevelArray[i][j] == '$')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[20]);
            }
            if (Level.LevelArray[i][j] == '+')
            {
                c.X = i;
                c.Y = j;
                g_Console.writeToBuffer(c, " ", colors[21]);
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
                PlaySound(TEXT("386550__blockh34d__short-chillout-loop-for-games-or-layering.wav"), NULL, SND_ASYNC | SND_LOOP);
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
            storybuttonskip();
        }
        else if (Storylevel1 == true) {
            renderLevel1();
            storylevel1();
            storybuttonskip();
        }
        else if (startingscreen == true) {
            if (soundcheck == true) {
                PlaySound(TEXT("386550__blockh34d__short-chillout-loop-for-games-or-layering.wav"), NULL, SND_ASYNC | SND_LOOP);
                soundcheck = false;
            }
            StartingGamescreen();
            StartingEvents();
        }
        else if (Tutorial == true || level1 == true || level2 == true || level3 == true || level4 == true) {
            if (soundcheck == true) {
                PlaySound(TEXT("86758__vicces1212__oldvideogame.wav"), NULL, SND_ASYNC | SND_LOOP);
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
   if (level4status == true && level4==true) {
     if (momstatus == true) {
         rendermomlevel();
     }
     else if (dadstatus == true) {
         renderdadlevel();
     }

    }
   else if (level3status == true && level3==true) {
       renderLevel3();

   }
   else if (level2status == true && level2==true) {
       renderLevel2();

   }
   else if (level1status == true && level1==true) {
       renderLevel1();
   }
   else if (Tutorialstatus == true && Tutorial==true) {
        if (resetvalues == true) {
            g_sChar.m_cLocation.X = 73;
            g_sChar.m_cLocation.Y = 16;
            Ammo = 100;
            resetvalues = false;
        }
        renderTutorial();// renders the map to the buffer first

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
        charColor = 0x5A;
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



