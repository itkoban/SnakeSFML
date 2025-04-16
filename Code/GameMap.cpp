#include "GameMap.h"

/*
-----------------
PRIVATE Functions
-----------------
*/

bool GameMap::checkLetter(int x, int y)
{
	if (cur_letter >= word.length())
	{
		return false;
	}
	if (map[x][y] == word.at(cur_letter))
	{
		cur_letter++;
		return true;
	}
	else
	{
		return false;
	}
}

bool GameMap::checkHead(Snake* snake, int x, int y)
{
	int snake_head_x = snake->getBody(0).x;
	int snake_head_y = snake->getBody(0).y;

	if (snake_head_x == x - 1 || snake_head_x == x + 1 || snake_head_x == x)
	{
		if (snake_head_y == y - 1 || snake_head_y == y + 1 || snake_head_y == y)
		{
			return true;
		}
	}
	return false;
}

/*
----------------
PUBLIC Functions
----------------
*/

void GameMap::init(Dictionary* dictionary, Snake* snake, float scale_X, float scale_Y, float d_X, float d_Y)
{
	//�������� �������
	std::cout << "BLUE: " << box_blue.loadFromFile("images/Box/box_blue.png") << std::endl;
	std::cout << "GREEN: " << box_green.loadFromFile("images/Box/box_green.png") << std::endl;
	std::cout << "ORANGE: " << box_orange.loadFromFile("images/Box/box_orange.png") << std::endl;
	std::cout << "YELLOW: " << box_yellow.loadFromFile("images/Box/box_yellow.png") << std::endl;
	
	//�������� ������
	std::cout << "FONT: " << font.loadFromFile("Calibri.ttf") << std::endl;
	
	heart.loadFromFile("images/HUD/heart_on.png");


	scale_x = scale_X;
	scale_y = scale_Y;
	dX = d_X;
	dY = d_Y;

	score = 0;

	//������������� ����� ���������� ������
	for (int i = 0; i < snake->getLength(); i++) {
		map[snake->getBody(i).x][snake->getBody(i).y] = '~';
	}
	word = dictionary->getRandWord();
	cur_letter = 0;
	
	//��������� ����� ������ �������
	int counter = word.length() - 1;
	int loop = 0;

	letters.clear();
	//boxSprites = new Sprite[word.length()];
	while (counter >= 0)
	{
		int box = rand() % 4;
		BOX_COLOR color;
		
		switch (box)
		{
			case 0:
			{
				color = BOX_COLOR::BLUE;
				break;
			}

			case 1:
			{
				color = BOX_COLOR::GREEN;
				break;
			}

			case 2:
			{
				color = BOX_COLOR::ORANGE;
				break;
			}

			case 3:
			{
				color = BOX_COLOR::YELLOW;
				break;
			}
		}

		int letter_x = rand() % 25;
		int letter_y = rand() % 14;
		if (map[letter_x][letter_y] == ' ' && !checkHead(snake, letter_x, letter_y))
		{
			map[letter_x][letter_y] = word.at(counter);
			Bonus bon(word.at(counter), letter_x, letter_y, color);
			letters.push_back(bon);
			counter--;
		}
		//���� ����� �� ������� ��������� �����, �� ������� �� �����
		if (loop < 50)
		{
			loop++;
		}
		else
		{
			counter = -1;
		}
	}
	for (int i = 0; i < letters.size(); i++)
	{
		std::cout << letters.at(i).getType() << std::endl;
	}
	
}

int GameMap::getScore()
{
	return score;
}

bool GameMap::checkMap(Snake* snake)
{
	bool over = false;
	int snake_head_x = snake->getBody(0).x;
	int snake_head_y = snake->getBody(0).y;
	//�������� ����� ����� ����
	if (map[snake_head_x][snake_head_y] == '~')
	{
		snake->retry();
		score = 0;
		over = true;
		cur_letter = word.length();
	}
	//�������� ����� ������
	else if (map[snake_head_x][snake_head_y] == '+')
	{
		snake->addHelth();
		map[snake_head_x][snake_head_y] = ' ';
	}
	else if (map[snake_head_x][snake_head_y] == ' ')
	{
		map[snake_head_x][snake_head_y] = '~';
	}
	//�������� ����� �����
	//���� ���������, �� ��������� ����
	else if (checkLetter(snake_head_x, snake_head_y))
	{
		snake->addBody();

		map[snake_head_x][snake_head_y] = '~';
		score += 5;
		auto iter = letters.cbegin();
		for (int i = letters.size() - 1; i >= 0; i--)
		{
			if (letters.at(i).getX() == snake_head_x && letters.at(i).getY() == snake_head_y)
			{
				letters.erase(iter + i);
				i = -10;
			}
		}
		if (letters.empty())
		{
			score += 10;
		}
	}
	//����� ������� ����� � �������� �����
	else
	{
		
		snake->minusHealth();
		if (snake->getHealth() == 0) {
			score = 0;
			over = true;
		}
		map[snake_head_x][snake_head_y] = ' ';
		letters.clear();
		
	}
	return over;
}



