#ifndef MAP_H
#define MAP_H
#include <vector>
#include "Room.h"
#include <random>
#include <iostream>
#include <random>

class Map
{
public:
	Map();
	Map(int&, int&);
	~Map() {}
	void setEnemyStatus(bool);
	void setJefeStatus(bool);
	void setPosition(int,int);
	void setMap(bool,bool);
	void Reset(int&, int&);
	std::tuple<int, int, int, int, int, int, int, int,int> search(const int, const int);
	void setCoordenadas(int, int);
	std::tuple<int, int>Coordenadas();
	void random();
	void randomWalls(int, int);
	void enemiesAndChests(bool, bool);
	std::string getEnemy(int, int);
	Item* getChestItem(int, int);
	void setWorldNum(int);
	int getWorldNum();
	Enemy* getEnemy();
	void setChestStatus(bool);
	void setItemStatus2(bool,bool,int,int);
	void setKey(bool, int, int);
	bool getKey(int, int);
	std::tuple <bool, bool> getExitDoor(int, int);
private:
	std::vector<std::vector<Room>> data;
	int r;
	int c;
	int worldNum;
	int room;
	int pos1;
	int pos2;
	bool settings;
	bool spear, dagger;
};

#endif