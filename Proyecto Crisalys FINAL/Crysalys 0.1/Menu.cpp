#include "Menu.h"

Menu::Menu()
{
    a = 0;
    b = 0;
    opc1 = 0;
    i = 0;
    value = 1;
    muertes = 0;
    count2 = 1;
    str = "";
    world = new World;
    player = new Player;
    opc = Opcion::exit;
}

Menu::~Menu()
{
    delete world;
    delete player;
}

void Menu::dead()
{
        std::cout << "                  _|_" << '\n';
        std::cout << "                   |" << '\n';
        std::cout << "               .-*****-." << '\n';
        std::cout << "            .-*         *-    " << '\n';
        std::cout << "          .-*  :::::_:::::*- _" << '\n';
        std::cout << "     ___/ ==:...:::-:::...:== |___" << '\n';
        std::cout << "    /_____________________________| " << '\n';
        std::cout << "   ':'-._________________________.-'_" << '\n';
        std::cout << "   ':::| @-,`-[-][-^-][-]-`,-@ / _| |_" << '\n';
        std::cout << "    '::| .-------------------. ||_ @ _|" << '\n';
        std::cout << "     ::|=|*   ___  _  ___   *|=|'.| |" << '\n';
        std::cout << "     ':| |'   ))_) )) ))_)  '| |::.^|" << '\n';
        std::cout << "    _ :|=|'  ((`( (( ((     '|=|::::::." << '\n';
        std::cout << "  _| |_| |'        _        '| |:::::::." << '\n';
        std::cout << " |_   _|=|'1990  _( )_  2020'|=|':::::." << '\n';
        std::cout << "   | | | |' (   (_ ~ _)   ) '| | ':::'" << '\n';
        std::cout << "   |^| |=|*  )    (_)    (  *|=| '::'" << '\n';
        std::cout << "       | '-------------------' |::::'" << '\n';
        std::cout << "       |_______________________|:::::::::'" << '\n';
        std::cout << "     .*_______________________:::::::::::::" << '\n';
        std::cout << "     |_______|  " << player->getName() <<" |___::::::::" << '\n';
        std::cout << "   .'____________________.:::::::::::::::::" << '\n';
}

void Menu::menu()
{
    logoCycle();
    stroptions.push_back(") Continuar Juego");
    stroptions.push_back(") New Game");
    stroptions.push_back(") Informacion sobre el juego");
    stroptions.push_back(") Salir");
    PlaySound(TEXT("rpg2.wav"), NULL, SND_ASYNC);
    do
    {
      
    jump:
        system("cls");
        std::cout << "===========================================================================================" << std::endl;
        std::cout << "========================== Bienvenidos a Aventura en el Castillo ==========================" << std::endl;
        std::cout << "===========================================================================================" << std::endl << std::endl;
        if (value == 1) {
            for (int i = 1; i < 4; i++ ) {
                std::cout << count2++ << stroptions[i];
                std::cout << '\n';
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                std::cout << count2++ << stroptions[i];
                std::cout << '\n';
            }
        }
        count2 = 1;
        std::cout << "Digite la opcion deseada: ";
        std::cin >> opc1;
        opc1 = opc1 + value;

            if (std::cin.fail()) {
                fail();
                goto jump;
            }

            switch (opc1)
            {
            case 1:
                gameMenu();
                break;
            case 2:
                if (value == 1) {
                    gameMenu();
                    value = 0;
                }
                else {
                    std::cout << "Desea iniciar una nueva partida? Sus datos seran borrados" << '\n';
                    std::cout << "1) Si" << '\n';
                    std::cout << "2) No" << '\n';
                jump6:
                    std::cin >> opc2;
                    if (std::cin.fail()) {
                        fail();
                        std::cout << "Error, dato invalido" << '\n';
                        goto jump6;
                    }
                    if (opc2 == 1)
                    {
                        PlaySound(TEXT("rpg2.wav"), NULL, SND_ASYNC);
                    }
                    else if (opc2 == 2) {
                        goto jump5;
                    }
                    else {
                        std::cout << "Error, solo hay dos opciones" << '\n';
                    }
                    player->reset();
                    player->deleteVector(7658);
                    world->reset();
                    for (int i = 0; i < options.size(); i++) {
                        delete options[i];
                    }
                    options.clear();
                    gameMenu();
              
                }
            jump5:
             
                break;
            case 3:
                info.Information();
                break;
            case 4:
                std::cout << std::endl;
                std::cout << "===========================================================================================" << std::endl;
                std::cout << "======================= Gracias por jugar a Aventura en el Castillo =======================" << std::endl;
                std::cout << "===========================================================================================" << std::endl << std::endl;
                opc1 = 4;
                break;
            default:
                std::cout << "Error, el valor debe ser x" << '\n';
                break;
            }
        } while (opc1 != 4);
    }

