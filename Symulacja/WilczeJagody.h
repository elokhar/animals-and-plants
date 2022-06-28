#pragma once
#include "Roslina.h"


class WilczeJagody :
	public Roslina
{
protected:
	Organizm* potomek(int x, int y) override;
public:
	WilczeJagody(int x, int y, Swiat& w);
	char efektZjedzenia(Organizm *zjadajacy) override;
	std::string gatunek() override;
	~WilczeJagody();
};

