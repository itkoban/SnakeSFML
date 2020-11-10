#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

bool Menu::containsSprite(sf::Sprite sprite, int x, int y) {
	
	int sprite_size_x = sprite.getTexture()->getSize().x;
	int sprite_size_y = sprite.getTexture()->getSize().y;

	int sprite_x = sprite.getPosition().x;
	int sprite_y = sprite.getPosition().y;

	if ((x >= sprite_x && x <= sprite_size_x + sprite_x) && (y >= sprite_y && y <= sprite_y + sprite_size_y)) {
		return true;
	}
	return false;
}



Menu::Menu(sf::RenderWindow & window) {

	scale_x = window.getSize().x / 1920.0f;
	scale_y = window.getSize().y / 1080.0f;

	menuNum = 0;

	active = true;

	menu_state = MENU_STATE::NONE;

	backTexture.loadFromFile("images/Menu/back.png");
	backSprite.setTexture(backTexture);
	backSprite.setScale(scale_x, scale_y);

	//Блок текстур
	playTexturePassive.loadFromFile("images/Menu/play.png");
	playTextureActive.loadFromFile("images/Menu/play_active.png");
	playButton.setTexture(playTexturePassive);
	playButton.setScale(scale_x, scale_y);
	playButton.setPosition(window.getSize().x / 2 - scale_x * playTexturePassive.getSize().x / 2, window.getSize().y / 2 - scale_y * playTexturePassive.getSize().y * 1.2);


	rateTexturePassive.loadFromFile("images/Menu/rate.png");
	rateTextureActive.loadFromFile("images/Menu/rate_active.png");
	rateButton.setTexture(rateTexturePassive);
	rateButton.setScale(scale_x, scale_y);
	rateButton.setPosition(window.getSize().x / 2 - scale_x * rateTexturePassive.getSize().x / 2, window.getSize().y / 2);


	settingsTexturePassive.loadFromFile("images/Menu/settings.png");
	settingsTextureActive.loadFromFile("images/Menu/settings_active.png");
	settingsButton.setTexture(settingsTexturePassive);
	settingsButton.setScale(scale_x, scale_y);
	settingsButton.setPosition(window.getSize().x / 2 - scale_x * settingsTexturePassive.getSize().x / 2, window.getSize().y / 2 + window.getSize().y / 8 - scale_y * settingsTexturePassive.getSize().y / 4);

	closeTexturePassive.loadFromFile("images/Menu/close.png");
	closeTextureActive.loadFromFile("images/Menu/close_active.png");
	closeButton.setTexture(closeTexturePassive);
	closeButton.setScale(scale_x, scale_y);
	closeButton.setPosition(window.getSize().x / 2 - scale_x * closeTexturePassive.getSize().x / 2, window.getSize().y / 2 + window.getSize().y / 4 + scale_y * closeTexturePassive.getSize().y / 2);
}

void Menu::draw(sf::RenderWindow& window) {
		
	window.clear(sf::Color::White);
	window.draw(backSprite);
	window.draw(playButton);
	window.draw(rateButton);
	window.draw(settingsButton);
	window.draw(closeButton);

}

//Сделать класс КНОПКИ
void Menu::events(sf::RenderWindow & window) {
	
	if (active)
	{
		int mouse_x = sf::Mouse::getPosition(window).x;
		int mouse_y = sf::Mouse::getPosition(window).y;

		menuNum = 0;
		//PLAY
		if (containsSprite(playButton, mouse_x, mouse_y)) {
			playButton.setTexture(playTextureActive);
			menuNum = 1;
		}
		else {
			playButton.setTexture(playTexturePassive);
		}

		//RATE
		if (containsSprite(rateButton, mouse_x, mouse_y)) {
			rateButton.setTexture(rateTextureActive);
			menuNum = 2;
		}
		else {
			rateButton.setTexture(rateTexturePassive);
		}

		//SETTINGS
		if (containsSprite(settingsButton, mouse_x, mouse_y)) {
			settingsButton.setTexture(settingsTextureActive);
			menuNum = 3;
		}
		else {
			settingsButton.setTexture(settingsTexturePassive);
		}

		//CLOSE
		if (containsSprite(closeButton, mouse_x, mouse_y)) {
			closeButton.setTexture(closeTextureActive);
			menuNum = 4;
		}
		else {
			closeButton.setTexture(closeTexturePassive);
		}



		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			switch (menuNum)
			{

			case 1: {
				menu_state = MENU_STATE::GAME;
				break;
			}

			case 4: {
				menu_state = MENU_STATE::CLOSE;
				break;
			}

			default:
				menu_state = MENU_STATE::NONE;
				break;
			}
		}
	}

	
}

void Menu::disable()
{
	active = false;
}

void Menu::activate()
{
	active = true;
}

bool Menu::isActive()
{
	return active;
}

void Menu::setState(MENU_STATE state)
{
	menu_state = state;
}

MENU_STATE Menu::getState()
{
	return menu_state;
}
