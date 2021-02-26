#ifndef BARONZOLTAN_H
#define BARONZOLTAN_H
#include "Enemy.h"
#include <random>

class BaronZoltan : public Enemy
{
public:
	BaronZoltan();
	~BaronZoltan();
	BaronZoltan(std::string);
	std::string getPassiveAbilityName();
	std::string KingsHonor();
private:
	std::string passive;
	int chances;
};

#endif

