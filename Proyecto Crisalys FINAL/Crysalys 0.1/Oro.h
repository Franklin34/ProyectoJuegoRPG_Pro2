#ifndef ORO_H
#define ORO_H
#include "Item.h"

class Oro : public Item
{
public:
	Oro(std::string n) : Item(n) {}
	~Oro() {}
	Oro() {}
};

#endif