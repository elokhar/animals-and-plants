#include "Owca.h"


Owca::Owca(int x, int y, Swiat& w) :
	Zwierze(x, y, 4, 4, 'O', w) {}

std::string Owca::gatunek()
{
	return "Owca";
}

Organizm * Owca::potomek(int x, int y)
{
	return new Owca(x, y, swiat);
}

Owca::~Owca()
{
}
