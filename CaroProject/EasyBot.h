#ifndef EASY_BOT_H
#define EASY_BOT_H
#include "Player.h"
#include <ctime>
#include <cstdlib>

class EasyBot : public Player
{
public:
	EasyBot();
	EasyBot(const int& order, Board* board);
	int GetMove() const;
	Player* GetClone(const int& order, Board* board) const;
	string GetName() const;
	int GetCode() const;
};

#endif