/*
 * ---------------------------------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <edouembe@ensea.fr> and <showok@showok.info> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Edouard Emberger and Théo Segonds
 * ---------------------------------------------------------------------------------------------------
 */
#ifndef GRAPHICS
#define GRAPHICS

#define SPRITE_SIZE 80
#define WINDOW_W 1100
#define WINDOW_H 720

#include "Point2I.h"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std; 

class GraphicElement {


	public:	GraphicElement();
		~GraphicElement();
		GraphicElement(const string s);
		void draw(sf::RenderWindow & window);
		void setSprite(string fileName, int lvl);
		sf::Sprite& getSprite(char state);
		void setPosition(Point2I p);
		Point2I getPosition();
		void setRotation(float angle);
		void setScale(float size);
		void checkPosition();

protected:
    sf::Sprite img;
    sf::Texture t;
    Point2I p;
};

#endif

