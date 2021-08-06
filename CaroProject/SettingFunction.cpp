#include "SettingFunction.h"

vector<int> SettingFunction::holdSizes = {3, 5, 7};
int SettingFunction::sizeBoardIndex = 1;
int SettingFunction::timeToWinIndex = 0;

SettingFunction::SettingFunction()
	: Function({ "Setting_None.txt", "Setting_Has.txt" })
{
	sizeFunc = new Function({ "", "Setting_Size_Has.txt" });
	timeToWinFunc = new Function({ "", "Setting_Time_Has.txt" });
}

SettingFunction::~SettingFunction()
{
	delete sizeFunc;
	delete timeToWinFunc;
}

int SettingFunction::GetBoardSize()
{
	return holdSizes[sizeBoardIndex - 1];
}

int SettingFunction::GetTimeToWin()
{
	return holdSizes[timeToWinIndex];
}

void SettingFunction::StartFunction(const int& specificStatic, const int& specificDyn)
{
	staticMenu->Show(0);
	staticMenu->Show(sizeBoardIndex);
	staticMenu->Show(TIME_TO_WIN_OFFSET);
	dynamicMenu->Show();
	while (true)
	{
		int choice = dynamicMenu->Interact();
		switch (choice)
		{
		case 0:
			SettingSize();
			break;
		case 1:
			SettingTimeToWin();
			break;
		case 2:
			return;
		}
	}
}

void SettingFunction::SettingSize()
{
	sizeFunc->StartFunction();
	int choice = sizeFunc->EndFunction() + 1;
	if (choice != sizeBoardIndex)
	{
		staticMenu->Hide(sizeBoardIndex);
		staticMenu->Show(choice);
		sizeBoardIndex = choice;
	}
}

void SettingFunction::SettingTimeToWin()
{
	timeToWinFunc->StartFunction();
	int choice = timeToWinFunc->EndFunction();
	if (choice != timeToWinIndex && choice < sizeBoardIndex)
	{
		staticMenu->Hide(TIME_TO_WIN_OFFSET + timeToWinIndex);
		staticMenu->Show(TIME_TO_WIN_OFFSET + choice);
		timeToWinIndex = choice;
	}
}
