#include "GameMenu.h"

/*
-----------------
PRIVATE Functions
-----------------
*/

bool GameMenu::containsSprite(sf::Sprite sprite, int x, int y) {

	int sprite_size_x = sprite.getTexture()->getSize().x;
	int sprite_size_y = sprite.getTexture()->getSize().y;

	int sprite_x = sprite.getPosition().x;
	int sprite_y = sprite.getPosition().y;

	if ((x >= sprite_x && x <= sprite_size_x + sprite_x) && (y >= sprite_y && y <= sprite_y + sprite_size_y)) {
		return true;
	}
	return false;
}

void GameMenu::drawStars(sf::RenderWindow& window)
{
	int score = game_obj->getScore();
	if (score < 100 && score > 0)
	{
		leftStar.setTexture(leftStarActive);
	}
	else if (score < 150 && score >= 100)
	{
		leftStar.setTexture(leftStarActive);
		centerStar.setTexture(centerStarActive);
	}
	else if(score >= 150)
	{
		leftStar.setTexture(leftStarActive);
		centerStar.setTexture(centerStarActive);
		rightStar.setTexture(rightStarActive);
	}

	window.draw(leftStar);
	window.draw(centerStar);
	window.draw(rightStar);
}

/*
----------------
PUBLIC Functions
----------------
*/

GameMenu::GameMenu(sf::RenderWindow& window, Game* game_link)
{
	game_obj = game_link;

	scale_x = window.getSize().x / 1920.0f;
	scale_y = window.getSize().y / 1080.0f;

	menuNum = 0;

	font.loadFromFile("Calibri.ttf");

	backTexture.loadFromFile("images/GameMenu/back.png");
	backSprite.setTexture(backTexture);
	backSprite.setScale(scale_x, scale_y);

	//Блок текстур
	returnTexturePassive.loadFromFile("images/GameMenu/return.png");
	returnTextureActive.loadFromFile("images/GameMenu/return_active.png");
	returnButton.setTexture(returnTexturePassive);
	returnButton.setScale(scale_x, scale_y);
	returnButton.setPosition(window.getSize().x / 2 - 1.6 * scale_x * returnTexturePassive.getSize().x, window.getSize().y / 2 + window.getSize().y / 4 - 1.2 * scale_y * returnTexturePassive.getSize().y / 2);

	//window.getSize().x / 2 - scale_x * returnTexturePassive.getSize().x / 2
	retryTexturePassive.loadFromFile("images/GameMenu/retry.png");
	retryTextureActive.loadFromFile("images/GameMenu/retry_active.png");
	retryButton.setTexture(retryTexturePassive);
	retryButton.setScale(scale_x, scale_y);
	retryButton.setPosition(window.getSize().x / 2 - scale_x * retryTexturePassive.getSize().x / 2, window.getSize().y / 2 + window.getSize().y / 4 - 1.2 * scale_y * retryTexturePassive.getSize().y / 2);


	closeTexturePassive.loadFromFile("images/GameMenu/close.png");
	closeTextureActive.loadFromFile("images/GameMenu/close_active.png");
	closeButton.setTexture(closeTexturePassive);
	closeButton.setScale(scale_x, scale_y);
	closeButton.setPosition(window.getSize().x / 2 + 1.2 * scale_x * closeTexturePassive.getSize().x / 2, window.getSize().y / 2 + window.getSize().y / 4 - 1.2 * scale_y * closeTexturePassive.getSize().y / 2);
	
	leftStarPassive.loadFromFile("images/HUD/star_left_off.png");
	leftStarActive.loadFromFile("images/HUD/star_left_on.png");
	leftStar.setTexture(leftStarPassive);
	leftStar.setScale(scale_x, scale_y);
	leftStar.setPosition(window.getSize().x / 2 - 200.0 * scale_x, window.getSize().y / 5);


	centerStarPassive.loadFromFile("images/HUD/star_center_off.png");
	centerStarActive.loadFromFile("images/HUD/star_center_on.png");
	centerStar.setTexture(centerStarPassive);
	centerStar.setScale(scale_x, scale_y);
	centerStar.setPosition(window.getSize().x / 2 - scale_x * centerStarPassive.getSize().x / 2, window.getSize().y / 5);

	rightStarPassive.loadFromFile("images/HUD/star_right_off.png");
	rightStarActive.loadFromFile("images/HUD/star_right_on.png");
	rightStar.setTexture(rightStarPassive);
	rightStar.setScale(scale_x, scale_y);
	rightStar.setPosition(window.getSize().x / 2 + 100.0 * scale_x, window.getSize().y / 5);

}

void GameMenu::draw(sf::RenderWindow& window) {

	std::ostringstream score;
	score << game_obj->getScore();

	std::string text("Score\t\t\t\t\t\t\t\t" + score.str());
	Text score_text("", font, 40);
	score_text.setString(text);
	score_text.setPosition(window.getSize().x / 2 - 1.8 * scale_x * returnTexturePassive.getSize().x, window.getSize().y / 3 * 1.0f);
	
	window.draw(backSprite);
	window.draw(returnButton);
	window.draw(retryButton);
	window.draw(closeButton);
	window.draw(score_text);
	drawStars(window);
}

//Сделать класс КНОПКИ
COMMAND GameMenu::events(sf::RenderWindow& window) {

	int mouse_x = sf::Mouse::getPosition(window).x;
	int mouse_y = sf::Mouse::getPosition(window).y;

	menuNum = 0;
	//BACK
	if (containsSprite(returnButton, mouse_x, mouse_y)) {
		returnButton.setTexture(returnTextureActive);
		menuNum = 1;
	}
	else {
		returnButton.setTexture(returnTexturePassive);
	}

	//RETRY
	if (containsSprite(retryButton, mouse_x, mouse_y)) {
		retryButton.setTexture(retryTextureActive);
		menuNum = 2;
	}
	else {
		retryButton.setTexture(retryTexturePassive);
	}


	//CLOSE
	if (containsSprite(closeButton, mouse_x, mouse_y)) {
		closeButton.setTexture(closeTextureActive);
		menuNum = 3;
	}
	else {
		closeButton.setTexture(closeTexturePassive);
	}



	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		switch (menuNum)
		{

		case 1: {
			return COMMAND::BACK;
			break;
		}

		case 2: {
			return COMMAND::RETRY;
			break;
		}

		case 3: {
			return COMMAND::MENU;
			break;
		}

		default:
			return COMMAND::NONE;
			break;
		}
	}


}
