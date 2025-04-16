#pragma once
#include <SFML/Graphics.hpp>

//Перечесление направления движения
enum DIR { RIGHT, LEFT, UP, DOWN };

//Структура для куска тела змейки
struct Body { 
	int x;
	int y;
	DIR direction;
	sf::Sprite sprite;
};

class Snake {

private:

	Body* body; //Тело
	unsigned int length; //Длина тела
	int health; //Жизни
	
	//Размер поля в спрайтах
	int size_x; 
	int size_y;
	
	//Текстуры головы
	sf::Texture head_LEFT, head_RIGHT, head_UP, head_DOWN;

	//Текстуры хвоста
	sf::Texture tail_LEFT, tail_RIGHT, tail_UP, tail_DOWN;

	//Текстуры тела
	sf::Texture body_LEFT, body_RIGHT, body_UP, body_DOWN;

	//Текстуры тела
	sf::Texture bend_LEFT_UP, bend_RIGHT_UP, bend_UP_LEFT, bend_DOWN_LEFT;
	//Текстуры тела
	sf::Texture bend_LEFT_DOWN, bend_RIGHT_DOWN, bend_UP_RIGHT, bend_DOWN_RIGHT;

	bool checkCollision(); // Проверяет скушает ли змейка сама себя

public:

	Snake(); //Конструктор по умолчанию
	
	~Snake(); //Деструктор

	void retry();
	
	void go(); //Двигает змейку в направлении движения

	void addBody(); //Добавляет 1 часть тела

	Body getBody(int i); //Возвращает кусок тела

	void addHelth();

	void minusHealth();

	int getHealth();

	bool isAlive();
	
	unsigned int getLength(); //Возвращает длину тела

	bool setDirection(DIR dir); //Меняет направление змейки

	void updateTexture(int i);

	void drawSnake(sf::RenderWindow& window);

};
