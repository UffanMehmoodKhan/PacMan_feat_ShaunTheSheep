#pragma once
#include "brick.h"
#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
brick :: brick()
{

}
brick::brick(string name, float x, float y)
{
    position = Vector2f(x, y);
    sprite.setPosition(position);
    setupsprite(name);
}
void brick :: setupsprite(string textname)
{
    texture.loadFromFile(textname);
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(0, 0, 50, 50));
}
Sprite brick :: getsprite()
{
    return sprite;
}
