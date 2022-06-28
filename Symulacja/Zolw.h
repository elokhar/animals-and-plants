#pragma once
#include "Zwierze.h"


class Zolw :
	public Zwierze
{
protected:
	Organizm* potomek(int x, int y) override;
public:
	Zolw(int x, int y, Swiat& w);
	void akcja() override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
	std::string gatunek() override;
	~Zolw();
};

