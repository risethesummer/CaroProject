#ifndef SAVE_FUNCTION_H
#define SAVE_FUNCTION_H
#define MAX_SLOT 4
#include "Function.h"
#include <fstream>
#include <ctime>
#include "SlotBoard.h"

using namespace std;

class SaveFunction : public Function
{
	static SaveFunction* init;
	SaveFunction();
public:
	static SaveFunction* GetInit();
	void StartFunction(const int& mode, const string& playerName, const int& turn, const int& ttw, vector<vector<SlotBoard*>>* move);
};

#endif