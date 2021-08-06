#ifndef SETTING_FUNCTION_H
#define SETTING_FUNCTION_H
#define TIME_TO_WIN_OFFSET 4
#include <iostream>
#include "FileManager.h"
#include "Function.h"

using namespace std;

class SettingFunction : public Function
{
	static int sizeBoardIndex;
	static int timeToWinIndex;
	static vector<int> holdSizes;
	Function* sizeFunc;
	Function* timeToWinFunc;
public:
	SettingFunction();
	~SettingFunction();
	static int GetBoardSize();
	static int GetTimeToWin();
	void StartFunction(const int& specificStatic = -1, const int& specificDyn = -1);
	void SettingSize();
	void SettingTimeToWin();
};


#endif
