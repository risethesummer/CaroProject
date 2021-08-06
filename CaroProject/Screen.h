#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <Windows.h>
#include "Point.h"
#include "Utility.h"
#include "Color.h"
#include <vector>
#define MIN_X 0
#define MIN_Y 0
#define MAX_X 200
#define MAX_Y 200
using namespace std;

class Screen
{
	public:
		static void FixConsoleWindow();
		//Jump to a point on the screen
		static void Jump(const Point&); 
		//Draw a shape
		static void Draw(const Point& anchor, const vector<string>& content, const int& color = WHITE_WHITE);
		//Print a string
		static void Print(const Point& point, const std::string& content);
		//Print a char
		static void Print(const Point&, const char&);
		static void DrawArea(const Point& startAnchor, const Point& endAnchor, const int& color = WHITE_WHITE);
		static void ModifyTextColor(const int&);
};


#endif // !SCREEN_H

