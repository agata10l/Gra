#include<iostream>
#include "plansza.h"

/*Tworzy planszê wpisuj¹c do pól 0-GRACZ_NIEZNANY*/
Plansza::Plansza(int rozmiar,int ile_w_rzedzie) :
	rozmiar_(rozmiar),
	liczba_ruchow_(rozmiar*rozmiar),
	ile_w_rzedzie_(ile_w_rzedzie),
	ost_ruch_{rozmiar*rozmiar}
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

	if (plansza_[x][y] == ' ')
	{
		plansza_[x][y] = gracz;

		ost_ruch_[0] = x;
		ost_ruch_[1] = y;

		--liczba_ruchow_;

		return true;
	}
	return false;
}

bool Plansza::usun_ruch(int x, int y)
{
	if (plansza_[x][y] != ' ')
	{
		plansza_[x][y] = ' ';

		++liczba_ruchow_;

		ost_ruch_[0] = rozmiar_;
		ost_ruch_[1] = rozmiar_;

		return true;
	}
	return false;
}

char Plansza::zwroc_plansze(int x, int y)
{
	return plansza_[x][y];
}

void Plansza::wyswietl()
{
		system("cls");

		int i, j, k;
		std::cout << "\t\tGra Kolko i Krzyzyk! (" << rozmiar_ << "x" << rozmiar_ << ")\n";
		std::cout << "\tTY - X\t|\tKOMPUTER - O" << "\n\n";

		std::cout << "\t";
		for (k = 0; k < rozmiar_; k++)
		{
			std::cout << ((k > 9) ? ("    ") : ("     ")) << k;
		}

		std::cout << "\n\t   ";
		for (k = 0; k < rozmiar_; k++)
		{
			std::cout << "______";
		}

		std::cout << "\n";
		for (i = 0; i < rozmiar_; i++)
		{
			std::cout << "\t  |";
			for (k = 0; k < rozmiar_; k++)
			{
				std::cout << "     |";
			}

			std::cout << "\n\t" << i;
			std::cout << ((i > 9) ? ("|") : (" |"));

			for (j = 0; j < rozmiar_; j++)
			{
				std::cout << "  " << plansza_[i][j] << "  |";
			}

			std::cout << "\n\t  |";
			for (k = 0; k < rozmiar_; k++)
			{
				std::cout << "_____|";
			}

			std::cout << "\n";
		}
}
/*Funkcja sprawdzajaca wygranego:
//Gdy ostatni ruch jest rowny rozmiarowi to zwraca 0
//Gdy liczba ruchów jest mniejsza od 0 b¹dŸ równa 0 to zwraca 0, jeœli nie to zwraca N(gra trwa)*/
char Plansza::sprawdzenie_wygranego()
{
	int tmp, a, b;

	if (ost_ruch_[0] == rozmiar_)
	{
		return 0;
	}

	for (int i = -1; i < 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i >= 0 && j >= 0)
			{
				return (liczba_ruchow_ <= 0) ? (GRA_TRWA) : (0);
			}

			tmp = 1;
			a = i;
			b = j;
			while (ost_ruch_[0] + a >= 0 &&
				ost_ruch_[0] + a < rozmiar_ &&
				ost_ruch_[1] + b >= 0 &&
				ost_ruch_[1] + b < rozmiar_ &&
				plansza_[ost_ruch_[0] + a][ost_ruch_[1] + b] == plansza_[ost_ruch_[0]][ost_ruch_[1]])
			{
				++tmp;
				a += i;
				b += j;
			}

			a = i;
			b = j;
			while (ost_ruch_[0] - a >= 0 &&
				ost_ruch_[0] - a < rozmiar_ &&
				ost_ruch_[1] - b >= 0 &&
				ost_ruch_[1] - b < rozmiar_ &&
				plansza_[ost_ruch_[0] - a][ost_ruch_[1] - b] == plansza_[ost_ruch_[0]][ost_ruch_[1]])
			{
				++tmp;
				a += i;
				b += j;

			}

			if (tmp >= ile_w_rzedzie_)
			{
				return plansza_[ost_ruch_[0]][ost_ruch_[1]];
			}
		}
	}

	return 0;
}

int Plansza::zwroc_rozmiar()
{
	return rozmiar_;
}


