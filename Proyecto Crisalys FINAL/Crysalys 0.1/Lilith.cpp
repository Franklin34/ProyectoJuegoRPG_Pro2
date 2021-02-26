#include "Lilith.h"

Lilith::Lilith()
{

}

Lilith::Lilith(std::string n)
{
    setName(n);
    setMaxHealthPoints(300);
    setHealthPoints(300);
    setStrenght(25);
    setDefense(25);
    setDexterity(25);
    setAccuracy(30);
    passive = "Vuelta de Edom";
}

std::string Lilith::getPassiveAbilityName()
{
	return passive;
}
