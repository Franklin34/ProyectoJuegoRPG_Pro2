#ifndef LANZA_H
#define LANZA_H
#include <iostream> 
#include "Item.h"

class Lanza : public Item
{
public:
	Lanza() {}
	~Lanza() {}
	Lanza(std::string n) : Item(n) {}

};
#endif
