#include "Bonus.h"

void Bonus::loadTextures()
{
	switch (box_color)
	{

		case BOX_COLOR::BLUE:
		{
			std::cout << "BOX" << texture_box.loadFromFile("images/Box/box_blue.png") << std::endl;
			
			std::string str1("images/Letters/Blue/");
			str1.push_back(type);
			std::string str = str1 + ".png";

			std::cout << "LETTER" << texture_letter.loadFromFile(str) << std::endl;
			break;
		}

		case BOX_COLOR::GREEN:
		{
			texture_box.loadFromFile("images/Box/box_green.png");
			std::string str1("images/Letters/Green/");
			str1.push_back(type);
			std::string str = str1 + ".png";

			std::cout << "LETTER" << texture_letter.loadFromFile(str) << std::endl;
			break;
		}

		case BOX_COLOR::ORANGE:
		{
			texture_box.loadFromFile("images/Box/box_orange.png");
			std::string str1("images/Letters/Orange/");
			str1.push_back(type);
			std::string str = str1 + ".png";

			std::cout << "LETTER" << texture_letter.loadFromFile(str) << std::endl;
			break;
		}

		case BOX_COLOR::YELLOW:
		{
			texture_box.loadFromFile("images/Box/box_yellow.png");
			std::string str1("images/Letters/Yellow/");
			str1.push_back(type);
			std::string str = str1 + ".png";

			std::cout << "LETTER" << texture_letter.loadFromFile(str) << std::endl;
			break;
		}


	}
}

Bonus::Bonus()
{
	
}

Bonus::Bonus(char t, int x, int y, BOX_COLOR color)
{
	type = t;
	this->x = x;
	this->y = y;

	box_color = color;
	
	loadTextures();
	
	sprite_box.setTexture(texture_box);
	sprite_box.setScale(0.29f, 0.2842f);
	sprite_box.setPosition((x + 4) * 58.18f, (y + 2) * 56.84f);

	sprite_letter.setTexture(texture_letter);
	sprite_letter.setScale(0.29f, 0.2842f);
	sprite_letter.setPosition((x + 4) * 58.18f, (y + 2) * 56.84f);

}



void Bonus::drawCell(RenderWindow& window)
{
	sprite_box.setTexture(texture_box);
	window.draw(sprite_box);
	sprite_letter.setTexture(texture_letter);
	window.draw(sprite_letter);
}

char Bonus::getType()
{
	return type;
}

int Bonus::getX()
{
	return x;
}

int Bonus::getY()
{
	return y;
}