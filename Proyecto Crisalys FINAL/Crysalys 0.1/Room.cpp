#include "Room.h"


Room::Room()
{
	currentPos = false;
	enemy = false;
	typeofenemy = "none";
	chest = false;
	up = false;
	down = false;
	left = false;
	right = false;
	key = false;
	exitRoom = false;
	roomNum = 0;
	doorscount = 0;
	jefe = false;
}

Room::~Room()
{

}

void Room::setCurrentPos(bool pos)
{
	this->currentPos = pos;
}

bool Room::getCurrentPos()
{
	return currentPos;
}

void Room::setNum(int roomNum)
{
	this->roomNum += roomNum;
}

int Room::getNum()
{
	return roomNum;
}

void Room::setEnemy(bool enemy)
{
	this->enemy = enemy;
}

bool Room::getEnemy()
{
	return enemy;
}

void Room::setTypeOfEnemy()
{
	if (enemy == true && typeofenemy == "none") {
		std::random_device rd{};
		std::mt19937 engine{ rd() };
		std::uniform_int_distribution<int>d(0,1);
		int type = d(engine);
		std::string passivename ="";

		switch (type)
		{
		case 0:
			enemigo = new Vampyre("Vampyre");
			typeofenemy = enemigo->getName();
			enemigo->setAbility();
			enemigo->setAbility2();
			enemigo->setPassive();
			passivename = enemigo->getPassiveAbilityName();
			enemigo->setPassiveAbilityName(passivename);
			break;
		case 1:
			enemigo = new Ghoul("Ghoul");
			typeofenemy = enemigo->getName();

			enemigo->setAbility();
			enemigo->setAbility2();
			enemigo->setPassive();
			passivename = static_cast<Ghoul*> (enemigo)->getPassiveAbilityName();
			enemigo->setPassiveAbilityName(passivename);
			break;
		}
	}


}

std::string Room::getTypeOfEnemy()
{
	return typeofenemy;
}

void Room::setChest(bool chest)
{
	this->chest = chest;
}

bool Room::getChest()
{
	return chest;
}

Item* Room::getChestItem()
{
	return cofre->getTipodeitem();
}

void Room::setUp(bool up)
{
	this->up = up;
}

bool Room::getUp()
{
	return up;
}

void Room::setDown(bool down)
{
	this->down = down;
}

bool Room::getDown()
{
	return down;
}

void Room::setRight(bool right)
{
	this->right = right;
}

bool Room::getRight()
{
	return right;
}

void Room::setLeft(bool left)
{
	this->left = left;
}

bool Room::getLeft()
{
	return left;
}

void Room::setKey(bool a)
{
	key = a;
}

bool Room::getKey()
{
	return key;
}

void Room::setExit(bool a)
{
	exitRoom = a;
}

bool Room::getExit()
{
	return exitRoom;
}

int Room::checkRoom()
{
	doorscount = 0;
	if (up == true) {
		doorscount++;
	}
	if (down == true) {
		doorscount++;
	}
	if (right == true) {
		doorscount++;
	}
	if (left == true) {
		doorscount++;
	}
	return doorscount;
}

Enemy* Room::getEnemigo()
{
	return enemigo;
}

std::tuple<bool, bool, bool, bool, bool, bool, bool, bool,bool> Room::data1()
{
	return std::make_tuple<>(enemy, chest, up, down, right, left, key, exitRoom,jefe);
}

std::tuple<bool, bool, bool, bool> Room::check()
{
	return std::make_tuple<>(up, down, right, left);
}

std::tuple<bool,bool> Room::setItemStatus(bool a, bool b)
{
	cofre = new Cofre();
	cofre->getInt(roomNum);
	return cofre->setItemStatus(a,b);
}

void Room::setJefe(bool j)
{ 
	jefe = j;
}

bool Room::getJefe()
{
	return jefe;
}

void Room::setTipoJefe(int x)
{
	if (jefe == true) {
		if (x == 1) {
			enemigo = new Ludwig("Ludwig");
			typeofenemy = enemigo->getName();
			enemigo->setAbility();
			enemigo->setAbility2();
		}
		else if (x == 3) {
			enemigo = new Lilith("Lilith");
			typeofenemy = enemigo->getName();
			enemigo->setAbility();
			enemigo->setAbility2();
			enemigo->setPassive();
		}
		else if (x == 5) {
			enemigo = new IronGolem("Iron Golem");
			typeofenemy = enemigo->getName();
			enemigo->setAbility();
			enemigo->setAbility2();

		}
		else if (x == 7) {
			enemigo = new Belial("Belial");
			typeofenemy = enemigo->getName();
			enemigo->setAbility();
			enemigo->setAbility2();
			enemigo->setPassive();
		}
		else if (x == 9) {
			enemigo = new BaronZoltan("Baron Zoltan");
			typeofenemy = enemigo->getName();
			enemigo->setAbility();
			enemigo->setAbility2();
		}

	}
}


