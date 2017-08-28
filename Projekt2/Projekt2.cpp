//##################################################################
//# Progam rysuj¹cy dan¹ figurê o wprowadzonych wymiarach znakiem  #
//# z tablicy ASCII. Podany wymiar poddany jest kontroli formalnej #
//# i logicznej. Figurê w konsoli mo¿emy przemieszczaæ             #
//# jak i powiekszaæ w danym oknie konsoli. Projekt wykonany       #
//# obiektowo. Menu umo¿liwia wybór wielkoœci startowej lub        #
//# zdefiniowanej.                                                 #
//##################################################################

#include "stdafx.h"		// implementaja bibliotek
#include "fProgramu.h"
#include "fkonsoli.h"
#include "Klasy.h"
#include <conio.h>
#include <windows.h>

//----------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------
const int Esc = 27;		// zmienna globalna
//----------------------------------------------------------------------------
void main()				// funkcja g³ówna
{
	char znak;							// zmianna lokalna znaku rysowania
	int wymiar, klawisz = 0, x = 0, y = 0;	// zmienne int lokalne: wymiar figury, klawisz klawiatury, zmienne po³o¿enia karety w konsoli
	polskie_litery();
	SMALL_RECT windowSize = { 0, 0, 79, 24 };  // ustalenie parametrow konsoli
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize); // wczytanie parametrow do konsoli
	setbuffersize(); // blokada buffora
	opis();
	do
	{
		klawisz = menu();
		if (klawisz != 3)
		{
			switch (klawisz)
			{
			case 1:
			{
				system("cls");
				legenda();
				Kwadrat K1(x, y, '#', 2, 10);
				K1.Steruj(); break;
			}
			case 2:
			{
				dane(wymiar, znak);
				legenda();
				Kwadrat K1(x, y, znak, 2, wymiar);
				K1.Steruj(); break;
			}
			case 3:break;
			default:break;
			}
		}
	} while (klawisz != 3);
}
//----------------------------------------------------------------------------