#include "GameManager.h"
using namespace std;

int main()
{
	Screen::FixConsoleWindow();
	GameManager::GetInit()->RunGame();
	delete GameManager::GetInit();
	return 0;
}