#pragma once
#include "Plansza.h"
class Komputer
{
	int rzad_max;
	int kol_max;
	int skos_max;
	int najlepszyRzad(Plansza & plansza);
	int najlepszaKolumna(Plansza & plansza);
	int najlepszySkos(Plansza & plansza);
public:
	bool ruch(Plansza & plansza);
	Komputer();
	~Komputer();
};

