#pragma once
#include"Ghosts.h"
#include<iostream>
#include<SFML/Graphics.hpp>
#include"movments.h"
#include <math.h>
#include<time.h>
using namespace std;
using namespace sf;
class Orangeghost :public Ghosts
{
	Texture ORtexture;
public:
	Sprite ORghost;
	Texture newoutfit4;
	int counters ;

	Orangeghost() :Ghosts()
	{
		counters = 0;
		ORtexture.loadFromFile("orangeghost.png");
		ORghost.setTexture(ORtexture);
		ORghost.setPosition(Vector2f(925.0f, 100.0f)); // we need to impliment its origion depending on its direction so that it only eats when fully emerged
		ORghost.setOrigin(25.0f, 25.0f);
	}
	void revert(movments& m1);
	void target(RenderWindow& window, movments& m1, Sprite  pacman, float dt, int arr[][16], int left, int right, int down, int up);
	void respawn();
	void colourandspeed(movments& m1);
	Sprite getghostSP();

};

