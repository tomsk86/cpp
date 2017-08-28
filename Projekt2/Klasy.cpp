#include "stdafx.h"
#include "fProgramu.h"
#include "fkonsoli.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
//----------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------
const int Esc = 27;		// zmienna globa
//----------------------------------------------------------------------------
class Punkt // klasa punkt
{
protected:
	int x, y, kolor;
	char znak;
	void Rysuj();
public:
	Punkt(int _x, int _y, char _znak, int _kolor) : x(_x), y(_y), znak(_znak), kolor(_kolor) //konstruktor
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolor);
		HideCursor();
	}
	~Punkt() { cout << "\n\nLikwiduje obiekt klasy Punkt\n"; }; //destruktor

};
//----------------------------------------------------------------
void Punkt::Rysuj() //funkcja rysuj¹ca punkt
{
	gotoxy(x, y);
	cout << znak;
}
//----------------------------------------------------------------
class Odcinek : public Punkt //klasa pochodna odcinek
{
protected:
	int wymiar;
public:
	void Rysuj_horyzontalnie();
	void Rysuj_wertykalnie();
	void Rysuj_przekatna1();
	void Rysuj_przekatna2();

	Odcinek(int _x, int _y, char _znak, int _kolor, int _wymiar) : //konstruktor
		Punkt(_x, _y, _znak, _kolor), wymiar(_wymiar)
	{ };
	~Odcinek() { cout << "\n\nLikwiduje obiekt klasy Odcinek\n"; }; //destruktor
};
//----------------------------------------------------------------
void Odcinek::Rysuj_horyzontalnie() // funkcja rysuj¹ca odcinek poziomo
{
	for (int i = 1; i <= wymiar; i++)
	{
		gotoxy(x, y);
		Punkt::Rysuj();
		x += 2;
	}
}
void Odcinek::Rysuj_wertykalnie() // funkcja rysuj¹ca odcinek pionowo
{
	for (int i = 1; i <= wymiar; i++)
	{
		gotoxy(x, y);
		Punkt::Rysuj();
		y++;
	}
}
void Odcinek::Rysuj_przekatna1() // funkcja rysuj¹ca odcinek ukoœnie
{
	for (int i = 1; i <= wymiar - 1; i++)
	{
		gotoxy(x, y);
		Punkt::Rysuj();
		x = x - 2;
		y++;
	}
}
void Odcinek::Rysuj_przekatna2() // funkcja rysuj¹ca odcinek ukoœnie
{
	for (int i = 1; i <= wymiar / 2; i++)
	{
		gotoxy(x, y);
		Punkt::Rysuj();
		y++;
		x = x + 2;
	}
}
//----------------------------------------------------------------
class Kwadrat : public Odcinek // klasa pochodna kwadrat
{
private:
	void Rysuj();
public:

	Kwadrat(int _x, int _y, char _znak, int _kolor, int _wymiar) : //konstruktor
		Odcinek(_x, _y, _znak, _kolor, _wymiar)
	{ };
	~Kwadrat() { cout << "\n\nLikwiduje obiekt klasy Kwadrat\n"; }; //destruktor
	void Steruj();
};
//----------------------------------------------------------------
void Kwadrat::Rysuj() // funkcja rysujaca kwadrat
{
	int x1, y1;
	gotoxy(x, y);
	x1 = wherex();
	y1 = wherey();
	Odcinek::Rysuj_przekatna2();
	x = x1;
	y = y1;
	Odcinek::Rysuj_wertykalnie();
	x = x1 + wymiar * 2 - 2;
	y = y1;
	Odcinek::Rysuj_wertykalnie();
	y = y1;
	Odcinek::Rysuj_przekatna1();
	Odcinek::Rysuj_horyzontalnie();
	x = x1;
	y = y1;

}
//----------------------------------------------------------------
void Kwadrat::Steruj() //funkcja sterujaca kwadratem na ekranie
{
	char klawisz, znak1 = znak;
	do
	{
		Rysuj();
		klawisz = _getch();
		switch (klawisz)
		{
		case 43:
			if (y + wymiar < 20 && x + wymiar * 2 < 80) // powiekszenie
			{
				znak = ' ';
				Rysuj();
				znak = znak1;
				wymiar++;

			}
			break;
		case 45:
			if (wymiar > 5)						// zmniejszenie
			{
				znak = ' ';
				Rysuj();
				znak = znak1;
				wymiar--;
			}
			break;
		case 75:
			if (x>0)								// przesuniecie w lewo
			{
				znak = ' ';
				Rysuj();
				znak = znak1;
				x--;
			}
			break;
		case 77:
			if (2 * wymiar - 1 + x < 80)				// przesuniecie w prawo
			{
				znak = ' ';
				Rysuj();
				znak = znak1;
				x++;
			}
			break;
		case 72:
			if (y > 0)								// przesuniecie do gory
			{
				znak = ' ';
				Rysuj();
				znak = znak1;
				y--;
			}
			break;
		case 80:
			if (wymiar + y < 20)					// przesuniecie do dolu
			{
				znak = ' ';
				Rysuj();
				znak = znak1;
				y++;
			}
			break;
		case Esc: break;								// wyjscie
		}
	} while (klawisz != Esc);
}
//----------------------------------------------------------------------------
