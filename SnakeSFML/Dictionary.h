#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>


class Dictionary
{
private:

	std::string* words;
	int count_words;
	std::ifstream file;
	bool is_loaded;
	
	
public:

	~Dictionary();

	bool init(std::string path);

	bool initWords();

	int getSize();

	std::string getWord(int index);

	std::string getRandWord();

};

