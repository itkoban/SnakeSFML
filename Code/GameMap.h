#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include "Snake.h"
#include "Bonus.h"
#include "Dictionary.h"
#include <vector>

using namespace sf;



class GameMap
{

private:

	int score;

	Texture box_blue;
	Texture box_green;
	Texture box_orange;
	Texture box_yellow;

	Texture heart;

	Font font;

	char map[25][14];
	std::vector<Bonus> letters;
	std::vector<Bonus> sprites;

	float scale_x;
	float scale_y;

	float dX;
	float dY;


	std::string word;
	int cur_letter;

	bool checkLetter(int x, int y);

	bool checkHead(Snake* snake, int x, int y);

public:

	void init(Dictionary* dictionary, Snake* snake, float scale_X, float scale_Y,	float d_X, float d_Y);

	int getScore();

	bool checkMap(Snake* snake);

	void updateMap(Dictionary* dictionary, Snake* snake);

	void drawMap(RenderWindow& window);

	std::string getWord();

	void restart(Dictionary* dictionary, Snake* snake);

};

