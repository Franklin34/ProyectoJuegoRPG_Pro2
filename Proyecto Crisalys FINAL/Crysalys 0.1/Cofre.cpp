#include "Cofre.h"

Cofre::Cofre()
{
	dagger = false;
	spear = false;
	item = nullptr;
	num = 0;
}

Cofre::~Cofre()
{
	//delete item;
}

void::Cofre::Cofre2()
{
	item = nullptr;
	jump:
	int x = getRand();

	if (x == 0) {
		if (dagger == true) {
			goto jump;
		}
		item = new Daga("Daga");
		dagger = true;
	}
	else if (x == 1) {
		if (spear == true) {
			goto jump;
		}
		item = new Lanza("Lanza");
		spear = true;
	}else if (x == 2) {
		item = new Pocion("Pocion");
	}else if (x == 3) {
		item = new Key("Key");
	}
	else if (x == 4) {
		item = new Oro("Oro");
	}
	else if (x == 5) {
		item = new Diamante("Diamante");
	}

}

int Cofre::getRand()
{
	if (num >= 7) {
		dagger = true;
		spear = true;
	}

	int chances = 0;
	if (dagger == false || spear == false) {
		std::random_device rd{};
		std::mt19937 engine{ rd() };
		std::uniform_int_distribution<int>d(0, 1);
		chances = d(engine);
		return chances;
	}
	
	std::random_device rd{};
	std::mt19937 engine{ rd() };
	std::uniform_int_distribution<int>d(0, 100);
	chances = d(engine);

	if (chances <= 50) {
		if (dagger == false) {
			return 0;
		}
		else if (spear == false) {
			return 1;
		}
		else {
			return 4; //////////// item mas comun
		}
	}
	else if (chances >= 50 && chances < 55) {
		return 5;
	}
	else if (chances >= 55 && chances <= 93) {
		return 2;
	}
	else if (chances > 93) {
		return 3;
	}

	return 2;
}

void Cofre::getInt(int a)
{
	num = a;
}

std::tuple<bool, bool> Cofre::setItemStatus(bool a, bool b)
{
	dagger = b;
	spear = a;
	Cofre2();
	return std::make_tuple<>(spear,dagger);
}
