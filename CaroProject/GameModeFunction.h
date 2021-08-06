#ifndef GAME_MODE_FUNCTION_H
#define GAME_MODE_FUNCTION_H
#define GAME_MODE_BACK_MENU 3
#include "Function.h"
#include "RoundManager.h"

class GameModeFunction : public Function
{
public:
	GameModeFunction();
	void StartFunction();
};

#endif