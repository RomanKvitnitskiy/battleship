#pragma once
#include "Map.h"

class Game
{
public:
	void shot(Map&, Map&);

	void setPlayerShot(int);
	int getPlayerShot();

	void setBotShot(int);
	int getBotShot();

private:
	int playerShot = 20;
	int botShot = 20;

	void firstComplexity(Map&, Map&);
	void secondComplexity(Map&, Map&);
	void thirdComplexity(Map&, Map&);
};
