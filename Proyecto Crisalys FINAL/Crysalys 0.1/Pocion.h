#ifndef POCION_H
#define POCION_H
#include <iostream>
#include "Item.h"

class Pocion : public Item
{
public:
	Pocion() {}
	~Pocion() {}
	Pocion(std::string n) : Item(n) {}
};
#endif
