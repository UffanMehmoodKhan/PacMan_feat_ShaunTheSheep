#pragma once
#ifndef SmflTesting_brick_H
#define SmflTesting_brick_H

#include<iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class brick
{
private:
    Vector2f position;
    Texture texture;
    Sprite sprite;
public:
    brick();
    brick(string name, float x, float y);
    void setupsprite(string textname);
    Sprite getsprite();
    
};
#endif // !SmflTesting_brick_H


