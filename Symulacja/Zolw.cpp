#include "Zolw.h"
#include <cstdlib>


Zolw::Zolw(int x, int y, Swiat& w) :
	Zwierze(x, y, 2, 1, 'Z', w) {}

void Zolw::akcja() {
	if (rand() % 4 < 1) ruch();
}

Organizm * Zolw::potomek(int x, int y)
{
	return new Zolw(x, y, swiat);
}

bool Zolw::czyOdbilAtak(Organizm* atakujacy) {
	if (atakujacy->getSila() < 5) return true;
	else return false;
 }

std::string Zolw::gatunek()
{
	return "Zolw";
}

Zolw::~Zolw()
{
}
