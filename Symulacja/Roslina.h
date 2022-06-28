#pragma once
#include "Organizm.h"


class Roslina
	: public Organizm
{
protected:
		float prawdopodobienstwo;
		void rozsiej(float p);
public:
	Roslina(int x, int y, int s, float p, char z, Swiat& w);
	virtual char efektZjedzenia(Organizm * zjadajacy);
	virtual void akcja() override;
	~Roslina();
};

