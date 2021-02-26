#include "Option.h"

Option::Option() : a{ opc }, b{ end }
{
    player = nullptr;
    world = nullptr;
    opc = 0;
    end = 0;
    salira = false;
}

Option::Option(int& uno, int& dos, Player* player1, World* world1) : a{ uno }, b{ dos }, player{ player1 }, world{ world1 }
{
    opc = 0;
    end = 0;
    salira = false;
}

std::string Option::menuOption()
{
    std::vector<std::string> g1;
    std::string str = "";
    int count1 = 1;

    do
    {

        if (player->getHealthPoints() <= 0) {
            goto jump3;
        }

        system("cls");
        bool enemy1, chest1, up1, down1, right1, left1, key1, exit1, jefe1;
        enemy1 = 0;
        chest1 = 0;
        up1 = 0;
        down1 = 0;
        right1 = 0;
        left1 = 0;
        key1 = 0;
        exit1 = 0;
        jefe1 = 0;
        std::cout << std::endl;
        system("cls");
        std::cout << "===========================================================================================" << std::endl;
        std::cout << "========================== Bienvenidos a Aventura en el Castillo ==========================" << std::endl;
        std::cout << "===========================================================================================" << std::endl << std::endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        gotoxy(43, 4);
        std::cout << "******************************************" << std::endl;
        gotoxy(43, 5);
        std::cout << "**** Inventario: ";
        for (int i = 0; i < player->tamanovec(); i++) {
            std::cout << player->retotnarVec(i) << ", ";
        }
        gotoxy(43, 6);
        std::cout << "******************************************" << std::endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        gotoxy(0, 4);
        player->AsigNivel();
        std::cout << "Jugador: " << player->getName() << "  HP: " << player->getHealthPoints() << " LvL: " << player->getNivel() << " Exp: " << player->getExp() << '\n';
        roomName();
        std::tie(a, b) = player->getCoordenadas();
        std::cout << "Se encuentra en el cuarto: " << a << ',' << b << '\n' << '\n';
        std::tie(enemy1, chest1, up1, down1, right1, left1, key1, exit1, jefe1) = world->search(a, b);
        int num;
        if (up1 == true) {
            std::cout << count1++ << ") Arriba" << '\n';
            g1.push_back("up");
        }
        if (down1 == true) {
            std::cout << count1++ << ") Abajo" << '\n';
            g1.push_back("down");
        }
        if (right1 == true) {
            std::cout << count1++ << ") Derecha" << '\n';
            g1.push_back("right");
        }
        if (left1 == true) {
            std::cout << count1++ << ") Izquierda" << '\n';
            g1.push_back("left");
        }
        if (enemy1 == true || jefe1 == true) {
            std::cout << count1++ << ") Atacar enemigo" << " (" << world->getEnemy(a, b) << ")" << '\n';
            g1.push_back("enemigo");
        }
        if (chest1 == true) {
            std::cout << count1++ << ") Abrir cofre" << '\n';
            g1.push_back("cofre");
        } 
        if (exit1 == true) {
         
            if (a == 0 && b == 0) {
                std::cout << count1++ << ") Bajar de piso" << '\n';
                g1.push_back("moveF");
            }
            else {
                if (jefe1 == true) {
                    std::cout << "*Para acceder al siguiente piso debes matar al jefe primero" << '\n';
                }
                else {
                    std::cout << count1++ << ") Subir de piso" << '\n';
                    g1.push_back("moveF");
                }
                
            }
        }
        std::cout << count1++ << ") Aumentar de Nivel" << '\n';
        g1.push_back("level");
        std::cout << count1++ << ") Salir" << '\n';
        g1.push_back("salir");

        std::cout << std::endl;
        jump5:
        std::cout << "Eliga la opcion deseada: ";
        std::cin >> num;
        if (std::cin.fail()) {
            fail();
            goto jump5;
        }
        if (num > g1.size()) {
            std::cout << "Error, opcion no valida" << '\n';
            goto jump5;
        }
        num = num - 1;
        str = g1[num];
    jump3:
        return str;
    } while (end != 99);

    return std::string();
}

void Option::fail()
{
    std::cin.clear();
    std::cin.ignore(256, '\n');
}

void Option::setCoordenadaA(int b)
{
    a = b;
}

int Option::getCoordenadaA()
{
    return a;
}

int Option::getCoordenadaB()
{
    return b;
}

void Option::roomName()
{
    if (world->currentPos() == 1) {
        std::cout << "Alcantarillas Antiguas" << '\n';
    }
    else if (world->currentPos() == 2) {
        std::cout << "Celdas Subterraneas" << '\n';
    }
    else if (world->currentPos() == 3) {
        std::cout << "Piso de Experimentos" << '\n';
    }
    else if (world->currentPos() == 4) {
        std::cout << "Celdas de la Tortura" << '\n';
    }
    else if (world->currentPos() == 5) {
        std::cout << "Sala del Tesoro" << '\n';
    }
    else if (world->currentPos() == 6) {
        std::cout << "Biblioteca" << '\n';
    }
    else if (world->currentPos() == 7) {
        std::cout << "Jardin Central" << '\n';
    }
    else if (world->currentPos() == 8) {
        std::cout << "Pabellon de la Mentira" << '\n';
    }
    else if (world->currentPos() == 9) {
        std::cout << "Puerta del Halcon" << '\n';
    }
    else if (world->currentPos() == 10) {
        std::cout << "Trono del Rey" << '\n';
    }
}

Player* Option::getPlayer()
{
    return player;
}

World* Option::getWorld()
{
    return world;
}



