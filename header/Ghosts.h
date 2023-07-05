#pragma once
#ifndef SmflTesting_Ghosts_H
#define SmflTesting_Ghosts_H
#include<iostream>
#include<SFML/Graphics.hpp>
#include"movments.h"
using namespace std;
using namespace sf;
class Ghosts
{

public:
	Texture newoutfit;

	Ghosts();
    void setupghosts(string file,Vector2f &ghostpos); // setting up their initial positions and for their respawn
	void createyourownghosts(); // If multiplayer or just personalisations
	virtual void colourandspeed( movments & m1)=0 ;
	virtual void revert(movments& m1)=0;
	virtual Sprite getghostSP() = 0;
	virtual void respawn() = 0;
	virtual void target(RenderWindow& window, movments& m1, Sprite pacman, float dt, int arr[][16], int left, int right, int down, int up)=0;
};
#endif // !SmflTesting_Ghosts_H

