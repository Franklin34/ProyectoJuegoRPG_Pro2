#ifndef VAMPYRE_H
#define VAMPYRE_H
#include "Enemy.h"

class Vampyre : public Enemy
{
public:
	Vampyre();
	~Vampyre() {}
	Vampyre(std::string);
	void setBloodLust(float);
	std::string getPassiveAbilityName();
private:
	float bloodlust;
	std::string passive;
};

#endif
