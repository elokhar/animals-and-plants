#pragma once
#include "Roslina.h"


class Trawa :
	public Roslina
{
protected:
	Organizm* potomek(int x, int y) override; 
public:
	Trawa(int x, int y, Swiat& w);
	std::string gatunek() override;
	~Trawa();
};

