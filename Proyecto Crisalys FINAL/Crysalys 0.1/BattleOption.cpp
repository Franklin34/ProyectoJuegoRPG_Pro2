#include "BattleOption.h"

BattleOption::BattleOption()
{
    randum = 0;
    dodge = 0.0f;
    battle = 0;
    choice = 0;
    dmg = 0;
    x = 0;
    tempDmg = 0.0f;
    tempDef = 0.0f;
    revivirlilith = 0;
    zoltan = false; 
    overcharge = false;
    mascarabelial = 0;
}

BattleOption::BattleOption(int& a, int& b, Player* player, World* world) : Option(a, b, player, world)
{
    randum = 0;
    dodge = 0.0f;
    battle = 0;
    choice = 0;
    dmg = 0;
    x = 0;
    tempDmg = 0.0f;
    tempDef = 0.0f;
    revivirlilith = 0;
    zoltan = false;
    overcharge = false;
    mascarabelial = 0;
}

void BattleOption::battle1(Enemy* enemy)
{
    std::cout << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    std::cout << "------------------------------[ Enemy's Turn ]-----------------------------------------" << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << std::endl;
    choice = rand();

    dodge = (getPlayer()->getDexterity() * 2.5f) - enemy->getAccuracy();
    rand2();

    if (randum <= dodge) {
        std::cout << "------------------[ Has esquivado el ataque del enemigo ]------------------" << '\n';
        goto jump3;
    }

    switch (choice)

    {
    case 0:
        dmg = enemy->getAbility() - getPlayer()->getDefense() * 0.5f;
        if (dmg < 0) {
            dmg = 0;
        }
        if(overcharge == true){
            dmg = dmg * 3.2f;
            zoltan = false;
            overcharge = false;
        }
        else if (zoltan == true) {
            dmg = dmg * 2.1f;
            zoltan = false;
        }
        getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - dmg));
        std::cout << enemy->getName() << " Ha dado un golpe debil" << " Dano recibido: " << dmg << '\n';

        break;
    case 1:
        dmg = enemy->getAbility2() - getPlayer()->getDefense() * 0.5f;
        if (dmg < 0) {
            dmg = 0;
        }
        if (overcharge == true) {
            dmg = dmg * 3.2f;
            zoltan = false;
            overcharge = false;
        }
        else if (zoltan == true) {
            dmg = dmg * 2.1f;
            zoltan = false;
        }
        getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - dmg));
        std::cout << enemy->getName() << " Ha dado un golpe fuerte" << " Dano recibido: " << dmg << '\n';
        break;

    case 2:
        dmg = enemy->getPassive() - getPlayer()->getDefense() * 0.5f;
        if (dmg < 0) {
            dmg = 0;
        }
        getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - dmg));

        if (enemy->getName() == "Vampyre") {

            if (enemy->getHealtPoints() != enemy->getMaxHealtPoints()) {
                static_cast<Vampyre*>(enemy)->setBloodLust(float(dmg / 2));
                std::cout << "El enemigo ha hecho su habilidad: " << enemy->getPassiveAbilityName() << "! El vampiro te mordio, dano: " << dmg << " damage" << '\n';
                std::cout << "El enemigo a recuperado vida" << '\n';
            }
            else {
                std::cout << "El enemigo ha hecho su habilidad: " << enemy->getPassiveAbilityName() << "! El vampiro te mordio, dano: " << dmg << " damage" << '\n';
            }
        }
        else if (enemy->getName() == "Ghoul") {
            dmg = enemy->getPassive() - getPlayer()->getDefense() * 0.5f;
            if (dmg < 0) {
                dmg = 0;
            }
            getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - dmg));
            std::cout << "El enemigo ha hecho su habilidad: " << enemy->getPassiveAbilityName() << "! Recibes 2 golpes de: " << dmg << " damage" << '\n';
        }
        else if (enemy->getName() == "Ludwig") {
            getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - 2));
            getPlayer()->setMarcado(true);
            std::cout << "El Boss ha hecho su habilidad: " << enemy->getPassiveAbilityName() << "! Quedas marcado por un damage creciente de: " << 2 << " de damage" << '\n';
        }
        else if (enemy->getName() == "Lilith") {
            getPlayer()->setDefense(getPlayer()->getDefense() - (getPlayer()->getDefense() / 10));
            std::cout << "El Boss ha hecho su habilidad: LLamada al infierno y recibes un golpe de " << dmg << " ademas de que tu defensa de disminuye en 10%" << '\n';
        }
        else if (enemy->getName() == "Iron Golem") {
            zoltanSTR = static_cast<IronGolem*>(enemy)->golemsHeart();
            enemy->setAbility();
            enemy->setAbility2();
            std::cout << "El Boss ha hecho su habilidad: " << enemy->getPassiveAbilityName() << zoltanSTR << '\n';
            if (zoltanSTR == "Carga de Energia") {
                if (zoltan == true) {
                    overcharge = true;
                    zoltan = false;
                }
                else {
                    zoltan = true;
                }
                std::cout << "El Golem esta reuniendo energia, es vulnerable!" << '\n';
            }
        }
        else if (enemy->getName() == "Belial") {
           getPlayer()->setMarcado(true);
           std::cout << "Belial te ha golpeado con la habilidad Fuego eterno, recibes: " << dmg << " ademas de que se difraza de Ludwig y activa su habilidad Marca de alma sobre ti" << std::endl;
        }
        else if (enemy->getName() == "Baron Zoltan") {
            zoltanSTR = static_cast<BaronZoltan*>(enemy)->KingsHonor();
            enemy->setAbility();
            enemy->setAbility2();
            std::cout << "El Boss ha hecho su habilidad: " << enemy->getPassiveAbilityName() << zoltanSTR << '\n';
            if (zoltanSTR == "Weaklings shall die") {
                std::cout << "Baron Zoltan va a desatar un Golpe Debastador" << '\n';
                if (zoltan == true) {
                    overcharge = true;
                    zoltan = false;
                }
                else {
                    zoltan = true;
                }
            }
        }
        break;
    }
    if (getPlayer()->getHealthPoints() <= 0) {
        goto jump2;
    }
    std::cout << std::endl;
