#pragma once
#ifndef SmflTesting_movments_H
#define SmflTesting_movments_H

#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class movments
{
    
public:
    Vector2f velocitypacman,velocityredghost,velocitypinkghost,velocityorangeghost;
    float movmentspeedpacman = 130.0f;
     float movmentspeedredghost = 100.0f;
     float movmentspeedpinkghost = 80.0f;
     float movmentspeedorangeghost = 90.0f;
    movments();
    
};
#endif // !SmflTesting_movments_H