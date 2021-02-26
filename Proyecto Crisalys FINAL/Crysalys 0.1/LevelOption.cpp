#include "LevelOption.h"

LevelOption::LevelOption()
{
	templevel = 0;
}

LevelOption::LevelOption(int& a, int& b, Player* player, World* world) : Option(a,b,player,world)
{
	templevel = 0;
}

LevelOption::~LevelOption() 
{
}

void LevelOption::Options(std::string)
{
	int opc;
	opc = 0;
	getPlayer()->getNivel();

	while(opc != 100) {
		system("cls");
		std::cout << "===========================================================================================" << std::endl;
		std::cout << "========================== Bienvenidos a Aventura en el Castillo ==========================" << std::endl;
		std::cout << "===========================================================================================" << std::endl << std::endl;
		std::cout << "------------Stats-----------" << '\n';
		std::cout << "1) Vida Maxima: " << getPlayer()->getMaxHealtPoints() << '\n';
		std::cout << "2) Fuerza: " << getPlayer()->getStrenght() << '\n';
		std::cout << "3) Defensa: " << getPlayer()->getDefense() << '\n';
		std::cout << "4) Destreza: " << getPlayer()->getDexterity() << '\n';
		std::cout << "5) Punteria: " << getPlayer()->getAccuracy() << '\n';
		std::cout << " Dpt: " << getPlayer()->getSkill() << '\n';
		std::cout << "6) Salir " << getPlayer()->getAccuracy() << '\n';
		std::cout << "==================================================" << '\n';
		std::cout << "Seleccione la estadistica que desea aumentar: " << '\n';
	jump1:
		if (getPlayer()->getNivel() > templevel) {
		std::cin >> opc;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << " Error: Dato no valido" << '\n';
			goto jump1;
		}

			switch (opc)
			{
			case 1:
				getPlayer()->setMaxHealthPoints(getPlayer()->getMaxHealtPoints()+25);
				getPlayer()->setHealthPoints(getPlayer()->getMaxHealtPoints());
				std::cout << "La vida maxima ha aumentado" << '\n';
				templevel++;
				break;
			case 2:
				getPlayer()->setStrenght(getPlayer()->getStrenght()+2);
				std::cout << "La Fuerza ha aumentado" << '\n';
				templevel++;
				break;
			case 3:
				getPlayer()->setDefense(getPlayer()->getDefense()+4);
				std::cout << "La Defensa ha aumentado" << '\n';
				templevel++;
				break;
			case 4:
				getPlayer()->setDexterity(getPlayer()->getDexterity() + 2);
				std::cout << "La Destreza ha aumentado" << '\n';
				templevel++;
				break;
			case 5:
				getPlayer()->setAccuracy(getPlayer()->getAccuracy()+5);
				std::cout << "La Punteria ha aumentado" << '\n';
				templevel++;
				break;
			case 6:
				opc = 100;
				break;
			default:
				std::cout << "Opcion no valida" << '\n';
				break;
			}
		}
		else {
			opc = 100;
			std::cout << "No puedes aumentar de nivel" << '\n';
		}
		system("pause");
	}
}
