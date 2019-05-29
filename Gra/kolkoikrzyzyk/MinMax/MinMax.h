#ifndef MINMAX_H
#define MINMAX_H

#include"C:/Users/Agata/source/repos/Gra/Gra/kolkoikrzyzyk/plansza/plansza.h"

struct MinMax_ruch_t
{
	int x;
	int y;

	int wynik;

	MinMax_ruch_t(int wynik = 0) :
		x(0),
		y(0),
		wynik(wynik)
	{};
};

class MinMax
{
public:
	MinMax_ruch_t ruch_gracza_AI(Plansza* plansza);

private:
	MinMax_ruch_t znajdz_najlepszy_ruch(Plansza* plansza, char gracz);
};

#endif