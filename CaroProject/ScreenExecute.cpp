#include "Screen.h"
#include "Point.h"
#include <iostream>
#include <Windows.h>

void Screen::ClearScreen()
{
	system("cls");
}

void Screen::FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
	//handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Screen::Jump(Point p)
{
	COORD coord;
	coord.X = p.x;
	coord.Y = p.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Screen::Draw(Point point, std::string content)
{
	Jump(point);
	std::cout << content;
}
