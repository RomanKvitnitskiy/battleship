#pragma once
#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

class Player
{
public:
	void setName(string);
	string getName();

	void setComplexity(int);
	int getComplexity();

	void setNumberOfShots(int);
	int getNumberOfShots();

	void setNumberOfHits(int);
	int getNumberOfHits();
private:
	string name;
	int complexity{};
	
	int numberOfShots{};
	int numberOfHits{};
};

