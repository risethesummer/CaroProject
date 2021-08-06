#include "RealPlayer.h"
#include "Input.h"
#include "KeyMapping.h"


RealPlayer::RealPlayer()
{
}

RealPlayer::RealPlayer(const int& ord, Board* board) : Player(ord, board)
{

}


int RealPlayer::GetMove() const
{
	if (order == 1)
		return GetMovePlayer1();
	return GetMovePlayer2();
}

int RealPlayer::GetMovePlayer1() const
{
	char temp;
	vector<char>* keys = KeyMapping::GetPlayerKeys_1();
	while (true)
	{
		temp = Input::GetInput(*keys);
		//If chose to move
		switch (temp)
		{
		case 'W':
			playBoard->MoveCursor(0, -1);
			break;
		case 'A':
			playBoard->MoveCursor(-1, 0);
			break;
		case 'D':
			playBoard->MoveCursor(1, 0);
			break;
		case 'S':
			playBoard->MoveCursor(0, 1);
			break;
		case 'E':
			if (playBoard->Input(order))
				return 0;
			break;
		case ESC:
			return EXIT;
		case TAB:
			return SAVE;
		}
	}
}

int RealPlayer::GetMovePlayer2() const
{
	char temp;
	vector<char>* keys = KeyMapping::GetPlayerKeys_2();
	while (true)
	{
		temp = Input::GetInput(*keys);
		//If chose to move
		switch (temp)
		{
		case ARROW_UP:
			playBoard->MoveCursor(0, -1);
			break;
		case ARROW_LEFT:
			playBoard->MoveCursor(-1, 0);
			break;
		case ARROW_RIGHT:
			playBoard->MoveCursor(1, 0);
			break;
		case ARROW_DOWN:
			playBoard->MoveCursor(0, 1);
			break;
		case ENTER:
			if (playBoard->Input(order))
				return 0;
			break;
		case ESC:
			return EXIT;
		case TAB:
			return SAVE;
		}
	}
}

string RealPlayer::GetName() const
{
	return "2 Players";
}

Player* RealPlayer::GetClone(const int& order, Board* board) const
{
	return new RealPlayer(order, board);
}

int RealPlayer::GetCode() const
{
	return 0;
}
