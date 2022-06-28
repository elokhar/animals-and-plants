#pragma once
#include "Zwierze.h"


class Owca :
	public Zwierze
{
protected:
	Organizm* potomek(int x, int y) override;
public:
	Owca(int x, int y, Swiat& w);
	std::string gatunek() override;
	~Owca();
};

