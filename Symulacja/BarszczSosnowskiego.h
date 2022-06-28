#pragma once
#include "Roslina.h"


class BarszczSosnowskiego :
	public Roslina
{
protected:
	Organizm *potomek(int x, int y) override;
public:
	BarszczSosnowskiego(int x, int y, Swiat& w);
	char efektZjedzenia(Organizm *zjadajacy) override;
	void akcja() override;
	std::string gatunek() override;
	~BarszczSosnowskiego();
};