void GameMap::updateMap(Dictionary* dictionary, Snake* snake)
{
	//������� ����� �� ����������� ��������� ������
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 14; y++) {
			if (map[x][y] == '~') map[x][y] = ' ';
		}
	}

	//������������� ����� ���������� ������
	for (int i = 0; i < snake->getLength(); i++) {
		map[snake->getBody(i).x][snake->getBody(i).y] = '~';
	}

	//���� ����� �����������, �� �������� ����� � �������
	if (letters.empty()) {
		//������� ����� �� ����������� ��������� ����
		for (int x = 0; x < 25; x++) {
			for (int y = 0; y < 14; y++) {
				if (map[x][y] != '~') map[x][y] = ' ';
			}
		}
		letters.clear();
		//������ ����� �����
		word = dictionary->getRandWord();
		cur_letter = 0;
		//��������� ����� ������ �������
		int counter = word.length() - 1;
		int loop = 0;
		
		while (counter >= 0)
		{
			int box = rand() % 4;
			BOX_COLOR color;

			switch (box)
			{
			case 0:
			{
				color = BOX_COLOR::BLUE;
				break;
			}

			case 1:
			{
				color = BOX_COLOR::GREEN;
				break;
			}

			case 2:
			{
				color = BOX_COLOR::ORANGE;
				break;
			}

			case 3:
			{
				color = BOX_COLOR::YELLOW;
				break;
			}
			}


			int letter_x = rand() % 25;
			int letter_y = rand() % 14;
			if (map[letter_x][letter_y] == ' ' && !checkHead(snake, letter_x, letter_y))
			{
				map[letter_x][letter_y] = word.at(counter);
				Bonus bon(word.at(counter), letter_x, letter_y, color);
				letters.push_back(bon);
				counter--;
			}
			//���� ����� �� ������� ��������� �����, �� ������� �� �����
			if (loop < 50)
			{
				loop++;
			}
			else
			{
				counter = -1;
			}
		}
	}

	int heart_is = rand() % 1000;
	if (heart_is < 5) {
		int heart_x = rand() % 25;
		int heart_y = rand() % 14;
		if (map[heart_x][heart_y] == ' ')
		{
			map[heart_x][heart_y] = '+';
		}
	}

	std::cout << word;
	std::cout << "##############" << std::endl;
	
	for (int y = 0; y < 14; y++) {
		for (int x = 0; x < 25; x++) {
			if (map[x][y] == ' ')
			{
				std::cout << '.';
			}
			else
			{
				std::cout << map[x][y];
			}
		}
		std::cout << std::endl;
	}

	std::cout << "##############" << std::endl;
	//�������� ��������� ��������
	

}


void GameMap::drawMap(RenderWindow& window)
{
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 14; y++) {
			if (map[x][y] == '+')
			{
				Sprite heart_sprite;
				heart_sprite.setScale(0.72725f, 0.71075f);
				heart_sprite.setTexture(heart);
				heart_sprite.setPosition((x + 4) * dX, (y + 2) * dY);
				window.draw(heart_sprite);
			}
		}
	}
	for (int i = letters.size() - 1; i >= 0; i--)
	{
		letters.at(i).drawCell(window);
	}
}

std::string GameMap::getWord()
{
	return word;
}

void GameMap::restart(Dictionary* dictionary, Snake* snake)
{
	//������� ����� �� ����������� ��������� ����
	for (int x = 0; x < 25; x++) {
		for (int y = 0; y < 14; y++) {
			map[x][y] = ' ';
		}
	}
	letters.clear();
	//������������� ����� ���������� ������
	for (int i = 0; i < snake->getLength(); i++) {
		map[snake->getBody(i).x][snake->getBody(i).y] = '~';
	}
	word = dictionary->getRandWord();
	cur_letter = 0;

	//��������� ����� ������ �������
	int counter = word.length() - 1;
	int loop = 0;

	
	//boxSprites = new Sprite[word.length()];
	while (counter >= 0)
	{
		int box = rand() % 4;
		BOX_COLOR color;

		switch (box)
		{
		case 0:
		{
			color = BOX_COLOR::BLUE;
			break;
		}

		case 1:
		{
			color = BOX_COLOR::GREEN;
			break;
		}

		case 2:
		{
			color = BOX_COLOR::ORANGE;
			break;
		}

		case 3:
		{
			color = BOX_COLOR::YELLOW;
			break;
		}
		}

		int letter_x = rand() % 25;
		int letter_y = rand() % 14;
		if (map[letter_x][letter_y] == ' ')
		{

			map[letter_x][letter_y] = word.at(counter);
			Bonus bon(word.at(counter), letter_x, letter_y, color);
			letters.push_back(bon);
			counter--;
		}
		//���� ����� �� ������� ��������� �����, �� ������� �� �����
		if (loop < 50)
		{
			loop++;
		}
		else
		{
			counter = -1;
		}
	}
	for (int i = 0; i < letters.size(); i++)
	{
		std::cout << letters.at(i).getType() << std::endl;
	}
}