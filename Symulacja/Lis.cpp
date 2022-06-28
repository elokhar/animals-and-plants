#include "Lis.h"


Lis::Lis(int x, int y, Swiat& sw) :
	Zwierze(x, y, 3, 7, 'L', sw) {}

void Lis::ruch()
{
	int dx;
	int dy;
	losujObok(&dx, &dy, 1, false);
	if (swiat.getTabAt(x + dx, y + dy) == nullptr || swiat.getTabAt(x + dx, y + dy)->getSila() <= this->getSila()) {
		swiat.przesun(this->getX() + dx, this->getY() + dy, this);
	}
}

std::string Lis::gatunek()
{
	return "Lis";
}

Organizm * Lis::potomek(int x, int y)
{
	return new Lis(x, y, swiat);
}

Lis::~Lis()
{
}
