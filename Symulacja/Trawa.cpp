#include "Trawa.h"


Trawa::Trawa(int x, int y, Swiat & w) :
	Roslina(x, y, 0, 0.2f, '.', w) {}

std::string Trawa::gatunek()
{
	return "Trawa";
}

Organizm * Trawa::potomek(int x, int y)
{
	return new Trawa(x, y, swiat);
}

Trawa::~Trawa()
{
}
