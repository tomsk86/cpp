//##################################################################
//# Progam rysuj¹cy dan¹ figurê o wprowadzonych wymiarach znakiem  #
//# z tablicy ASCII. Podany wymiar poddany jest kontroli formalnej #
//# i logicznej. Figurê w konsoli mo¿emy przemieszczaæ             #
//# jak i powiekszaæ w danym oknie konsoli.                        #
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
void main()				// funkcja g³ówna
{
	char znak;							// zmianna lokalna znaku rysowania
	int wymiar, klawisz, x = 0, y = 0;	// zmienne int lokalne: wymiar figury, klawisz klawiatury, zmienne po³o¿enia
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