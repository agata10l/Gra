#include<iostream>
#include<fstream>

#include "kolkoikrzyzyk.h"
#include "MinMax/MinMax.h"

using namespace std;

Kolkoikrzyzyk::Kolkoikrzyzyk() :
	plansza_(nullptr),
	MinMax_(nullptr)
{
}

void Kolkoikrzyzyk::start()
{
	inicializacja_();
	gra_();
}

void Kolkoikrzyzyk::inicializacja_()
{
	unsigned rozmiar;
	unsigned ile_w_rzedzie;

	std::cout << "\tKolko i krzyzyk!\n\n";
	std::cout << "Podaj rozmiar tablicy: ";
	std::cin >> rozmiar;
	if (rozmiar < 3 || rozmiar > 9)
	{
		std::cout << "Zly rozmiar, podaj nowy:";
		std::cin >> rozmiar;
	}

	std::cout << "Podaj rzad: ";
	std::cin >> ile_w_rzedzie;
	if (ile_w_rzedzie < 3 || ile_w_rzedzie > 9)
	{
		std::cout << "Zly rzad, podaj nowy:";
		std::cin >> ile_w_rzedzie;
	}

	 plansza_ = new Plansza(rozmiar, ile_w_rzedzie);
	 MinMax_= new MinMax();
}

void Kolkoikrzyzyk::gra_()
{
	char gracz = GRACZ_CZLOWIEK;
	unsigned x, y;

	while (plansza_->sprawdzenie_wygranego() == 0)
	{
		plansza_->wyswietl();

		if (gracz == GRACZ_CZLOWIEK)
		{
			std::cout << "Twoja kolej (rzad,kolumna): ";
			do
			{
				std::cin >> x >> y;
			} while (plansza_->dodaj_ruch(x, y, GRACZ_CZLOWIEK) == false);

			gracz = GRACZ_AI;
		}
		else if (gracz == GRACZ_AI)
		{
			MinMax_ruch_t ruch= MinMax_->najlepszy_ruch(plansza_);
			plansza_->dodaj_ruch(ruch.x, ruch.y, GRACZ_AI);

			gracz = GRACZ_CZLOWIEK;
		}
	}

	plansza_->wyswietl();
	std::cout << "Wygral: " << plansza_->sprawdzenie_wygranego();
}

