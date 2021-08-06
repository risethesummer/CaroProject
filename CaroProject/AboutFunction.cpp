#include "AboutFunction.h"

AboutFunction::AboutFunction()
	: Function({"About_None.txt", "About_Has.txt"})
{
}

//https://stackoverflow.com/questions/17347950/how-do-i-open-a-url-from-c
void AboutFunction::StartFunction()
{
	if (staticMenu && dynamicMenu)
	{
		staticMenu->Show();
		dynamicMenu->Show();
		choice = dynamicMenu->Interact();

		switch (choice)
		{
		case 0:
			ShellExecute(0, 0, L"https://github.com/risethesummer/CaroProject", 0, 0, SW_SHOW);
		case 1:
			return;
		}
	}
}
