#include "displayscreens.h"


displayscreens::displayscreens()
{
	namco.loadFromFile("namco.ttf");
	emulogic.loadFromFile("emulogic.ttf");
	pacfont.loadFromFile("pac-font.ttf");
	redheart.loadFromFile("redheart.png");
	greyheart.loadFromFile("greyheart.png");
	score10.loadFromFile("10.png");
	eatBG.loadFromFile("You.png");
	plus10.setTexture(score10);
	plus10.setPosition(480.0f, 33.0f);
	heart1.setPosition(863.0f, 38.0f);
	heart2.setPosition(908.0f, 38.0f);
	heart3.setPosition(953.0f, 38.0f);
	MMtexture.loadFromFile("mainmenu.png");
	Vector2f mm(1200.0f, 1100.0f);
	mainmenubackground.setSize(mm);
	mainmenubackground.setTexture(&MMtexture);
	eatannonceBG.setSize(Vector2f(1200.0f, 1100.0f));
	eatannonceBG.setTexture(&eatBG);
	playgame.setFont(emulogic);
	EXIT.setFont(emulogic);
	Credits.setFont(emulogic);
	Pacmantext.setFont(pacfont);
	Game.setFont(pacfont);
	On.setFont(pacfont);
	charactertext.setFont(namco);
	T1P.loadFromFile("Czohaib.png");
	zohaibpic.setTexture(T1P);
	T2P.loadFromFile("Cuffan.png");
	uffanpic.setTexture(T2P);
	T3P.loadFromFile("Csheep.png");
	TApic.setTexture(T3P);
	LSBG.loadFromFile("loadingpacman.png");
	loadingscreenBG.setSize(Vector2f(1200.0f, 1100.0f));
	MPtexture.loadFromFile("movingpacman.png"); // Pacman picture
	loadingscreenBG.setTexture(&MPtexture);
	movingpacman.setTexture(LSBG);// pacmansprite
	movingpacman.setPosition(Vector2f(295.0f, 795.0f));
	LStexture.loadFromFile("OVER.png");
	losing.setSize(Vector2f(1200.0f, 1100.0f));
	losing.setTexture(&LStexture); // Losing screen rectangle
	Wtexture.loadFromFile("WON.png");
	winning.setSize(Vector2f(1200.0f, 1100.0f));
	winning.setTexture(&Wtexture);
	RGT.loadFromFile("redmenu.png");
	RG.setTexture(RGT);
	PGT.loadFromFile("pinkmenu.png");
	PG.setTexture(PGT);
	ORGT.loadFromFile("orangemenu.png");
	ORG.setTexture(ORGT);
	creditsBG.setSize(Vector2f(1200.0f, 1100.0f));
	creditsT.loadFromFile("creditsbackground.png");
	creditsBG.setTexture(&creditsT);
}
void displayscreens::creditsscreen(RenderWindow& window, int& menuchoice,Event & event)
{
	int x = 0;
	int y = 0;
	x = Mouse::getPosition(window).x;
	y = Mouse::getPosition(window).y;
	window.draw(creditsBG);
	EXIT.setCharacterSize(32);
	EXIT.setPosition(100.0f, 760.0f);
	EXIT.setOutlineColor(Color::Blue);
	EXIT.setOutlineThickness(2);
	EXIT.setString("EXIT");
	if (x >= 100 && x <= 230 && y >= 760 && y <= 791)
	{
		EXIT.setFillColor(Color::Red);
	}
	else
	{
		EXIT.setOutlineColor(Color::Magenta);
		EXIT.setFillColor(Color::White);
	}
	window.draw(EXIT);
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		x = Mouse::getPosition(window).x;
		y = Mouse::getPosition(window).y;
		if (x >= 100 && x <= 230 && y >= 760 && y <= 791)
		{
			menuchoice = 0;
		}
	}
}
void displayscreens::scoresandlife(RenderWindow& window,int score,int totallives,int & highscore)
{

	Score.setFont(namco);
	Score.setString("score");
	Score.setCharacterSize(24);
	Score.setFillColor(Color::Yellow);
	Score.setPosition(210.0f, 40.0f);
	window.draw(Score);
	stringstream ss,HS;
	ss << score;
	digitscores.setFont(namco);
	digitscores.setString(ss.str().c_str());
	digitscores.setFillColor(Color::Yellow);
	digitscores.setCharacterSize(24);
	digitscores.setPosition(380.0f, 40.0f);
	window.draw(digitscores);
	HStext.setFont(namco);
	HStext.setString("highest");
	HStext.setCharacterSize(24);
	HStext.setFillColor(Color::Red);
	HStext.setPosition(500.0f, 40.0f);
	window.draw(HStext);

	HS << highscore;
	Highscore.setFont(namco);
	Highscore.setString(HS.str().c_str());
	Highscore.setFillColor(Color::Cyan);
	Highscore.setCharacterSize(24);
	Highscore.setPosition(710.0f, 40.0f);
	window.draw(Highscore);
	if (totallives==3)
	{
		heart1.setTexture(redheart);
		heart2.setTexture(redheart);
		heart3.setTexture(redheart);
		window.draw(heart1); window.draw(heart2); window.draw(heart3);
	}
	else if (totallives==2)
	{
		heart1.setTexture(redheart);
		heart2.setTexture(redheart);
		heart3.setTexture(greyheart);
		window.draw(heart1); window.draw(heart2); window.draw(heart3);
	}
	else if (totallives==1)
	{
		heart1.setTexture(redheart);
		heart2.setTexture(greyheart);
		heart3.setTexture(greyheart);
		window.draw(heart1); window.draw(heart2); window.draw(heart3);
	}
	else
	{
		heart1.setTexture(greyheart);
		heart2.setTexture(greyheart);
		heart3.setTexture(greyheart);
		window.draw(heart1); window.draw(heart2); window.draw(heart3);
	}
	// These if conditions print hearts

}
void displayscreens::score10display(RenderWindow& window)
{
	window.draw(plus10);
}
void displayscreens::mainmenu(int & menuchoice,RenderWindow & window,Event & event,Ghosts * Allghosts[4],int & totallifes,int & music)
{
	int x = 0,y=0;
	x = Mouse::getPosition(window).x;
	y = Mouse::getPosition(window).y;
	
	window.draw(mainmenubackground);
	Pacmantext.setCharacterSize(74);
	Pacmantext.Bold;
	Pacmantext.setOutlineThickness(3);

	if (x >= 130.0f && x <= 690.0f && y >= 30.0f && y <= 110.0f)
	{
		playgame.setFillColor(Color::Black);
		Pacmantext.setOutlineColor(Color::Blue);

	}
	else
	{
		playgame.setOutlineColor(Color::Magenta);
		playgame.setFillColor(Color::White);
	}
	Pacmantext.setString("PAC-MAN");
	Pacmantext.setLetterSpacing(3);
	Pacmantext.setPosition(Vector2f(130.0f, 20.0f));
	window.draw(Pacmantext);
	playgame.setCharacterSize(32);
	playgame.setPosition(300.0f, 300.0f);
	playgame.setOutlineColor(Color::Blue);
	playgame.setOutlineThickness(2);
	playgame.setString("PLAYGAME");
	if (x >= 300 && x <= 560 && y >= 300 && y <= 331)
	{
		playgame.setFillColor(Color::Red);
	}
	else
	{
		playgame.setOutlineColor(Color::Magenta);
		playgame.setFillColor(Color::White);
	}
	Credits.setCharacterSize(32);
	Credits.setPosition(300.0f, 400.0f);
	Credits.setOutlineColor(Color::Blue);
	Credits.setOutlineThickness(2);
	Credits.setString("CREDITS");
	if (x >= 300 && x <= 520 && y >= 400 && y <= 431)
	{
		Credits.setFillColor(Color::Red);
	}
	else
	{
		Credits.setOutlineColor(Color::Magenta);
		Credits.setFillColor(Color::White);
	}
	
	RG.setPosition(Vector2f(280.0f, 440.0f));
	ORG.setPosition(Vector2f(280.0f, 540.0f));
	PG.setPosition(Vector2f(280.0f, 640.0f));
	window.draw(RG);
	window.draw(PG);
	window.draw(ORG);
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		 x = Mouse::getPosition(window).x;
		 y = Mouse::getPosition(window).y;
		
		if (x >=300 && x<=560 && y >=300 && y<=331)
		{
			totallifes = 3;
			Allghosts[0]->respawn();
			menuchoice = 3; // to display choesse your character ascreen
			//intromusic.stop();
			// Respawn every thing
			music = 0;
		}
		else if (x >= 300 && x <= 520 && y >= 400 && y <= 431)
		{
			menuchoice = 2; // To display Credits
			///intromusic.stop();
			music = 0;
		}
	}

	


	window.draw(Credits);
	window.draw(playgame);

	// 0 -----> menuscreen
	

}
void displayscreens::gamescreen(RenderWindow& window,Event & event,int & menuchoice,int & music, Ghosts* allghosts[4],int arr[][16],int & counter,int& score, int& totallives)
{
	int x = 0, y = 0;
	x = Mouse::getPosition(window).x;
	y = Mouse::getPosition(window).y;
	Pacmantext.setCharacterSize(74);
	Pacmantext.Bold;
	Pacmantext.setFillColor(Color::Yellow);
	Pacmantext.setOutlineColor(Color::Blue);
	Pacmantext.setOutlineThickness(3);
	Pacmantext.setString("PAC-MAN");
	Pacmantext.setLetterSpacing(3);
	Pacmantext.setPosition(Vector2f(330.0f, 885.0f));
	window.draw(Pacmantext);
	Game.setCharacterSize(40);
	Game.Bold;
	Game.setFillColor(Color::White);
	Game.setOutlineColor(Color::Blue);
	Game.setOutlineThickness(3);
	Game.setString("GAME");
	Game.setLetterSpacing(2);
	Game.setPosition(Vector2f(4.0f, 50.0f));
	window.draw(Game);
	On.setCharacterSize(40);
	On.Bold;
	On.setFillColor(Color::White);
	On.setOutlineColor(Color::Blue);
	On.setOutlineThickness(3);
	On.setString("ON");
	On.setLetterSpacing(2);
	On.setPosition(Vector2f(4.0f, 100.0f));
	window.draw(On);
	EXIT.setCharacterSize(32);
	EXIT.setPosition(40.0f, 460.0f);
	EXIT.setOutlineColor(Color::Blue);
	EXIT.setOutlineThickness(2);
	EXIT.setString("EXIT");
	if (x >= 40 && x <= 170 && y >= 460 && y <= 491)
	{
		EXIT.setFillColor(Color::Red);
	}
	else
	{
		EXIT.setOutlineColor(Color::Magenta);
		EXIT.setFillColor(Color::White);
	}
	window.draw(EXIT);
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		if (x >= 40 && x <= 170 && y >= 460 && y <= 491)
		{
			menuchoice = 0;
			/*allghosts[0]->respawn();
			allghosts[1]->respawn();*/
			ifstream file("intarray.txt");
			for (int i = 0; i < 16; ++i) {
				for (int j = 0; j < 16; ++j) {
					if (!(file >> arr[i][j])) {
						std::cerr << "Error reading from file " << arr << std::endl;
						file.close();
					}
				}
			}
			file.close();
			counter = 0;
			music = 0;
			score = 0;
			totallives = 3;
		}
	}
}
void displayscreens::pacmaneaten(RenderWindow& window)
{
	window.draw(eatannonceBG);
}
void displayscreens::choeseyourcharacter(RenderWindow& window, int& menuchoice,Event & event,int& zohaibornot)
{
	static int x = 0, y = 0;
	static int finalchoice = 0;
	x = Mouse::getPosition(window).x;
	y = Mouse::getPosition(window).y;
	charactertext.setCharacterSize(44);
	charactertext.setPosition(55.0f, 100.0f);
	charactertext.setOutlineColor(Color::Magenta);
	charactertext.setOutlineThickness(1);
	charactertext.setString("chose your character");
	if (x >= 50 && x <= 1150 && y >= 100 && y <= 150)
	{
		charactertext.setFillColor(Color::White);
	}
	else
	{
		charactertext.setOutlineColor(Color::Blue);
		charactertext.setFillColor(Color::Red);
	}
	window.draw(charactertext);
	
	circle1.setRadius(130);
	circle1.setOrigin(Vector2f());
	if (x >= 450 && x <= 710 && y >= 650 && y <= 910)
	{
		circle1.setFillColor(Color::Yellow);
	}
	else
	{
		circle1.setFillColor(Color::Cyan);
	}
	circle1.setPosition(Vector2f(450.0f, 650.0f));
	window.draw(circle1);
	zohaibpic.setPosition(Vector2f(465.0f, 650.0f));
	window.draw(zohaibpic);
	circle2.setRadius(130);
	
	if (x >= 810 && x <= 1060 && y >= 650 && y <= 910)
	{
		circle2.setFillColor(Color::Yellow);
	}
	else
	{
		circle2.setFillColor(Color::Cyan);
	}
	circle2.setPosition(Vector2f(810.0f, 650.0f));
	window.draw(circle2);
	uffanpic.setPosition(Vector2f(825.0f, 650.0f));
	window.draw(uffanpic);
	circle3.setRadius(130);

	if (x >= 630 && x <= 880 && y >= 350 && y <= 610)
	{
		circle3.setFillColor(Color::Red);
	}
	else
	{
		circle3.setFillColor(Color::Magenta);
	}
	circle3.setPosition(Vector2f(630.0f, 350.0f));
	
	window.draw(circle3);
	TApic.setPosition(Vector2f(645.0f, 350.0f));
	window.draw(TApic);
	playgame.setCharacterSize(32);
	playgame.setPosition(100.0f, 400.0f);
	playgame.setOutlineColor(Color::Blue);
	playgame.setOutlineThickness(2);
	playgame.setString("PLAYGAME");
	if (x >= 100 && x <= 360 && y >= 400 && y <= 431)
	{
		playgame.setFillColor(Color::Red);
	}
	else
	{
		playgame.setOutlineColor(Color::Magenta);
		playgame.setFillColor(Color::White);
	}
	window.draw(playgame);
	EXIT.setCharacterSize(32);
	EXIT.setPosition(100.0f, 460.0f);
	EXIT.setOutlineColor(Color::Blue);
	EXIT.setOutlineThickness(2);
	EXIT.setString("EXIT");
	if (x >= 100 && x <= 230 && y >= 460 && y <= 491)
	{
		EXIT.setFillColor(Color::Red);
	}
	else
	{
		EXIT.setOutlineColor(Color::Magenta);
		EXIT.setFillColor(Color::White);
	}
	window.draw(EXIT);
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		
			x = Mouse::getPosition(window).x;
			y = Mouse::getPosition(window).y;
			if (x >= 450 && x <= 710 && y >= 650 && y <= 910)
			{
				
				circle1.setOutlineThickness(6);
				circle1.setOutlineColor(Color::White);
				circle2.setOutlineThickness(0);
				circle3.setOutlineThickness(0);
				finalchoice = 1;
			}
			if (x >= 810 && x <= 1060 && y >= 650 && y <= 910)
			{
				
				circle2.setOutlineThickness(6);
				circle2.setOutlineColor(Color::White);
				circle1.setOutlineThickness(0);
				circle3.setOutlineThickness(0);
				finalchoice = 2;
			}
			if (x >= 630 && x <= 880 && y >= 350 && y <= 610)
			{
				circle3.setOutlineThickness(6);
				circle3.setOutlineColor(Color::White);
				circle1.setOutlineThickness(0);
				circle2.setOutlineThickness(0);
				finalchoice = 3;
			}
		
		if (x >= 100 && x <= 230 && y >= 460 && y <= 491)
		{
			menuchoice = 0;
		}
		if (x >= 100 && x <= 360 && y >= 400 && y <= 431 && (finalchoice==1 || finalchoice==2|| finalchoice==3))
		{
			menuchoice = 4;
			zohaibornot = finalchoice;

		}
		
		// exit 
		// play game
	
	}
	


}
void displayscreens::loadingscreen(RenderWindow& window, int& menuchoice)
{
	
	Vector2f velocity;
	int x = 0;
	velocity.x = 0.0f;
	velocity.y = 0.0f;
	velocity.x = 80.0f *0.0234 ;
	movingpacman.move(velocity);
	x = movingpacman.getPosition().x;
	int y = movingpacman.getPosition().y;
	if (x>=830.0f)
	{
		menuchoice = 1;
		movingpacman.setPosition(Vector2f(295.0f, 795.0f));
	}
	

	window.draw(loadingscreenBG);
	

	window.draw(movingpacman);
}
void displayscreens::losingscreen(RenderWindow & window,Event & event,int & menuchoice,int & music ,int arr [16][16],int & counter,int & score , int & totallives)
{
	int x = 0; int y = 0;
	x = Mouse::getPosition(window).x;
	y = Mouse::getPosition(window).y;
	window.draw(losing);
	EXIT.setCharacterSize(32);
	EXIT.setPosition(100.0f, 460.0f);
	EXIT.setOutlineColor(Color::Blue);
	EXIT.setOutlineThickness(2);
	EXIT.setString("EXIT");
	if (x >= 100 && x <= 230 && y >= 460 && y <= 491)
	{
		EXIT.setFillColor(Color::Red);
	}
	else
	{
		EXIT.setOutlineColor(Color::Magenta);
		EXIT.setFillColor(Color::White);
	}
	window.draw(EXIT);
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		if (x >= 100 && x <= 230 && y >= 460 && y <= 491)
		{
			menuchoice = 0;
			/*allghosts[0]->respawn();
			allghosts[1]->respawn();*/
			ifstream file("intarray.txt");
			for (int i = 0; i < 16; ++i) {
				for (int j = 0; j < 16; ++j) {
					if (!(file >> arr[i][j])) {
						std::cerr << "Error reading from file " << arr << std::endl;
						file.close();
					}
				}
			}
			file.close();
			score = 0;
			totallives = 3;
			counter = 0;
			music = 0;
		}
	}
}
void displayscreens::winningcreen(RenderWindow& window, Event& event, int & menuchoice, int& music, int arr[16][16], int& counter, int& score, int& totallives)
{
	int x = 0; 
	int y = 0;
	x = Mouse::getPosition(window).x;
	y = Mouse::getPosition(window).y;
	window.draw(winning);
	EXIT.setCharacterSize(32);
	EXIT.setPosition(100.0f, 760.0f);
	EXIT.setOutlineColor(Color::Blue);
	EXIT.setOutlineThickness(2);
	EXIT.setString("EXIT");
	if (x >= 100 && x <= 230 && y >= 760 && y <= 791)
	{
		EXIT.setFillColor(Color::Red);
	}
	else
	{
		EXIT.setOutlineColor(Color::Magenta);
		EXIT.setFillColor(Color::White);
	}
	window.draw(EXIT);
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		x = Mouse::getPosition(window).x;
		y = Mouse::getPosition(window).y;
		if (x >= 100 && x <= 230 && y >= 760 && y <= 791)
		{
			menuchoice = 0;
			/*allghosts[0]->respawn();
			allghosts[1]->respawn();*/
			ifstream file("intarray.txt");
			for (int i = 0; i < 16; ++i) {
				for (int j = 0; j < 16; ++j) {
					if (!(file >> arr[i][j])) {
						std::cerr << "Error reading from file " << arr << std::endl;
						file.close();
					}
				}
			}
			file.close();
			score = 0;
			totallives = 3;
			counter = 0;
			music = 0;
		}
	}
}