void Menu::gameMenu()
{
    int c = 0;
    int d = 0;
    bool x = false;
    
    do {
        
        if (world->maxPos() == 0) {
            a = 0;
            b = 0;
            world->setWeaponStatus(false,false);
            world->newWorld();
            std::cin.ignore(256, '\n');
            system("cls");
            std::cout << "===========================================================================================" << std::endl;
            std::cout << "========================== Bienvenidos a Aventura en el Castillo ==========================" << std::endl;
            std::cout << "===========================================================================================" << std::endl << std::endl;
            std::cout << "Esriba su nombre: ";
            std::getline(std::cin, str);
            player->setName(str);
            player->setWorld(world->currentPos());
            std::tie(a, b) = world->getCoordenadas();
            player->setCoordenadas(a, b);
            options.push_back(new Option(a, b, player, world));
            options.push_back(new MovementOption(a, b, player, world));
            options.push_back(new ChestOption(a, b, player, world));
            options.push_back(new BattleOption(a, b, player, world));
            options.push_back(new LevelOption(a, b, player, world));
            options.push_back(new Salir(false));
        }
        else {
            std::tie(a, b) = world->getCoordenadas();
            std::tie(c, d) = player->getCoordenadas();
        }
        std::string str = options[0]->menuOption();

        if (str == "up") {
            opc = Opcion::up;
        }
        else if (str == "down") {
            opc = Opcion::down;
        }
        else if (str == "right") {
            opc = Opcion::right;
        }
        else if (str == "left") {
            opc = Opcion::left;
        }
        else if (str == "enemigo") {
            opc = Opcion::enemy;
        }
        else if (str == "cofre") {
            opc = Opcion::chest;
        }
        else if (str == "moveF") {
            opc = Opcion::exit;
        }
        else if (str == "level") {
            opc = Opcion::level;
        }
        else if (str == "salir") {
            opc = Opcion::salir;
        }

        if (player->getHealthPoints() <= 0) {
            
            if(muertes == 0){
                system("cls");
                dead();
                Sleep(400);
                PlaySound(TEXT("rpgsad.wav"), NULL, SND_ASYNC);
                muertes++;
            }
            else
            {
                std::cout << "No puedes jugar, estas muertisimo" << '\n';
            }
            system("pause");
            goto sal;
        }
        switch (opc)
        {
        case Opcion::enemy:
            if (world->getEnemy(a, b) == "Vampyre") {
                if (player->getSpear() == false) {
                    player->setHealthPoints(0);
                    goto jump;
                }
                options[3]->Options(str);
            jump: {}
            }
            else if (world->getEnemy(a, b) == "Ghoul") {
                if (player->getDagger() == false) {
                    player->setHealthPoints(0);
                    goto jump67;
                }
                options[3]->Options(str);
            jump67: {}
            }
            else if(world->getEnemy(a, b) == "Ludwig") {
                if (player->getDagger() == false || player->getSpear() == false) {
                    player->setHealthPoints(0);
                    goto jump69;
                }
                options[3]->Options(str);
            jump69: {}
            }
            else if (world->getEnemy(a, b) == "Lilith") {
                if (player->getSpear() == false ) {
                    player->setHealthPoints(0);
                    goto jump70;
                }
                options[3]->Options(str);
            jump70: {}
            }
            else if (world->getEnemy(a, b) == "Iron Golem") {
                options[3]->Options(str);
            }
            else if (world->getEnemy(a, b) == "Belial") {
                options[3]->Options(str);
            }
            else if (world->getEnemy(a, b) == "Baron Zoltan") {
                options[3]->Options(str);
                return;
            }
            break;
        case Opcion::chest:
            options[2]->Options(str);
            break;
        case Opcion::up:
            options[1]->Options(str);
            break;
        case Opcion::down:
            options[1]->Options(str);
            break;
        case Opcion::right:
            options[1]->Options(str);
            break;
        case Opcion::left:
            options[1]->Options(str);
            break;
        case Opcion::exit:
            world->moveToWorld(c, d);
            if (a == 0 && b == 0) {
                world->setCoordenadas(2, 2);
                player->setCoordenadas(2, 2);
                player->setWorld(world->currentPos());
            }
            else {
                world->setCoordenadas(0, 0);
                player->setCoordenadas(0, 0);
                player->setWorld(world->currentPos());
            }
            break;
        case Opcion::level:
            options[4]->Options(str);
            break;
        case Opcion::salir:
            sal:
            x = true;
            break;
        }
    } while (x != true);
}

