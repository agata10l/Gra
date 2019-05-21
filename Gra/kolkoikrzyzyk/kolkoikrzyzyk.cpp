#include<iostream>
#include<fstream>

#include "kolkoikrzyzyk.h"

Kolkoikrzyzyk::~Kolkoikrzyzyk()
{
	delete plansza_;
}

void Kolkoikrzyzyk::inicializacja()
{
	int rozmiar;
	char wybor_gracza;
	std::cout << "Witaj w grze Kolko i Krzyzyk !" << std::endl;
	std::cout << "Podaj rozmiar planszy:" << "\t";
	std::cin >> rozmiar;

	plansza_ = new Plansza(rozmiar);

	std::cout << "Podaj ilosc znakow w rzedzie:" << "\t";
	std::cin >> ile_w_rzedzie_;

	std::cout << "Wybierz zaczynajacego:" << std::endl;
	std::cout << "[X] -ty" << std::endl;
	std::cout << "[Y] -komputer" << std::endl;
	std::cin >> wybor_gracza;
	if (wybor_gracza == 'x' || wybor_gracza == 'X')
	{
		gracz_ = GRACZ_CZLOWIEK;
	}
	else
	{
		gracz_ = GRACZ_AI;
	}

	start();
}

char Kolkoikrzyzyk::start()
{
	while (wykonuj_ruch() == 0) plansza_->wyswietl();

	return 0;
}

char Kolkoikrzyzyk::wykonuj_ruch()
{
	int x, y;
	bool czyWygral;

	if (gracz_ == GRACZ_CZLOWIEK)
	{
		do
		{
			std::cout << "Podaj pozycjê:";
			std::cin >> x >> y;
			
		} while (plansza_->dodaj_ruch(x, y, gracz_) == false);

		if (plansza_->czy_wygrana(gracz_, ile_w_rzedzie_))
		{
			return gracz_;
		}
		gracz_ = GRACZ_AI;
	}
	else if (gracz_ == GRACZ_AI)
	{
		do
		{
			std::cout << "Podaj pozycjê:";
			std::cin >> x >> y;

		} while (plansza_->dodaj_ruch(x, y, gracz_) == false);
		
		if (plansza_->czy_wygrana(gracz_, ile_w_rzedzie_))
		{
			return gracz_;
		}
		gracz_ = GRACZ_CZLOWIEK;

	}

	if (plansza_->czy_remis())
	{
		return GRACZ_NIEZNANY;
	}

	return 0;
}
