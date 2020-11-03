#pragma once
#include <SFML/Graphics.hpp>

//—делать класс  Ќќѕ »
class Menu
{

private:

	float scale_x;
	float scale_y;

	int menuNum;

	bool is_menu;

	//‘он
	sf::Texture backTexture;
	sf::Sprite backSprite;
	
	// нопки
	sf::Texture playTextureActive;
	sf::Texture playTexturePassive;
	sf::Sprite playButton;

	sf::Texture rateTextureActive;
	sf::Texture rateTexturePassive;
	sf::Sprite rateButton;

	sf::Texture settingsTextureActive;
	sf::Texture settingsTexturePassive;
	sf::Sprite settingsButton;

	sf::Texture closeTextureActive;
	sf::Texture closeTexturePassive;
	sf::Sprite closeButton;

	bool containsSprite(sf::Sprite sprite, int x, int y);

public:

	Menu(sf::RenderWindow & window);

	void draw(sf::RenderWindow & window);

	void events(sf::RenderWindow & window);

	bool isMenu();

	void goMenu(bool isMenu);

};

