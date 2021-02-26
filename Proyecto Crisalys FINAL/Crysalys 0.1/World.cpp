#include "World.h"

World::World()
{
	pos = 0; 
	max_c = 0;
	room = 0;
	dagger = false;
	spear = false;
}

World::World(Map* a)
{
	room = 0;
	pos = 0;
	max_c = 0;
	vec.push_back(a);
	pos++;
	dagger = false;
	spear = false;
}

void World::reset()
{
	pos = 0;
	max_c = 0;
	room = 0;
	dagger = false;
	spear = false;
	for (int i = 0; i < vec.size(); i++) {
		delete vec[i];
	}
	vec.clear();
}

void World::setEnemyStatus(bool a)
{
	vec[unsigned __int64(pos) - 1]->setEnemyStatus(a);
}

void World::setJefeEstatus(bool a)
{
	vec[unsigned __int64(pos) - 1]->setJefeStatus(a);
}

void World::moveToWorld(int a, int b)
{
	
	if (a == 0 && b == 0) {
		pos = pos - 1;
	}
	else {
		if (pos >= vec.size()) {
			newWorld();
		}
		else
		{
			pos = pos + 1;
		}
	}

}

void World::newWorld()
{
	Map *a = new Map;
	if (pos != 0) {
		spear = true;
		dagger = true;
	}
	a->setWorldNum(pos++);
	a->setMap(spear, dagger);
	vec.push_back(a);
	max_c++;
}

int World::currentPos()
{
	return pos;
}

void World::setPos(int a, int b)
{
	vec[unsigned __int64(pos) - 1]->setPosition(a,b);
}

int World::maxPos()
{
	return max_c;
}

int World::getRoomNum()
{
	return 0;
}

std::tuple<int, int, int, int, int, int, int, int,int> World::search(int a, int  b)
{
	return vec[unsigned __int64(pos) - 1]->search(a, b);
}

void World::setCoordenadas(int cord1, int cord2)
{
	vec[unsigned __int64(pos) - 1]->setCoordenadas(cord1, cord2);
}

std::tuple<int, int> World::getCoordenadas()
{
	return vec[unsigned __int64(pos) - 1]->Coordenadas();
}

std::string World::getEnemy(int a, int b)
{
	return vec[unsigned __int64(pos) - 1]->getEnemy(a,b);
}

Item* World::getChestItem(int a, int b)
{
	return vec[unsigned __int64(pos) - 1]->getChestItem(a, b);
}

Enemy* World::getEnemigo()
{
	return vec[unsigned __int64(pos) -1]->getEnemy();
}

void World::setChestStatus(bool a)
{
	vec[unsigned __int64(pos)-1]->setChestStatus(a);
}

void World::setWeaponStatus(bool a, bool b)
{
	spear = a;
	dagger = b;
}

void World::setKey(bool key, int a, int b)
{
	vec[unsigned __int64(pos) - 1]->setKey(key, a, b);
}

bool World::getKey(int a, int b)
{
	return vec[unsigned __int64(pos) - 1]->getKey(a,b);
}
