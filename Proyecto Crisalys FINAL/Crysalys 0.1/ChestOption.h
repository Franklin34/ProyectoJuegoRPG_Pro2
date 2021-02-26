#ifndef CHESTOPTION_H
#define CHESTOPTION_H
#include "Option.h"

class ChestOption : public Option
{
public:
    ChestOption(int&, int&, Player* player, World* world);
    ~ChestOption() {}
    void Options(std::string);
};
#endif // !CHESTOPTION_H

