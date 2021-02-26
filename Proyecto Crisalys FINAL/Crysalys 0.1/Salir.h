#ifndef SALIR_H
#define SALIR_H
#include "Option.h"

class Salir : public Option
{
public:
	Salir(bool);
	~Salir() {}
	bool getSalir();
private:
	bool salir;
};

#endif