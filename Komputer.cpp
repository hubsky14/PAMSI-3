#include "Komputer.h"
#include <iostream>


//sprawdza rzad w poszukiwaniu kolek gracza i najlepszej opcji
int Komputer::najlepszyRzad(Plansza & plansza)
{
	int licznik = 0;
	int bestWynik = 0;
	for (int i = 0; i < plansza.rozmiar; i++)
	{
		if (plansza.rzadPelny(i)) continue;
		for (int j = 0; j < plansza.rozmiar; j++)
		{
			if (plansza.pola[i][j].zwrocWartosc() == 'O') licznik++;
		}
		if (bestWynik <= licznik)
		{
			bestWynik = licznik;
			rzad_max = i+1; //przechowuje nr rzedu, gdzie grac ma najwiecej znakow
		}
		licznik = 0;

	}
	return bestWynik; //zwraca najlepszy wynik
}
//sprawdza kolumne w poszukiwaniu O gracza i najlepszej opcji
int Komputer::najlepszaKolumna(Plansza& plansza)
{
	int licznik = 0;
	int bestWynik = 0;
	for (int i = 0; i < plansza.rozmiar; i++)
	{
		if (plansza.kolumnaPelna(i)) continue;
		for (int j = 0; j < plansza.rozmiar; j++)
		{
			if (plansza.pola[j][i].zwrocWartosc() == 'O') licznik++;
		}
		if (bestWynik < licznik)
		{
			bestWynik = licznik;
			kol_max = i + 1;	//kolumna, gdzie gracz ma najwiecej znakow
		}
		licznik = 0;

	}
	return bestWynik;	//zwraca najlepsza opcje
}
//ruch komputera
bool Komputer::ruch(Plansza& plansza)
{
	int i = 1;
	int j = 1;
	i = plansza.znajdzWKolumnie();	
	j = plansza.znajdzWRzedzie();
	if (najlepszaKolumna(plansza) > najlepszyRzad(plansza)) //jesli kolumna ma lepszy wynik, wybierz ja
	{	//petle do postawinia X, biorace pod uwage pozycje uzytkownika
		for (i; i < plansza.rozmiar; i++)
		{
			if (plansza.zmienWartosc(i, kol_max, 'X')) return true;
		}
		i = plansza.znajdzWKolumnie();
		for (i; i > 0; i--)
		{
			if (plansza.zmienWartosc(i, kol_max, 'X')) return true;
		}
	}
	else //jesli rzad, wybierz go
	{	//petle stawiajace X, biorace pod uwage figury uzytkownika
		for (j; j < plansza.rozmiar; j++)
		{
			if (plansza.zmienWartosc(rzad_max, j, 'X')) return true;
		}
		j = plansza.znajdzWRzedzie();
		for (j; j > 0; j--)
		{
			if (plansza.zmienWartosc(rzad_max, j, 'X')) return true;
		}
	}
	return false;
}
//konstruktor
Komputer::Komputer(): skos_max(0), kol_max(0), rzad_max(0)
{
}

//destruktor
Komputer::~Komputer()
{
}

