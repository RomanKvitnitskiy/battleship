#pragma once
#include "Player.h"

using namespace std;

class Map : public Player
{
public:
	bool arrangement();
	void random_arrangement();

	void setMap(int, int, int);
	int getMap(int, int);
	
	void setShot(bool);
	bool getShot();

	friend void show(Map&, Map&);

private:
	const int SIZE = 10;

	int map[10][10]{};

	bool shot = 1;

	void set_ship(int, int);
	bool set_ship(int, int, int, int);

	void drawField();
	void printMainMenu(int, string*, int, bool);
	void printMenuShip(int, string*, int*, int, bool);
};

