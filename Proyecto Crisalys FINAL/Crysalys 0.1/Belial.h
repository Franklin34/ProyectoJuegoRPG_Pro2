#ifndef BELIAL_H
#define BELIAL_H
#include <iostream>
#include "Enemy.h"

class Belial : public Enemy
{
public:
    Belial();
    ~Belial() {}
    Belial(std::string n);
    std::string getPassiveAbilityName();
private:
    std::string passive;
};
#endif
