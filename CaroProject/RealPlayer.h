#ifndef REALPLAYER_H
#define REALPLAYER_H
#define EXIT 1
#define SAVE 2
#include "Player.h"
#include <vector>

class RealPlayer : public Player
{
public:
	RealPlayer();
	RealPlayer(const int& ord, Board* board);
	int GetMove() const;
	int GetMovePlayer1() const;
	int GetMovePlayer2() const;
	string GetName() const;
	Player* GetClone(const int& order, Board* board) const;
	int GetCode() const;
};
#endif // !REALPLAYER_H

