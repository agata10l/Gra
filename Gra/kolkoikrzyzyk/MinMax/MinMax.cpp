#include "MinMax.h"
#include"C:/Users/Agata/source/repos/Gra/Gra/kolkoikrzyzyk/gracz/gracz.h"

#include <vector>
#include <iostream>


MinMax::MinMax() :
	maks_glebokosc_(0)
{
}

MinMax_ruch_t MinMax::najlepszy_ruch(Plansza* plansza)
{
	return znajdz_najlepszy_ruch(plansza, -10000, 10000, 0, 0, GRACZ_AI);
}

MinMax_ruch_t MinMax::znajdz_najlepszy_ruch(Plansza* plansza, int alpha, int beta, int glebokosc, bool rec, char gracz)
{
	char wygrany = plansza->sprawdzenie_wygranego();
	std::vector<MinMax_ruch_t> ruchy;
	int najlepszy_wynik=0;
	unsigned najlepszy_ruch=0;
	MinMax_ruch_t ruch;

	glebokosc += rec;

	if (gracz != 0)
	{
		return (najlepszy_wynik == -1) ? MinMax_ruch_t(-1000 * najlepszy_wynik - 20 * glebokosc) : MinMax_ruch_t(-1000 * najlepszy_wynik + 20 * glebokosc);
	}

	if (gracz == GRACZ_AI)
	{
		najlepszy_wynik = alpha;

		for (unsigned x = 0; x < plansza->zwroc_rozmiar(); ++x)
		{
			for (unsigned y = 0; y < plansza->zwroc_rozmiar(); ++y)
			{
				if (plansza->zwroc_plansze(x, y) == GRACZ_NIEZNANY)
				{
					plansza->dodaj_ruch(x, y, gracz);

					ruch.x = x;
					ruch.y = y;
					ruch.wynik = znajdz_najlepszy_ruch(plansza, najlepszy_wynik, beta, glebokosc, true, GRACZ_CZLOWIEK).wynik;

					plansza->usun_ruch(x, y);

					ruchy.push_back(ruch);

					if (ruch.wynik > najlepszy_wynik)
					{
						ruch.wynik = najlepszy_wynik;
					}
					if (beta <= najlepszy_wynik)
					{
						x = y = plansza->zwroc_rozmiar();
					}
				}
			}
		}

		najlepszy_wynik = INT_MIN;
		for (int q = 0; q < ruchy.size(); ++q)
		{
			if (ruchy[q].wynik > najlepszy_wynik)
			{
				najlepszy_ruch = q;
				najlepszy_wynik = ruchy[q].wynik;
			}
		}
	}
	else
	{
		najlepszy_wynik = beta;

		for (int x = 0; x < plansza->zwroc_rozmiar(); ++x)
		{
			for (int y = 0; y < plansza->zwroc_rozmiar(); ++y)
			{
				if (plansza->zwroc_plansze(x, y) == GRACZ_NIEZNANY)
				{
					plansza->dodaj_ruch(x, y, gracz);

					ruch.x = x;
					ruch.y = y;
					ruch.wynik = znajdz_najlepszy_ruch(plansza, najlepszy_wynik, beta, glebokosc, true, GRACZ_CZLOWIEK).wynik;

					plansza->usun_ruch(x, y);

					ruchy.push_back(ruch);

					if (ruch.wynik < najlepszy_wynik)
					{
						ruch.wynik = najlepszy_wynik;
					}
					if (alpha >= najlepszy_wynik)
					{
						x = y = plansza->zwroc_rozmiar();
					}
				}
			}
		}

		najlepszy_wynik = INT_MAX;
		for (int q = 0; q < ruchy.size(); ++q)
		{
			if (ruchy[q].wynik < najlepszy_wynik)
			{
				najlepszy_ruch = q;
				najlepszy_wynik = ruchy[q].wynik;
			}
		}
	}

	return ruchy[najlepszy_ruch];
}
	

	