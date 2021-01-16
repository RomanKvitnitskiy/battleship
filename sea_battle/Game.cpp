#include "Game.h"
#include <Windows.h>
#include <vector>

void Game::shot(Map& first, Map& second)
{
	bool shot = first.getShot();
	int x, y;

	system("cls");
	show(first, second);

	if (shot)
	{
		first.setNumberOfShots(1);
		cout << endl << "Ходит " << first.getName() << endl;
		cout << "Введите координаты атаки:" << endl;

		cout << "x -> ";
		cin >> y;
		cout << "y -> ";
		cin >> x;

		if (second.getMap(x, y) == 0)
		{
			cout << "Промах!" << endl;
			second.setMap(x, y, 3);

			first.setShot(0);
		}
		else if (second.getMap(x, y) == 1)
		{
			cout << "Попадание!" << endl;

			botShot--;
			second.setMap(x, y, 2);

			first.setShot(1);
		}

		Sleep(1000);
	}
	else
	{
		cout << endl << "Ходит компьютер" << endl;
		if (first.getComplexity() == 1)
			firstComplexity(first, second);
		else if (first.getComplexity() == 2)
			secondComplexity(first, second);
		else if (first.getComplexity() == 3)
			thirdComplexity(first, second);		
	}
}

void Game::setPlayerShot(int playerShot) { this->playerShot = playerShot; }
int Game::getPlayerShot() { return playerShot; }

void Game::setBotShot(int botShot) { this->botShot = botShot; }
int Game::getBotShot() { return botShot; }

void Game::firstComplexity(Map& first, Map& second)
{
	int x, y;

	Sleep(1000);

	x = rand() % 10;
	y = rand() % 10;

	if (first.getMap(x, y) == 0)
	{
		cout << "Промах!" << endl;
		first.setMap(x, y, 3);

		first.setShot(1);
	}
	else if (first.getMap(x, y) == 1)
	{
		cout << "Попадание!" << endl;
		first.setMap(x, y, 2);

		playerShot--;
		first.setShot(0);
	}

	Sleep(1000);
}
void Game::secondComplexity(Map& first, Map& second)
{
	Sleep(1000);

	int x{}, y{};
	int count{};

	do
	{
		x = rand() % 10;
		y = rand() % 10;
		count++;
	} while (first.getMap(x, y) != 1 && count < 3);

	if (first.getMap(x, y) == 1)
	{
		cout << "Попадание" << endl;
		playerShot--;
		first.setMap(x, y, 2);

		first.setShot(0);
	}
	else
	{
		cout << "Промах" << endl;
		first.setMap(x, y, 3);

		first.setShot(1);
	}

	Sleep(2000);
}
void Game::thirdComplexity(Map& first, Map& second)
{	
	Sleep(1000);

	int x{}, y{};
	int count{};

	do
	{
		x = rand() % 10;
		y = rand() % 10;
		count++;

		if (first.getMap(x, y) == 3 || first.getMap(x, y) == 2)
			count--;
	} while (first.getMap(x, y) != 1 && count < 5);

	if (first.getMap(x, y) == 1)
	{
		cout << "Попадание" << endl;
		playerShot--;
		first.setMap(x, y, 2);

		first.setShot(0);
	}
	else
	{
		cout << "Промах" << endl;
		first.setMap(x, y, 3);

		first.setShot(1);
	}

	Sleep(2000);
}
