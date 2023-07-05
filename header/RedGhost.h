#pragma once
#include"Ghosts.h"
#include<iostream>
#include<SFML/Graphics.hpp>
#include"movments.h"
#include <math.h>

using namespace std;
using namespace sf;
class RedGhost:public Ghosts
{
	Texture RGtexture;
public:
	Sprite Rghost;
	Texture newoutfit1;

	RedGhost() :Ghosts()
	{
		RGtexture.loadFromFile("redghost.png");
		Rghost.setTexture(RGtexture);
		Rghost.setPosition(Vector2f(275.0f, 375.0f)); // we need to impliment its origion depending on its direction so that it only eats when fully emerged
		Rghost.setOrigin(25.0f, 25.0f);
	}
	void revert(movments& m1);
	void target(RenderWindow& window, movments& m1, Sprite  pacman, float dt, int arr[][16], int left, int right, int down, int up);
	void respawn();
	void colourandspeed( movments& m1);
	Sprite getghostSP();
	
};

