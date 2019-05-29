#include "MinMax.h"
#include"C:/Users/Agata/source/repos/Gra/Gra/kolkoikrzyzyk/gracz/gracz.h"

#include <vector>
#include <iostream>

MinMax_ruch_t MinMax::ruch_gracza_AI(Plansza* plansza)
{
	return znajdz_najlepszy_ruch(plansza, GRACZ_AI);
}

MinMax_ruch_t MinMax::znajdz_najlepszy_ruch(Plansza* plansza, char gracz)
{
	char wygrany = plansza->zwroc_wygranego();
	std::vector<MinMax_ruch_t> ruchy;
	int najlepszy_wynik;
	int najlepszy_ruch;

	if (wygrany == GRACZ_AI)
	{
		return MinMax_ruch_t(1);
	}
	else if (wygrany == GRACZ_CZLOWIEK)
	{
		return MinMax_ruch_t(-1);
	}
	else if (wygrany == REMIS)
	{
		return MinMax_ruch_t(0);
	}

	for (int y = 0; y < plansza->zwroc_rozmiar(); ++y)
	{
		for (int x = 0; x < plansza->zwroc_rozmiar(); ++x)
		{
			if (plansza->zwroc_plansze(x, y) == GRACZ_NIEZNANY)
			{
				MinMax_ruch_t ruch(0);

				ruch.x = x;
				ruch.y = y;

				plansza->dodaj_ruch(x, y, gracz);

				if (gracz == GRACZ_AI)
				{
					ruch.wynik = znajdz_najlepszy_ruch(plansza, GRACZ_CZLOWIEK).wynik;
				}
				else if (gracz == GRACZ_CZLOWIEK)
				{
					ruch.wynik = znajdz_najlepszy_ruch(plansza, GRACZ_AI).wynik;
				}

				ruchy.push_back(ruch);

				plansza->usun_ruch(x, y);
			}
		}
	}

	if (gracz == GRACZ_AI)
	{
		najlepszy_wynik = INT32_MIN;

		for (int i = 0; i < ruchy.size(); ++i)
		{
			if (ruchy[i].wynik > najlepszy_wynik)
			{
				najlepszy_ruch = i;
				najlepszy_wynik = ruchy[i].wynik;
			}
		}
	}
	else
	{
		najlepszy_wynik = INT32_MAX;

		for (int i = 0; i < ruchy.size(); ++i)
		{
			if (ruchy[i].wynik < najlepszy_wynik)
			{
				najlepszy_ruch = i;
				najlepszy_wynik = ruchy[i].wynik;
			}
		}
	}
	return ruchy[najlepszy_ruch];
}