jump3:
    info(enemy);
    std::cout << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "------------------------------[ Your turn ]-----------------------------------------" << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    if (getPlayer()->getNivel() == 0) {
        if (vecHabilidades.size() == 0) {
            vecHabilidades.push_back("1) Golpe Ligero");
            vecHabilidades.push_back("Habilidad: Disponible a LVL 5");
            vecHabilidades.push_back("Habilidad: Disponible a LVL 10");
            vecHabilidades.push_back("Habilidad: Disponible a LVL 15");
            vecHabilidades.push_back("Digite la habilidad a realizar: ");
        }
    }
    else if (getPlayer()->getNivel() == 5) {
        vecHabilidades[1].assign("2) Arrasar");
    }
    else if (getPlayer()->getNivel() == 10) {
        vecHabilidades[2].assign("3) Aumentar Ataque");
    }
    else if (getPlayer()->getNivel() == 15) {
        vecHabilidades[3].assign("4) Grito");
    }
    for (int i = 0; i < vecHabilidades.size() - 1; i++) {
        std::cout << vecHabilidades[i] << '\n';
    }
    ///////////////////////////////////////////////////
jump:
    std::cin >> x;
    if (std::cin.fail()) {
        fail();
        std::cout << "Error, dato no valido" << '\n';
        system("pause");
        goto jump;
    }

    x = verificaNivel(x);
    if (x == 999) {
        std::cout << "La habilidad no existe, vuelva a intentar" << '\n';
        goto jump;
    }
    switch (x)
    {
    case 1:
        dmg = getPlayer()->getSkill() - (enemy->getDefense() * 0.5f);
        if (dmg < 0) {
            dmg = 0;
        }
        enemy->setHealthPoints(float(enemy->getHealtPoints() - dmg));
        std::cout << std::endl;
        std::cout << enemy->getName() << " Ha recibido dano: " << dmg << '\n';
        break;
    case 2:
        dmg = dmg = getPlayer()->getSkill() - (enemy->getDefense() * 0.5f);
        if (dmg < 0) {
            dmg = 0;
        }
        dmg = dmg - (dmg / 5);
        enemy->setHealthPoints(float(enemy->getHealtPoints() - dmg));
        enemy->setDefense(enemy->getDefense() / 1.43f);
        std::cout << std::endl;
        std::cout << enemy->getName() << " Ha recibido dano: " << dmg << " y su defensa se ha reducido en 30%" << '\n';
        break;
    case 3:
        dmg = getPlayer()->getStrenght();
        dmg = dmg + (dmg * 0.5f);
        getPlayer()->setStrenght(dmg);
        std::cout << std::endl;
        std::cout << getPlayer()->getName() << " Ha aumentado su fuerza en un 50%" << '\n';
        break;
    case 4:
        enemy->setDexterity(enemy->getDexterity() - enemy->getDexterity() / 10);
        std::cout << std::endl;
        std::cout << getPlayer()->getName() << " Ha usado su skill Grito y " << enemy->getName() << " ha reducido su velocidad en un 10% " << '\n';
        break;
    }

    std::cout << std::endl;
