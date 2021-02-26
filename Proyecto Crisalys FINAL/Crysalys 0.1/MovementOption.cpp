#include "MovementOption.h"

MovementOption::MovementOption(int& a, int& b, Player* player, World* world) : Option(a,b,player,world)
{
	
}

void MovementOption::Options(std::string move)
{
	bool a = 0;
	
	if (move == "up") {
		bool a = getWorld()->getKey(getCoordenadaA() - 1, getCoordenadaB());

		if (a == true) {
			if (getPlayer()->tamanovec() == 0) {
				std::cout << "La puerta esta cerrada con llave" << '\n';
				system("pause");
				move = "";
			}
			for (int i = 0; i < getPlayer()->tamanovec(); i++) {
				if (getPlayer()->retotnarVec(i) == "Key") {
					getPlayer()->deleteVector(i);
					getWorld()->setKey(false, getCoordenadaA()-1, getCoordenadaB());
					std::cout << "Puerta Abierta" << '\n';
					system("pause");
					move = "";
				}
			}
		}
	}
	else if (move == "down") {
		bool a = getWorld()->getKey(getCoordenadaA() + 1, getCoordenadaB());
		////////
		if (a == true) {
			if (getPlayer()->tamanovec() == 0) {
				std::cout << "La puerta esta cerrada con llave" << '\n';
				system("pause");
				move = "";
			}
			for (int i = 0; i < getPlayer()->tamanovec(); i++) {
				if (getPlayer()->retotnarVec(i) == "Key") {
					getPlayer()->deleteVector(i);
					getWorld()->setKey(false, getCoordenadaA()+1, getCoordenadaB());
					std::cout << "Puerta Abierta" << '\n';
					system("pause");
					move = "";
				}
			}
		}
	}
	else if (move == "right") {
		bool a = getWorld()->getKey(getCoordenadaA(), getCoordenadaB() +1);
		////////
		if (a == true) {
			if (getPlayer()->tamanovec() == 0) {
				std::cout << "La puerta esta cerrada con llave" << '\n';
				system("pause");
				move = "";
			}
			for (int i = 0; i < getPlayer()->tamanovec(); i++) {
				if (getPlayer()->retotnarVec(i) == "Key") {
					getPlayer()->deleteVector(i);
					getWorld()->setKey(false, getCoordenadaA(), getCoordenadaB()+1);
					std::cout << "Puerta Abierta" << '\n';
					system("pause");
					move = "";
				}
			}
		}
	}
	else if (move == "left") {
		bool a = getWorld()->getKey(getCoordenadaA(), getCoordenadaB() - 1);
		////////
		if (a == true) {
			if (getPlayer()->tamanovec() == 0) {
				std::cout << "La puerta esta cerrada con llave" << '\n';
				system("pause");
				move = "";
			}
			for (int i = 0; i < getPlayer()->tamanovec(); i++) {
				if (getPlayer()->retotnarVec(i) == "Key") {
					getPlayer()->deleteVector(i);
					getWorld()->setKey(false, getCoordenadaA(), getCoordenadaB() - 1);
					std::cout << "Puerta Abierta" << '\n';
					system("pause");
					move = "";
				}
			}
		}
	}

	if (move == "up") {
		getWorld()->setCoordenadas(getCoordenadaA()-1, getCoordenadaB());
		getPlayer()->setCoordenadas(getCoordenadaA()-1, getCoordenadaB());
	}
	else if (move == "down"){
		getWorld()->setCoordenadas(getCoordenadaA() + 1, getCoordenadaB());
		getPlayer()->setCoordenadas(getCoordenadaA() + 1, getCoordenadaB());
	}
	else if (move == "right"){
		getWorld()->setCoordenadas(getCoordenadaA(), getCoordenadaB()+1);
		getPlayer()->setCoordenadas(getCoordenadaA(), getCoordenadaB()+1);
	}
	else if (move == "left"){
		getWorld()->setCoordenadas(getCoordenadaA(), getCoordenadaB()-1);
		getPlayer()->setCoordenadas(getCoordenadaA(), getCoordenadaB()-1);
	}
	
}

