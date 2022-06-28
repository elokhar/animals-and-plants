#pragma once
#include "Zwierze.h"


class Wilk :
	public Zwierze
{
public:
	Wilk(int x, int y, Swiat& w);
	Organizm* potomek(int x, int y) override;
	std::string gatunek() override;
	~Wilk();
};