jump2:
    info(enemy);
    std::cout << std::endl;
    std::cout << "==================================== La Ronda termino ====================================" << std::endl;
    std::cout << std::endl;
    if (enemy->getName() == "Belial" && enemy->getHealtPoints() <= 100 && mascarabelial == 0) {
        mascarabelial = 1;
        enemy->setHealthPoints(getPlayer()->getHealthPoints());
        enemy->setStrenght(getPlayer()->getStrenght());
        enemy->setDexterity(getPlayer()->getDexterity() - 4);
        enemy->setAbility();
        enemy->setAbility2();
        system("cls");
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        std::cout << "           Belial se siente apurado " << std::endl;
        int i = 0;
        while (i != 3) {
            Sleep(1500);
            std::cout << '.';
            i++;
        }
        Sleep(300);
        system("cls");
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        std::cout << "          Belial a utilizado su habilidad Marca del infierno y ahora Belial a copiado tus estadisticas!!!" << '\n';
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
    }
    if (getPlayer()->getMarcado() == true) {

        getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - 2));
        std::cout << std::endl;
        std::cout << "===================== Ludwig te a marcado y ahora recibes dano cada ronda ====================================" << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    if (enemy->getHealtPoints() <= 0) {
        std::cout << std::endl;
        std::cout << "                                 Enemigo Asesinado                                 " << std::endl;
        std::cout << std::endl;
        if (enemy->getName() == "Lilith" && revivirlilith == 0) {
            enemy->setHealthPoints(150);

            system("cls");

            std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
            std::cout << "           Algo sucede con la alma de Lilith " << '\n';
            int i = 0;
            while (i != 3) {
                Sleep(1500);
                std::cout << '.';
                i++;
            }
            Sleep(300);
            system("cls");
            std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
            std::cout << "          Lilith a Utlizado su Pasiva: " << enemy->getPassiveAbilityName() << " Ahora Lilith revivio con la mitad de su vida" << '\n';
            std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
            revivirlilith = 1;
            goto saltoi;
        }
        if (enemy->getName() == "Belial") {
            system("cls");

            std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
            std::cout << "         Antes de que me envies denuevo al infierno tengo que decirte esto" << '\n';
            int i = 0;
            while (i != 3) {
                Sleep(1500);
                std::cout << '.';
                i++;
            }
            Sleep(300);
            system("cls");
            char answer;
            std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
            std::cout << "         La razon por la que estoy aqui no es mas por mandadto de mi madre Lilith..." << '\n';
            std::cout << "         ahora que tu la enviaste donde pertenece quiero ofrecerte mi ayuda para " << '\n';
            std::cout << "         matar al rey del Castillo Baron Zoltan no hay nadie mas que odie que a esa" << '\n';
            std::cout << "         abominacion. Quieres que unamos fuerzas para destrozarlo?(s/n)" << '\n' << '\n';
            std::cout << " Belial te esta ofreciendo su ayuda quieres aceptarla?(s/n): ";
        jump9:
            std::cin >> answer;
            answer = char(tolower(answer));
            if (answer != 'n' && answer != 's') {
                std::cout << "No hay tiempo humano, Responde!" << '\n';
                std::cin.clear();
                std::cin.ignore(256, '\n');
                goto jump9;
            }
            if (answer == 'n') {
                std::cout << std::endl;
                std::cout << "         JAJAJA te perdiste mi ayuda.... Te vere en el infierno... " << '\n';
                std::cout << std::endl;

            }
            else if (answer == 's') {
                getPlayer()->setHealthPoints(0);
                system("cls");
                std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
                std::cout << "Yo el demonio de la mentira te traiciono y por el poder que se me otorga en el mundo de las tinieblas" << std::endl;
                std::cout << " te envio directo al infierno" << std::endl;
                std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
                goto saltoi;
            }

        }
        else if (enemy->getName() == "Baron Zoltan") {
            FindelJuego();
            return;
        }

        getPlayer()->setExp(25);

        if (getPlayer()->getMarcado() == true) {
            std::cout << "=================== La marca de Ludwig a desaparecido ==============================" << std::endl;
            getPlayer()->setMarcado(false);

        }
    saltoi: {}
    }
    system("pause");
}