/*

//analiza ruchu komputera przez skos1 (zgodnie z analiza planszy na skosy)
int Komputer::najlepszySkos1(Plansza& plansza)
{
	int bestWynik = 0;
	int pom = 0;
	int pom2 = 0;
	int licznik = 0;
	for (int i = 0; i < plansza.rozmiar; i++, pom++, pom2 = 0)
	{
		for (int j = 0; j < plansza.rozmiar - pom; j++, pom2++)
		{
			if (plansza.pola[i + pom2][j].zwrocWartosc() == 'O') licznik++;
		}
		if (bestWynik < licznik)
		{
			bestWynik = licznik;
			skosa_max = i + 1;
		}
		licznik = 0;
	}
	return bestWynik;
}
//analiza ruchu komputera przez skos2(zgodnie z analiza planszy na skosy)
int Komputer::najlepszySkos2(Plansza& plansza)
{
	int bestWynik = 0;
	int pom = 0;
	int pom2 = 0;
	int licznik = 0;
	for (int i = 0; i < plansza.rozmiar; i++, pom++, pom2 = 0)
	{
		for (int j = 0; j < plansza.rozmiar - pom; j++, pom2++)
		{
			if (plansza.pola[j][i + pom2].zwrocWartosc() == 'O') licznik++;
		}
		if (bestWynik < licznik) {
			bestWynik = licznik;
			skosb_max = i + 1;
		}
		licznik = 0;
	} return bestWynik;
}
//analiza ruchu komputera przez skos3 (zgodnie z analiza planszy na skosy)

int Komputer::najlepszySkos3(Plansza& plansza)

{
	int bestWynik = 0;
	int pom = 0;
	int pom2 = 0;
	int licznik = 0;
	for (int i = 0; i < plansza.rozmiar; i++, pom++, pom2 = 0)
	{
		for (int j = 0; j < plansza.rozmiar - pom; j++, pom2++)
		{
			if (plansza.pola[i + j][plansza.rozmiar - pom2 - 1].zwrocWartosc() == 'O') licznik++;
		}
		if (bestWynik < licznik) {
			bestWynik = licznik;
			skosc_max = i + 1;
		}
		licznik = 0;
	}return bestWynik;
}
//analiza ruchu komputera przez skos4 (zgodnie z analiza planszy na skosy)

int Komputer::najlepszySkos4(Plansza& plansza)
{
	int bestWynik = 0;
	int pom = 0;
	int pom2 = 0;
	int licznik = 0;
	for (int i = 0; i < plansza.rozmiar; i++, pom++, pom2 = 0)
	{
		for (int j = 0; j < plansza.rozmiar - pom; j++, pom2++)
		{
			if (plansza.pola[j][plansza.rozmiar - pom2 - 1 - i].zwrocWartosc() == 'O') licznik++;
		}
		if (bestWynik <= licznik) {
			bestWynik = licznik;
			skosd_max = i + 1;
		}
		licznik = 0;
	}return bestWynik;
}
//ruch komputera
void Komputer::ruch(Plansza& plansza)
{
	int i = 1;
	//i = plansza.znajdzWKolumnie(kol_max-1);
	//j = plansza.znajdzWRzedzie(rzad_max-1);
	//jesli najlepsza kolumna, stawiaj w kolumna
	if (najlepszaKolumna(plansza) > najlepszyRzad(plansza) && najlepszaKolumna(plansza) > najlepszySkos1(plansza) && najlepszaKolumna(plansza) > najlepszySkos2(plansza) && najlepszaKolumna(plansza) > najlepszySkos3(plansza) && najlepszaKolumna(plansza) > najlepszySkos4(plansza))
	{
		while (!plansza.zmienWartosc(i, kol_max, 'X')) i++;
	}
	//jesli najlepszy skos 1, tam postaw
	else if (najlepszySkos1(plansza) > najlepszyRzad(plansza) && najlepszySkos1(plansza) > najlepszaKolumna(plansza) && najlepszySkos1(plansza) > najlepszySkos2(plansza) && najlepszySkos1(plansza) > najlepszySkos3(plansza) && najlepszySkos1(plansza) > najlepszySkos4(plansza))
	{
		while (!plansza.zmienWartosc(skosa_max, i, 'X')) i++;
	}
	//jesli najlepszy skos 2, tam postaw
	else if (najlepszySkos2(plansza) > najlepszyRzad(plansza) && najlepszySkos2(plansza) > najlepszaKolumna(plansza) && najlepszySkos2(plansza) > najlepszySkos1(plansza) && najlepszySkos2(plansza) > najlepszySkos3(plansza) && najlepszySkos2(plansza) > najlepszySkos4(plansza))
	{
		while (!plansza.zmienWartosc(skosb_max, i, 'X')) i++;
	}
	//jesli najlepszy skos 3 , tam postaw
	else if (najlepszySkos3(plansza) > najlepszyRzad(plansza) && najlepszySkos3(plansza) > najlepszaKolumna(plansza) && najlepszySkos3(plansza) > najlepszySkos1(plansza) && najlepszySkos3(plansza) > najlepszySkos2(plansza) && najlepszySkos3(plansza) > najlepszySkos4(plansza))
	{
		while (!plansza.zmienWartosc(skosc_max, i, 'X')) i++;
	}
	//jesli najlepszy skos 4,tam postaw
	else if (najlepszySkos4(plansza) > najlepszyRzad(plansza) && najlepszySkos4(plansza) > najlepszaKolumna(plansza) && najlepszySkos4(plansza) > najlepszySkos1(plansza) && najlepszySkos4(plansza) > najlepszySkos2(plansza) && najlepszySkos4(plansza) > najlepszySkos3(plansza))
	{
		while (!plansza.zmienWartosc(skosd_max, i, 'X')) i++;
	}
	//jesli najlepszy rzad, tam postaw
	else {
		while (!plansza.zmienWartosc(rzad_max, i, 'X')) i++;
	}
	i = 1;
}
//konstruktor komputer
	Komputer::Komputer(): skosa_max(0), skosb_max(0), skosc_max(0), skosd_max(0), kol_max(0), rzad_max(0)//funkcje znakow
	{
	}

	//destruktor
	Komputer::~Komputer()
	{
	}
	*/
