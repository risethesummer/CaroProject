#include "EasyBot.h"

EasyBot::EasyBot()
{
}

EasyBot::EasyBot(const int& order, Board* board)
	: Player(order, board)
{
}

int EasyBot::GetMove() const
{
	srand(time(NULL));
	int range = playBoard->GetSize();
	vector<vector<SlotBoard*>>* slots = playBoard->GetPoints();
	bool checkDone = false;
	int tempRow, tempCol;
	do
	{
		tempRow = rand() % range;
		tempCol = rand() % range;
		checkDone = (*slots)[tempRow][tempCol]->GetMark() == 0;
		if (checkDone)
		{
			playBoard->SetCurrentIndex(tempRow, tempCol);
			playBoard->Input(order);
		}
	} while (!checkDone);

	return 0;
}

Player* EasyBot::GetClone(const int& order, Board* board) const
{
	return new EasyBot(order, board);
}

string EasyBot::GetName() const
{
	return "Easy Bot";
}


int EasyBot::GetCode() const
{
	return 1;
}