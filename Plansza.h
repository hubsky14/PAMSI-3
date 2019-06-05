#pragma once
#include "PolePlanszy.h"
class Plansza : public PolePlanszy
{
	void numeruj();
	
	void sprawdzRzedy();
	void sprawdzKolumny();
	void sprawdzSkosy();

public:
	PolePlanszy** pola;
	int rozmiar;
	int win_row;
	bool rzadPelny(int rzad);
	int znajdzWRzedzie();
	bool kolumnaPelna(int kolumna);
	int znajdzWKolumnie();

	void rysujPlansze();
	bool zmienWartosc(int num1, int num2, char war);
	void sprawdzPlansze();
	Plansza(int roz, int win);
	~Plansza();
};

