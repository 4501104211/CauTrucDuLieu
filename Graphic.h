#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

/*************************************************
* Hàm thay doi kich thuoc khung
**************************************************/
void resizeConsole(int _iWidth, int _iHeight)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, _iWidth, _iHeight, TRUE);
}

/************************************************
* Hàm tô màu.
*************************************************/
void textcolor(int _iX)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, _iX);
}

/************************************************
* Hàm d?ch chuy?n con tr? ??n t?a ?? x, y.
*************************************************/
void gotoxy(int _iX, int _iY)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { _iX - 1,_iY - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void ToMau(int _iX, int _iY, string _sA, int _iColor) // x, y là t?a ?? con tr? c?n nh?y ??n ?? vi?t, a là chu?i c?n truy?n vào, color là màu truy?n vào.
{
	gotoxy(_iX, _iY);
	textcolor(_iColor);
	cout << _sA;
	textcolor(7);
}
void SizeFont(int _iXX) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = _iXX;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	//std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}