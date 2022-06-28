#pragma once
#include "Zwierze.h"


class Lis :
	public Zwierze
{
protected:
	Organizm* potomek(int x, int y) override;
public:
	Lis(int x, int y, Swiat& sw);
	void ruch() override;
	std::string gatunek() override;
	~Lis();
};

