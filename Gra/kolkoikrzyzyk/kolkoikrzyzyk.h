#ifndef KOLKOIKRZYZYK_H
#define KOLKOIKRZYZYK_H

#include "gracz/gracz.h"
#include "plansza/plansza.h"
#include"MinMax/MinMax.h"

class Kolkoikrzyzyk
{
public:
	Kolkoikrzyzyk();
	~Kolkoikrzyzyk();

	void inicializacja();

private:
	Plansza* plansza_;
	MinMax* minmax_;
	int ile_w_rzedzie_;
	char gracz_;

	char start();
	char wykonuj_ruch();

};

#endif