void BattleOption::battle2(Enemy* enemy)
{
    std::cout << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    std::cout << "------------------------------[ Your turn ]-----------------------------------------" << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << std::endl;

    if (getPlayer()->getNivel() == 0) {
        if (vecHabilidades.size() == 0) {
            vecHabilidades.push_back("1) Golpe Ligero");
            vecHabilidades.push_back("Habilidad: Disponible a LVL 5");
            vecHabilidades.push_back("Habilidad: Disponible a LVL 10");
            vecHabilidades.push_back("Habilidad: Disponible a LVL 15");
            vecHabilidades.push_back("Digite la habilidad a realizar: ");
        }
    }
    else if (getPlayer()->getNivel() == 5) {
        vecHabilidades[1].assign("2) Arrasar");
    }
    else if (getPlayer()->getNivel() == 10) {
        vecHabilidades[2].assign("3) Aumentar Ataque");
    }
    else if (getPlayer()->getNivel() == 15) {
        vecHabilidades[3].assign("4) Grito");
    }
    for (int i = 0; i < vecHabilidades.size() - 1; i++) {
        std::cout << vecHabilidades[i] << '\n';
    }
    ///////////////////////////////////////////////////
jump:
    std::cin >> x;
    if (std::cin.fail()) {
        fail();
        std::cout << "Error, dato no valido" << '\n';
        system("pause");
        goto jump;
    }

    x = verificaNivel(x);

    if (x == 999) {
        std::cout << "La habilidad no existe, vuelva a intentar" << '\n';
        goto jump;
    }

    switch (x)
    {
    case 1:
        dmg = getPlayer()->getSkill() - (enemy->getDefense() * 0.5f);
        if (dmg < 0) {
            dmg = 0;
        }
        enemy->setHealthPoints(float(enemy->getHealtPoints() - dmg));
        std::cout << std::endl;
        std::cout << enemy->getName() << " Ha recibido dano: " << dmg << '\n';
        break;
    case 2:
        dmg = getPlayer()->getSkill() - (enemy->getDefense() * 0.5f);
        if (dmg < 0) {
            dmg = 0;
        }
        dmg = dmg - (dmg / 5);
        enemy->setHealthPoints(float(enemy->getHealtPoints() - dmg));
        enemy->setDefense(enemy->getDefense() / 1.43f);
        std::cout << std::endl;
        std::cout << enemy->getName() << " Ha recibido dano: " << dmg << " y su defensa se ha reducido en 30%" << '\n';
        break;
    case 3:
        dmg = getPlayer()->getStrenght();
        dmg = dmg + (dmg * 0.5f);
        getPlayer()->setStrenght(dmg);
        std::cout << std::endl;
        std::cout << getPlayer()->getName() << " Ha aumentado su fuerza en un 50%" << '\n';
        break;
    case 4:
        enemy->setDexterity(enemy->getDexterity() - enemy->getDexterity() / 10);
        std::cout << std::endl;
        std::cout << getPlayer()->getName() << " Ha usado su skill Grito y " << enemy->getName() << " ha reducido su velocidad en un 10% " << '\n';
        break;
    }

    std::cout << std::endl;
    /////////////////////////

    info(enemy);
    std::cout << std::endl;
    std::cout << std::endl;
    if (enemy->getHealtPoints() <= 0) {
        std::cout << std::endl;
        std::cout << "                                 Enemigo Asesinado                                 " << std::endl;
        std::cout << std::endl;
        if (enemy->getName() == "Lilith" && revivirlilith == 0) {
            enemy->setHealthPoints(150);
            system("cls");
            std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
            std::cout << "           Algo sucede con la alma de Lilith " << '\n';
            int i = 0;
            while (i != 3) {
                Sleep(1500);
                std::cout << '.';
                i++;
            }
            Sleep(300);
            system("cls");
            std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
            std::cout << "          Lilith a Utlizado su Pasiva: " << enemy->getPassiveAbilityName() << " Ahora Lilith revivio con la mitad de su vida" << '\n';
            std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
            revivirlilith = 1;
            goto saltoi;
        }
        if (enemy->getName() == "Belial") {
            system("cls");

            std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
            std::cout << "         Antes de que me envies denuevo al infierno tengo que decirte esto" << '\n';
            int i = 0;
            while (i != 3) {
                Sleep(1500);
                std::cout << '.';
                i++;
            }
            Sleep(300);
            system("cls");
            char answer;
            std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
            std::cout << "         La razon por la que estoy aqui no es mas por mandadto de mi madre Lilith..." << '\n';
            std::cout << "         ahora que tu la enviaste donde pertenece quiero ofrecerte mi ayuda para " << '\n';
            std::cout << "         matar al rey del Castillo Baron Zoltan no hay nadie mas que odie que a esa" << '\n';
            std::cout << "         abominacion. Quieres que unamos fuerzas para destrozarlo?(s/n)" << '\n' << '\n';
            std::cout << " Belial te esta ofreciendo su ayuda quieres aceptarla?(s/n): ";
            jump9:
            std::cin >> answer;
            answer = char(tolower(answer));
            if (answer != 'n' && answer != 's') {
                std::cout << "No hay tiempo humano, Responde!" << '\n';
                std::cin.clear();
                std::cin.ignore(256,'\n');
                goto jump9;
            }
            if (answer == 'n') {
                std::cout << std::endl;
                std::cout << "         JAJAJA te perdiste mi ayuda.... Te vere en el infierno... " << '\n';
                std::cout << std::endl;

            }
            else if (answer == 's') {
                getPlayer()->setHealthPoints(0);
                system("cls");
                std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
                std::cout << "Yo el demonio de la mentira te traiciono y por el poder que se me otorga en el mundo de las tinieblas te envio directo al infierno" << std::endl;
                std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
                goto saltoi;
            }
        }
        else if (enemy->getName() == "Baron Zoltan") {
            FindelJuego();
            return;
        }
        getPlayer()->setExp(25);
        if (getPlayer()->getMarcado() == true) {
            std::cout << "=================== La marca de Ludwig a desaparecido ==============================" << std::endl;
            getPlayer()->setMarcado(false);
        }
        saltoi:
        goto jump3;
    }

    std::cout << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
    std::cout << "------------------------------[ Enemy's Turn ]-----------------------------------------" << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << std::endl;
    choice = rand();

    dodge = (getPlayer()->getDexterity() * 2.5f) - enemy->getAccuracy();
    rand2();

    if (randum <= dodge) {
        std::cout << "------------------[ Has esquivado el ataque del enemigo ]------------------" << '\n';
        goto jump3;
    }

    switch (choice)
    {
    case 0:
        dmg = enemy->getAbility() - getPlayer()->getDefense() * 0.5f;
        if (dmg < 0) {
            dmg = 0;
        }
        if (overcharge == true) {
            dmg = dmg * 3.2f;
            zoltan = false;
            overcharge = false;
        }
        else if (zoltan == true) {
            dmg = dmg * 2.1f;
            zoltan = false;
        }
        getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - dmg));
        std::cout << enemy->getName() << " Ha dado un golpe debil" << " Dano recibido: " << dmg << '\n';
        break;
    case 1:
        dmg = enemy->getAbility2() - getPlayer()->getDefense() * 0.5f;
        if (dmg < 0) {
            dmg = 0;
        }
        if (overcharge == true) {
            dmg = dmg * 3.2f;
            zoltan = false;
            overcharge = false;
        }
        else if (zoltan == true) {
            dmg = dmg * 2.1f;
            zoltan = false;
        }
        getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - dmg));
        std::cout << enemy->getName() << " Ha dado un golpe fuerte" << " Dano recibido: " << dmg << '\n';
        break;

    case 2:
        dmg = enemy->getPassive() - getPlayer()->getDefense() * 0.5f;
        if (dmg < 0) {
            dmg = 0;
        }
        getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - dmg));

        if (enemy->getName() == "Vampyre") {

            if (enemy->getHealtPoints() != enemy->getMaxHealtPoints()) {
                static_cast<Vampyre*>(enemy)->setBloodLust(float(dmg / 2));
                std::cout << "El enemigo ha hecho su habilidad: " << enemy->getPassiveAbilityName() << "! El vampiro te mordio, dano: " << dmg << " damage" << '\n';
                std::cout << "El enemigo a recuperado vida" << '\n';
            }
            else {
                std::cout << "El enemigo ha hecho su habilidad: " << enemy->getPassiveAbilityName() << "! El vampiro te mordio, dano: " << dmg << " damage" << '\n';
            }
        }
        else if (enemy->getName() == "Ghoul") {
            dmg = enemy->getPassive() - getPlayer()->getDefense() * 0.5f;
            if (dmg < 0) {
                dmg = 0;
            }
            getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - dmg));
            std::cout << "El enemigo ha hecho su habilidad: " << enemy->getPassiveAbilityName() << "! Recibes 2 golpes de: " << dmg << " damage" << '\n';
        }
        else if (enemy->getName() == "Ludwig") {
            getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - 2));
            getPlayer()->setMarcado(true);
            std::cout << "El Boss ha hecho su habilidad: " << enemy->getPassiveAbilityName() << "! Quedas marcado por un damage creciente de: " << 2 << " de damage" << '\n';

        }
        else if (enemy->getName() == "Lilith") {
            getPlayer()->setDefense(getPlayer()->getDefense() - (getPlayer()->getDefense()/10) );
            std::cout << "El Boss ha hecho su habilidad: LLamada al infierno y recibes un golpe de " << dmg << " ademas de que tu defensa de disminuye en 10%" << '\n';
        }
        else if (enemy->getName() == "Iron Golem") {
            zoltanSTR = static_cast<IronGolem*>(enemy)->golemsHeart();
            enemy->setAbility();
            enemy->setAbility2();
            std::cout << "El Boss ha hecho su habilidad: " << enemy->getPassiveAbilityName() << zoltanSTR << '\n';
            if(zoltanSTR == "Carga de Energia") {
                if (zoltan == true) {
                    overcharge = true;
                    zoltan = false;
                }
                else {
                    zoltan = true;
                }
                std::cout << "El Golem esta reuniendo energia, es vulnerable!" << '\n';
            }
        }
        else if (enemy->getName() == "Belial") {
             getPlayer()->setMarcado(true);
             std::cout << "Belial te ha golpeado con la habilidad Fuego eterno, recibes: " << dmg << " ademas de que se difraza de Ludwig y activa su habilidad Marca de alma sobre ti" << std::endl;
        }
        else if (enemy->getName() == "Baron Zoltan") {
            zoltanSTR = static_cast<BaronZoltan*>(enemy)->KingsHonor();
            enemy->setAbility();
            enemy->setAbility2();
            std::cout << "El Boss ha hecho su habilidad: " << enemy->getPassiveAbilityName() << zoltanSTR << '\n';
            if (zoltanSTR == "Weaklings shall die") {
                std::cout << "================ Baron Zoltan va a desatar un Golpe Debastador ================" << '\n';
                if (zoltan == true) {
                    overcharge = true;
                    zoltan = false;
                }
                else {
                    zoltan = true;
                }
            }
        }
        break;
        break;
    }

    std::cout << std::endl;
