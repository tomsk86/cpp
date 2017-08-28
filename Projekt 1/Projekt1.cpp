//##################################################################
//# Progam rysuj�cy dan� figur� o wprowadzonych wymiarach znakiem  #
//# z tablicy ASCII. Podany wymiar poddany jest kontroli formalnej #
//# i logicznej. Figur� w konsoli mo�emy przemieszcza�             #
//# jak i powieksza� w danym oknie konsoli.                        #
//##################################################################

#include "stdafx.h"		// implementaja bibliotek
#include "Funkcje.h"
#include "fkonsoli.h"
#include <conio.h>

//----------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------
const int Esc = 27;		// zmienna globalna
//----------------------------------------------------------------------------
void main()				// funkcja g��wna
{
	char znak;							// zmianna lokalna znaku rysowania
	int wymiar, klawisz, x = 0, y = 0;	// zmienne int lokalne: wymiar figury, klawisz klawiatury, zmienne po�o�enia
										//karety w konsoli

	polskie_litery();
	setbuffersize();
	opis();
	dane(wymiar, znak);
	legenda();
	do
	{
		figura(wymiar, x, y, znak);
		klawisz = _getch();
		ruch(klawisz, wymiar, x, y);
	} while (klawisz != Esc);

}
//----------------------------------------------------------------------------