void Menu::battleMenu()
{
    
}

void Menu::fail()
{
	std::cin.clear();
	std::cin.ignore(256, '\n');
}

Enemy Menu::returnEnemy(std::string)
{
    return Enemy();
}

void Menu::logo()
{
    system("cls");
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "                           .n                   .                 .                  n." << '\n';
    std::cout << "                     .   .dP                  dP                   9b                 9b.    ." << '\n';
    std::cout << "                    4    qXb         .       dX                     Xb       .        dXp     t" << '\n';
    std::cout << "                   dX.    9Xb      .dXb    __                         __    dXb.     dXP     .Xb" << '\n';
    std::cout << "                   9XXb._       _.dXXXXb dXXXXbo.                 .odXXXXb dXXXXb._       _.dXXP" << '\n';
    std::cout << "                    9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.           .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP" << '\n';
    std::cout << "                     `9XXXXXXXXXXXXXXXXXXXXX ~   ~`OOO8b   d8OOO ~   ~ XXXXXXXXXXXXXXXXXXXXXP'" << '\n';
    std::cout << "                       `9XXXXXXXXXXXP' `9XX'   DIE    `98v8P'  HUMAN   `XXP' `9XXXXXXXXXXXP'" << '\n';
    std::cout << "                           ~~~~~~~       9X.          .db|db.          .XP       ~~~~~~~" << '\n';
    std::cout << "                                           )b.  .dbo.dP `v `9b.odb.  .dX(" << '\n';
    std::cout << "                                         ,dXXXXXXXXXXXb     dXXXXXXXXXXXb." << '\n';
    std::cout << "                                        dXXXXXXXXXXXP    .   `9XXXXXXXXXXXb" << '\n';
    std::cout << "                                       dXXXXXXXXXXXXb   d|b   dXXXXXXXXXXXXb" << '\n';
    std::cout << "                                       9XXb     XXXXXb.dX|Xb.dXXXXX    `dXXP" << '\n';
    std::cout << "                                        `'      9XXXXXX(   )XXXXXXP      `'" << '\n';
    std::cout << "                                                 XXXX X.`v'.X XXXX" << '\n';
    std::cout << "                                                 XP^X `b   d `X^XX" << '\n';
    std::cout << "                                                 X. 9  `      P )X" << '\n';
    std::cout << "                                                 `b  `          d" << '\n';
    std::cout << "                                                  `             '";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    std::cout << ",," << '\n';
    std::cout << "                                                                 `7MM                     " << '\n';
    std::cout << "                                                                   MM                     " << '\n';
    std::cout << "                    ,p6*bo  `7Mb,od8 `7M    `MF ,pP*Ybd  ,6 Yb.    MM  `7M'   `MF',pP Ybd " << '\n';
    std::cout << "                   6M   OO    MM       VA   ,V  8I   `* 8)   MM    MM    VA   ,V  8I   ` " << '\n';
    std::cout << "                   8M         MM        VA ,V   `YMMMa.  ,pm9MM    MM     VA ,V   `YMMMa. " << '\n';
    std::cout << "                   YM.    ,   MM         VVV         I8 8M   MM    MM      VVV         I8 " << '\n';
    std::cout << "                   YMbmd*  .JMML.       ,V     M9mmmP* `Moo9^Yo..JMML.    ,V     M9mmmP  " << '\n';
    std::cout << "                       ,V                                ,V              " << '\n';
    std::cout << " LOADING...         OOb*                              OOb*               " << '\n';
  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    Sleep(1500);
}

