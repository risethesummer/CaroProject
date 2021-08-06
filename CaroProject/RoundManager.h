#ifndef ROUND_H
#define ROUND_H
#define REAL 0
#define EASY_BOT 1
#define HARD_BOT 2
#define ICON_OFFSET 6
#define WIN_OFFSET 2
#include "Point.h"
#include "Board.h"
#include "Function.h"
#include "RealPlayer.h"
#include "EasyBot.h"
#include "HardBot.h"
#include "SaveFunction.h"

class RoundManager : public Function
{
	private:
		Function* confirmOut;
		Player* player1;
		Player* player2;
		Board* board;
		bool liveGame;
		static vector<Player*> clones;
		int player2Index;
		int mode;
	public:
		RoundManager(const int& mode);
		RoundManager(const int& mode, const int& size, const int& time, const vector<vector<int>>& markBoard);
		static void DestroyClones();
		void StartFunction(int t = 0);
		int StartRound(const int& t = 0);
		void Congratulate(const int& winner);
		~RoundManager();
};

#endif // !ROUND_H

