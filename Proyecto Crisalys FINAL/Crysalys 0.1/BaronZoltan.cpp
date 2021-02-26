#include "BaronZoltan.h"

BaronZoltan::BaronZoltan()
{
	passive = "king's Honor ";
	chances = 0;
}

BaronZoltan::~BaronZoltan()
{
}

BaronZoltan::BaronZoltan(std::string n)
{
	setName(n);
	setMaxHealthPoints(800);
	setHealthPoints(800);
	setStrenght(27);
	setDefense(35);
	setDexterity(27);
	setAccuracy(50);
	passive = "king's Honor ";
}

std::string BaronZoltan::getPassiveAbilityName()
{
	return passive;
}

std::string BaronZoltan::KingsHonor()
{
	int i = 0;
	int j = 0;
	std::random_device rd{};
	std::mt19937 engine{ rd() };
	std::uniform_int_distribution<int>d(0, 100);
	chances = d(engine);

	if (chances <= 40) {
		chances = 1;
	}
	else if (chances > 40 && chances <= 75) {
		chances = 2;
	}
	else {
		chances = 3;
	}

	switch (chances)
	{
	case 1:
		if (getHealtPoints() + 35 > getMaxHealtPoints()) {
			setHealthPoints(getMaxHealtPoints());
		}
		else {
			setHealthPoints(getHealtPoints() + 35);
		}
		setStrenght(getStrenght() + 3);
		setDefense(getDefense() + 5);
		setDexterity(getDexterity() + 3);
		setAccuracy(getAccuracy() + 3);
		return "Bow Before Me";
		break;
	case 2:
		if (getHealtPoints() + 70 > getMaxHealtPoints()) {
			setHealthPoints(getMaxHealtPoints());
		}
		else {
			setHealthPoints(getHealtPoints() + 70);
		}
		setMaxHealthPoints(getMaxHealtPoints() + 35);
		return "Amaranthine";
		break;
	case 3:
		if (getHealtPoints() + 30 > getMaxHealtPoints()) {
			setHealthPoints(getMaxHealtPoints());
		}
		else {
			setHealthPoints(getHealtPoints() + 30);
		}
		setStrenght(getStrenght() + 1);
		setDefense(getDefense() + 1);
		setDexterity(getDexterity() + 1);
		setAccuracy(getAccuracy() + 1);
		return "Weaklings shall die";
		break;
	}

	return "FUCK";

}
