#ifndef PLANSZA_H
#define PLANSZA_H

#include"../gracz/gracz.h"

class Plansza
{
public:
	Plansza(int rozmiar = 3);
	~Plansza();

	bool dodaj_ruch(int x, int y, char gracz);
	bool usun_ruch(int x, int y);
	void wyswietl();

	bool czy_wygrana(char gracz, int ile_w_rzedzie);
	bool czy_remis();

private:
	char** plansza_;
	int rozmiar_;
	int liczba_ruchow_;

};

#endif
