#include "Orangeghost.h"

void Orangeghost::revert(movments& m1)
{
	newoutfit4.loadFromFile("orangeghost.png");
	m1.movmentspeedorangeghost = 90.0f;
	ORghost.setTexture(newoutfit4);
}
void Orangeghost::target(RenderWindow& window, movments& m1, Sprite pacman, float dt, int arr[][16], int left, int right, int down, int up)
{
	static int x = 0, y = 0;
	
	static int Gx = 0, Gy = 0, c = 0;
	float distance[4];
	// 0 = left
	// 1 = right
	// 2 = down
	// 3 = up
	// setting up target for the  ghost
	/*x = pacman.getPosition().x;
	y = pacman.getPosition().y;
	x = ((x - 200) / 50);
	y = ((y - 95) / 50);*/
	if (counters == 0)
	{
		x = 6; y = 1;
	}
	if (counters == 1)
	{	
		x = 1; y = 1;
	}
	if (counters == 2)
	{
		x = 7; y = 14;
	}
	if (counters == 3)
	{
		x = 5; y = 13;
	}
	if (counters == 4)
	{
		x = 13; y = 13;
	}
	if (counters == 5)
	{
		x = 5; y = 7;
	}
	if (counters == 6)
	{
		x = 10; y = 3;
	}
	if (counters == 7)
	{
		x = 1; y = 9;

	}


	int leftindicator = 0;
	 int rightindicator = 0;
	 int downindicator = 0;
	 int upindicator = 0;
	//cout << x << "-----" << y << endl;
	// immpliment on the distance base
	Gx = ORghost.getPosition().x;
	Gy = ORghost.getPosition().y;
	Gx = ((Gx - 200) / 50);
	Gy = ((Gy - 95) / 50);
	//cout << Gx << "   ----     " << Gy << endl;;
	if (Gx == x && Gy == y)
	{
		if (counters == 7)
		{
			counters = -1; // Should be accesible via last poition
		}
		counters++;

	}
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
		//Vector2f ghostpos = Pghost.getPosition();
		upindicator = 1;
		rightindicator = 0, downindicator = 0, leftindicator = 0;
		//int f = (int)ghostpos.x / 50.0f;
		////Rghost.move(2.0f, 0.0f);
		//Rghost.setPosition((f * 50) + 25.0f, ghostpos.y);
	}


	if (upindicator > 0)
	{
		// Moving the sprite

		m1.velocityorangeghost.y = -m1.movmentspeedorangeghost * dt;
	}
	else if (downindicator > 0)
	{
		m1.velocityorangeghost.y = m1.movmentspeedorangeghost * dt;
	}
	else if (leftindicator > 0)
	{
		m1.velocityorangeghost.x = -m1.movmentspeedorangeghost * dt;
	}
	else if (rightindicator > 0)
	{
		m1.velocityorangeghost.x = m1.movmentspeedorangeghost * dt;
	}
	ORghost.move(m1.velocityorangeghost);
}

void Orangeghost::respawn() 
{
	ORghost.setPosition(Vector2f(925.0f, 500.0f)); // we need to impliment its origion depending on its direction so that it only eats when fully emerged
	ORghost.setOrigin(25.0f, 25.0f);
	counters = 0;
	
}
void Orangeghost::colourandspeed(movments& m1)
{
	newoutfit4.loadFromFile("scaredghost.png");
	m1.movmentspeedorangeghost = 40.0f;
	ORghost.setTexture(newoutfit4);
}
Sprite Orangeghost::getghostSP()
{
	return ORghost;
}
