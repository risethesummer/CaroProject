#include "KeyMapping.h"

vector<char> KeyMapping::player1 = { 'W', 'A', 'S', 'D', 'E', ESC, TAB };
vector<char> KeyMapping::player2 = { ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT, ARROW_UP, ENTER, ESC, TAB };
vector<char> KeyMapping::interactMenu = { ARROW_DOWN, ARROW_UP, 'W', 'S' , ENTER, 'E'};

vector<char>* KeyMapping::GetPlayerKeys_1()
{
	return &player1;
}
vector<char>* KeyMapping::GetPlayerKeys_2()
{
	return &player2;
}
vector<char>* KeyMapping::GetMenuKeys()
{
	return &interactMenu;
}

char KeyMapping::GetExitKey()
{
	return ESC;
}

char KeyMapping::GetPauseKey()
{
	return SPACE;
}

char KeyMapping::GetSaveKey()
{
	return TAB;
}