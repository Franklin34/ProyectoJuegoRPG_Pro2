#ifndef MOVEMENTOPTION_H
#define MOVEMENTOPTION_H
#include "Option.h"


class MovementOption : public Option 
{
public:
	MovementOption(int&,int&,Player* player, World* world);
	~MovementOption() {}
	void Options(std::string);
private:
};

#endif