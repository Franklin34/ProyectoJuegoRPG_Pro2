#ifndef IRONGOLEM_H
#define IRONGOLEM_H
#include "Enemy.h"
#include <random>

class IronGolem : public Enemy
{
public:
	IronGolem();
	~IronGolem();
	IronGolem(std::string);
	std::string getPassive();
	std::string golemsHeart();
private:
	std::string passive;
	int chances;
};

#endif