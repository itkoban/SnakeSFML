#pragma once

#include <SFML\Graphics.hpp>
#include "Snake.h"
#include "Dictionary.h"
#include "GameMap.h"

using namespace sf;


class Game
{

private:
	
	int score;
	std::vector<Sprite> score_sprites;
	Texture score_textures[10];

	float scale_x;
	float scale_y;

	float dX;
	float dY;

	GameMap game_map;

	int key_time;

	Clock clock;
	float timer = 0, delay = 0.14;


	Texture field_texture;
	Sprite field_sprite;

	std::vector<Sprite> word_sprites;
	std::vector<Texture> word_textures;
	std::string word;

	bool is_stop;
	bool is_pause;

	Snake snake;

	Dictionary dictionary;

	void drawWord(RenderWindow& window);

	void initWord();

	void drawScore(RenderWindow& window);

	void updateScore();

	void initScore();

public:

	Game();

	void Tick();

	void input(Keyboard::Key key);

	void pause(bool pause);

	void stop(bool stop);

	bool isStop(); //Возвращает состояние - Остановлена игра или нет

	bool isPause();

	bool initDictionary();

	void addScore(int points);

	void gameOver();

	void draw(RenderWindow& window);

	void restart();

};