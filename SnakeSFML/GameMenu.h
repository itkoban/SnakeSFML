#pragma once

#include <sstream>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Game.h"

enum class COMMAND
{
	NONE, BACK, RETRY, MENU
};

class GameMenu
{

private:

	float scale_x;
	float scale_y;

	int menuNum;

	Game* game_obj;

	Font font;

	//‘он
	sf::Texture backTexture;
	sf::Sprite backSprite;

	// нопки
	// нопка возврата в игру
	sf::Texture returnTextureActive;
	sf::Texture returnTexturePassive;
	sf::Sprite returnButton;

	// нопка рестарта игры
	sf::Texture retryTextureActive;
	sf::Texture retryTexturePassive;
	sf::Sprite retryButton;

	// нопка перехода в ћеню
	sf::Texture closeTextureActive;
	sf::Texture closeTexturePassive;
	sf::Sprite closeButton;

	//STARS
	sf::Texture leftStarPassive;
	sf::Texture leftStarActive;
	sf::Sprite leftStar;
	
	sf::Texture centerStarPassive;
	sf::Texture centerStarActive;
	sf::Sprite centerStar;
	
	sf::Texture rightStarPassive;
	sf::Texture rightStarActive;
	sf::Sprite rightStar;



	bool containsSprite(sf::Sprite sprite, int x, int y);

	void drawStars(sf::RenderWindow& window);

public:

	GameMenu(sf::RenderWindow& window, Game *game_link);

	void draw(sf::RenderWindow& window);

	COMMAND events(sf::RenderWindow& window);
};