void Menu::logo2()
{
    system("cls");
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "                           .n                   .                 .                  n." << '\n';
    std::cout << "                     .   .dP                  dP                   9b                 9b.    ." << '\n';
    std::cout << "                    4    qXb         .       dX                     Xb       .        dXp     t" << '\n';
    std::cout << "                   dX.    9Xb      .dXb    __                         __    dXb.     dXP     .Xb" << '\n';
    std::cout << "                   9XXb._       _.dXXXXb dXXXXbo.                 .odXXXXb dXXXXb._       _.dXXP" << '\n';
    std::cout << "                    9XXXXXXXXXXXXXXXXXXXVXXXXXXXXOo.           .oOXXXXXXXXVXXXXXXXXXXXXXXXXXXXP" << '\n';
    std::cout << "                     `9XXXXXXXXXXXXXXXXXXXXX ~   ~`OOO8b   d8OOO ~   ~ XXXXXXXXXXXXXXXXXXXXXP'" << '\n';
    std::cout << "                       `9XXXXXXXXXXXP' `9XX'   DIE    `98v8P'  HUMAN   `XXP' `9XXXXXXXXXXXP'" << '\n';
    std::cout << "                           ~~~~~~~       9X.          .db|db.          .XP       ~~~~~~~" << '\n';
    std::cout << "                                           )b.  .dbo.dP `v `9b.odb.  .dX(" << '\n';
    std::cout << "                                         ,dXXXXXXXXXXXb     dXXXXXXXXXXXb." << '\n';
    std::cout << "                                        dXXXXXXXXXXXP    .   `9XXXXXXXXXXXb" << '\n';
    std::cout << "                                       dXXXXXXXXXXXXb   d|b   dXXXXXXXXXXXXb" << '\n';
    std::cout << "                                       9XXb     XXXXXb.dX|Xb.dXXXXX    `dXXP" << '\n';
    std::cout << "                                        `'      9XXXXXX(   )XXXXXXP      `'" << '\n';
    std::cout << "                                                 XXXX X.`v'.X XXXX" << '\n';
    std::cout << "                                                 XP^X `b   d `X^XX" << '\n';
    std::cout << "                                                 X. 9  `      P )X" << '\n';
    std::cout << "                                                 `b  `          d" << '\n';
    std::cout << "                                                  `             '";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    std::cout << ",," << '\n';
    std::cout << "                                                                 `7MM                     " << '\n';
    std::cout << "                                                                   MM                     " << '\n';
    std::cout << "                    ,p6*bo  `7Mb,od8 `7M    `MF ,pP*Ybd  ,6 Yb.    MM  `7M'   `MF',pP Ybd " << '\n';
    std::cout << "                   6M   OO    MM       VA   ,V  8I   `* 8)   MM    MM    VA   ,V  8I   ` " << '\n';
    std::cout << "                   8M         MM        VA ,V   `YMMMa.  ,pm9MM    MM     VA ,V   `YMMMa. " << '\n';
    std::cout << "                   YM.    ,   MM         VVV         I8 8M   MM    MM      VVV         I8 " << '\n';
    std::cout << "                   YMbmd*  .JMML.       ,V     M9mmmP* `Moo9^Yo..JMML.    ,V     M9mmmP  " << '\n';
    std::cout << "                       ,V                                ,V              " << '\n';
    std::cout << " LOADING...         OOb*                              OOb*               " << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    Sleep(1500);
}

