#include "stdafx.h"
#include "fProgramu.h"
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
		<< "\t# jak i powieksza� w danym oknie konsoli. Projekt wykonany       #\n"
		<< "\t# obiektowo. Menu umo�liwia wyb�r wielko�ci startowej lub        #\n"
		<< "\t# zdefiniowanej.                                                 #\n"
		<< "\t##################################################################";
	gotoxy(40, 12);
	ustaw_kolor(6);
	cout << "Zadanie 2: I NST 2016";
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
int menu() // tworzy menu wyboru
{
	int klawisz;

	ustaw_kolor(13);
	system("cls");
	gotoxy(81 / 2, 1);
	cout << "MENU";
	ustaw_kolor(10);
	gotoxy(5, 3);
	cout << "1. Rysuj okiekt danymi standardowymi: wymiar = 10, znak = #";
	gotoxy(5, 5);
	cout << "2. Wprowad� dane jakimi ma by� rysowany obiekt.";
	gotoxy(5, 7);
	cout << "3. Koniec";
	gotoxy(5, 9);
	cout << "Tw�j wyb�r: ";
	ShowCursor();
	klawisz = kontrola(1, 3);
	cin.ignore(INT_MAX, '\n');			// czyszczenie strumienia wej�cia
	cin.clear();
	HideCursor();
	return klawisz;
}
//----------------------------------------------------------------------------
void dane(int &wymiar, char &znak)		// funkcja ekran pobieraj�cy dane
{
	ShowCursor();
	ustaw_kolor(9);
	gotoxy(20, 16);
	cout << "Podaj wysoko�� figury (5-15): ";
	wymiar = kontrola(5, 15);

	cin.ignore(INT_MAX, '\n');			// czyszczenie strumienia wej�cia
	cin.clear();

	gotoxy(20, 18);
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
