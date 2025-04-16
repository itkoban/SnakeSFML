#pragma once
#include <SFML/Graphics.hpp>

//������������ ����������� ��������
enum DIR { RIGHT, LEFT, UP, DOWN };

//��������� ��� ����� ���� ������
struct Body { 
	int x;
	int y;
	DIR direction;
	sf::Sprite sprite;
};

class Snake {

private:

	Body* body; //����
	unsigned int length; //����� ����
	int health; //�����
	
	//������ ���� � ��������
	int size_x; 
	int size_y;
	
	//�������� ������
	sf::Texture head_LEFT, head_RIGHT, head_UP, head_DOWN;

	//�������� ������
	sf::Texture tail_LEFT, tail_RIGHT, tail_UP, tail_DOWN;

	//�������� ����
	sf::Texture body_LEFT, body_RIGHT, body_UP, body_DOWN;

	//�������� ����
	sf::Texture bend_LEFT_UP, bend_RIGHT_UP, bend_UP_LEFT, bend_DOWN_LEFT;
	//�������� ����
	sf::Texture bend_LEFT_DOWN, bend_RIGHT_DOWN, bend_UP_RIGHT, bend_DOWN_RIGHT;

	bool checkCollision(); // ��������� ������� �� ������ ���� ����

public:

	Snake(); //����������� �� ���������
	
	~Snake(); //����������

	void retry();
	
	void go(); //������� ������ � ����������� ��������

	void addBody(); //��������� 1 ����� ����

	Body getBody(int i); //���������� ����� ����

	void addHelth();

	void minusHealth();

	int getHealth();

	bool isAlive();
	
	unsigned int getLength(); //���������� ����� ����

	bool setDirection(DIR dir); //������ ����������� ������

	void updateTexture(int i);

	void drawSnake(sf::RenderWindow& window);

};
