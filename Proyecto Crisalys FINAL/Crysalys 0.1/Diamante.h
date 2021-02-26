#ifndef DIAMANTE_H
#define DIAMANTE_H
#include "Item.h"

class Diamante : public Item
{
public: 
	Diamante() {}
	~Diamante() {}
	Diamante(std::string n) : Item(n) {}
};
#endif 
