#ifndef LUDWIG_H
#define LUDWIG_H
#include "Enemy.h"

class Ludwig : public Enemy
{
public:
    Ludwig();
    ~Ludwig() {}
    Ludwig(std::string);
    std::string getPassiveAbilityName();
private:
    std::string passive;
};
#endif
