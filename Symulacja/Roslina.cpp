#include "Roslina.h"
#include <cstdlib>


Roslina::Roslina(int x, int y, int s, float p, char z, Swiat & w) 
	: Organizm(x,y,s,0,z,w) 
{
	this->prawdopodobienstwo = p;
}

void Roslina::akcja() 
{
	rozsiej(prawdopodobienstwo);
}

void Roslina::rozsiej(float p)
{
	if (wiek > 0) 
	{
		int n = rand() % 100 + 1;
		if (n < (p * 100)) 
		{
			int dx, dy;
			losujObok(&dx, &dy, 1, true);
			Organizm* pot = this->potomek(x + dx, y + dy);
			swiat.dodajOrganizm(pot);
		}
	}	
}

char Roslina::efektZjedzenia(Organizm *zjadajacy) 
{
	return '\0';
}

Roslina::~Roslina()
{
}
