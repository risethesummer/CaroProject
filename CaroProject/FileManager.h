#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <vector>
#include <fstream>
#include <string>
#include "Point.H"
#include "UIComponent.h"
using namespace std;

class FileManager
{
public:
	//Read file paths from a file
	static vector<string> ReadTextFile(const string&);
	static vector<int> ReadNumberFile(const string&);
	static void ReadComponent(const string&, UIComponent&);
	//static bool WriteTeFile(const string&);
};

#endif 