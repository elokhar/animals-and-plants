#include "Czlowiek.h"


Czlowiek::Czlowiek(int x, int y, Swiat & sw)
	: Zwierze(x, y, 5, 4, 'C', sw) {}


void Czlowiek::akcja()
{
	ruch(swiat.getWejscie());
	if (licznikUmiejetnosci > -5)
		licznikUmiejetnosci--;
	if (licznikUmiejetnosci >= 0) 
	{
		swiat.dodajKomunikat(
			"Pozostale tury dzialania umiejetnosci czlowieka: "
			+ std::to_string(licznikUmiejetnosci));
	}
}

std::string Czlowiek::gatunek()
{
	return "Czlowiek";
}

void Czlowiek::aktywujUmiejetnosc()
{
	if (licznikUmiejetnosci == -5) 
	{
		licznikUmiejetnosci = 5;
		swiat.dodajKomunikat("Szybkosc antylopy zostala aktywowana");
	}
	else if (licznikUmiejetnosci >= 0) 
	{
		swiat.dodajKomunikat("Umiejetnosc jest juz aktywna");
	}
	else 
	{
		swiat.dodajKomunikat("Umiejetnosc bedzie gotowa za "
			+ std::to_string(5 + licznikUmiejetnosci) + " tur");
	}		
}

void Czlowiek::ruch(char kierunek)
{
	int dx, dy;
	switch (kierunek) 
	{
	case 72:
		zamienNaWspolrzedne(1, zasiegRuchu(), &dx, &dy);
		break;
	case 80:
		zamienNaWspolrzedne(6, zasiegRuchu(), &dx, &dy);
		break;
	case 77:
		zamienNaWspolrzedne(4, zasiegRuchu(), &dx, &dy);
		break;
	case 75:
		zamienNaWspolrzedne(3, zasiegRuchu(), &dx, &dy);
		break;
	default:
		return;
	}
	if (x+dx>=0 && x+dx<swiat.getSzerokosc() && y+dy>=0 && y+dy<swiat.getWysokosc())
		swiat.przesun(x + dx, y + dy, this);
}

int Czlowiek::zasiegRuchu()
{
	if (licznikUmiejetnosci > 0)
		return 2;
	else
		return 1;
}

int Czlowiek::getLicznik() 
{
	return licznikUmiejetnosci;
}

void Czlowiek::setLicznik(int l)
{
	this->licznikUmiejetnosci = l;
}

Organizm * Czlowiek::potomek(int x, int y)
{
	return nullptr;
}

Czlowiek::~Czlowiek()
{
}
