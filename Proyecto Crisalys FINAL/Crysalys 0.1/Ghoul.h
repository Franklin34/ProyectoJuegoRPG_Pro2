#ifndef GHOUL_H
#define GHOUL_H
#include "Enemy.h"

class Ghoul : public Enemy
{
public:
	Ghoul();
	~Ghoul() {}
	Ghoul(std::string n);
	std::string getPassiveAbilityName();

private:
	std::string passive;
};
#endif

