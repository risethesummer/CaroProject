#include "HardBot.h"

vector<int> HardBot::scores = { 0, LOSE_SCORE, WIN_SCORE};

HardBot::HardBot()
{
}

HardBot::HardBot(const int& ord, Board* board)
	: Player(ord, board)
{
}


//https://github.com/GeorgeSeif/Tic-Tac-Toe-AI/blob/master/Source.cpp
// Apply the minimax game optimization algorithm
pair<int, PairIndex> HardBot::AlphaBetaPrunning(int who, int depth, int alpha, int beta) const
{
	// Initialize best move
	PairIndex bestMove(-1, -1);
	int bestScore = (who == MARK_BOT) ? LOSE_SCORE : WIN_SCORE;

	// If we hit a terminal state (leaf node), return the best score and move
	if (playBoard->IsFull() || (playBoard->IsEndGame()))
	{
		bestScore = scores[playBoard->GetWinner()];
		return make_pair(bestScore, bestMove);
	}

	vector<PairIndex> steps = playBoard->AvailableSlots();

	for (const PairIndex& index : steps)
	{
		//If the slot is available
		if ((*playBoard->GetPoints())[index.GetRow()][index.GetCol()]->GetMark() == 0)
		{
			//Try to get the temporary state
			playBoard->InputNotAffect(who, index);

			if (who == MARK_BOT)
			{
				int scoreNow = AlphaBetaPrunning(MARK_PLAYER, depth + 1, alpha, beta).first;

				if (bestScore < scoreNow)
				{
					bestScore = scoreNow;
					bestMove = index;
					alpha = max(alpha, bestScore);
				}
			}
			else
			{
				int scoreNow = AlphaBetaPrunning(MARK_BOT, depth + 1, alpha, beta).first;

				if (bestScore > scoreNow)
				{
					bestScore = scoreNow;
					bestMove = index;
					beta = min(beta, bestScore);
				}
			}

			playBoard->RetriveInput(index); // Undo
			//Violate the alpha beta condition
			if (beta <= alpha)
				break;
		}
	}

	return make_pair(bestScore, bestMove);
}



int HardBot::GetMove() const
{
	PairIndex bestMove = AlphaBetaPrunning(MARK_BOT, 0, LOSE_SCORE, WIN_SCORE).second;
	playBoard->SetCurrentIndex(bestMove.GetRow(), bestMove.GetCol());
	playBoard->Input(order);
	return 0;
}



string HardBot::GetName() const
{
	return "Hard Bot";
}

Player* HardBot::GetClone(const int& order, Board* board) const
{
	return new HardBot(order, board);
}

int HardBot::GetCode() const
{
	return 2;
}
