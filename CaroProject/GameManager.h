#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#define MODE 0
#define LOAD 1
#define SETTING 2
#define ABOUT 3
#define EXIT_GAME 4
#include "Point.h"
#include "FileManager.h"
#include "InteractiveMenu.h"
#include "GameModeFunction.h"
#include "SettingFunction.h"
#include "LoadFunction.h"
#include "AboutFunction.h"

class GameManager
{
private:
	static GameManager* init;
	Function* intro;
	Function* outro;
	Function* firstMenuFunction;
	AboutFunction* aboutFunction;
	GameModeFunction* gameModeFunction;
	SettingFunction* settingFunction;
	LoadFunction* loadFunction;
	GameManager();
public:
	static GameManager* GetInit();
	~GameManager();
	void RunGame();
	void StartPage();
	void ModeMenu();
	void LoadPage();
	void AboutPage();
	void SettingPage();
};

#endif