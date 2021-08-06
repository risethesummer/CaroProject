#include "Player.h"

Player::Player()
{
	playBoard = nullptr;
	order = 0;
	score = 0;
}

Player::Player(const int& order, Board* board)
{
	this->order = order;
	this->playBoard = board;
	this->score = 0;
}

int Player::GetScore() const
{
	return score;
}


int Player::GetOrder() const
{
	return order;
}

void Player::SetScore(const int& newScore)
{
	if (newScore > 0)
		this->score = newScore;
}
