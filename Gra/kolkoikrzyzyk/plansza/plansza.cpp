#include<iostream>
#include "plansza.h"


Plansza::Plansza(int rozmiar) :
	rozmiar_(rozmiar),
	liczba_ruchow_(0)
{
	plansza_ = new char*[rozmiar_];
	for (int i = 0; i < rozmiar_; i++)
	{
		plansza_[i] = new char[rozmiar_];

		for (int j = 0; j < rozmiar_; j++)
		{
			plansza_[i][j] = GRACZ_NIEZNANY;
		}
	}
}

Plansza::~Plansza()
{
	for (int i = 0; i < rozmiar_; i++)
	{
		delete[] plansza_[i];
	}
	delete[] plansza_;
}

bool Plansza::dodaj_ruch(int x, int y, char gracz)
{

	if (plansza_[x][y] == GRACZ_NIEZNANY)
	{
		plansza_[x][y] = gracz;
		++liczba_ruchow_;
		return true;
	}
	return false;
}

bool Plansza::usun_ruch(int x, int y)
{
	if (plansza_[x][y] != GRACZ_NIEZNANY)
	{
		plansza_[x][y] = GRACZ_NIEZNANY;
		--liczba_ruchow_;
		return true;
	}
	return false;
}

void Plansza::wyswietl()
{
	system("cls");

	for (int i = 0; i < rozmiar_; i++)
	{
		for (int j = 0; j < rozmiar_; j++)
		{
			std::cout<< plansza_[i][j];
		}
		std::cout << std::endl;
	}
}

bool Plansza::czy_wygrana(char gracz,int ile_w_rzedzie)
{
	int w_rzedzie=0;

// Wiersze
	for (int i = 0; i < rozmiar_; i++)
	{
		for (int j = 0; j < rozmiar_; j++)
		{
			if (plansza_[i][j] == gracz)
			{
				w_rzedzie++;
				if (w_rzedzie == ile_w_rzedzie)
				{
					return true;
				}

			}
			else
			{
				w_rzedzie = 0;
			}
		}
	}

// Kolumny
	w_rzedzie = 0;
	for (int i = 0; i < rozmiar_; i++)
	{
		for (int j = 0; j< rozmiar_; j++)
		{
			if (plansza_[j][i] == gracz)
			{
				w_rzedzie++;
				if (w_rzedzie == ile_w_rzedzie)
				{
					return true;
				}
			}
			else
			{
				w_rzedzie = 0;
			}
		}
	}

//Przekatna 1
	unsigned x, y;
	for (int i = 0; i < rozmiar_; i++)
	{
		w_rzedzie = 0;
		x = i;
		y = 0;
		while (x < rozmiar_)
		{
			if (gracz == plansza_[x++][y++])
			{
				if (++w_rzedzie == ile_w_rzedzie)
				{
					return true;
				}
			}
			else
			{
				w_rzedzie = 0;
			}
		}
	}
	for (int i = 0; i < rozmiar_; i++)
	{
		w_rzedzie = 0;
		x = 0;
		y = i;
		while (y < rozmiar_)
		{
			if (gracz == plansza_[x++][y++])
			{
				if (++w_rzedzie == ile_w_rzedzie)
				{
					return true;
				}
			}
			else
			{
				w_rzedzie = 0;
			}
		}
	}

// Przekatna 2
	for (int i = 0; i < rozmiar_; i++)
	{
		w_rzedzie = 0;
		x = 0;
		y = rozmiar_ - i;
		while (y < rozmiar_)
		{
			if (gracz == plansza_[x++][y--])
			{
				if (++w_rzedzie == ile_w_rzedzie)
				{
					return true;
				}
			}
			else
			{
				w_rzedzie = 0;
			}
		}
	}
	for (int i = 0; i < rozmiar_; i++)
	{
		w_rzedzie = 0;
		x = rozmiar_ - 1;
		y = i;
		while (y < rozmiar_)
		{
			if (gracz == plansza_[x--][y++])
			{
				if (++w_rzedzie == ile_w_rzedzie)
				{
					return true;
				}
			}
			else
			{
				w_rzedzie = 0;
			}
		}
	}
	return false;
}

bool Plansza::czy_remis()
{
	return liczba_ruchow_ == rozmiar_ * rozmiar_;
}

