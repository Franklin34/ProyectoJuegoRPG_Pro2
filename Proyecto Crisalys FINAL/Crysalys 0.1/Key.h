#ifndef KEY_H
#define KEY_H
#include "Item.h"

class Key : public Item
{
public:
	Key() {}
	~Key() {}
	Key(std::string n):Item(n){}
private:
};

#endif