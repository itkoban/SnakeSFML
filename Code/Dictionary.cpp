#include "Dictionary.h"

bool Dictionary::initWords()
{
	//�������� ������ �� ����
	if (!is_loaded)
	{
		count_words = 0;
		return false;
	}

	//����������� ������� �������
	if (file.good())
	{
		file >> count_words;
		words = new std::string[count_words];
	}
	else
	{
		count_words = 0;
		return false;
	}

	//�������� ����
	for (int i = 0; i < count_words; i++) {
		if (!file.eof()) file >> words[i];
	}

	return true;
}

Dictionary::~Dictionary() {
	if (file.is_open()) file.close();
	delete[] words;
}

bool Dictionary::init(std::string path)
{
	file.open(path);
	is_loaded = file.is_open();
	return is_loaded;
}

int Dictionary::getSize()
{
	return count_words;
}


std::string Dictionary::getWord(int index)
{
	if (index < count_words)
	{
		return words[index];
	}

	return "";
}



std::string Dictionary::getRandWord()
{
	int index = rand() % count_words;
	
	return words[index];
}


