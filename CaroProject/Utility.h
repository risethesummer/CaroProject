#ifndef UTILITY_H
#define UTILITY_H
#include <vector>
#include "Point.h"
#include <iostream>
using namespace std;

class Utility
{
public:
	template <class T>
	static int GetMax(const vector<T>&);
	static int GetMaxLength(const vector<string>&);
	static string GetCharString(const int&, const char&);
	static vector<string> CreateRectangleContent(const vector<string>& content, const Point& offset);
};

#endif