#ifndef PLANSZA_H
#define PLANSZA_H

#include"../gracz/gracz.h"

class Plansza
{
public:
	Plansza(int rozmiar,int ile_w_rzedzie);
	~Plansza();

	bool dodaj_ruch(int x, int y, char gracz);
	bool usun_ruch(int x, int y);
	void wyswietl();

	bool czy_wygrana(char gracz);
	char zwroc_wygranego();
	char zwroc_plansze(int x, int y);
	bool czy_remis();
	int zwroc_rozmiar();

private:
	char** plansza_;
	int rozmiar_;
	int liczba_ruchow_;
	int ile_w_rzedzie_;

};

#endif