jump3:
    info(enemy);
    std::cout << std::endl;
    std::cout << "==================================== La Ronda termino ====================================" << std::endl;
    std::cout << std::endl;
    if (enemy->getName() == "Belial" && enemy->getHealtPoints() <= 100 && mascarabelial ==0) {
        mascarabelial = 1;
        enemy->setHealthPoints(getPlayer()->getHealthPoints());
        enemy->setStrenght(getPlayer()->getStrenght());
        enemy->setDexterity(getPlayer()->getDexterity() - 4);
        enemy->setAbility();
        enemy->getAbility2();
        system("cls");
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        std::cout << "           Belial se siente apurado " << std::endl;
        int i = 0;
        while (i != 3) {
            Sleep(1500);
            std::cout << '.';
            i++;
        }
        Sleep(300);
        system("cls");
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        std::cout << "          Belial a utilizado su habilidad Marca del infierno y ahora Belial a copiado tus estadisticas!!!" << '\n';
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
    }
    if (getPlayer()->getMarcado() == true) {

        getPlayer()->setHealthPoints(float(getPlayer()->getHealthPoints() - 2));
        std::cout << std::endl;
        std::cout << "===================== Ludwig te a marcado y ahora recibes dano cada ronda ====================================" << std::endl;
        std::cout << std::endl;
    }
    system("pause");
}

