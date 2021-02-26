#include "Map.h"

Map::Map()
{
	data;
	r = 0;
	c = 0;
	room = 0;
	spear = false;
	dagger = false;
	pos1 = 0;
	pos2 = 0;
	worldNum = 0;
	settings = false;
}

Map::Map(int& rows,int& cols)
{
	Reset(rows, cols);
	r = rows;
	c = cols;
}

void Map::setEnemyStatus(bool a)
{
	data.at(pos1).at(pos2).setEnemy(a);
}

void Map::setJefeStatus(bool a)
{
	data.at(pos1).at(pos2).setJefe(a);
}

void Map::setPosition(int a, int b)
{
	pos1 = a;
	pos2 = b;
}

void Map::setMap(bool a, bool b)
{
	random();
	Reset(r, c);
	randomWalls(r,c);
	enemiesAndChests(a,b);
}

void Map::Reset(int& rows, int& cols)
{
	if (rows == 0 || cols == 0) {
		data.assign(0, std::vector<Room>(0));
	}
	else {
		data.assign(rows, std::vector<Room>(cols));
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			data.at(i).at(j).setNum(room++);
		}
	}
	

}

std::tuple<int, int, int, int, int, int, int, int,int> Map::search(const int row1, const int col1)

{
	return data.at(row1).at(col1).data1();
}

void Map::setCoordenadas(int a, int b)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (data.at(i).at(j).getCurrentPos() == true) {
				data.at(i).at(j).setCurrentPos(false);
			}
		}
	}

	data.at(a).at(b).setCurrentPos(true);

}

std::tuple<int, int> Map::Coordenadas()
{

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (data.at(i).at(j).getCurrentPos() == true) {
				return std::make_tuple<>(i,j);
			}
		}
	}
	return std::make_tuple<>(0,0);
}

void Map::random()
{

	int a, b;
	a = 1;
	b = 1;
	std::random_device rd{};
	std::mt19937 engine{ rd() };
    std::uniform_int_distribution<int>d(1, 4);
	a = d(engine);

	/*if (settings == true) {
		std::cout << "Ajustes del tamanno del mapa: " << '\n';
		std::cout << "1: Mapas de 6 cuartos " << '\n';
		std::cout << "2: Mapas de 9 cuartos (Recomendado) " << '\n';
		std::cin >> ;
	}*/

	switch (a)
	{
	case 1:
		a = 2;
		b = 3;
		break;
	case 2:
		a = 3;
		b = 2;
		break;
	case 3:
		a = 1;
		b = 6;
		break;
	case 4:
		a = 6;
		b = 1;
		break;
	}
	r = 3;
	c = 3;
	
}

void Map::randomWalls(int fil, int col)
{
	bool up, down, right, left;
	bool up1, down1, right1, left1;
	int randNum;
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col;j++) {
			if (i == 0 && j == 0) {
				data.at(i).at(j).setCurrentPos(true);
			}
			up1 = true;
			down1 = true;
			right1 = true;
			left1 = true;

			std::tie(up, down, right, left) = data.at(i).at(j).check();
			if (up == false && down == false && right == false && left == false) {

				if (i-1 < 0) {
					up1 = false;
				}
				if (i+1 == fil) {
					down1 = false;
				}

				if (j-1 < 0) {
					left1 = false;
				}
				if (j+1 == col) {
					right1 = false;
				}

				std::vector<std::string> g1;

				if (up1 == true) {
					g1.push_back("up");
				}
				if (down1 == true) {
					g1.push_back("down");
				}
				if (right1 == true) {
					g1.push_back("right");
				}
				if (left1 == true) {
					g1.push_back("left");
				}

				std::random_device rd{};
				std::mt19937 engine{ rd() };
				std::uniform_int_distribution<int>d(0, unsigned(g1.size()-1));
				randNum = d(engine);
				std::string str = g1[randNum];

				if (str == "up") {
					data.at(i).at(j).setUp(true);
					int xt = i - 1;
					data.at(xt).at(j).setDown(true);
				}
				else if (str == "down") {
					data.at(i).at(j).setDown(true);
					int yt = i + 1;
					data.at(yt).at(j).setUp(true);
				}
				else if (str == "right") {
					data.at(i).at(j).setRight(true);
					int zt = j + 1;
					data.at(i).at(zt).setLeft(true);
				}
				else if (str == "left") {
					data.at(i).at(j).setLeft(true);
					int uy = j - 1;
					data.at(i).at(uy).setRight(true);
				}
			}
			//////////////////////////////////////////////////////////////////////
			else {

				if (up == true) {
					up1 = false;
				}
				if (down == true) {
					down1 = false;
				}
				if (right == true) {
					right1 = false;
				}
				if (left == true) {
					left1 = false;
				}

				if (i - 1 < 0) {
					up1 = false;
				}
				if (i + 1 == fil) {
					down1 = false;
				}

				if (j - 1 < 0) {
					left1 = false;
				}
				if (j + 1 == col) {
					right1 = false;
				}

				std::vector<std::string> g2;

				if (up1 == false && down1 == false && right1 == false && left1 == false) {
					break;
				}
				if (up1 == true) {
					g2.push_back("up");
				}
				if (down1 == true) {
					g2.push_back("down");
				}
				if (right1 == true) {
					g2.push_back("right");
				}
				if (left1 == true) {
					g2.push_back("left");
				}

				std::random_device rd{};
				std::mt19937 engine{ rd() };
				std::uniform_int_distribution<int>d(0, unsigned(g2.size() - 1));
				randNum = d(engine);
				std::string str = g2[randNum];

				if (str == "up") {
					data.at(i).at(j).setUp(true);
					int xt = i - 1;
					data.at(xt).at(j).setDown(true);
				}
				else if (str == "down") {
					data.at(i).at(j).setDown(true);
					int gh = i + 1;
					data.at(gh).at(j).setUp(true);
				}
				else if (str == "right") {
					data.at(i).at(j).setRight(true);
					int op = j + 1;
					data.at(i).at(op).setLeft(true);
				}
				else if (str == "left") {
					data.at(i).at(j).setLeft(true);
					int rt = j - 1;
					data.at(i).at(rt).setRight(true);
				}

			}

		}
	}
	worldNum;
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			if (i != 0 && j != 0 && data.at(i).at(j).checkRoom() == 1 && i != (fil-1) && j != (col-1)) {
				
				data.at(i).at(j).setKey(true);

			}
			else {
				
				data.at(unsigned __int64(fil) - 1).at(unsigned __int64(col) - 1).setExit(true);
				if (worldNum >= 1) {
					data.at(0).at(0).setExit(true);
				}

			}
		}
	}

}

