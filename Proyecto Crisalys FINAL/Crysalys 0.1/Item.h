#ifndef ITEM_H
#define ITEM_H
#include <iostream>


class Item
{
private:
	std::string nombre;
public:
	Item() { nombre = ""; }
	~Item() {}
	Item(std::string n) { nombre = n; }

	std::string getNombre() { return nombre; }
};
#endif