#include "Ludwig.h"

Ludwig::Ludwig()
{
}

Ludwig::Ludwig(std::string n)
{
    setName(n);
    setMaxHealthPoints(200);
    setHealthPoints(200);
    setStrenght(20);
    setDefense(20);
    setDexterity(20);
    setAccuracy(25);
    passive = "Marca de Alma";
}

std::string Ludwig::getPassiveAbilityName()
{
    return passive;
}
