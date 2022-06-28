#include "Antylopa.h"


Antylopa::Antylopa(int x, int y, Swiat& w) :
	Zwierze(x, y, 4, 4, 'A', w) {}

void Antylopa::ruch() 
{
	int dx;
	int dy;
	losujObok(&dx, &dy, 2,false);
	swiat.przesun(this->getX() + dx, this->getY() + dy, this);
}

Organizm * Antylopa::potomek(int x, int y)
{
	return new Antylopa(x, y, swiat);
}

bool Antylopa::ucieczka()
{
	if (rand()%2==0)
		return false;
	else 
	{
		int dx, dy;
		losujObok(&dx, &dy, 1,true);
		if (dx == 0 && dy == 0) return false;
		else 
		{
			swiat.przesun(x + dx, y + dy, this);
			return true;
		}
	}

}

std::string Antylopa::gatunek()
{
	return "Antylopa";
}

Antylopa::~Antylopa()
{
}
