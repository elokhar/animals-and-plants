#pragma once
#include "Zwierze.h"


class Antylopa :
	public Zwierze
{
protected:
	Organizm* potomek(int x, int y) override;
public:
	Antylopa(int x, int y, Swiat& w);
	void ruch() override;	
	bool ucieczka() override;
	std::string gatunek() override;
	~Antylopa();
};

