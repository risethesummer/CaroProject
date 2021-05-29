#ifndef PLAYER_H
#define PLAYER_H
#include "Point.h"
#include <iostream>
using namespace std;

class Player
{
	private:
		string name;
		int score;
	public:
		Player(string);
		int GetScore();
		void SetScore(const int&);
		string GetName();
		virtual Point GetMove();
};

#endif // !PLAYER_H

