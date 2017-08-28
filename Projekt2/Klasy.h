#ifndef Klasy
#define Klasy

#include <Windows.h>

class Punkt
{
protected:
	int x, y, kolor;
	char znak;
	void Rysuj();
public:
	Punkt(int _x, int _y, char _znak, int _kolor) : x(_x), y(_y), znak(_znak), kolor(_kolor){}
	~Punkt() {}
};
//----------------------------------------------------------------
class Odcinek : public Punkt
{
protected:
	int wymiar;
public:
	void Rysuj_horyzontalnie();
	void Rysuj_wertykalnie();
	void Rysuj_przekatna1();
	void Rysuj_przekatna2();

	Odcinek(int _x, int _y, char _znak, int _kolor, int _wymiar) :
		Punkt(_x, _y, _znak, _kolor), wymiar(_wymiar){}
	~Odcinek() {}
};
//----------------------------------------------------------------
class Kwadrat : public Odcinek
{
private:
	void Rysuj();
public:

	Kwadrat(int _x, int _y, char _znak, int _kolor, int _wymiar) :
		Odcinek(_x, _y, _znak, _kolor, _wymiar)
	{ };
	~Kwadrat() {}
	void Steruj();
};
//----------------------------------------------------------------
#endif