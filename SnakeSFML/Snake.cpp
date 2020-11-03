#include "Snake.h"
#include <iostream>

bool Snake::checkCollision()
{
	for (int i = length; i > 0; i--)
	{
		if (body[0].x == body[i].x && body[0].y == body[i].y)
		{
			return true;
		}
		else return false;
	}
	return false;
}

Snake::Snake() {
	length = 3;
	body = new Body[100];
	size_x = 25;
	size_y = 14;
		
	health = 3;
	for (int i = 0; i < 100; i++)
	{
		body[i].sprite.setScale(0.29f, 0.2842f);
	}
	//ГОЛОВА
	body[0].x = 0;
	body[0].y = size_y / 2;
	body[0].direction = LEFT;

	std::cout << "images/Snake/Head/head_left.png " << head_LEFT.loadFromFile("images/Snake/Head/head_left.png") << std::endl;;
	std::cout << "images/Snake/Head/head_right.png " << head_RIGHT.loadFromFile("images/Snake/Head/head_right.png") << std::endl;
	std::cout << "images/Snake/Head/head_up.png " << head_UP.loadFromFile("images/Snake/Head/head_up.png") << std::endl;
	std::cout << "images/Snake/Head/head_down.png " << head_DOWN.loadFromFile("images/Snake/Head/head_down.png") << std::endl;
		
	//Тело
	body[1].x = 1;
	body[1].y = size_y / 2;
	body[1].direction = LEFT;

	std::cout << "images/Snake/Body/body_left.png " << body_LEFT.loadFromFile("images/Snake/Body/body_left.png") << std::endl;
	std::cout << "images/Snake/Body/body_right.png " << body_RIGHT.loadFromFile("images/Snake/Body/body_right.png") << std::endl;
	std::cout << "images/Snake/Body/body_up.png " << body_UP.loadFromFile("images/Snake/Body/body_up.png") << std::endl;
	std::cout << "images/Snake/Body/body_down.png " << body_DOWN.loadFromFile("images/Snake/Body/body_down.png") << std::endl;

	//ХВОСТ
	body[2].x = 2;
	body[2].y = size_y / 2;
	body[2].direction = LEFT;

	std::cout << "images/Snake/Tail/tail_left.png " << tail_LEFT.loadFromFile("images/Snake/Tail/tail_left.png") << std::endl;
	std::cout << "images/Snake/Tail/tail_right.png " << tail_RIGHT.loadFromFile("images/Snake/Tail/tail_right.png") << std::endl;
	std::cout << "images/Snake/Tail/tail_up.png " << tail_UP.loadFromFile("images/Snake/Tail/tail_up.png") << std::endl;
	std::cout << "images/Snake/Tail/tail_down.png " << tail_DOWN.loadFromFile("images/Snake/Tail/tail_down.png") << std::endl;

	//Перегибы
	std::cout << "images/Snake/Bend/bend_LEFT_UP.png " << bend_LEFT_UP.loadFromFile("images/Snake/Bend/bend_LEFT_UP.png") << std::endl;
	std::cout << "images/Snake/Bend/bend_RIGHT_UP.png " << bend_RIGHT_UP.loadFromFile("images/Snake/Bend/bend_RIGHT_UP.png") << std::endl;
	std::cout << "images/Snake/Bend/bend_UP_LEFT.png " << bend_UP_LEFT.loadFromFile("images/Snake/Bend/bend_UP_LEFT.png") << std::endl;
	std::cout << "images/Snake/Bend/bend_DOWN_LEFT.png " << bend_DOWN_LEFT.loadFromFile("images/Snake/Bend/bend_DOWN_LEFT.png") << std::endl;

	std::cout << "images/Snake/Bend/bend_LEFT_DOWN.png " << bend_LEFT_DOWN.loadFromFile("images/Snake/Bend/bend_LEFT_DOWN.png") << std::endl;
	std::cout << "images/Snake/Bend/bend_RIGHT_DOWN.png " << bend_RIGHT_DOWN.loadFromFile("images/Snake/Bend/bend_RIGHT_DOWN.png") << std::endl;
	std::cout << "images/Snake/Bend/bend_UP_RIGHT.png " << bend_UP_RIGHT.loadFromFile("images/Snake/Bend/bend_UP_RIGHT.png") << std::endl;
	std::cout << "images/Snake/Bend/bend_DOWN_RIGHT.png " << bend_DOWN_RIGHT.loadFromFile("images/Snake/Bend/bend_DOWN_RIGHT.png") << std::endl;
}

Snake::~Snake() {
	delete [] body;
}

void Snake::retry() {
		
	length = 3;

	body[0].x = 0;
	body[0].y = size_y / 2;
	body[0].direction = LEFT;

	body[1].x = 1;
	body[1].y = size_y / 2;
	body[1].direction = LEFT;

	body[2].x = 2;
	body[2].y = size_y / 2;
	body[2].direction = LEFT;

}

	
//Добавить разворот спрайтов
void Snake::go() {
	//Двигаем тело
	for (int i = length - 1; i >= 1; i--) {
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
		body[i].direction = body[i - 1].direction;
	}

	//Двигаем голову
	switch (body[0].direction) {
		case RIGHT: {
			body[0].x = (size_x + body[0].x + 1) % size_x;
			break;
		}
		case LEFT: {
			body[0].x = (size_x + body[0].x - 1) % size_x;
			break;
		}
		case UP: {
			body[0].y = (size_y + body[0].y - 1) % size_y;
			break;
		}
		case DOWN: {
			body[0].y = (size_y + body[0].y + 1) % size_y;;
			break;
		}
	}

	//Обновляем текстуры змейки
	for (int i = 0; i < length; i++) {
		updateTexture(i);
	}
}



