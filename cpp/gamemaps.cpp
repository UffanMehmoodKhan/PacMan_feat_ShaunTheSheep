//#pragma once
//#include "gamemaps.h"
//#include<iostream>
//#include<SFML/Graphics.hpp>
//using namespace sf;
//using namespace std;
//    // 0 shows pellet 
//    // 1 shows wall
//    // 2 shows blank space
//    // 3 shows door
//    // 4 shows cherry
//    gamemaps::gamemaps(RenderWindow& window, movments& m1, float& dt, Clock dt_clock)
//    {
//        gridlength = 16;
//        playerpos = Vector2f(575.0f, 175.0f);
//        setupplayer(); // Intial poition of Player.
//        setmapwalls();
//        print(window, m1, dt, dt_clock);
//    }
//    void gamemaps :: setupplayer()
//    {
//        text.loadFromFile("zohaib.png");
//        text.setSmooth(true);
//        player.setTexture(text);
//        player.setPosition(playerpos);
//        player.setTextureRect(IntRect(0, 0, 40, 40));
//
//        player.setOrigin(25.0f, 25.0f);
//    }
//    void gamemaps::setmapwalls()
//    {
//        printarr = new brick * *[16];
//        for (int i = 0; i < 16; i++)
//        {
//            printarr[i] = new brick * [16];
//        }
//        for (int i = 0; i < 16; i++)
//        {
//            for (int j = 0; j < 16; j++)
//            {
//                if (arr[i][j] == 1)
//                {
//                    printarr[i][j] = new brick("walls.png", j * 50 + 200, i * 50 + 95);
//                }
//                else if (arr[i][j] == 0)
//                {
//                    printarr[i][j] = new brick("pellets.png", j * 50 + 200, i * 50 + 95);
//                }
//                else if (arr[i][j] == 2)
//                {
//                    printarr[i][j] = new brick("blankspace.png", j * 50 + 200, i * 50 + 95);
//                }
//                else if (arr[i][j] == 3 && j == 15)
//                {
//                    printarr[i][j] = new brick("rightdoor.png", j * 50 + 200, i * 50 + 95);
//                }
//                else if (arr[i][j] == 3 && j == 0)
//                {
//                    printarr[i][j] = new brick("leftdoor.png", j * 50 + 200, i * 50 + 95);
//                }
//                else if (arr[i][j] == 4)
//                {
//                    printarr[i][j] = new brick("cherry.png", j * 50 + 200, i * 50 + 95);
//                }
//
//            }
//
//        }
//    }
//    void gamemaps::print(RenderWindow& window, movments m1, float dt, Clock dt_clock)
//    {
//
//        window.setFramerateLimit(120);
//        window.clear(Color::Black);
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        for (int i = 0; i < 16; i++)
//        {
//            for (int j = 0; j < 16; j++)
//            {
//                window.draw(printarr[i][j]->getsprite());
//            }
//        }
//        player.move(m1.velocity);
//        window.draw(player);
//        window.display();
//
//    }
//    void gamemaps::checking(movments& m1, int& up, int& left, int& down, int& right, bool& blokeageup, bool& blocakageleft, bool& blocakgedown, bool& blackageright)
//    {/*Music eatingsound;
//    eatingsound.openFromFile("pacman_chomp.wav");*/
//        Vector2f currentpos = player.getPosition();
//
//        int x = ((int)currentpos.x - 200) / 50;
//        int y = ((int)currentpos.y - 95) / 50;
//        if (arr[y][x] == 0 || arr[y][x] == 4)
//        {
//            /*eatingsound.play();*/
//            printarr[y][x] = new brick("blankspace.png", (x * 50) + 200, (y * 50) + 95);
//            // checking if player is standing on indices taht either conatins pellets or cherry and then remove it 
//        }
//        if (arr[y][x] == 3 && x == 0)
//        {
//            player.setPosition(200.0f + 750.0f, 520.0f);
//            // left door and setting cords of right gate next tile
//        }
//
//        if (arr[y][x] == 3 && x == 15)
//        {
//            player.setPosition(250.0f, 520.0f);
//            // right door and setting cords of left gate            
//        }
//        if (up == 1)
//        {
//            int x = ((int)currentpos.x - 200) / 50;
//            int y = ((int)currentpos.y + 25 - 95) / 50;
//            // is doing sperately because of differnce in origin 
//            if (arr[y - 1][x] == 1) // looking a step ahead to see what it is 
//            {
//                up = 0;
//                blokeageup = true;
//            }
//        }
//        else if (left == 1)
//        {
//            int x = ((int)currentpos.x + 25 - 200) / 50;
//            int y = ((int)currentpos.y - 95) / 50;
//            // is doing sperately because of differnce in origin 
//            if (arr[y][x - 1] == 1) // looking a step ahead to see what it is 
//            {
//                left = 0;
//                blocakageleft = true;
//            }
//
//        }
//        else if (down == 1)
//        {
//            int x = ((int)currentpos.x - 200) / 50;
//            int y = ((int)currentpos.y - 25 - 95) / 50;
//            // is doing sperately because of differnce in origin 
//            if (arr[y + 1][x] == 1) // looking a step ahead to see what it is 
//            {
//                down = 0;
//                blocakgedown = true;
//            }
//
//
//        }
//        else if (right == 1)
//        {
//            int x = ((int)currentpos.x - 25 - 200) / 50;
//            int y = ((int)currentpos.y - 95) / 50;
//            // is doing sperately because of differnce in origin 
//            if (arr[y][x + 1] == 1) // looking a step ahead to see what it is 
//            {
//                right = 0;
//                blackageright = true;
//            }
//        }
//    }
//
//
