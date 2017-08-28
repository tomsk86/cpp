#include "stdafx.h"
#include "Funkcje.h"
#include "fkonsoli.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
//----------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------
const int Esc = 27;		// zmienna globalna
//----------------------------------------------------------------------------
void opis()				// funkcja ekran tytu�owy programu
{
	HideCursor();
	ustaw_kolor(3);
	cout << "\n\n\n"
		<< "\t##################################################################\n"
		<< "\t# Progam rysuj�cy dan� figur� o wprowadzonych wymiarach znakiem  #\n"
		<< "\t# z tablicy ASCII. Podany wymiar poddany jest kontroli formalnej #\n"
		<< "\t# i logicznej. Figur� w konsoli mo�emy przemieszcza�             #\n"
		<< "\t# jak i powieksza� w danym oknie konsoli.                        #\n"
		<< "\t##################################################################";
	gotoxy(40, 12);
	ustaw_kolor(6);
	cout << "Zadanie 1: I NST 2016";
	gotoxy(40, 13);
	cout << "Tomasz Skiba 167970";
	gotoxy(15, 22);
	cout << "--- Naci�nij dowolny klawisz, aby kontynuowa�. ---";
	_getch();
	system("cls");
}
//----------------------------------------------------------------------------
int kontrola(int ogrMin, int ogrMax)	// kontrola formalna i logiczna zmiennej
{
	int liczba, x, y;
	bool err;

	x = wherex();
	y = wherey();
	do
	{
		err = false;
		gotoxy(x, y);
		clreol();
		cin >> liczba;

		if (!cin.good())  // Zabezpieczenie przed wprowadzeniem niewlasciwego znaku
		{
			err = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (liczba < ogrMin || liczba > ogrMax || err); //kontrola logiczna
	return liczba;
}
//----------------------------------------------------------------------------
void dane(int &wymiar, char &znak)		// funkcja ekran pobieraj�cy dane
{
	ShowCursor();
	ustaw_kolor(9);
	gotoxy(20, 10);
	cout << "Podaj wysoko�� figury (5-15): ";
	wymiar = kontrola(5, 15);

	cin.ignore(INT_MAX, '\n');			// czyszczenie strumienia wej�cia
	cin.clear();

	gotoxy(20, 15);
	cout << "Podaj znak: ";
	cin >> znak;

	system("cls");
	HideCursor();
}
//----------------------------------------------------------------------------
void legenda()				// funkcja wy�wietlaj�ca legend�
{
	int x, y;

	gotoxy(0, 20);

	wherex();
	wherey();
	x = wherex();
	y = wherey();

	ustaw_kolor(6);

	cout << ' ';
	for (int i = 1; i <= 78; i++)   
	{
		cout << '#';
	}
	cout << "\n";
	for (int i = 1; i < 4; i++)
	{
		cout << " #";
		for (int j = 1; j <= 76; j++)
		{
			cout << ' ';
		}
		cout << "#\n";
	}
	cout << ' ';
	for (int i = 1; i <= 78; i++)
	{
		cout << '#';
	}

	ustaw_kolor(5);
	// opis wew. funkcji klawiszy
	gotoxy(x + 3, y + 2);
	cout << char(30) << " w g�r�";
	gotoxy(x + 13, y + 2);
	cout << char(31) << " w d�";
	gotoxy(x + 23, y + 2);
	cout << char(17) << " w lewo";
	gotoxy(x + 33, y + 2);
	cout << char(16) << " w prawo";
	gotoxy(x + 45, y + 2);
	cout << "+" << " powi�kszanie";
	gotoxy(x + 62, y + 2);
	cout << "-" << " zmniejszanie";
}
//----------------------------------------------------------------------------
void figura(int wymiar, int x, int y, char znak)		// funkcja rysuj�ca figur�
{
	int x1, y1;
	ustaw_kolor(8);
	x1 = x;
	y1 = y;
	for (int i = 1; i <= wymiar; i++)  //lewy bok
	{
		gotoxy(x1, y1);
		cout << znak;
		y1++;
	}

	y1--;
	for (int i = 1; i <= wymiar; i++)  //kraw�d� dolna
	{
		gotoxy(x1, y1);
		cout << znak;
		x1 = x1 + 2;
	}

	x1 = x1 - 2;
	for (int i = 1; i <= wymiar; i++)  //prawy bok
	{
		gotoxy(x1, y1);
		cout << znak;
		y1--;
	}

	y1++;
	for (int i = 1; i <= wymiar; i++)  //przek�tna1
	{
		gotoxy(x1, y1);
		cout << znak;
		x1 = x1 - 2;
		y1++;
	}

	x1 = x;
	y1 = y;
	for (int i = 1; i <= wymiar / 2; i++)  //przek�tna2
	{
		gotoxy(x1, y1);
		cout << znak;
		y1++;
		x1 = x1 + 2;
	}
	gotoxy(x, y);		// powr�t do pkt. odniesienia
}
//----------------------------------------------------------------------------
void ruch(int &klawisz, int &wymiar, int &x, int &y) // funkcja odpowiedzialna za ruch i zmiany wymiaru figury
{
	switch (klawisz)
	{
	case 43:
		if (y + wymiar < 20 && x + wymiar * 2 < 80) // powiekszenie
		{
			figura(wymiar, x, y, ' ');
			wymiar++;
		}
		break;
	case 45:
		if (wymiar > 5)						// zmniejszenie
		{
			figura(wymiar, x, y, ' ');
			wymiar--;
		}
		break;
	case 75:
		if (x>0)								// przesuniecie w lewo
		{
			figura(wymiar, x, y, ' ');
			x--;
		}
		break;
	case 77:
		if (2 * wymiar - 1 + x < 80)				// przesuniecie w prawo
		{
			figura(wymiar, x, y, ' ');
			x++;
		}
		break;
	case 72:
		if (y>0)								// przesuniecie do gory
		{
			figura(wymiar, x, y, ' ');
			y--;
		}
		break;
	case 80:
		if (wymiar + y < 20)					// przesuniecie do dolu
		{
			figura(wymiar, x, y, ' ');
			y++;
		}
		break;
	case Esc: break;								// wyjscie
	}
}
//----------------------------------------------------------------------------
