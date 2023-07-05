#pragma once
#include"Ghosts.h"
#include<iostream>
#include<SFML/Graphics.hpp>
#include"movments.h"
#include <math.h>
#include<cstdlib>
using namespace std;
using namespace sf;

class PinkGhost :public Ghosts
{
	Texture PGtexture;
	int counter = 0;
public:
	Sprite Pghost;
	Texture newoutfit3;

	PinkGhost() :Ghosts()
	{
		PGtexture.loadFromFile("pinkghost.png");
		Pghost.setTexture(PGtexture);
		Pghost.setPosition(Vector2f(925.0f, 810.0f)); // we need to impliment its origion depending on its direction so that it only eats when fully emerged
		Pghost.setOrigin(25.0f, 25.0f);
	}
	void revert(movments& m1);
	void target(RenderWindow& window, movments& m1, Sprite  pacman, float dt, int arr[][16], int left, int right, int down, int up);
	void respawn();
	void colourandspeed(movments& m1);
	Sprite getghostSP();

};
