#include "Screen.h"

void Screen::FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	ShowWindow(consoleWindow, SW_MAXIMIZE);
	ShowScrollBar(consoleWindow, SB_VERT, FALSE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	//https://stackoverflow.com/questions/30126490/how-to-hide-console-cursor-in-c
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);

	system("Color F0");
}

void Screen::Jump(const Point& p)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)p.GetX(), (short)p.GetY() });
}

void Screen::Draw(const Point& anchor, const vector<std::string>& content, const int& charColor)
{
	Point clone(anchor);
	Jump(clone);
	ModifyTextColor(charColor);
	for (const string& current : content)
	{
		for (int i = 0; i < current.length(); i++)
		{
			//Jump the next char
			clone.MoveX(1);
			//If not space -> drawing
			if (!isspace(current[i]))
				cout << current[i];
			else
				Jump(clone); //Jump to next if not a char
		}
		clone.MoveY(1);
		clone.SetX(anchor.GetX());
		Jump(clone);
	}
}

void Screen::Print(const Point& point, const std::string& content)
{
	Jump(point);
	std::cout << content;
}

void Screen::Print(const Point& point, const char& ch)
{
	Jump(point);
	std::cout << ch;
}

void Screen::DrawArea(const Point& startAnchor, const Point& endAnchor, const int& color)
{
	ModifyTextColor(color);
	string line = Utility::GetCharString(endAnchor.GetX() - startAnchor.GetX() + 4, '*');
	for (int r = 0; r < endAnchor.GetY() - startAnchor.GetY() + 2; r++)
	{
		Jump(Point(startAnchor.GetX() - 1, startAnchor.GetY() + r - 1));
		cout << line;
	}
}

void Screen::ModifyTextColor(const int& color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

