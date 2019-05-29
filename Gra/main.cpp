#include<iostream>
#include "kolkoikrzyzyk/kolkoikrzyzyk.h"

int main()
{
	Kolkoikrzyzyk a;
	MinMax minmax;
	MinMax_ruch_t ruch;
	int x, y;

	a.inicializacja();
	Plansza p(3, 3);
	while (1)
	{
		do
		{
			std::cin >> x >> y;
		} while (p.dodaj_ruch(x, y, GRACZ_CZLOWIEK) == false);
		p.wyswietl();

		ruch = minmax.ruch_gracza_AI(&p);
		p.dodaj_ruch(ruch.x, ruch.y, GRACZ_AI);
		p.wyswietl();
	}


	return 0;

	system("pause");

	return 0;
}