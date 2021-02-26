#ifndef BATTLEOPTION_H
#define BATTLEOPTION_H
#include "Option.h"
#include <Windows.h>

class BattleOption : public Option
{
public:
    BattleOption();
    BattleOption(int&, int&, Player* player, World* world);
    ~BattleOption() {}
    void battle1(Enemy*);
    void battle2(Enemy*);
    void Options(std::string);
    void info(Enemy*);
    int rand();
    void rand2();
    int verificaNivel(int);
    void lore(Enemy*);
    void FindelJuego();
private:
    int randum;
    int battle;
    int choice;
    float dmg;
    int x;
    float dodge;
    float tempDmg;
    float tempDef;
    std::vector<std::string>vecHabilidades;
    int revivirlilith;
    bool zoltan;
    bool overcharge;
    std::string zoltanSTR;
    int mascarabelial;
};

#endif