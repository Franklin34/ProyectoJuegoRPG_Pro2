#include "Vampyre.h"

Vampyre::Vampyre()
{
	bloodlust = 0;
	passive = "Blood Lust";
}

Vampyre::Vampyre(std::string n)
{
	setName(n);
	setMaxHealthPoints(40);
	setHealthPoints(40);
	setStrenght(12);
	setDefense(8);
	setDexterity(16);
	setAccuracy(25);
	passive = "Blood Lust";
}


void Vampyre::setBloodLust(float bloodlust)
{
	if (getHealtPoints()+bloodlust > getMaxHealtPoints()) {
		setHealthPoints(getMaxHealtPoints());
	}
	setHealthPoints(getHealtPoints()+bloodlust);
}

std::string Vampyre::getPassiveAbilityName()
{
	return passive;
}






