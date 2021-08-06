#ifndef KEY_MAPPING
#define KEY_MAPPING
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define SPACE 32
#define ENTER 13
#define ESC 27
#define TAB 9
#include <vector>
using namespace std;

class KeyMapping
{
	static vector<char> player1;
	static vector<char> player2;
	static vector<char> interactMenu;
public:
	static vector<char>* GetPlayerKeys_1();
	static vector<char>* GetPlayerKeys_2();
	static vector<char>* GetMenuKeys();
	static char GetExitKey();
	static char GetPauseKey();
	static char GetSaveKey();
};

#endif
