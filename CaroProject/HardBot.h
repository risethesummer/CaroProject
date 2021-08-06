#ifndef HARD_BOT_H
#define HARD_BOT_H
#define WIN_SCORE 10
#define LOSE_SCORE -10
#define TIE_SCORE 0
#define MARK_BOT 2
#define MARK_PLAYER 1
#include "Player.h"

using namespace std;

class HardBot : public Player
{
	static vector<int> scores;
public:
	HardBot();
	HardBot(const int&, Board* board);
	int GetMove() const;
	string GetName() const;
	Player* GetClone(const int& order, Board* board) const;
	pair<int, PairIndex> AlphaBetaPrunning(int who, int depth, int alpha, int beta) const;
	int GetCode() const;
};

#endif