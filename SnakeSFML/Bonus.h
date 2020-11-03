#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
//'a'..'z' - letter, '+' - heart, '~' - snake, ' ' - none 

using namespace sf;

enum class BOX_COLOR
{
	BLUE, GREEN, ORANGE, YELLOW
};

class Bonus
{

private:
	
	char type;

	BOX_COLOR box_color;

	Sprite sprite_box;
	Texture texture_box;
	
	Sprite sprite_letter;
	Texture texture_letter;

	int x;
	int y;

	void loadTextures();

public:

	Bonus();

	Bonus(char t, int x, int y, BOX_COLOR color);

	void drawCell(RenderWindow& window);

	char getType();

	int getX();

	int getY();



};

