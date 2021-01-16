#include <iostream>
#include <Windows.h>
#include "Map.h"
#include "Game.h"
using namespace std;

//const int NotUsed = system("color 30");

void printMainMenu(int x, string* m, int len, bool centrScreen)
{
	if (centrScreen)
		for (int i = 0; i < 5; i++) cout << "\n";

	for (int i = 0; i < len; i++)
	{
		if (centrScreen) cout << "\n\t\t\t\t\t\t";
		else cout << "\n";

		if (i == x) cout << " > ";
		else cout << "   ";

		cout << m[i].c_str();
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Map gamer, bot;
	Game game;
	Player player;

	string name;
	string menu[3] = {
		"Старт игры",
		"Статистика",
		"Выход"
	};
	string installShip[2] = {
		"Установить корабли вручную",
		"Установить корабли автоматически"
	};

	int cursor{};
	int key;
	int complexity;

	while (1)
	{
		system("cls");
		cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

		cout << "\n\n\t\t\t\t\t\tМ О Р С К О Й  Б О Й" << endl;
		printMainMenu(cursor, menu, 3, true);
		cout << endl <<"\n\n\n\n\n\n\n\n\n\n\ \t\t\t\t\t\tby Kvitnytskyi Roman \n//////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

		key = _getch();

		if ((key == 72) && cursor != 0) cursor--;
		if ((key == 80) && cursor != 2) cursor++;

		if (key == 13)
		{
			if (cursor == 0)
			{
				system("cls");

				cout << "Введите ваше имя -> ";
				cin >> name;

				system("cls");
				cout << "Выберите сложность игры:" << endl
					<< "1) Легко;" << endl
					<< "2) Средне; " << endl
					<< "3) Сложно; " << endl << endl;

				cout << "Сложность -> ";
				cin >> complexity;

				gamer.setName(name);
				gamer.setComplexity(complexity);

				int tempCursor{};

				do
				{
					system("cls");
					printMainMenu(tempCursor, installShip, 2, false);

					key = _getch();

					if ((key == 72) && tempCursor != 0) tempCursor--;
					if ((key == 80) && tempCursor != 1) tempCursor++;

				} while (key != 13);

				if (tempCursor == 0)
					gamer.arrangement();
				else
				{
					system("cls");
					cout << "Расстановка";
					for (int i = 0; i < 3; i++)
					{
						Sleep(500);
						cout << ".";
					}

					gamer.random_arrangement();
					system("cls");
				}

				system("cls");
				cout << "Игра начинается!!!" << endl;
				Sleep(1500);
				bot.random_arrangement();

				do
				{
					while (gamer.getShot())
						game.shot(gamer, bot);

					while (!gamer.getShot())
						game.shot(gamer, bot);
				} while (game.getBotShot() != 0 && game.getPlayerShot() != 0);

				system("cls");

				cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
				cout << "\n\n\t\t\t\tИгра окончена!" << endl;
				if (game.getPlayerShot() == 0)
					cout << "\t\tВыиграл компьютер" << endl;
				else
					cout << "\t\t\tВыиграл " << gamer.getName() << endl;
				cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

				system("pause");
			}
			else if (cursor == 1)
			{
				system("cls");

				cout << "Player name: " << gamer.getName() << endl;
				cout << "Complexity: " << gamer.getComplexity() << endl;
				cout << "Number of shots: " << gamer.getNumberOfShots() << endl;

				system("pause");
			}
			else if (cursor == 2)
			{
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n";
				cout << "\t\t\t\t\t\t";
				cout << "  ИГРА ОКОНЧЕНА!" << endl;
				cout << "\n\n\n\n\n\n\n\n\n\n";

				system("pause");
				return 0;
			}
		}
	}

	return 0;
}
