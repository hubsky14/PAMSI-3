#include "PolePlanszy.h"
#include <iostream>
#include <windows.h>

using namespace std;
//funkcja ustaw kursor do rysowania
void setCursor(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//funkcja do rysowania planszy za pomoca tab znakow ASCII
void PolePlanszy::rysujPole(int x, int y)
{
	char pion = 179;
	char poziom = 196;
	char lacznik = 197;
	setCursor(x+1, y+1);
	cout << lacznik << poziom << poziom << poziom << lacznik;
	setCursor(x+1, y + 2);
	cout << pion << " " << wartosc << " " << pion;
	setCursor(x+1, y + 3);
	cout << lacznik << poziom << poziom << poziom << lacznik; //sekwencja zrobienia okna
}
//ustala wartosc pola z planszy
void PolePlanszy::ustawWartosc(char war)
{
	wartosc = war;
}
//zwraca wartosc na planszy
char PolePlanszy::zwrocWartosc()
{
	return wartosc;
}

PolePlanszy::PolePlanszy()
{
	wartosc = ' ';
}

//destruktor pola
PolePlanszy::~PolePlanszy()
{
}
