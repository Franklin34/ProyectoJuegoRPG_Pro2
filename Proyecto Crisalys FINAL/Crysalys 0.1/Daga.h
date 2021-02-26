#ifndef DAGA_H
#define DAGA_H
#include <iostream> 
#include "Item.h"

class Daga : public Item
{
public:
	Daga() {}
	~Daga() {}
	Daga(std::string n) : Item(n) {}
};
#endif