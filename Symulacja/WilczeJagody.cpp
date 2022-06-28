#include "WilczeJagody.h"


WilczeJagody::WilczeJagody(int x, int y, Swiat & w)
	: Roslina(x, y, 99, 0.1f, '%', w) {}

char WilczeJagody::efektZjedzenia(Organizm * zjadajacy)
{
	zjadajacy->zabij();
	return 'z';
}

std::string WilczeJagody::gatunek()
{
	return "Wilcze Jagody";
}

Organizm * WilczeJagody::potomek(int x, int y)
{
	return new WilczeJagody(x, y, swiat);
}

WilczeJagody::~WilczeJagody()
{
}
