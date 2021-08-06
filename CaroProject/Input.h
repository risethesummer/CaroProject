#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;

class Input
{
public:
	static string GetInput();
	static char GetInput(const char&);
	static char GetInput(const std::vector<char>&);
};


#endif // !INPUT_H