void Menu::logoCycle()
{
    std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "          ____           _____                _    _ _                          _   __   __        _ _      " << '\n';
    std::cout << "         | __ ) _   _   |  ___| __ __ _ _ __ | | _| (_)_ __      __ _ _ __   __| |  | | / /_ _  __| (_)_ __ " << '\n';
    std::cout << "         |  _| | | | |  | |_ |  __/ _` |  _ || |/ / | |  _ |    / _` |  _ | / _` |   | V / _` |/ _` | |  __|" << '\n';
    std::cout << "         | |_) | |_| |  |  _|| | | (_| | | | |   <| | | | | |  | (_| | | | | (_| |    | | (_| | (_| | | |   " << '\n';
    std::cout << "         |____/  __, |  |_|  |_|  |__,_|_| |_|_||_|_|_|_| |_|   |__,_|_| |_||__,_|    |_||__,_||__,_|_|_|   " << '\n';
    std::cout << "                |___/                                                                                       " << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    Sleep(3000);
    PlaySound(TEXT("rpg0.wav"), NULL, SND_ASYNC);
    while (i != 3) {
        logo();
        logo2();
        
        i++;
    }
    historia();
}

void Menu::historia()
{
    system("cls");
    std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    std::cout << "            Eres un aventurero del mundo de Crysalys. Tu pasión es visitar lugares lejanos y recolectar los " << '\n';
    std::cout << "            más raros tesoros. En uno de tus viajes, encuentras el aislado castillo del malvado Barón Zoltan " << '\n';
    std::cout << "            donde sabes que está escondida la Pluma Dorada, la pluma del legendario Halcón de Fuego." << '\n';
    std::cout << "            No son muchos los que tienen el valor de adentrarse en el castillo, pero tu eres valiente y logras " << '\n';
    std::cout << "            encontrar una entrada a través de una de las torres. Sin embargo, una vez dentro del castillo,  " << '\n';
    std::cout << "            caes en una trampa que te lleva al lugar más profundo y oscuro, conformado por una serie de " << '\n';
    std::cout << "            cuartos – algunos de ellos conectados entre sí. " << '\n' << '\n';
    std::cout << "            Los cuartos están separados por una gruesa puerta de cedro, por lo que no es posible ver lo que " << '\n';
    std::cout << "            hay en los cuartos adyacentes. Así, tu debes recorrerlos en una aventura en la cual te " << '\n';
    std::cout << "            encontraras con Ghouls y Vampiros, cofres con Dagas y otros artículos que te ayudarán en el viaje" << '\n';
   
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    
    std::cout << " LOADING";
    i = 0;
    while (i != 3) {
        Sleep(1500);
        std::cout << '.';
        i++;
    }
    Sleep(300);
    system("cls");
    std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    std::cout << "            Eres un aventurero del mundo de Crysalys. Tu pasión es visitar lugares lejanos y recolectar los " << '\n';
    std::cout << "            más raros tesoros. En uno de tus viajes, encuentras el aislado castillo del malvado Barón Zoltan " << '\n';
    std::cout << "            donde sabes que está escondida la Pluma Dorada, la pluma del legendario Halcón de Fuego." << '\n';
    std::cout << "            No son muchos los que tienen el valor de adentrarse en el castillo, pero tu eres valiente y logras " << '\n';
    std::cout << "            encontrar una entrada a través de una de las torres. Sin embargo, una vez dentro del castillo,  " << '\n';
    std::cout << "            caes en una trampa que te lleva al lugar más profundo y oscuro, conformado por una serie de " << '\n';
    std::cout << "            cuartos – algunos de ellos conectados entre sí. " << '\n' << '\n';
    std::cout << "            Los cuartos están separados por una gruesa puerta de cedro, por lo que no es posible ver lo que " << '\n';
    std::cout << "            hay en los cuartos adyacentes. Así, tu debes recorrerlos en una aventura en la cual te " << '\n';
    std::cout << "            encontraras con Ghouls y Vampiros, cofres con Dagas y otros artículos que te ayudarán en el viaje" << '\n';

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("pause");
    PlaySound(TEXT("rpg1.wav"), NULL, SND_ASYNC);
    std::cout << "LOADING";
    i = 0;
    while (i != 3) {
        Sleep(750);
        std::cout << '.';
        i++;
    }
    std::cout << '\n';
    Sleep(300);
}
