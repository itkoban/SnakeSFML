#pragma once
#include <SFML/Graphics.hpp>

enum class MENU_STATE
{
	CLOSE, SETTINGS, RATING, GAME, NONE
};

//—делать класс  Ќќѕ »
class Menu
{

private:

	float scale_x;
	float scale_y;

	bool active;

	int menuNum;

	MENU_STATE menu_state;

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

	void setState(MENU_STATE state);

	void disable();

	void activate();

	bool isActive();

	MENU_STATE getState();

};

