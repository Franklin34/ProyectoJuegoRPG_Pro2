#ifndef ROOM_H
#define ROOM_H
#include <tuple>
#include <iostream>
//#include <random>
//#include "Enemy.h"
#include "Vampyre.h"
#include "Cofre.h"
#include "Ghoul.h"
#include "Lilith.h"
#include "Ludwig.h"
#include "IronGolem.h"
#include "BaronZoltan.h"
#include "Belial.h"

class Room
{
public:
	Room();
	~Room();
	void setCurrentPos(bool);
	bool getCurrentPos();
	void setNum(int);
	int getNum();
	void setEnemy(bool);
	bool getEnemy();
	void setTypeOfEnemy();
	std::string getTypeOfEnemy();
	void setChest(bool);
	bool getChest();
	Item* getChestItem();
	void setUp(bool);
	bool getUp();
	void setDown(bool);
	bool getDown();
	void setRight(bool);
	bool getRight();
	void setLeft(bool);
	bool getLeft();
	void setKey(bool);
	bool getKey();
	void setExit(bool);
	bool getExit();
	int checkRoom();
	Enemy* getEnemigo();
	std::tuple<bool, bool, bool, bool, bool, bool, bool, bool,bool> data1();
	std::tuple<bool, bool, bool, bool> check();
	std::tuple <bool,bool> setItemStatus(bool,bool);
	void setJefe(bool);
	bool getJefe();
	void setTipoJefe(int x);
private:
	bool currentPos;
	bool enemy;
	std::string typeofenemy;
	bool chest;
	bool up;
	bool down;
	bool right;
	bool left;
	int roomNum;
	bool key;
	bool exitRoom;
	int doorscount;
	Enemy *enemigo;
	Cofre* cofre;
	bool jefe;
};

#endif