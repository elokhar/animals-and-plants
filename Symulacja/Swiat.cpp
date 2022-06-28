#include "Swiat.h"
#include "Organizm.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Trawa.h"
#include "Zolw.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Antylopa.h"
#include "BarszczSosnowskiego.h"
#include "WilczeJagody.h"
#include "Czlowiek.h"

#include <list>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>


Swiat::Swiat(int a, int b, int x, int y) 
	: szerokosc(a), wysokosc(b), startX(x), startY(y)
{
	stworzTablice(szerokosc, wysokosc);
}

void Swiat::start()
{
	srand((int)time(NULL));
	dodajOrganizmy(4);
	rysujSwiat();
	do 
	{		
		wejscie = _getch();

		switch (wejscie)
		{
		case -32:
			wejscie = _getch();
			wykonajTure();
			break;
		case 'u':
			gracz->aktywujUmiejetnosc();
			break;
		case 'z':
			zapisz();
			break;
		case 'w':
			wczytaj();
			break;
		}

		rysujSwiat();
		wypiszKomunikaty();
		
		
	} while (wejscie != '\x1B' && gracz->czyMartwy()==false);
	przesunKursorDo(1, startY + wysokosc + 10);
}

void Swiat::rysujSwiat()
{
	system("cls");
	std::list<Organizm*>::iterator it1;
	przesunKursorDo(startX + szerokosc + 3, 1);
	std::cout << "Autor projektu: Piotr Wojciechowski 175757";
	for (it1 = lista.begin(); it1 != lista.end(); ++it1) 
	{
		(*it1)->narysuj();
	}
	rysujRamke();
	rysujLegende();
}

void Swiat::wypiszKomunikaty()
{
	std::list<std::string>::iterator it;
	int i = 0;
	for (it = komunikaty.begin(); it != komunikaty.end(); it++, i++) 
	{
		przesunKursorDo(startX + szerokosc + 3, 3 + i);
		std::cout << (*it);
	}
	komunikaty.clear();
}

void Swiat::wykonajTure()
{
	lista.sort([](Organizm* a, Organizm* b) 
	{
		if (a->getIni() != b->getIni())
			return (a->getIni() > b->getIni());
		else
			return (a->getWiek() > b->getWiek());
	});
	std::list<Organizm*>::iterator it1;
	std::list<Organizm*> martweOrganizmy;
	for (it1 = lista.begin(); it1 != lista.end(); it1++) 
	{
		if ((*it1)->czyMartwy() == true) 
		{
			martweOrganizmy.push_back((*it1));
		}
		else 
		{
			(*it1)->akcja();
			(*it1)->zwiekszWiek(1);
		}
	}
	std::list<Organizm*>::iterator it2;
	for (it2 = martweOrganizmy.begin(); it2 != martweOrganizmy.end(); ++it2) 
	{
 		usun((*it2));
	}
}

void Swiat::dodajOrganizm(Organizm* org) 
{
	Organizm* cel = tab[org->getX()][org->getY()];
	if (cel != nullptr && cel->czyMartwy()==false)
		tab[org->getX()][org->getY()]->zabij();

	lista.push_back(org);
	tab[org->getX()][org->getY()] = org;
}

void Swiat::dodajOrganizmy(int ile) 
{
	for (int i = 0; i < ile; i++) 
	{		
		dodajOrganizm(new Owca(rand() % szerokosc, rand() % wysokosc, (*this)));
		dodajOrganizm(new Wilk(rand() % szerokosc, rand() % wysokosc, (*this)));
		dodajOrganizm(new Lis(rand() % szerokosc, rand() % wysokosc, (*this)));
		dodajOrganizm(new Zolw(rand() % szerokosc, rand() % wysokosc, (*this)));
		dodajOrganizm(new Antylopa(rand() % szerokosc, rand() % wysokosc, (*this)));
		dodajOrganizm(new Trawa(rand() % szerokosc, rand() % wysokosc, (*this)));
		dodajOrganizm(new Mlecz(rand() % szerokosc, rand() % wysokosc, (*this)));
		dodajOrganizm(new WilczeJagody(rand() % szerokosc, rand() % wysokosc, (*this)));
		dodajOrganizm(new BarszczSosnowskiego(rand() % szerokosc, rand() % wysokosc, (*this)));
		dodajOrganizm(new Guarana(rand() % szerokosc, rand() % wysokosc, (*this)));
	}	
	gracz = new Czlowiek(rand() % szerokosc, rand() % wysokosc, (*this));
	dodajOrganizm(gracz);
}

void Swiat::usunOrganizmy() 
{
	for (int i = 0; i < wysokosc; i++) 
	{
		for (int j = 0; j < szerokosc; j++) 
		{
			if (dynamic_cast<Organizm*>(tab[i][j]) != nullptr)
				delete tab[i][j];
		}
	}
}

void Swiat::oproznij(int x, int y) 
{
	tab[x][y] = nullptr;
}

void Swiat::usun(Organizm* org) 
{
	Organizm* pom = org;
	lista.remove(org);
	if (tab[org->getX()][org->getY()] == org) 
		oproznij(org->getX(), org->getY());
}

void Swiat::przesun(int x, int y, Organizm* org) 
{
	if (org->getX() == x && org->getY() == y) return;
	if (tab[x][y] == nullptr || tab[x][y]->czyMartwy()) 
	{
		tab[x][y] = org;
		tab[org->getX()][org->getY()] = nullptr;
		org->setX(x);
		org->setY(y);
	}
	else org->kolizja(tab[x][y]);
}

