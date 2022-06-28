#pragma once
#include "Organizm.h"


class Zwierze :
	public Organizm
{
protected:
	virtual void ruch();
public:
	using Organizm::Organizm;
	virtual bool ucieczka();
	bool rozmnazanie();
	bool czyOdbilAtak(Organizm * atakujacy);
	virtual void akcja() override;

	~Zwierze();
};

