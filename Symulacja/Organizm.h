#pragma once
#include "Swiat.h"
#include <string.h>

class Swiat;
class Zwierze;
class Roslina;


class Organizm
{
protected:
	int x;
	int y;
	int sila;
	int inicjatywa;
	int wiek = 0;
	char symbol;
	bool martwy = false;
	Swiat& swiat;

	virtual void zaatakuj(Zwierze* drugi);
	virtual void walcz(Zwierze* drugi);
	virtual void zjedz(Roslina* drugi);
	virtual Organizm* potomek(int x, int y) = 0;

	void losujObok(int * dx, int * dy, int zasieg, bool tylkoWolne);
	void zamienNaWspolrzedne(int wynik, int zasieg, int * dx, int * dy);
	void wpiszSasiadow(bool * sasiedzi, int zasieg);
	void wybierzWolnych(bool * sasiedzi, int zasieg);

public:
	Organizm(int x, int y, int s, int i, char z, Swiat& sw, int w=0);
	
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* drugi);
	virtual bool czyOdbilAtak(Organizm* atakuj¹cy);
	virtual void narysuj();
	virtual std::string gatunek() = 0;

	int getX();
	int getY();
	int getSila();
	int getWiek();
	int getIni();
	char getSymbol();
	bool czyMartwy();
	std::string nazwa();

	void setX(int n);
	void setY(int n);
	void setWiek(int n);
	void setSila(int n);
	void zwiekszSila(int n);
	void zwiekszWiek(int n);
	void zabij();
	
	~Organizm();
};

