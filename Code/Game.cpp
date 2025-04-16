#include "Game.h"
#include <Math.h>
#include <iostream>
#include <sstream>
#include "GameMap.h"

/*
-----------------
PRIVATE Functions
-----------------
*/

void Game::drawWord(RenderWindow& window)
{
	if (game_map.getWord() != word)
	{
		initWord();
	}
	auto iterator = word_sprites.begin();
	while (iterator != word_sprites.end())
	{
		window.draw(*iterator);
		iterator++;
	}
}

void Game::initWord()
{
	word_sprites.clear();
	word_textures.clear();

	word = game_map.getWord();


	for (int i = 0; i < word.length(); i++)
	{
		std::string str1("images/Letters/Pink/");
		str1.push_back(word.at(i));
		std::string str = str1 + ".png";
		Texture letter_texture;
		letter_texture.loadFromFile(str);

		word_textures.push_back(letter_texture);

		Sprite letter_sprite;
		letter_sprite.setScale(scale_x, scale_y);
		letter_sprite.setPosition((i + 4) * dX, 17 * dY);

		word_sprites.push_back(letter_sprite);
	}

	auto iterSprites = word_sprites.begin();
	auto iterTextures = word_textures.begin();
	while (iterSprites != word_sprites.end())
	{
		iterSprites->setTexture(*iterTextures);

		iterSprites++;
		iterTextures++;
	}


}

void Game::drawScore(RenderWindow& window)
{
	auto iterator = score_sprites.begin();
	while (iterator != score_sprites.end())
	{
		window.draw(*iterator);
		iterator++;
	}
}

void Game::updateScore()
{
	score = game_map.getScore();

	int buff_score = score;
	int length = 0;

	while (buff_score != 0)
	{
		int i = buff_score % 10;
		length++;
		buff_score = buff_score / 10;
	}
	if (score_sprites.size() < length)
	{
		//Добавить спрайт
		Sprite firstScore;
		firstScore.setScale(1.32f, 1.00f);
		firstScore.setTexture(score_textures[0]);
		firstScore.setPosition((28 - score_sprites.size()) * dX, 17 * dY);
		score_sprites.push_back(firstScore);

	}
	buff_score = score;
	auto iterator = score_sprites.begin();
	while (iterator != score_sprites.end())
	{
		int i = buff_score % 10;
		buff_score = buff_score / 10;
		iterator->setTexture(score_textures[i]);
		iterator++;
	}
}

void Game::initScore()
{
	for (int i = 0; i < 10; i++) {
		std::ostringstream ostr;
		ostr << "images/Digits/";
		ostr << i;
		ostr << ".png";
		//str1.push_back(ostr.str().at(0));
		std::string str = ostr.str();
		//str1 + ".png";
		std::cout << i;
		std::cout << str + ":" << i + ":" << score_textures[i].loadFromFile(str) << std::endl;
		ostr.clear();
	}
	Sprite firstScore;
	firstScore.setScale(1.32f, 1.00f);
	firstScore.setTexture(score_textures[0]);
	firstScore.setPosition(28 * dX, 17 * dY);
	score_sprites.push_back(firstScore);
}

void Game::drawHearts(RenderWindow& window)
{
	for (int i = 0; i < snake.getHealth(); i++)
	{
		heart_live_sprite.setPosition((4 + i) * dX, dY);
		window.draw(heart_live_sprite);
	}

	for (int i = 0; i < 3 - snake.getHealth(); i++)
	{
		heart_sprite.setPosition((4 + i + snake.getHealth()) * dX, dY);
		window.draw(heart_sprite);
	}
}

void Game::initHearts()
{
	heart_texture.loadFromFile("images/HUD/heart_off.png");
	heart_sprite.setScale(0.72725f, 0.71075f);
	heart_sprite.setTexture(heart_texture);

	heart_live_texture.loadFromFile("images/HUD/heart_on.png");
	heart_live_sprite.setScale(0.72725f, 0.71075f);
	heart_live_sprite.setTexture(heart_live_texture);
}

void Game::endGame()
{
	game_state = GAME_STATE::RESULT;
	alive = false;
}

/*
----------------
PUBLIC Functions
----------------
*/

Game::Game(RenderWindow& window)
{	
	game_state = GAME_STATE::MENU;
	
	dX = 58.18f;
	dY = 56.84f;
	
	alive = true;

	scale_x = 0.29f;
	scale_y = 0.2842f;

	std::cout << "FIELD" << field_texture.loadFromFile("images/Snake/field.png") << std::endl;
	field_sprite.setTexture(field_texture);

	dictionary.init("dictionaries/Dictionary.txt");
	dictionary.initWords();

	game_map.init(&dictionary, &snake, scale_x, scale_y, dX, dY);

	initWord();

	initScore();

	initHearts();
}


void Game::Tick(RenderWindow& window)
{
	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += time;

	if (timer > delay)
	{
		timer = 0;

		snake.go();

		if (game_map.checkMap(&snake))
		{
			endGame();
		}
		else
		{
			game_map.updateMap(&dictionary, &snake);
			updateScore();
		}
		
	}

}

void Game::input(Keyboard::Key key)
{
	
	switch (key)
	{
		case Keyboard::Left:
		{
			snake.setDirection(LEFT);
			break;
		}
		case Keyboard::Right:
		{
			snake.setDirection(RIGHT);
			break;
		}
		case Keyboard::Up:
		{
			snake.setDirection(UP);
			break;
		}
		case Keyboard::Down:
		{
			snake.setDirection(DOWN);
			break;
		}
	}
	
}

void Game::setGameState(GAME_STATE state)
{
	game_state = state;
}

GAME_STATE Game::getGameState()
{
	return game_state;
}

bool Game::initDictionary() 
{
	return true;
}

void Game::draw(RenderWindow& window) 
{
	//Отрисовка фона
	window.draw(field_sprite);
	
	for (int i = 0; i < snake.getLength(); i++) {
		snake.updateTexture(i);
	}
	//Отрисовка змейки
	snake.drawSnake(window);

	//Отрисовка бонусов
	game_map.drawMap(window);


	Font font;
	font.loadFromFile("Calibri.ttf");
	std::ostringstream len, heal, sc;
	len << snake.getLength();
	heal << snake.getHealth();
	sc << game_map.getScore();

	std::string snake_len("Snake is " + len.str());
	Text snake_l("", font, 20);
	snake_l.setString(snake_len);
	snake_l.setPosition(0.0f, 0.0f);

	std::string lt("HEALTH: " + heal.str());
	Text snake_health("", font, 20);
	snake_health.setString(lt);

	snake_health.setPosition(0.0f, 20.0f);

	std::string game_score("SCORE: " + sc.str());
	Text game_sc("", font, 20);
	game_sc.setString(game_score);

	game_sc.setPosition(0.0f, 40.0f);

	window.draw(snake_l);
	window.draw(snake_health);
	window.draw(game_sc);

	drawWord(window);

	drawScore(window);

	drawHearts(window);

}

bool Game::isGameOver()
{
	return !alive;
}

int Game::getScore()
{
	return score;
}

void Game::restart()
{
	alive = true;
	snake.retry();
	game_map.restart(&dictionary, &snake);
}