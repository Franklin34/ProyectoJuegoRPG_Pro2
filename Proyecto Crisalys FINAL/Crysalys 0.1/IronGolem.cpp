#include "IronGolem.h"

IronGolem::IronGolem()
{
	passive = "Corazon de Golem: ";
	chances = 0;
}

IronGolem::~IronGolem()
{
}

IronGolem::IronGolem(std::string n)
{
	setName(n);
	setMaxHealthPoints(650);
	setHealthPoints(650);
	setStrenght(25);
	setDefense(50);
	setDexterity(10);
	setAccuracy(45);
	passive = "Corazon de Golem: ";
}

std::string IronGolem::getPassive()
{
	return passive;
}

std::string IronGolem::golemsHeart()
{

	int i = 0;
	int j = 0;
	std::random_device rd{};
	std::mt19937 engine{ rd() };
	std::uniform_int_distribution<int>d(0, 100);
	chances = d(engine);

	if (chances <= 50) {
		chances = 1;
	}
	else if (chances > 50 && chances <= 75) {
		chances = 2;
	}
	else {
		chances = 3;
	}

	switch (chances)
	{
	case 1:
		if(getDefense() <= 50){
			setDefense(50);
		}
		if (getHealtPoints()+50 > getMaxHealtPoints()) {
			setHealthPoints(getMaxHealtPoints());
		}
		else {
			setHealthPoints(getHealtPoints() + 50);
		}
		setDefense(getDefense()+10);
		return "Nueva Defensa";
		break;
	case 2:
		if (getHealtPoints()-20 <= 0) {
			setHealthPoints(1);
		}
		setHealthPoints(getHealtPoints()-20);
		if (getDefense()-10 <= 0) {
			setDefense(1);
		}
		else {
			setDefense(getDefense() - 10);
		}

		setDexterity(getDexterity()+10);

		return "Sacrificio";
		break;
	case 3:
		setDefense(getDefense()-10);
		return "Carga de Energia";
		break;
	}

	return "FUCK";
}
