#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "Map.h"


class World
{
public:
	World();
	~World() {}
	World(Map*);
	void reset();
	void setEnemyStatus(bool);
	void setJefeEstatus(bool);
	void moveToWorld(int,int);
	void newWorld();
	int currentPos();
	void setPos(int, int);
	int maxPos();
	int getRoomNum();
	std::tuple<int, int, int, int, int, int, int, int,int> search(int, int);
	void setCoordenadas(int, int);
	std::tuple<int, int>getCoordenadas();
	std::string getEnemy(int, int);
	Item* getChestItem(int, int);
	Enemy* getEnemigo();
	void setChestStatus(bool);
	void setWeaponStatus(bool, bool);
	void setKey(bool, int, int);
	bool getKey(int,int);
private:
	std::vector<Map*>vec;
	int pos;
	int max_c;
	int room;
	bool dagger;
	bool spear;
};

#endif