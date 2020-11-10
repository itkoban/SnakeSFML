#pragma once

#include <Math.h>
#include <iostream>
#include <sstream>

#include <SFML\Graphics.hpp>

#include "Snake.h"
#include "Dictionary.h"
#include "GameMap.h"


using namespace sf;

enum class GAME_STATE
{
	PLAY, PAUSE, RESULT, MENU
};

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

	Clock clock;
	float timer = 0, delay = 0.14;

	bool alive;

	Texture field_texture;
	Sprite field_sprite;

	std::vector<Sprite> word_sprites;
	std::vector<Texture> word_textures;
	std::string word;

	Texture heart_texture;
	Sprite heart_sprite;

	Texture heart_live_texture;
	Sprite heart_live_sprite;

	Snake snake;

	Dictionary dictionary;
	
	GAME_STATE game_state;

	void drawWord(RenderWindow& window);

	void initWord();

	void drawScore(RenderWindow& window);

	void updateScore();

	void initScore();

	void drawHearts(RenderWindow& window);

	void initHearts();

	void endGame();

public:

	Game(RenderWindow& window);

	void Tick(RenderWindow& window);

	void input(Keyboard::Key key);

	void setGameState(GAME_STATE state);

	GAME_STATE getGameState();

	bool initDictionary();

	void addScore(int points);

	void draw(RenderWindow& window);
	
	bool isGameOver();

	int getScore();

	void restart();

};