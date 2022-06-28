#include "Zwierze.h"
#include <cstdlib>
#include <ctime>


void Zwierze::ruch() 
{
	int dx;
	int dy;
	losujObok(&dx, &dy, 1, false);
	swiat.przesun(x + dx, y + dy, this);
}

bool Zwierze::rozmnazanie()
{
	int dx, dy;
	losujObok(&dx, &dy, 1, true);
	if (dx == 0 && dy == 0) return false;
	else
	{
		swiat.dodajOrganizm(potomek(x + dx, y + dy));
		return true;
	}
}

void Zwierze::akcja() 
{
	ruch();
}

bool Zwierze::czyOdbilAtak(Organizm* atakujacy)
{
	return false;
}

bool Zwierze::ucieczka() 
{
	return false;
}

Zwierze::~Zwierze() 
{	
}
