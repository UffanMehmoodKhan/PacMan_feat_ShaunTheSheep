#pragma once
#ifndef SmflTesting_displayscreens_H
#define SmflTesting_displayscreens_H
#include <fstream>
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <string>
#include <sstream>
#include"Ghosts.h"
#include"RedGhost.h"
using namespace sf;
using namespace std;
class displayscreens
{
	Text HStext, Highscore,Score,digitscores,playgame,Credits,Pacmantext,Game,On,charactertext,EXIT;	
	Font namco,emulogic,pacfont;
	Sprite heart1,heart2,heart3,plus10,zohaibpic,uffanpic,TApic,movingpacman;
	Texture redheart,greyheart,MMtexture,score10,eatBG,T1P,T2P,T3P,LSBG,MPtexture,LStexture,Wtexture,creditsT;
	RectangleShape mainmenubackground,eatannonceBG,loadingscreenBG,losing,winning,blue,creditsBG;
	CircleShape circle1, circle2, circle3; // For choese your character
	Sprite RG, PG, ORG , Z ,U ,S ;
	Texture RGT, PGT, ORGT, ZT, UT, ST;
public:
	displayscreens();
	void creditsscreen(RenderWindow& window, int& menuchoice, Event& event);
	void scoresandlife(RenderWindow & window,int score,int totallives, int& highscore);
	void score10display(RenderWindow& window);
	void mainmenu(int& menuchoice, RenderWindow& window, Event& event, Ghosts* Allghosts[4], int& totallifes,int & music);
	void gamescreen(RenderWindow& window, Event & event,int& menuchoice,int & music, Ghosts* allghosts[4],int arr[][16],int & counter,int & score,int & totallives);
	void pacmaneaten(RenderWindow& window);
	void choeseyourcharacter(RenderWindow& window, int& menuchoice,Event & event,int& zohaibornot);
	void loadingscreen(RenderWindow & window , int & menuchoice);
	void losingscreen(RenderWindow & window,Event & event,int & menuchoice, int& music, int arr[16][16], int& counter, int& score, int& totallives);
	void winningcreen(RenderWindow & window,Event & event, int & menuchoice, int& music, int arr[16][16], int& counter, int& score, int& totallives);
};
#endif // !SmflTesting_displayscreens_H

