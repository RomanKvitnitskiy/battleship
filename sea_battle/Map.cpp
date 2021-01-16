#include "Map.h"

void show(Map& first, Map& second)
{
	cout << " Player " << first.getName() << " \t\t\t\t\t\t" << "Bot" << endl << endl;

	string h = "  0 1 2 3 4 5 6 7 8 9";
	cout << h << " \t\t\t\t\t" << h << endl;

	for (int i = 0; i < first.SIZE; i++)
	{
		cout << i;
		for (int j = 0; j < first.SIZE; j++)
		{
			if (first.map[i][j] == 0)
				cout << " -";
			else if (first.map[i][j] == 1)
				cout << " #";
			else if (first.map[i][j] == 2)
				cout << " X";
			else if (first.map[i][j] == 3)
				cout << " .";
		}
			
		cout << "\t\t\t\t\t";

		cout << i;
		for (int j = 0; j < second.SIZE; j++)
		{
			if (second.map[i][j] == 0)
				cout << "  ";
			else if (second.map[i][j] == 1)
				cout << " #";
			else if (second.map[i][j] == 2)
				cout << " X";
			else if (second.map[i][j] == 3)
				cout << " .";
		}
		cout << endl;
	}
}

bool Map::arrangement()
{
	string installShip[2] = {
		"Установить корабль",
		"Начать игру"
	};
	string direction[2] = {
		"Вертикаль",
		"Горизонталь"
	};
	string listShip[4] = {
		"1) [] \t осталось ",
		"2) [][] \t осталось ",
		"3) [][][] \t осталось ",
		"4) [][][][] \t осталось "
	};

	int mode{};
	int cursors[3]{};
	int maxCursors[3] = { 2, 2, 4 };
	int ships[4] = { 4, 3, 2, 1 };

	bool start = 1;

	do
	{
		if (ships[0] == 0 &&
			ships[1] == 0 &&
			ships[2] == 0 &&
			ships[3] == 0)
		{
			start = 0;
		}

		system("cls");
		drawField();

		if (mode == 0)
		{
			cout << "\n\n Режим установки корабля" << endl;
			printMainMenu(cursors[0], installShip, maxCursors[0], false);

			if (cursors[0] == 2)
			{
				return 0;
			}
		}
		else if (mode == 1)
		{
			cout << "\n\n Выберите положение корабля" << endl;
			printMainMenu(cursors[1], direction, maxCursors[1], false);
		}
		else if (mode == 2)
		{
			cout << "\n\n Выберите тип корабля" << endl;
			printMenuShip(cursors[2], listShip, ships, maxCursors[2], false);
		}
		else if (mode == 3)
		{
			int x, y;
			cout << "\n\n Введите координаты первой палубы" << endl;

			cout << "x -> ";
			cin >> x;

			cout << "y -> ";
			cin >> y;

			bool set = set_ship(y, x, cursors[1], cursors[2] + 1);
			if (set)
				ships[cursors[2]]--;			
		}

		char key = _getch();

		if (key == 13)
		{
			mode++;
			if (mode > 3) mode = 0;
		}
		if (key == 72)
		{
			cursors[mode]--;
			if (cursors[mode] < 0) cursors[mode] = 0;
		}
		if (key == 80)
		{
			cursors[mode]++;
			if ((maxCursors[mode] - 1) < cursors[mode]) cursors[mode] = maxCursors[mode] - 1;
		}
	} while (start);
}
void Map::printMainMenu(int x, string *m, int len, bool centrScreen)
{
	if (centrScreen)
		for (int i = 0; i < SIZE; i++) cout << "\n";
	
	for (int i = 0; i < len; i++)
	{
		if (centrScreen) cout << "\n\t\t\t\t";
		else cout << "\n";

		if (i == x) cout << " > ";
		else cout << "   ";

		cout << m[i].c_str();
	}
}
void Map::printMenuShip(int x, string* m, int* n, int len, bool centrScreen)
{
	if (centrScreen)
		for (int i = 0; i < SIZE; i++) cout << "\n";

	for (int i = 0; i < len; i++)
	{
		if (centrScreen) cout << "\n\t\t\t\t";
		else cout << "\n";

		if (i == x) cout << " > ";
		else cout << "   ";

		cout << m[i].c_str();
		cout << n[i];
	}
}
void Map::drawField()
{
	string h = "  0 1 2 3 4 5 6 7 8 9";
	cout << h;

	for (int i = 0; i < SIZE; i++)
	{
		cout << endl << i << " ";

		for (int j = 0; j < SIZE; j++)
		{
			if (map[i][j] == 0) cout << "-" << " ";
			else if (map[i][j] == 1) cout << "#" << " ";
		}
	}
}

