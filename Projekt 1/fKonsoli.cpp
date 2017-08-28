#include "stdafx.h"
#include "fkonsoli.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <locale>
//----------------------------------------------------------------------------
using namespace std;
//----------------------------------------------------------------------------
void polskie_litery()
{
	locale locpl("Polish_Poland");	//tworzy obiekt z lokalizacja
	locale::global(locpl);			//lokalizacja globalnie
	cout.imbue(locpl);				// lokalizacja strumienia cout
	cin.imbue(locpl);				// lokalizacja strumienia cin
}
//----------------------------------------------------------------------------
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//----------------------------------------------------------------------------
int wherex()
{

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}
//---------------------------------------------------------------------------- 
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}
//----------------------------------------------------------------------------  
void clreol()
{
	int x, y;
	x = wherex();
	y = wherey();
	gotoxy(x, y);
	for (int i = x; i <= 79; i++)
		cout << " ";
	gotoxy(x, y);
}
//----------------------------------------------------------------------------
void HideCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}
//----------------------------------------------------------------------------
void ShowCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = TRUE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}
//----------------------------------------------------------------------------
void ustaw_kolor(int kolor)
{
	HANDLE uchwyt;
	uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(uchwyt, kolor);
}
//----------------------------------------------------------------------------
void setbuffersize()
{
	COORD c;
	c.X = 80;
	c.Y = 25;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);
}