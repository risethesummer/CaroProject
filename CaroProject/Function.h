#ifndef FUNCTION_H
#define FUNCTION_H
#include "InteractiveMenu.h"

class Function
{
protected:
	Menu* staticMenu;
	InteractiveMenu* dynamicMenu;
	int choice;
public:
	virtual ~Function();
	Function();
	Function(vector<string> menuComFiles);
	void SetColorBound(const int& color);
	virtual void StartFunction();
	void StartFunctionGradually(const float& timeStep);
	void EndFunctionGradually(const float& timeStep);
	virtual void StartFunction(const int& specificStatic, const int& specificDyn);
	virtual int EndFunction();
};

#endif