void Map::random_arrangement()
{
	set_ship(4, 1);
	set_ship(3, 2);
	set_ship(2, 3);
	set_ship(1, 4);
}

void Map::setMap(int x, int y, int z) { map[x][y] = z; }
int Map::getMap(int x, int y) { return map[x][y]; }

void Map::setShot(bool shot) { this->shot = shot; }
bool Map::getShot() { return shot; }

void Map::set_ship(int size, int num)
{
	srand(time(NULL));

	int x, y;
	int dir{}; // случайное направление
	int count_ship{};

	while (count_ship < num)
	{
		x = rand() % SIZE;
		y = rand() % SIZE;

		int temp_x = x;
		int temp_y = y;
		bool flag_set = 1;

		dir = rand() % 4; // генерация направления

		for (int i = 0; i < size; i++)
		{
			if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
			{
				flag_set = 0;
				break;
			}

			if (map[x][y] == 1 ||
				map[x][y + 1] == 1 ||
				map[x][y - 1] == 1 ||
				map[x + 1][y] == 1 ||
				map[x + 1][y + 1] == 1 ||
				map[x + 1][y - 1] == 1 ||
				map[x - 1][y] == 1 ||
				map[x - 1][y + 1] == 1 ||
				map[x - 1][y - 1] == 1)
			{
				flag_set = 0;
				break;
			}

			if (dir == 0)
				x++;
			else if (dir == 1)
				y++;
			else if (dir == 2)
				x--;
			else if (dir == 3)
				y--;
		}

		if (flag_set)
		{
			x = temp_x;
			y = temp_y;

			for (int i = 0; i < size; i++)
			{
				map[x][y] = 1;


				if (dir == 0)
					x++;
				else if (dir == 1)
					y++;
				else if (dir == 2)
					x--;
				else if (dir == 3)
					y--;
			}
			count_ship++;
		}
	}
}
bool Map::set_ship(int x, int y, int dir, int size)
{
	srand(time(NULL));

	int choice{};
	if (dir == 0)
	{
		cout << "Куда вы хотите поставить корабль, вверх или вниз?" << endl
			<< "Вверх - 0; Вниз - 1" << endl;

		cin >> choice;

		if (choice == 0) dir = 2;
		else if (choice == 1) dir = 0;
	}
	else
	{
		cout << "Куда вы хотите поставить корабль, влево или вправо?" << endl
			<< "Влево - 0; Вправо - 1" << endl;

		cin >> choice;

		if (choice == 0) dir = 3;
		else if (choice == 1) dir = 1;
	}

	int count_ship{};

	while (count_ship < 1)
	{
		int temp_x = x;
		int temp_y = y;
		bool flag_set = 1;

		for (int i = 0; i < size; i++)
		{
			if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
			{
				cout << "Корабль не может быть установлен!" << endl;
				return 0;
			}

			if (map[x][y] == 1 ||
				map[x][y + 1] == 1 ||
				map[x][y - 1] == 1 ||
				map[x + 1][y] == 1 ||
				map[x + 1][y + 1] == 1 ||
				map[x + 1][y - 1] == 1 ||
				map[x - 1][y] == 1 ||
				map[x - 1][y + 1] == 1 ||
				map[x - 1][y - 1] == 1)
			{
				cout << "Корабль не может быть установлен!" << endl;
				return 0;
			}

			if (dir == 0)
				x++;
			else if (dir == 1)
				y++;
			else if (dir == 2)
				x--;
			else if (dir == 3)
				y--;
		}

		if (flag_set)
		{
			x = temp_x;
			y = temp_y;

			for (int i = 0; i < size; i++)
			{
				map[x][y] = 1;

				if (dir == 0)
					x++;
				else if (dir == 1)
					y++;
				else if (dir == 2)
					x--;
				else if (dir == 3)
					y--;
			}
			count_ship++;
		}
	}
	return 1;
}
