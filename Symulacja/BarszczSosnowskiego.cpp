#include "BarszczSosnowskiego.h"
#include "Zwierze.h"
#include <string>


Organizm * BarszczSosnowskiego::potomek(int x, int y)
{
	return new BarszczSosnowskiego(x, y, swiat);
}

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y, Swiat & w)
	: Roslina(x,y,10,0.1f,'$',w) {}

char BarszczSosnowskiego::efektZjedzenia(Organizm* zjadajacy)
{
	zjadajacy->zabij();
	return 'z';
}

void BarszczSosnowskiego::akcja()
{
	bool sasiedzi[8];
	int dx, dy;
	std::string komunikat;
	wpiszSasiadow(sasiedzi, 1);
	Organizm* sasiad;
	for (int i = 0; i < 8; i++) {
		if (sasiedzi[i] == true) {
			zamienNaWspolrzedne(i, 1, &dx, &dy);
			sasiad = swiat.getTabAt(x + dx, y + dy);
			if (sasiad != nullptr && 
				dynamic_cast<Zwierze *>(sasiad)!=nullptr &&
				sasiad->czyMartwy()==false) {
				swiat.getTabAt(x + dx, y + dy)->zabij();
				komunikat = this->nazwa() + " zabija " + swiat.getTabAt(x + dx, y + dy)->nazwa();
				swiat.dodajKomunikat(komunikat);
			}
				
		}
	}
	rozsiej(prawdopodobienstwo);
}

std::string BarszczSosnowskiego::gatunek()
{
	return "Barszcz Sosnowskiego";
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}
