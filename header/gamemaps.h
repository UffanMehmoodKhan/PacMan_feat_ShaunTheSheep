//#pragma once
//#ifndef SmflTesting_gamemaps_H
//#define SmflTesting_gamemaps_H
//#include "movments.h"
//#include"brick.h"
//#include<iostream>
//#include"pacman.cpp"
//#include<SFML/Graphics.hpp>
//using namespace sf;
//using namespace std;
//class gamemaps
//{
//    Vector2f playerpos;
//public:
//    Sprite player;
//    int gridlength;
//    brick*** printarr;
//    int arr[16][16] = {
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//     {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
//     {1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1},
//     {1, 0, 1, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
//     {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
//     {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
//     {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
//     {3, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 3},
//     {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
//     {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
//     {1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
//     {1, 0, 0, 4, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
//     {1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1},
//     {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 4, 1},
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };
//    // 0 shows pellet 
//    // 1 shows wall
//    // 2 shows blank space
//    // 3 shows door
//    // 4 shows cherry
//    gamemaps(RenderWindow& window, movments& m1, float& dt, Clock dt_clock);
//    void setupplayer();
//    void setmapwalls();
//    void print(RenderWindow& window, movments m1, float dt, Clock dt_clock);
//    void checking(movments& m1, int& up, int& left, int& down, int& right, bool& blokeageup, bool& blocakageleft, bool& blocakgedown, bool& blackageright);
//};
//#endif // !SmflTesting_gamemaps_H
//