void Swiat::zapisz() 
{
	FILE* plik;
	fopen_s(&plik,"save.txt", "w");
	fprintf(plik, "%d,%d,%d,%d\n", startX, startY, szerokosc, wysokosc);
	fprintf(plik, "%d,%d,%d,%d,%d\n", gracz->getX(), gracz->getY(),
		gracz->getSila(), gracz->getWiek(), gracz->getLicznik());
	std::list<Organizm*>::iterator it1;
	Organizm* org;
	fprintf(plik, "%d\n", lista.size()-1);
	for (it1 = lista.begin(); it1 != lista.end(); it1++)
	{
		org = (*it1);
		if(org!=gracz)
		{
			fprintf(plik, "%d,%d,%d,%d,%d\n",(int)(org->getSymbol()), 
				org->getX(), org->getY(), org->getSila(), org->getWiek());
		}		
	}

	fclose(plik);
	dodajKomunikat("Zapisano stan gry");
}

void Swiat::wczytaj()
{
	oproznijTablice();
	lista.clear();
	std::list<Organizm*> nowa_lista;

	FILE* plik;
	Organizm* org;
	fopen_s(&plik,"save.txt", "r");
	int x, y, szerokosc, wysokosc, sila, wiek, licznik, ilosc;
	int symbol;

	fscanf_s(plik, "%d,%d,%d,%d", &x, &y, &szerokosc, &wysokosc);
	this->startX = x;
	this->startY = y;
	this->szerokosc = szerokosc;
	this->wysokosc = wysokosc;

	stworzTablice(szerokosc, wysokosc);

	fscanf_s(plik, "%d,%d,%d,%d,%d", &x, &y, &sila, &wiek, &licznik);
	gracz = new Czlowiek(x, y, (*this));
	gracz->setSila(sila);
	gracz->setWiek(wiek);
	gracz->setLicznik(licznik);
	dodajOrganizm(gracz);

	fscanf_s(plik, "%d\n", &ilosc);
	for (int i = 0; i < ilosc; i++)
	{
		fscanf_s(plik, "%d,%d,%d,%d,%d", &symbol, &x, &y, &sila, &wiek);
		org = wybierzOrganizm((char)symbol, x, y);
		org->setSila(sila);
		org->setWiek(wiek);
		dodajOrganizm(org);
	}
	fclose(plik);
	dodajKomunikat("Wczytano stan gry");
}

Organizm* Swiat::wybierzOrganizm(char symbol, int x, int y) 
{
	Organizm* org = nullptr;
	switch (symbol)
	{
	case 'A':
		org = new Antylopa(x, y, (*this));
		break;
	case 'L':
		org = new Lis(x, y, (*this));
		break;
	case 'O':
		org = new Owca(x, y, (*this));
		break;
	case 'W':
		org = new Wilk(x, y, (*this));
		break;
	case 'Z':
		org = new Zolw(x, y, (*this));
		break;
	case '$':
		org = new BarszczSosnowskiego(x, y, (*this));
		break;
	case '@':
		org = new Guarana(x, y, (*this));
		break;
	case '%':
		org = new WilczeJagody(x, y, (*this));
		break;
	case ';':
		org = new Mlecz(x, y, (*this));
		break;
	case '.':
		org = new Trawa(x, y, (*this));
		break;
	}
	return org;
}

int Swiat::getWysokosc() 
{
	return wysokosc;
}

int Swiat::getSzerokosc() 
{
	return szerokosc;
}

int Swiat::getStartX() 
{
	return startX;
}

int Swiat::getStartY() 
{
	return startY;
}

Organizm* Swiat::getTabAt(int x, int y) 
{
	return tab[x][y];
}

char Swiat::getWejscie()
{
	return wejscie;
}

void Swiat::dodajKomunikat(std::string komunikat) 
{
	komunikaty.push_back(komunikat);
}

void Swiat::przesunKursorDo(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Swiat::narysujZnak(int x, int y, char z) 
{
	przesunKursorDo(x, y);
	putchar(z);
}

void Swiat::rysujRamke() 
{
	for (int i = 0; i < szerokosc; i++) 
	{
		narysujZnak(startX, startY + i + 1, '#');
		narysujZnak(startX + wysokosc + 1, startY + i + 1, '#');
	}
	for (int i = 0; i < wysokosc + 2; i++) 
	{
		narysujZnak(startX + i, startY, '#');
		narysujZnak(startX + i, startY + szerokosc + 1, '#');
	}
}

void Swiat::rysujLegende()
{
	przesunKursorDo(1, startY + wysokosc + 2);
	std::cout << "Legenda:\n$ - barszcz\n@ - guarana\n; - mlecz\n. - trawa\n% - wilcze jagody";
}

void Swiat::stworzTablice(int szerokosc, int wysokosc) 
{
	tab = new Organizm**[szerokosc];
	for (int i = 0; i < szerokosc; i++)
	{
		tab[i] = new Organizm*[wysokosc];
	}
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			tab[i][j] = nullptr;
		}
	}
}

void Swiat::oproznijTablice() {
	usunOrganizmy();
	for (int i = 0; i < wysokosc; i++)
	{
		delete tab[i];
	}
	delete tab;
}

Swiat::~Swiat()
{
	oproznijTablice();
}
