#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <Windows.h>
#include "Point.h"

class Screen
{
	public:
		//static void* handle;
		static void ClearScreen();
		static void FixConsoleWindow();
		static void Jump(Point); //Jump to a point on the screen
		static void Draw(Point, std::string);
};

#endif // !SCREEN_H

