#pragma once
#include <SFML/Graphics.hpp>

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

	//���
	sf::Texture backTexture;
	sf::Sprite backSprite;

	//������
	//������ �������� � ����
	sf::Texture returnTextureActive;
	sf::Texture returnTexturePassive;
	sf::Sprite returnButton;

	//������ �������� ����
	sf::Texture retryTextureActive;
	sf::Texture retryTexturePassive;
	sf::Sprite retryButton;

	//������ �������� � ����
	sf::Texture closeTextureActive;
	sf::Texture closeTexturePassive;
	sf::Sprite closeButton;

	bool containsSprite(sf::Sprite sprite, int x, int y);

public:

	GameMenu(sf::RenderWindow& window);

	void draw(sf::RenderWindow& window);

	COMMAND events(sf::RenderWindow& window);
};

