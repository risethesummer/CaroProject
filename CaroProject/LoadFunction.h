#ifndef LOAD_FUNCTION_H
#define LOAD_FUNCTION_H
#define LOAD_EXIT 4
#include "RoundManager.h"
#include <fstream>
#include "Function.h"
#include "SaveFunction.h"

class LoadFunction : public Function
{
public:
	LoadFunction();
	void FirstCheck();
	void StartFunction();
	void LoadFile(const int& choice);
};

#endif