void BattleOption::Options(std::string)
{
    int a, b;
    std::tie(a, b) = getPlayer()->getCoordenadas();
    getWorld()->setPos(a, b);
    Enemy* enemy = getWorld()->getEnemigo();
    battle = 0;
    system("cls");
    int ir = 1;
    tempDmg = 0.0f;
    tempDmg = getPlayer()->getStrenght();
    tempDef = 0.0f;
    tempDef = getPlayer()->getDefense();
    lore(enemy);
    do
    {
        if (getPlayer()->getHealthPoints() <= 0) {
            goto jump2;
        }
        system("cls");
        std::cout << "===========================================================================================" << std::endl;
        std::cout << "========================== Bienvenidos a Aventura en el Castillo ==========================" << std::endl;
        std::cout << "===========================================================================================" << std::endl << std::endl;
        std::cout << "Ronda " << ir++ << std::endl << std::endl;

        info(enemy);

        if (getPlayer()->getDexterity() > enemy->getDexterity()) {
            battle2(enemy);
        }
        else {
            battle1(enemy);
        }
        /////////////////////////////////////////////////////////////////////////////////////////////
        if (getPlayer()->getHealthPoints() <= 0 || enemy->getHealtPoints() <= 0) {
        jump2:
            battle = 100;
            if (enemy->getHealtPoints() <= 0) {
                getWorld()->setEnemyStatus(false);
                if (enemy->getName() == "Ludwig" || enemy->getName() == "Lilith" || enemy->getName() == "Iron Golem" || enemy->getName() == "Belial" || enemy->getName() == "Baron Zoltan" ) {
                    getWorld()->setJefeEstatus(false);
                    PlaySound(TEXT("rpg2.wav"), NULL, SND_ASYNC);
                }
                delete enemy;
            }
        }
    } while (battle != 100);
    getPlayer()->setStrenght(tempDmg);
    getPlayer()->setDefense(tempDef);
}

void BattleOption::info(Enemy* enemy)
{
    std::cout << "[ Jugador: " << getPlayer()->getName() << SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14) <<

        "  HP: " << getPlayer()->getHealthPoints()
        << " ]  -------  [ " << "Enemigo: " << enemy->getName() << "  HP: " << enemy->getHealtPoints() << " ]" << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int BattleOption::rand()
{
    std::random_device rd{};
    std::mt19937 engine{ rd() };
    std::uniform_int_distribution<int>d(0, 100);
    randum = d(engine);
    if (randum < 50) {
        return 0;
    }
    else if (randum >= 50 && randum < 80) {
        return 2;
    }
    else {
        return 1;
    }
    return 0;
}

void BattleOption::rand2()
{
    std::random_device rd{};
    std::mt19937 engine{ rd() };
    std::uniform_int_distribution<int>d(0, 100);
    randum = d(engine);
}

int BattleOption::verificaNivel(int x)
{
    if (x == 1) {
        return x;
    }
    else if (x == 2 && getPlayer()->getNivel() >= 5) {
        return x;
    }
    else if (x == 3 && getPlayer()->getNivel() >= 10) {
        return x;
    }
    else if (x == 4 && getPlayer()->getNivel() >= 15) {
        return x;
    }
    else {
        return 999;
    }
    return 999;
}

