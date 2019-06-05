#include <iostream>
#include "Plansza.h"
#include "Komputer.h"


using namespace std;

//glowna petla gry
int main()
{	//deklaracja potrzebnych zmiennych
	int rozmiar = 3;//poczatkowe deklaracje
	int win_row = 3;
	int ruch1 = 1; //zmienne sluzace do ruchu gracza wiersz i koumna
	int ruch2 = 1;
	cout << "Zdefiniuj rozmiar planszy: ";//wybor rozmiaru
	cin >> rozmiar;
	do
	{	
		cout << "Zdefinij ile w rzedzie wygrywa: ";//wybor il wygrywajacych znakow
		cin >> win_row;
	} while (win_row > rozmiar||win_row<=1); //blokada przez zlym wyborem il wygrywajacych znakow

	Plansza plansza(rozmiar, win_row); //konstr planszy o odpowiednim rozmiarze i wygrywajacej il znakow
	Komputer komputer;
	while (true)
	{
		plansza.rysujPlansze();
		cout << endl << "Ruch gracza: ";
		cin >> ruch1 >> ruch2;
		plansza.zmienWartosc(ruch1, ruch2, 'O'); //wyk ruch uzytkownika
		plansza.sprawdzPlansze(); //sprawdza ew zwyciestwo
		komputer.ruch(plansza); //wyk ruch komputera
		plansza.sprawdzPlansze();//sprawdza ew zwyciestwo
	}
}





