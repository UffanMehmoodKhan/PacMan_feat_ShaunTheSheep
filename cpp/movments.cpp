
#pragma once
#include "movments.h"
#include<iostream>
#include<SFML/Graphics.hpp>


using namespace sf;
using namespace std;    

movments::movments()
{
	velocitypacman.x = 0.0f;
	velocitypacman.y = 0.0f;
	velocityredghost.x = 0.0f;
	velocityredghost.y = 0.0f;
	velocitypinkghost.x = 0.0f;
	velocitypinkghost.y = 0.0f;
}