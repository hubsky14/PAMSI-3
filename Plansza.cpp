#include "Plansza.h"
#include <iostream>
#include <windows.h>
//do obslugi rysowaniapo planszy
void setCursors(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

Plansza::Plansza(int roz, int win) : rozmiar(roz), win_row(win)
{
	pola = new PolePlanszy * [rozmiar];
	for (int i = 0; i < rozmiar; i++) pola[i] = new PolePlanszy[rozmiar];
}
//numeracja planszy za pomoca kursorow ( w zal od rozmiaru)
void Plansza::numeruj()
{
	for (int i = 0; i < rozmiar; i++)
	{
		setCursors(4 + i*4, 1);
		std::cout << i + 1;
	}
	for (int i = 0; i < rozmiar; i++)
	{
		setCursors(1, 3 + i*2);
		std::cout << i + 1;
	}
}
//zwraca info czy rzad jest juz zapelniony
bool Plansza::rzadPelny(int rzad)
{
		int licznik=0;
		for (int j = 0; j < rozmiar; j++)
		{
			if (pola[rzad][j].zwrocWartosc() != ' ') licznik++;
		}
		if(licznik==rozmiar) return true;
		return false;
}
//przeszukuje rzad w poszukiwaniu znakow uzytkownika
int Plansza::znajdzWRzedzie()
{
	int licznik = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			if (pola[i][j].zwrocWartosc() == 'O')
			{
				return j+1;
			}
		}
	}
}
//zwraca info czy kolumna jest pelna
bool Plansza::kolumnaPelna(int kolumna)
{
	int licznik=0;
	for (int j = 0; j < rozmiar; j++)
	{
		if (pola[j][kolumna].zwrocWartosc() != ' ') licznik++;
	}
	if (licznik == rozmiar) return true;
	return false;
}
//znajduje w kolumnie znaki uzytkownika
int Plansza::znajdzWKolumnie()
{
	int licznik = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			if (pola[j][i].zwrocWartosc() == 'O')
			{
				return j + 1;
			}
		}
	}
}
//sprawdza rzedy w poszukiwaniu ew zwyciestwa
void Plansza::sprawdzRzedy()
{
	int licznik = 0;
	int licznik2 = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			if (pola[i][j].zwrocWartosc() == 'O') licznik++; //przeszukue plansze w poszukiwaniu serii O
			else licznik = 0;

			if (pola[i][j].zwrocWartosc() == 'X') licznik2++;//przeszukuje plansze w poszukiwaniu serii X
			else licznik2 = 0;

			if (licznik == win_row)	//jesli liczba znakow uzytkownika=wygryna, konczy gre
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'O'";
				exit(0);
			}
			else if (licznik2 == win_row) //jesli liczba znakow komputera=wygryna, konczy gre
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'X'";
				exit(0);
			}
		}
	}
}
//sprawdza kolumny w poszukiwaniu ew wygranej, funkcja analogiczna do rzedow
void Plansza::sprawdzKolumny()
{
	int licznik = 0;
	int licznik2 = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			if (pola[j][i].zwrocWartosc() == 'O') licznik++;
			else licznik = 0;

			if (pola[j][i].zwrocWartosc() == 'X') licznik++;
			else licznik2 = 0;


			if (licznik == win_row)
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'O'";
				exit(0);
			}
			else if (licznik2 == win_row)
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'X'";
				exit(0);
			}
		}
	}
}
//funkcja do sprawdzania wygranej w skosach
/*Funkacja jest podzielona na 4 czesci, ktore robia dokladnie to samo jednak w innych kierunkach. 
Kazda z nich zaczyna od sprawdzenia przekatnej planszy, a nastepnie rozchodzi sie w wybranym kierunku (lewy dol/lewa gora/prawa gora/prawy dol*/
void Plansza::sprawdzSkosy()
{   
	int pom = 0; //pomocnicze do przeszukiwania planszy
	int pom2 = 0;
	int licznik = 0;
	int licznik2 = 0;
	for (int i = 0; i < rozmiar; i++, pom++, pom2=0)
	{
		for (int j = 0; j < rozmiar - pom; j++, pom2++)
		{
			if (pola[i+pom2][j].zwrocWartosc() == 'O') licznik++;
			else licznik = 0;

			if (pola[i + pom2][j].zwrocWartosc() == 'X') licznik2++;
			else licznik2 = 0;

			if (licznik == win_row)
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'O'";
				exit(0);
			}
			else if (licznik2 == win_row)
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'X'";
				exit(0);
			}
		}
	}
	pom = 0;
	pom2 = 0;
	licznik = 0;
	licznik2 = 0;
	for (int i = 0; i < rozmiar; i++, pom++, pom2 = 0)
	{
		if (i == 1) continue;
		for (int j = 0; j < rozmiar - pom; j++, pom2++)
		{
			if (pola[j][i + pom2].zwrocWartosc() == 'O') licznik++;
			else licznik = 0;

			if (pola[j][i + pom2].zwrocWartosc() == 'X') licznik2++;
			else licznik2 = 0;

			if (licznik == win_row)
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'O'";
				std::cin.get();
				exit(0);
			}
			else if (licznik2 == win_row)
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'X'";
				std::cin.get();
				exit(0);
			}
		}
	}
	pom = 0;
	pom2 = 0;
	licznik = 0;
	licznik2 = 0;
	for (int i = 0; i < rozmiar; i++, pom++, pom2 = 0)
	{
		if (i == 1) continue;
		for (int j = 0; j < rozmiar - pom; j++, pom2++)
		{
			if (pola[i+j][rozmiar-pom2-1].zwrocWartosc() == 'O') licznik++;
			else licznik = 0;

			if (pola[i + j][rozmiar - pom2 - 1].zwrocWartosc() == 'X') licznik2++;
			else licznik2 = 0;

			if (licznik == win_row)
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'O'";
				exit(0);
			}
			else if (licznik2 == win_row)
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'X'";
				std::cin.get();
				exit(0);
			}
		}
	}
	pom = 0;
	pom2 = 0;
	licznik = 0;
	licznik2 = 0;
	for (int i = 0; i < rozmiar; i++, pom++, pom2 = 0)
	{
		if (i == 1) continue;
		for (int j = 0; j < rozmiar - pom; j++, pom2++)
		{
			if (pola[j][rozmiar - pom2 - 1 - i].zwrocWartosc() == 'O') licznik++;
			else licznik = 0;

			if (pola[j][rozmiar - pom2 - 1 - i].zwrocWartosc() == 'X') licznik2++;
			else licznik2 = 0;

			if (licznik == win_row)
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'O'";
				std::cin.get();
				exit(0);
			}
			else if (licznik2 == win_row)
			{
				rysujPlansze();
				std::cout << std::endl << "Wygrywa 'X'";
				std::cin.get();
				exit(0);
			}
		}
	}
}
//sprawdza wszystkie mozliwosci na planszy
void Plansza::sprawdzPlansze()
{
	sprawdzRzedy();
	sprawdzKolumny();
	sprawdzSkosy();
}
//wyrysowuje cala plansze
void Plansza::rysujPlansze()
{
	system("cls");
	int counter = 2;
	int counter2 = 1;
	numeruj();
	for (int j = 0; j < rozmiar; j++)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			pola[j][i].rysujPole(counter, counter2);
			counter += 4;
		}
		counter = 2;
		counter2 += 2;
	}
}
//zmienia wartosc w wybranej komorce na X lub O
bool Plansza::zmienWartosc(int num1, int num2, char war)
{
	if (num1<=rozmiar+1&&num2<=rozmiar+1&&pola[num1 - 1][num2 - 1].zwrocWartosc() != 'X' && pola[num1 - 1][num2 - 1].zwrocWartosc() != 'O')
	{
		pola[num1 - 1][num2 - 1].ustawWartosc(war);
		return true;
	}
	return false;
}
//destruktor planszy
Plansza::~Plansza()
{
}
