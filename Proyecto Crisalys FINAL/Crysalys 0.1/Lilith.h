#ifndef LILITH_H
#define LILITH_H
#include "Enemy.h"

class Lilith : public Enemy
{
public:
    Lilith();
    ~Lilith() {}
    Lilith(std::string);
    std::string getPassiveAbilityName();
private:
    std::string passive;
};
#endif
