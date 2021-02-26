#include "Ghoul.h"

Ghoul::Ghoul()
{
	passive = "Double Attack";

}

Ghoul::Ghoul(std::string n)
{
	setName(n);
	setMaxHealthPoints(50);
	setHealthPoints(45);
	setStrenght(15);
	setDefense(8);
	setDexterity(11);
	setAccuracy(20);
	passive = "Double Attack";
}

std::string Ghoul::getPassiveAbilityName()
{
	return passive;
}
