#include "GameModeFunction.h"

GameModeFunction::GameModeFunction()
	: Function({ "Mode_None.txt" , "Mode_Has.txt" })
{
}


void GameModeFunction::StartFunction()
{
	while (staticMenu && dynamicMenu)
	{
		staticMenu->Show();
		dynamicMenu->Show();
		choice = dynamicMenu->Interact();
		EndFunction();
		//Back to main menu
		if (choice == GAME_MODE_BACK_MENU)
			return;
		RoundManager* roundManager = new RoundManager(choice);
		roundManager->StartFunction();
		roundManager->EndFunction();
	}
}
