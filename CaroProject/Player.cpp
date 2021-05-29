#include "Player.h"

Player::Player(string name)
{
	this->name = name;
	this->score = 0;
}

int Player::GetScore()
{
	return score;
}

void Player::SetScore(const int& newScore)
{
	this->score = newScore;
}

string Player::GetName()
{
	return this->name;
}

Point Player::GetMove()
{
	return Point();
}
