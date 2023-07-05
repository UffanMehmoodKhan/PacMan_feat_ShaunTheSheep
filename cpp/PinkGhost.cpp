#include "PinkGhost.h"

void PinkGhost::revert(movments& m1)
{
	newoutfit3.loadFromFile("pinkghost.png");
	m1.movmentspeedpinkghost = 80.0f;
	Pghost.setTexture(newoutfit3);
}
void PinkGhost::target(RenderWindow& window, movments& m1, Sprite pacman, float dt, int arr[][16], int left, int right, int down, int up)
{
	static int x = 2, y = 1;
	// 5 and 13
	// 14 and 7
	// 8 and 1
	// 13 and 13
	// 5 and 7
	//10 and 3
	//1 and 9
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
	if (counter==1)
	{
		x = 5; y = 13;
	}
	if (counter== 2)
	{
		x = 14; y = 7;
	}
	if (counter == 3)
	{
		x = 8; y = 1;
	}
	if (counter==4)
	{
		x = 13; y = 13;
	}
	if (counter==5)
	{
		x = 5; y = 7;
	}
	if (counter==6)
	{
		x = 10; y = 3;
	}
	if (counter==7)
	{
		x = 1; y = 9;
		
	}
	

	static int leftindicator = 0;
	static int rightindicator = 0;
	static int downindicator = 0;
	static int upindicator = 0;
	//cout << x << "-----" << y << endl;
	// immpliment on the distance base
	Gx = Pghost.getPosition().x;
	Gy = Pghost.getPosition().y;
	Gx = ((Gx - 200) / 50);
	Gy = ((Gy - 95) / 50);
	//cout << Gx << "   ----     " << Gy << endl;;
	if (Gx==x &&Gy==y)
	{
		if (counter==7)
		{
			counter = 1;
		}
		counter++;
		
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

		m1.velocitypinkghost.y = -m1.movmentspeedpinkghost * dt;
	}
	if (downindicator > 0)
	{
		m1.velocitypinkghost.y = m1.movmentspeedpinkghost * dt;
	}
	if (leftindicator > 0)
	{
		m1.velocitypinkghost.x = -m1.movmentspeedpinkghost * dt;
	}
	if (rightindicator > 0)
	{
		m1.velocitypinkghost.x = m1.movmentspeedpinkghost * dt;
	}

	Pghost.move(m1.velocitypinkghost);


}

void PinkGhost::respawn()
{
	Pghost.setPosition(Vector2f(525.0f, 510.0f)); // we need to impliment its origion depending on its direction so that it only eats when fully emerged
	Pghost.setOrigin(25.0f, 25.0f);
	counter = 1; // To rest the hardcoded logic pattren
}

void PinkGhost::colourandspeed(movments& m1)
{
	newoutfit3.loadFromFile("scaredghost.png");
	m1.movmentspeedpinkghost = 40.0f;
	Pghost.setTexture(newoutfit3);
}

Sprite PinkGhost::getghostSP()
{
	return Pghost;
}
