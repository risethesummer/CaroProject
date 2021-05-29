#ifndef ROUND_H
#define ROUND_H
#include "Point.h"
#include "Board.h"
#include "Player.h"

class RoundManager
{
	private:
		Player* player1;
		Player* player2;
		Point currentMousePosition;
		bool liveGame = false;
		Board* board;
	public:
		RoundManager(int, Point);
		~RoundManager();
};

#endif // !ROUND_H

