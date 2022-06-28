#pragma once
#include "Zwierze.h"


class Czlowiek :
	public Zwierze
{
protected:
	int licznikUmiejetnosci = -5;
	void ruch(char kierunek);
	int zasiegRuchu();
	Organizm* potomek(int x, int y) override;
public:
	Czlowiek(int x, int y, Swiat& sw);
	void akcja() override;
	std::string gatunek() override;
	void aktywujUmiejetnosc();
	int getLicznik();
	void setLicznik(int l);
	~Czlowiek();
};