void Snake::Snake::addBody() {
	length++;
		
	body[length - 1].x = body[length - 2].x;
	body[length - 1].y = body[length - 2].y;
	body[length - 1].direction = body[length - 2].direction;
	switch (body[length - 1].direction) {
		case RIGHT: {
			body[length - 1].x = (size_x + body[length - 1].x - 1) % size_x;
			break;
		}
		case LEFT: {
			body[length - 1].x = (size_x + body[length - 1].x + 1) % size_x;
			break;
		}
		case UP: {
			body[length - 1].y = (size_y + body[length - 1].y + 1) % size_y;
			break;
		}
		case DOWN: {
			body[length - 1].y = (size_y + body[length - 1].y - 1) % size_y;;
			break;
		}
	}
	
}

Body Snake::getBody(int i) {
	if (i < length) {
		return(body[i]);
	}
	return(body[0]);
}

void Snake::addHelth()
{
	if (health < 3)
	{
		health++;
	}
}

void Snake::minusHealth()
{
	health--;
	if (health == 0)
	{
		health = 3;
		retry();
	}
}

int Snake::getHealth()
{
	return health;
}

bool Snake::isAlive()
{
	if (health > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


unsigned int Snake::getLength() {
	return length;
}

bool Snake::setDirection(DIR dir) {
	switch (body[0].direction)
	{
	case RIGHT:
		if (dir == LEFT) {
			return false;
			break;
		}
		body[0].direction = dir;
		return true;
		break;
	case LEFT:
		if (dir == RIGHT) {
			return false;
			break;
		}
		body[0].direction = dir;
		return true;
		break;
	case UP:
		if (dir == DOWN) {
			return false;
			break;
		}
		body[0].direction = dir;
		return true;
		break;
	case DOWN:
		if (dir == UP) {
			return false;
			break;
		}
		body[0].direction = dir;
		return true;
		break;
	}

}

void Snake::updateTexture(int i) {
	if (i == length - 1) {

		switch (body[i].direction)
		{
		case RIGHT: 
				
			body[i].sprite.setTexture(tail_RIGHT);
			break;

		case LEFT: 
				
			body[i].sprite.setTexture(tail_LEFT);
			break;
		case UP: 
				
			body[i].sprite.setTexture(tail_UP);
			break;

		case DOWN: 
				
			body[i].sprite.setTexture(tail_DOWN);
			break;

		}

	}
	//Для головы
	else if (i == 0) {

		switch (body[i].direction)
		{
		case RIGHT: 
				
			body[i].sprite.setTexture(head_RIGHT);
			break;

		case LEFT: 
				
			body[i].sprite.setTexture(head_LEFT);
			break;

		case UP: 
				
			body[i].sprite.setTexture(head_UP);
			break;

		case DOWN: 
				
			body[i].sprite.setTexture(head_DOWN);
			break;

		}

	}
	//Для тела, ДОБАВИТЬ ПЕРЕГИБ
	else {
		if ((body[i].x == body[i - 1].x && body[i].x == body[i + 1].x) || (body[i].y == body[i - 1].y && body[i].y == body[i + 1].y)) {

			switch (body[i].direction)
			{
			case RIGHT: 
					
				body[i].sprite.setTexture(body_RIGHT);
				break;

			case LEFT: 
					
				body[i].sprite.setTexture(body_LEFT);
				break;

			case UP: 
					
				body[i].sprite.setTexture(body_UP);
				break;

			case DOWN: 
				
				body[i].sprite.setTexture(body_DOWN);
				break;

			}
		}
		else {

			switch (body[i + 1].direction)
			{
			case RIGHT:

				switch (body[i - 1].direction)
				{
				case UP: 
						
					body[i].sprite.setTexture(bend_UP_LEFT);
					break;

				case DOWN: 
					
					body[i].sprite.setTexture(bend_DOWN_LEFT);
					break;
				}
				break;
			case LEFT:
				switch (body[i - 1].direction)
				{
				case UP: 
					
					body[i].sprite.setTexture(bend_UP_RIGHT);
					break;
				case DOWN: 
					
					body[i].sprite.setTexture(bend_DOWN_RIGHT);
					break;
				}
				break;
			case UP:
				switch (body[i - 1].direction)
				{
				
				case RIGHT: 
					
					body[i].sprite.setTexture(bend_RIGHT_DOWN);
					break;
				case LEFT: 
					
					body[i].sprite.setTexture(bend_LEFT_DOWN);
					break;
				}
				break;

			case DOWN:
				switch (body[i - 1].direction)
				{
				
				case RIGHT: 
				
					body[i].sprite.setTexture(bend_RIGHT_UP);
					break;

				case LEFT: 
					
					body[i].sprite.setTexture(bend_LEFT_UP);
					break;
				}
				break;
			}
		}
	}
}

void Snake::drawSnake(sf::RenderWindow& window)
{
	for (int i = 0; i < length; i++) {
		body[i].sprite.setPosition((body[i].x + 4) * 58.18f, (body[i].y + 2) * 56.84f);
		window.draw(body[i].sprite);
	}
}