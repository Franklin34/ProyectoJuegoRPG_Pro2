#include "Belial.h"

Belial::Belial()
{
}

Belial::Belial(std::string n)
{
    setName(n);
    setMaxHealthPoints(500);
    setHealthPoints(500);
    setStrenght(25);
    setDefense(23);
    setDexterity(30);
    setAccuracy(50);
    passive = "Disfraz de mentiroso";

}

std::string Belial::getPassiveAbilityName()
{
	return passive;
}