void BattleOption::lore(Enemy* enemy)
{
    if (enemy->getName() == "Ludwig") {
        system("cls");
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        PlaySound(TEXT("rpg3.wav"), NULL, SND_ASYNC);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        std::cout << "           Ludwig era un siervo de la Iglesia de la Sanacion, posterior a Brador el " << '\n';
        std::cout << "           Asesino de la Iglesia, el cual fundo la estirpe de Cazadores que serviria a la " << '\n';
        std::cout << "           causa de la Sangre. Ludwig, el Primer Cazador, fue previamente un clerigo" << '\n';
        std::cout << "           de la Iglesia de la Sanacion, y como tal, su consumo de la Vieja Sangre lo" << '\n';
        std::cout << "           llevo a padecer la enfermedad de la Sangre." << '\n';
        std::cout << "           Ahora Ludwig se dedica a cuidar el Castillo donde se encuentra su amo Baron Soltan,  " << '\n';
        std::cout << "           con su espada echa de su alma promete no dejar que nadie pase de su Piso" << '\n' << '\n';
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        std::cout << "LOADING";
        int i = 0;
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
        std::cout << "           Ludwig era un siervo de la Iglesia de la Sanacion, posterior a Brador el " << '\n';
        std::cout << "           Asesino de la Iglesia, el cual fundo la estirpe de Cazadores que serviria a la " << '\n';
        std::cout << "           causa de la Sangre. Ludwig, el Primer Cazador, fue previamente un clerigo" << '\n';
        std::cout << "           de la Iglesia de la Sanacion, y como tal, su consumo de la Vieja Sangre lo" << '\n';
        std::cout << "           llevo a padecer la enfermedad de la Sangre." << '\n';
        std::cout << "           Ahora Ludwig se dedica a cuidar el Castillo donde se encuentra su amo Baron Soltan,  " << '\n';
        std::cout << "           con su espada echa de su alma promete no dejar que nadie pase de su Piso" << '\n' << '\n';
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
        PlaySound(TEXT("rpg4.wav"), NULL, SND_ASYNC);
        system("cls");
    }
    else if (enemy->getName() == "Lilith") {
        system("cls");
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        PlaySound(TEXT("rpg3.wav"), NULL, SND_ASYNC);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "           Lilith primera esposa de Adam, considerada la madre de todos los demonios " << '\n';
        std::cout << "           fue desterrada del eden luego de mostrar su superioridad con Adam " << '\n';
        std::cout << "           llegando a la tierra lilith se unio con Ludwig para proteger a Baron de " << '\n';
        std::cout << "           todo aquel que quiera hacerle dano, LIlith es considerada la reina de los" << '\n';
        std::cout << "           sucubos, y no descansara de matar a todo aquel que este dentro de su castillo" << '\n';


        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        std::cout << "LOADING";
        int i = 0;
        while (i != 3) {
            Sleep(1500);
            std::cout << '.';
            i++;
        }
        Sleep(300);
        system("cls");
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "           Lilith primera esposa de Adam, considerada la madre de todos los demonios " << '\n';
        std::cout << "           fue desterrada del eden luego de mostrar su superioridad con Adam " << '\n';
        std::cout << "           llegando a la tierra lilith se unio con Ludwig para proteger a Baron de " << '\n';
        std::cout << "           todo aquel que quiera hacerle dano, LIlith es considerada la reina de los" << '\n';
        std::cout << "           sucubos, y no descansara de matar a todo aquel que este dentro de su castillo" << '\n';
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
        PlaySound(TEXT("rpg5.wav"), NULL, SND_ASYNC);
        system("cls");
    }
    else if (enemy->getName() == "Iron Golem") {
        system("cls");
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        PlaySound(TEXT("rpg6.wav"), NULL, SND_ASYNC);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "            Despues de la caida del Imperio de Drangleic, el Rey decidio con su ultimo aliento " << '\n';
        std::cout << "            consumir el alma del Fenix Dorado,  burlandose de ese modo del Dios de la Muerte. Viendo el gran poder" << '\n';
        std::cout << "            del Fenix decidio usar a los ciudadanos del Imperio como experimentos para alcanzar la inmortalidad." << '\n' << '\n';
        std::cout << "            Los Golems de Hierro fueron creados por los hechizeros y las brujas de Drangleic" << '\n';
        std::cout << "            como medida de defensa del gran castillo de Baron Zoltan, cada Golem posee cientos de" << '\n';
        std::cout << "            almas humanas dentro de su nucleo junto con la sangre de su Rey que las usa como forma de" << '\n';
        std::cout << "            energia para poder funcionar." << '\n';
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        std::cout << "LOADING";
        int i = 0;
        while (i != 3) {
            Sleep(1500);
            std::cout << '.';
            i++;
        }
        Sleep(300);
        system("cls");
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "            Despues de la caida del Imperio de Drangleic, el Rey decidio con su ultimo aliento " << '\n';
        std::cout << "            consumir el alma del Fenix Dorado,  burlandose de ese modo del Dios de la Muerte. Viendo el gran poder" << '\n';
        std::cout << "            del Fenix decidio usar a los ciudadanos del Imperio como experimentos para alcanzar la inmortalidad." << '\n' << '\n';
        std::cout << "            Los Golems de Hierro fueron creados por los hechizeros y las brujas de Drangleic" << '\n';
        std::cout << "            como medida de defensa del gran castillo de Baron Zoltan, cada Golem posee cientos de" << '\n';
        std::cout << "            almas humanas dentro de su nucleo junto con la sangre de su Rey que las usa como forma de" << '\n';
        std::cout << "            energia para poder funcionar." << '\n';
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
        PlaySound(TEXT("rpg9.wav"), NULL, SND_ASYNC);
        system("cls");
    }
    else if (enemy->getName() == "Belial") {
        system("cls");
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        PlaySound(TEXT("rpg6.wav"), NULL, SND_ASYNC);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "           Belial Senor de la arrogancia o Senor del orgullo y el hijo del infierno. " << '\n';
        std::cout << "           ha sido considerado como príncipe de los infiernos. Hijo de Lilith   " << '\n';
        std::cout << "           no descansa de servir a su madre, fue traido del infierno para que cumpla con " << '\n';
        std::cout << "           los deseos de su madre, cuidar el Castillo de Baron Zoltan. " << '\n' << '\n';
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        std::cout << "LOADING";
        int i = 0;
        while (i != 3) {
            Sleep(1500);
            std::cout << '.';
            i++;
        }
        Sleep(300);
        system("cls");
        std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "           Belial Senor de la arrogancia o Senor del orgullo y el hijo del infierno. " << '\n';
        std::cout << "           ha sido considerado como príncipe de los infiernos. Hijo de Lilith   " << '\n';
        std::cout << "           no descansa de servir a su madre, fue traido del infierno para que cumpla con " << '\n';
        std::cout << "           los deseos de su madre, cuidar el Castillo de Baron Zoltan. " << '\n' << '\n';
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
        PlaySound(TEXT("rpg8.wav"), NULL, SND_ASYNC);
        system("cls");
    }
    else if (enemy->getName() == "Baron Zoltan") {
    system("cls");
    std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    PlaySound(TEXT("rpg6.wav"), NULL, SND_ASYNC);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "           Baron Zoltan de Drangleic fue el mas grande de los reyes y un poderoso guerrero.  " << '\n';
    std::cout << "           Era conocido como el Senor de la Luz y dirigio la gran batalla del Eden, " << '\n';
    std::cout << "           junto con el Senor del Rayo , la Bruja de la Iglesia de la Sanacion  " << '\n';
    std::cout << "           y , el Legendario Caza Dragones. Llevando a los humanos a la victoria.  " << '\n' << '\n';
    std::cout << "           En su intento de conquistar a los dioses y demonios, una gran maldicion cayo sobre el " << '\n';
    std::cout << "           de este manera siendo abandonado por el resto del mundo, Drangleic se convirtio" << '\n';
    std::cout << "           en el lugar perfecto para el nacimiento de los nuevos Senores del Abysmo." << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    std::cout << "LOADING";
    int i = 0;
    while (i != 3) {
        Sleep(1500);
        std::cout << '.';
        i++;
    }
    Sleep(300);
    system("cls");
    std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "           Baron Zoltan de Drangleic fue el mas grande de los reyes y un poderoso guerrero.  " << '\n';
    std::cout << "           Era conocido como el Senor de la Luz y dirigio la gran batalla del Eden, " << '\n';
    std::cout << "           junto con el Senor del Rayo , la Bruja de la Iglesia de la Sanacion  " << '\n';
    std::cout << "           y , el Legendario Caza Dragones. Llevando a los humanos a la victoria.  " << '\n' << '\n';
    std::cout << "           En su intento de conquistar a los dioses y demonios, una gran maldicion cayo sobre el " << '\n';
    std::cout << "           de este manera siendo abandonado por el resto del mundo, Drangleic se convirtio" << '\n';
    std::cout << "           en el lugar perfecto para el nacimiento de los nuevos Senores del Abysmo." << '\n';
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
    PlaySound(TEXT("rpg7.wav"), NULL, SND_ASYNC);
    system("cls");
    }
}

