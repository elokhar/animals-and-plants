#pragma once
#include "Roslina.h"


class Guarana :
	public Roslina
{
protected:
	Organizm* potomek(int x, int y) override;
public:
	Guarana(int x, int y, Swiat& w);
	char efektZjedzenia(Organizm* zjadajacy) override;
	std::string gatunek() override;
	~Guarana();
};

