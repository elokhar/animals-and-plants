#include "Guarana.h"


Guarana::Guarana(int x, int y, Swiat & w)
	: Roslina(x, y, 0, 0.2f, '@', w) {}

char Guarana::efektZjedzenia(Organizm* zjadajacy)
{
	zjadajacy->zwiekszSila(3);
	return 'w';
}

std::string Guarana::gatunek()
{
	return "Guarana";
}

Organizm* Guarana::potomek(int x, int y)
{
	return new Guarana(x, y, swiat);
}


Guarana::~Guarana()
{
}