void BattleOption::FindelJuego()
{
    system("cls");
    std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    PlaySound(TEXT("rpg10.wav"), NULL, SND_ASYNC);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "           Has asesinado a Baron Zoltan!!!  " << '\n';
    std::cout << "           Ahora el mundo de Crysalis es un lugar habitable de nuevo, sin amenazas " << '\n';
    std::cout << "           de demonios a la costa, el Castillo ahora sera un lugar para que las personas puedan   " << '\n';
    std::cout << "           reunirse para hablar y jugar.   " << '\n' << '\n';
    std::cout << "           Sin embargo, no podemos bajar la guardia, se dice que la piedra que contiene  " << '\n';
    std::cout << "           a los demonios a desaparecido del sotano del castillo y no sabemos quien la tomo " << '\n';
    std::cout << "           sea quien sea, estamos tranquilos ya que te tenemos a ti para que combatas" << '\n';
    std::cout << "           cualquier otra amenaza que se presente en nuestro mundo... "<< '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    std::cout << "LOADING";
    int i = 0;
    while (i != 3) {
        Sleep(1500);
        std::cout << '.';
        i++;
    }
    Sleep(300);
    std::cout << std::endl;
    std::cout << "                   " << system("pause");
    system("cls");
    std::cout << '\n' << '\n' << '\n' << '\n' << '\n' << '\n';
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "           **Creditos: **   " << '\n';
    std::cout << "           Estudiantes de Ingenieria en Sistemas de la UNA: " << '\n';
    std::cout << "           -Yadir Gerardo Rojas " << '\n';
    std::cout << "           -Franklin Sandoval " << '\n' << '\n';
    std::cout << "           Gracias por jugar a nuestro juego!!" << '\n';
    std::cout << "           Ya estamos pensando en el futuro del juego, asi que habra segunda parte!!" << '\n' << '\n';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    system("pause");
    return;

    std::cout << '\n';
    Sleep(300);
    PlaySound(TEXT("rpg7.wav"), NULL, SND_ASYNC);
    system("cls");
}