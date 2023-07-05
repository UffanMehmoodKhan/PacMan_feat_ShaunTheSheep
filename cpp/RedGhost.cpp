#pragma once
#include "RedGhost.h"
#include"Ghosts.h"
#include<SFML/Graphics.hpp>
void RedGhost::revert( movments& m1)
{
	newoutfit1.loadFromFile("redghost.png");
	m1.movmentspeedredghost = 100.0f;
	Rghost.setTexture(newoutfit1);
}
void RedGhost::target(RenderWindow& window, movments& m1, Sprite pacman, float dt, int arr[][16], int left, int right, int down, int up)
{
	static int x = 0, y = 0;
	static int Gx = 0, Gy = 0, c = 0;


	float distance[4];
	// 0 = left
	// 1 = right
	// 2 = down
	// 3 = up
	// setting up target for the  ghost to follow
	x = pacman.getPosition().x;
	y = pacman.getPosition().y;
	x = ((x - 200) / 50);
	y = ((y - 95) / 50);
	static int leftindicator = 0;
	static int rightindicator = 0;
	static int downindicator = 0;
	static int upindicator = 0;


	//cout << x << "-----" << y << endl;
	// immpliment on the distance base
	Gx = Rghost.getPosition().x;
	Gy = Rghost.getPosition().y;
	Gx = ((Gx - 200) / 50);
	Gy = ((Gy - 95) / 50);
	//cout << Gx << "   ----     " << Gy << endl;;

	for (int i = 0; i < 4; i++)
	{
		distance[i] = 2000;
	} // If someone has wall next to it distance will be other wise 0 -> not acceptable
	// calculating distance ->
	if (arr[Gy][Gx - 1] == 0 || arr[Gy][Gx - 1] == 2 || arr[Gy][Gx - 1] == 4)// Looking left
	{
		distance[0] = sqrt(abs(pow((Gx - 1) - x, 2) + pow(Gy - y, 2) * 1.0));
	}
	if (arr[Gy + 1][Gx] == 0 || arr[Gy + 1][Gx] == 2 || arr[Gy + 1][Gx] == 4)// looking down
	{
		distance[2] = sqrt(abs(pow(Gx - x, 2) + pow((Gy + 1) - y, 2) * 1.0));
	}
	if (arr[Gy][Gx + 1] == 0 || arr[Gy][Gx + 1] == 2 || arr[Gy][Gx + 1] == 4)// Looking right
	{
		distance[1] = sqrt(abs(pow((Gx + 1) - x, 2) + pow(Gy - y, 2) * 1.0));
	}
	if (arr[Gy - 1][Gx] == 0 || arr[Gy - 1][Gx] == 2 || arr[Gy - 1][Gx] == 4)// looking up
	{
		distance[3] = sqrt(abs(pow(Gx - x, 2) + pow((Gy - 1) - y, 2) * 1.0));
	}
	float min = 2222.0;

	for (int i = 0; i < 4; i++)
	{
		if (distance[i] < min)
		{
			min = distance[i];
		}
		//cout << distance[i] << "  ";
	} // calculating which is the shortest distance so a decision could be made
	cout << endl;

	if (min == distance[0]) // left 
	{
		leftindicator = 1;
		rightindicator = 0, downindicator = 0, upindicator = 0;
	}
	if (min == distance[1])//right
	{
		rightindicator = 1;
		leftindicator = 0, downindicator = 0, upindicator = 0;
	}
	if (min == distance[2])//down
	{
		downindicator = 1;
		rightindicator = 0, leftindicator = 0, upindicator = 0;
	}
	if (min == distance[3])// up
	{
		Vector2f ghostpos = Rghost.getPosition();
		upindicator = 1;
		rightindicator = 0, downindicator = 0, leftindicator = 0;
		//int f = (int)ghostpos.x / 50.0f;
		////Rghost.move(2.0f, 0.0f);
		//Rghost.setPosition((f * 50) + 25.0f, ghostpos.y);
	}


	if (upindicator > 0)
	{
		// Moving the sprite

		m1.velocityredghost.y = -m1.movmentspeedredghost * dt;
	}
	if (downindicator > 0)
	{
		m1.velocityredghost.y = m1.movmentspeedredghost * dt;
	}
	if (leftindicator > 0)
	{
		m1.velocityredghost.x = -m1.movmentspeedredghost * dt;
	}
	if (rightindicator > 0)
	{
		m1.velocityredghost.x = m1.movmentspeedredghost * dt;
	}

	Rghost.move(m1.velocityredghost);

}
void RedGhost::respawn()
{
	Rghost.setPosition(Vector2f(275.0f, 375.0f));
	Rghost.setOrigin(25.0f, 25.0f);
}

void RedGhost::colourandspeed( movments& m1)
{
	newoutfit1.loadFromFile("scaredghost.png");
	m1.movmentspeedredghost = 40.0f;
	Rghost.setTexture(newoutfit1);
}

Sprite RedGhost::getghostSP()
{
	return Rghost;
}

