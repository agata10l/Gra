#ifndef KOLKOIKRZYZYK_H
#define KOLKOIKRZYZYK_H

#include "gracz/gracz.h"
#include "plansza/plansza.h"
#include"MinMax/MinMax.h"

class Kolkoikrzyzyk
{
public:
	Kolkoikrzyzyk();
	
	void start();

private:

	void inicializacja_();
	void gra_();

	Plansza* plansza_;
	MinMax* MinMax_;
	
};

#endif