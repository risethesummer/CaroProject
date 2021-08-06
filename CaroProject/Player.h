#ifndef PLAYER_H
#define PLAYER_H
#include "Point.h"
#include <iostream>
#include "Board.h"

using namespace std;

class Player
{
	protected:
		int score;
		int order;
		Board* playBoard;
	public:
		Player();
		Player(const int&, Board* board);
		int GetOrder() const;
		int GetScore() const;
		void SetScore(const int&);
		virtual int GetMove() const = 0;
		virtual string GetName() const = 0;
		virtual Player* GetClone(const int& order, Board* board) const = 0;
		virtual int GetCode() const = 0;
};

#endif // !PLAYER_H

