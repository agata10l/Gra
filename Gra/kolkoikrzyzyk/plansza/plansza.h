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
	

	char sprawdzenie_wygranego();
	char zwroc_plansze(int x, int y); 
	int zwroc_rozmiar();

	void wyswietl();

private:
	char** plansza_;
	unsigned  rozmiar_;
	int liczba_ruchow_;
	int ile_w_rzedzie_;
	int ost_ruch_[2];

};

#endif

