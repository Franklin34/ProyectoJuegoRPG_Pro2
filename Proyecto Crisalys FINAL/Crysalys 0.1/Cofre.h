#ifndef COFRE_H
#define COFRE_H
#include <tuple>
#include <iostream>
#include "Daga.h"
#include "Lanza.h"
#include "Pocion.h"
#include "Key.h"
#include "Oro.h"
#include "Diamante.h"
#include <random>


class Cofre
{
private:
	Item* item;
	bool dagger;
	bool spear;
	int num;
public:
	Cofre();
	~Cofre();
	void Cofre2();
	int getRand();
	void getInt(int);
    Item* getTipodeitem() { return item; }
	std::tuple <bool,bool> setItemStatus(bool, bool);
};
#endif