void Map::enemiesAndChests(bool a, bool b)
{
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			std::random_device rd{};
			std::mt19937 engine{ rd() };
			std::uniform_int_distribution<int>d(0, 100);
			int chances = d(engine);
			if (chances < 65) {
				data.at(i).at(j).setEnemy(true);
				data.at(i).at(j).setTypeOfEnemy();
			}
		}
	}
	/////////////////////////////////////////////
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			std::random_device rd{};
			std::mt19937 engine{ rd() };
			std::uniform_int_distribution<int>d(0, 100);
			int chances = d(engine);
			if (chances < 80) {
				data.at(i).at(j).setChest(true);

				setItemStatus2(a, b, i, j);

			}
		}
	}

	if (worldNum == 1 || worldNum == 3 || worldNum == 5 || worldNum == 7 || worldNum == 9) {
		int d = r - 1;
		int gh = c - 1;
		data[d][gh].setJefe(true);
		data[d][gh].setTipoJefe(worldNum);
	}

	
}

std::string Map::getEnemy(int a, int b)
{
	return data.at(a).at(b).getTypeOfEnemy();
}

Item* Map::getChestItem(int a, int b)
{
	return data.at(a).at(b).getChestItem();
}

void Map::setWorldNum(int a)
{
	worldNum = a;
}

int Map::getWorldNum()
{
	return worldNum;
}

Enemy* Map::getEnemy()
{
	return data.at(pos1).at(pos2).getEnemigo();
}

void Map::setChestStatus(bool a) 
{
	data.at(pos1).at(pos2).setChest(a);
}

void Map::setItemStatus2(bool a, bool b, int x, int y)
{
	if (a == true && b == true) {
		data.at(x).at(y).setItemStatus(true, true);
	}
	else if(a == false && spear == false && dagger == false)
	{
		std::tie<>(spear, dagger) = data.at(x).at(y).setItemStatus(spear, dagger);
	}
	else if (spear == true || dagger == true) {
		std::tie<>(spear, dagger) = data.at(x).at(y).setItemStatus(spear, dagger);
	}
	
}

void Map::setKey(bool key, int a, int b)
{
	return data.at(a).at(b).setKey(key);
}

bool Map::getKey(int a, int b)
{
	return data.at(a).at(b).getKey();
}

std::tuple <bool, bool> Map::getExitDoor(int a, int b)
{
	bool primerb, segundob;
	if (a == 0 && b == 0) {
		primerb = true;
		segundob = data.at(a).at(b).getExit();
	}
	else if (a == r && b == c) {
		primerb = false;
		segundob = data.at(a).at(b).getExit();
	}
	return std::make_tuple<>(primerb,segundob);
}
