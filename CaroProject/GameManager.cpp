#include "GameManager.h"

GameManager* GameManager::init = nullptr;

GameManager::GameManager()
{
	intro = new Function({ "Intro_None.txt", "" });
	outro = new Function({ "Outro_None.txt", "" });
	firstMenuFunction = new Function({ "Menu_None.txt", "Menu_Has.txt" });
	gameModeFunction = new GameModeFunction();
	settingFunction = new SettingFunction();
	aboutFunction = new AboutFunction();
	loadFunction = new LoadFunction();
}

GameManager* GameManager::GetInit()
{
	if (!init)
		init = new GameManager();
	return init;
}

GameManager::~GameManager()
{
	delete SaveFunction::GetInit();
	RoundManager::DestroyClones();
	delete firstMenuFunction;
	delete gameModeFunction;
	delete settingFunction;
	delete aboutFunction;
	delete loadFunction;
	delete intro;
	delete outro;
}

void GameManager::RunGame()
{
	intro->StartFunctionGradually(600);
	intro->EndFunctionGradually(300);
	StartPage();
	firstMenuFunction->EndFunction();
	outro->StartFunctionGradually(600);
	outro->EndFunction();
}

void GameManager::StartPage()
{
	while (firstMenuFunction)
	{
		firstMenuFunction->StartFunction();
		int choice = firstMenuFunction->EndFunction();
		switch (choice)
		{
		case MODE:
			ModeMenu();
			break;
		case LOAD:
			LoadPage();
			break;
		case SETTING:
			SettingPage();
			break;
		case ABOUT:
			AboutPage();
			break;
		case EXIT_GAME:
			return;
		default:
			return;
		}
	}
}

void GameManager::ModeMenu()
{
	gameModeFunction->StartFunction();
	gameModeFunction->EndFunction();
}

void GameManager::LoadPage()
{
	loadFunction->StartFunction();
	loadFunction->EndFunction();
}

void GameManager::AboutPage()
{
	aboutFunction->StartFunction();
	aboutFunction->EndFunction();
}

void GameManager::SettingPage()
{
	settingFunction->StartFunction();
	settingFunction->EndFunction();
}

