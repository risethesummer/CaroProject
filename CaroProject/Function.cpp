#include "Function.h"

Function::~Function()
{
	delete staticMenu;
	delete dynamicMenu;
}

Function::Function()
{
	choice = 0;
	staticMenu = nullptr;
	dynamicMenu = nullptr;
}

Function::Function(vector<string> menuComFiles)
{
	vector<string> menuNone = FileManager::ReadTextFile(menuComFiles[0]);
	vector<string> menuHas = FileManager::ReadTextFile(menuComFiles[1]);

	staticMenu = new Menu(menuNone);
	dynamicMenu = new InteractiveMenu(menuHas);
	choice = 0;
}

void Function::SetColorBound(const int& color)
{
	dynamicMenu->SetColor(color);
}

void Function::StartFunction()
{
	if (staticMenu && dynamicMenu)
	{
		staticMenu->Show();
		//Exist at least one component to be interacted
		if (dynamicMenu->CountComponents() > 0)
		{
			dynamicMenu->Show();
			choice = dynamicMenu->Interact();
		}
	}
}

void Function::StartFunctionGradually(const float& timeStep)
{
	if (staticMenu)
		staticMenu->GraduallyShow(timeStep);
}

void Function::EndFunctionGradually(const float& timeStep)
{
	if (staticMenu)
		staticMenu->GraduallyHide(timeStep);
}


void Function::StartFunction(const int& specificStatic, const int& specificDyn)
{
	if (staticMenu && dynamicMenu)
	{
		if (specificStatic >= 0)
			staticMenu->Show(specificStatic);
		else
			staticMenu->Show();

		if (specificDyn >= 0)
			dynamicMenu->Show(specificDyn);
		else
			dynamicMenu->Show();

		choice = dynamicMenu->Interact();
	}
}

int Function::EndFunction()
{
	if (staticMenu && dynamicMenu)
	{
		staticMenu->Hide();
		dynamicMenu->Hide();
	}
	return choice;
}
