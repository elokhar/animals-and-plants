#include "Organizm.h"
#include "Zwierze.h"
#include "Roslina.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <string>


Organizm::Organizm(int x, int y, int s, int i, char z, Swiat& sw, int w)
	: x(x), y(y), sila(s), inicjatywa(i), symbol(z), swiat(sw), wiek(w) {}

void Organizm::kolizja(Organizm* drugi) 
{
	if (dynamic_cast<Zwierze*>(drugi) != nullptr)
	{

		std::string this_nazwa = typeid(this->potomek).name();
		std::string drugi_nazwa = typeid(drugi->potomek).name();
		if (this->gatunek() == drugi->gatunek()) 
		{	
			if (this->getWiek() == 0 || drugi->getWiek() == 0)
				return;
			bool sukces = ((Zwierze*)drugi)->rozmnazanie();
			if (sukces)
				swiat.dodajKomunikat(this->nazwa() 
				+ " rozmnaza sie z " + drugi->nazwa());
		}
		else
		{
			zaatakuj((Zwierze *)drugi);
		}
		
	}		
	else if (dynamic_cast<Roslina*>(drugi) != nullptr)
		zjedz((Roslina *)drugi);
}

bool Organizm::czyOdbilAtak(Organizm * atakuj¹cy)
{
	return false;
}

void Organizm::zaatakuj(Zwierze *drugi) 
{
	
	std::string komunikat;
	Organizm *atakujacy = this;
	Organizm *atakowany = drugi;
	komunikat = atakujacy->nazwa() + " atakuje " + atakowany->nazwa() + "!\n";
	this->swiat.dodajKomunikat(komunikat);

	int celX = drugi->getX();
	int celY = drugi->getY();

	if (drugi->ucieczka()) 
	{
		komunikat = drugi->nazwa() + " ucieka z pola ("
			+ std::to_string(celX) + "," + std::to_string(celY) + ")!\n";
		this->swiat.dodajKomunikat(komunikat);
		swiat.przesun(celX, celY, this);
		return;
	}

	if (drugi->czyOdbilAtak(this)) 
	{
		komunikat = atakowany->nazwa() + " odbija atak!\n";
		this->swiat.dodajKomunikat(komunikat);
	}
	else 
	{
		walcz(drugi);
	}
}

void Organizm::walcz(Zwierze* drugi) 
{

	std::string wygrany;
	std::string komunikat;

	if (this->sila >= drugi->getSila()) 
	{
		drugi->zabij();
		swiat.przesun(drugi->getX(), drugi->getY(), this);
		wygrany = this->nazwa();
	}
	else 
	{
		this->zabij();
		wygrany = drugi->nazwa();
	}
	komunikat = wygrany + " wygrywa walke\n";
	this->swiat.dodajKomunikat(komunikat);
}

void Organizm::zjedz(Roslina* drugi) 
{
	std::string komunikat;
	char efekt;
	std::string efekt_str;

	komunikat = this->nazwa() + " zjada " + drugi->nazwa();
	swiat.dodajKomunikat(komunikat);
	efekt = drugi->efektZjedzenia(this);
	if (efekt != '\0') 
	{
		switch (efekt) 
		{
		case 'z': 
			efekt_str = " zabija ";
			break;
		case 'w':
			efekt_str = " wzmacnia ";
			break;
		}
		komunikat = drugi->nazwa() + efekt_str + this->nazwa();
		swiat.dodajKomunikat(komunikat);
	}

	drugi->zabij();
	swiat.przesun(drugi->getX(), drugi->getY(), this);
}

void Organizm::narysuj() 
{
	swiat.narysujZnak(swiat.getStartX()+x+1, swiat.getStartY()+y+1, symbol);
}


void Organizm::losujObok(int *dx, int *dy, int zasieg, bool tylkoWolne) 
{	
	int zajete = 0;
	bool sasiedzi[8];

	wpiszSasiadow(sasiedzi, zasieg);

	if (tylkoWolne)
		wybierzWolnych(sasiedzi, zasieg);

	int licznik = rand() % 8;
	int wynik = 0;
	while (licznik >= 0 && zajete<8) 
	{
		wynik = (wynik + 1) % 8;
		if (sasiedzi[wynik] != false) 
		{
			licznik--;
			zajete = 0;
		}		
		else
			zajete++;
	}

	if (zajete >= 8) {
		(*dx) = 0;
		(*dy) = 0;
		return; 
	}

	zamienNaWspolrzedne(wynik, zasieg, dx, dy);	
}

void Organizm::zamienNaWspolrzedne(int wynik, int zasieg, int *dx, int *dy) 
{
	if (wynik < 3) 
	{
		*dx = (wynik - 1)*zasieg;
		*dy = -zasieg;
	}
	else if (wynik == 3) 
	{
		*dx = -zasieg;
		*dy = 0;
	}
	else if (wynik == 4) 
	{
		*dx = zasieg;
		*dy = 0;
	}
	else 
	{
		*dx = (wynik - 6)*zasieg;
		*dy = zasieg;
	}
}

void Organizm::wpiszSasiadow(bool *sasiedzi, int zasieg) 
{
	
	for (int i = 0; i < 8; i++) 
	{
		sasiedzi[i] = true;
	}
	if (this->getX() + 1 - zasieg <= 0)
		sasiedzi[0] = sasiedzi[3] = sasiedzi[5] = false;
	if (this->getX() - 1 + zasieg >= swiat.getSzerokosc() - 1)
		sasiedzi[2] = sasiedzi[4] = sasiedzi[7] = false;
	if (this->getY() + 1 - zasieg <= 0)
		sasiedzi[0] = sasiedzi[1] = sasiedzi[2] = false;
	if (this->getY() - 1 + zasieg >= swiat.getWysokosc() - 1)
		sasiedzi[5] = sasiedzi[6] = sasiedzi[7] = false;		
}

void Organizm::wybierzWolnych(bool *sasiedzi, int zasieg) 
{
	int dx, dy;
	for (int i = 0; i < 8; i++) 
	{
		if (sasiedzi[i] == true) 
		{
			zamienNaWspolrzedne(i, zasieg, &dx, &dy);
			if (swiat.getTabAt(x + dx, y + dy) != nullptr)
				sasiedzi[i] = false;
		}
	}
}

int Organizm::getX()
{
	return x;
}

int Organizm::getY()
{
	return y;
}

int Organizm::getSila() 
{
	return sila;
}

int Organizm::getWiek()
{
	return wiek;
}

int Organizm::getIni()
{
	return inicjatywa;
}

char Organizm::getSymbol()
{
	return symbol;
}

bool Organizm::czyMartwy()
{
	return martwy;
}

std::string Organizm::nazwa()
{
	std::string nazwa = gatunek() + "(" + std::to_string(x)
		+ "," + std::to_string(y) + ")";
	return nazwa;
}

void Organizm::zabij()
{
	martwy = true;
}

void Organizm::setX(int n)
{
	x = n;
}

void Organizm::setY(int n)
{
	y = n;
}

void Organizm::setWiek(int n)
{
	wiek = n;
}

void Organizm::setSila(int n)
{
	sila = n;
}

void Organizm::zwiekszSila(int n)
{
	sila += n;
}

void Organizm::zwiekszWiek(int n)
{
	wiek += n;
}

Organizm::~Organizm()
{
}
