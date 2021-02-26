#include "ChestOption.h"

ChestOption::ChestOption(int& a, int& b, Player* player, World* world) : Option(a, b, player, world)
{
}

void ChestOption::Options(std::string move)
{
    int a1, b1;
    std::tie(a1, b1) = getPlayer()->getCoordenadas();
    getWorld()->setPos(a1, b1);

    if (getWorld()->getChestItem(a1, b1)->getNombre() == "Daga") {
        getPlayer()->setDagger(true);
        std::cout << std::endl;
        std::cout << "** Has obtenido una: Daga ***" << '\n';
        std::cout << std::endl;
        getPlayer()->setItem(getWorld()->getChestItem(a1, b1));
        getWorld()->setChestStatus(false);
        system("pause");
    }
    else if (getWorld()->getChestItem(a1, b1)->getNombre() == "Lanza") {
        getPlayer()->setSpear(true);
        std::cout << std::endl;
        std::cout << "** Has obtenido una: Lanza **" << '\n';
        std::cout << std::endl;
        getPlayer()->setItem(getWorld()->getChestItem(a1, b1));
        getWorld()->setChestStatus(false);
        system("pause");
    }
    else if (getWorld()->getChestItem(a1, b1)->getNombre() == "Pocion") {
        std::cout << std::endl;
        std::cout << "** Has obtenido una: Pocion **" << '\n';
        std::cout << "Recuperas: ";
        if (getPlayer()->getHealthPoints() == getPlayer()->getMaxHealtPoints()) {
            std::cout << "No recuperas tienes tu vida al MAX" << std::endl;
        }
        else if (getPlayer()->getHealthPoints() < getPlayer()->getMaxHealtPoints()) {
            getPlayer()->setHealthPoints(getPlayer()->getMaxHealtPoints());
            std::cout << "Has recuperado tu vida MAX" << std::endl;
            getWorld()->setChestStatus(false);
            Item* item = getWorld()->getChestItem(a1, b1);
            delete item;
        }
        std::cout << std::endl;
        system("pause");
    }
    else if (getWorld()->getChestItem(a1, b1)->getNombre() == "Key") {
        std::cout << std::endl;
        if (getPlayer()->verificaLlave() == true) {
            std::cout << "Ya tienes una llave" << '\n';
        }
        else {
            std::cout << "** Has obtenido una: Llave**" << '\n';
            getPlayer()->setItem(getWorld()->getChestItem(a1, b1));
            getWorld()->setChestStatus(false);
        }
        std::cout << std::endl;
        system("pause");
    }
    else if (getWorld()->getChestItem(a1, b1)->getNombre() == "Oro") {
        std::cout << std::endl;
        std::cout << "** Has obtenido: Oro **" << '\n';
        std::cout << std::endl;
        getPlayer()->setItem(getWorld()->getChestItem(a1, b1));
        getWorld()->setChestStatus(false);
        system("pause");
    }
    else if (getWorld()->getChestItem(a1, b1)->getNombre() == "Diamante") {
        getPlayer()->setDiamante(true);
        std::cout << std::endl;
        std::cout << "** Has obtenido: Diamante **" << '\n';
        std::cout << std::endl;
        getPlayer()->setItem(getWorld()->getChestItem(a1, b1));
        getWorld()->setChestStatus(false);
        system("pause");
    }
}