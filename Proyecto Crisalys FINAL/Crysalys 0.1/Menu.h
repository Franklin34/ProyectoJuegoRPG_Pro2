#ifndef MENU_H
#define MENU_H
#include "Player.h"
#include "Enemy.h"
#include "Option.h"
#include"MovementOption.h"
#include "BattleOption.h"
#include "ChestOption.h"
#include "LevelOption.h"
#include "Salir.h"
#include "Info.h"
#include <Windows.h>

class Menu
{
public:
	Menu();
	~Menu();
	void dead();
	void menu();
	void gameMenu();
	void battleMenu();
	void fail();
	Enemy returnEnemy(std::string);
	void logo();
	void logo2();
	void logoCycle();
	void historia();
private:
	enum class Opcion { enemy, chest, up, down, right, left, exit, level, salir};
	Info info;
	Opcion opc;
	std::vector<Option*> options;
	std::vector<std::string> stroptions;
	int a, b, opc1, opc2, i, muertes, count2, value;
	std::string str;
	World* world;
	Player* player;
};

#endif