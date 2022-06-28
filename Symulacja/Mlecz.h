#pragma once
#include "Roslina.h"


class Mlecz :
	public Roslina
{
protected:
	Organizm* potomek(int x, int y) override;
public:
	Mlecz(int x, int y, Swiat& w);
	void akcja() override;
	std::string gatunek() override;
	~Mlecz();
};

