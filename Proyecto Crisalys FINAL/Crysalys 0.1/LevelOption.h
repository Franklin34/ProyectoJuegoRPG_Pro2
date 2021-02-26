#ifndef LEVELOPTION_H
#define LEVELOPTION_H
#include "Option.h"

class LevelOption : public Option
{
public:
	LevelOption();
	LevelOption(int&, int&, Player*, World*);
	~LevelOption();
	void Options(std::string);
private:
	int templevel;
};

#endif