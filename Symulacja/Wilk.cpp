#include "Wilk.h"


Wilk::Wilk(int x, int y, Swiat& w) :
	Zwierze(x, y, 9, 5, 'W', w) {}

Organizm * Wilk::potomek(int x, int y)
{
	return new Wilk(x, y, swiat);
}

std::string Wilk::gatunek()
{
	return "Wilk";
}

Wilk::~Wilk()
{
}
