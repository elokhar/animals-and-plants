#include "Mlecz.h"


Mlecz::Mlecz(int x, int y, Swiat& w) :
	Roslina(x, y, 0, 0.2f, ';', w) {}

void Mlecz::akcja() {
	rozsiej(prawdopodobienstwo);
	rozsiej(prawdopodobienstwo);
	rozsiej(prawdopodobienstwo);
}

std::string Mlecz::gatunek()
{
	return "Mlecz";
}

Organizm * Mlecz::potomek(int x, int y)
{
	return new Mlecz(x, y, swiat);
}


Mlecz::~Mlecz()
{
}
