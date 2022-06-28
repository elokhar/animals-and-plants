#pragma once
#include <list>
#include <string>

class Organizm;
class Czlowiek;


class Swiat
{
private:
	int szerokosc;
	int wysokosc;
	int startX;
	int startY;
	char wejscie;
	std::list<Organizm*> lista;
	std::list<std::string> komunikaty;
	Organizm ***tab;
	Czlowiek* gracz;
	void przesunKursorDo(int x, int y);
	void rysujRamke();
	void rysujLegende();
	void stworzTablice(int szerokosc, int wysokosc);
	void oproznijTablice();
	void zapisz();
	void wczytaj();
	Organizm * wybierzOrganizm(char symbol, int x, int y);
public:	
	Swiat(int a, int b, int x, int y);
	void start();
	void rysujSwiat();
	void narysujZnak(int x, int y, char z);
	void wypiszKomunikaty();
	void wykonajTure();
	void dodajOrganizm(Organizm* org);
	void dodajOrganizmy(int ile);
	void usunOrganizmy();
	void oproznij(int x, int y);
	void usun(Organizm *org);
	void przesun(int x, int y, Organizm* org);
	int getWysokosc();
	int getSzerokosc();
	int getStartX();
	int getStartY();
	Organizm * getTabAt(int x, int y);
	char getWejscie();

	void dodajKomunikat(std::string komunikat);
	
	~Swiat();
};

