#include "Input.h"

string Input::GetInput()
{
	string input;
	getline(cin, input);
	return input;
}

char Input::GetInput(const char& expect)
{
	char input;

	do
	{
		input = toupper(_getch());
	} while (input != expect);

	return '\n';
}

char Input::GetInput(const vector<char>& expect)
{
	char input;

	while (true)
	{
		input = toupper(_getch());
		for (int i = 0; i < expect.size(); i++)
		{
			if (input == expect[i])
				return input;
		}
	}
}