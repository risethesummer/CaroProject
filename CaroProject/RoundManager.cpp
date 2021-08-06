#include "RoundManager.h"

vector<Player*> RoundManager::clones = { new RealPlayer(), new EasyBot(), new HardBot() };

RoundManager::RoundManager(const int& mode)
	: Function({"Round_None.txt", ""})
{
	this->mode = mode;
	confirmOut = new Function({ "Round_Confirm_Out_None.txt", "Round_Confirm_Out_Has.txt" });
	confirmOut->SetColorBound(RED_RED);
	board = new Board(SettingFunction::GetBoardSize(), SettingFunction::GetTimeToWin());
	player1 = new RealPlayer(1, board);
	player2 = clones[mode]->GetClone(2, board);
	player2Index = player2->GetCode() + ICON_OFFSET + 1;
	liveGame = false;
}

RoundManager::RoundManager(const int& mode, const int& size, const int& time, const vector<vector<int>>& markBoard)
	: Function({ "Round_None.txt", "" })
{
	this->mode = mode;
	confirmOut = new Function({ "Round_Confirm_Out_None.txt", "Round_Confirm_Out_Has.txt" });
	confirmOut->SetColorBound(RED_RED);
	board = new Board(size, time, markBoard);
	player1 = new RealPlayer(1, board);
	player2 = clones[mode]->GetClone(2, board);
	player2Index = player2->GetCode() + ICON_OFFSET + 1;
	liveGame = false;
}

void RoundManager::DestroyClones()
{
	for (Player* c : clones)
		delete c;
}

void RoundManager::StartFunction(int t)
{
	while (true)
	{
		staticMenu->Show(0);
		staticMenu->Show(1);
		//Player 1
		staticMenu->Show(ICON_OFFSET);
		//Player 2 (real or bot)
		staticMenu->Show(player2Index);

		int win = StartRound(t);
		t = 0;

		board->Clear();

		if (win >= 0)
		{
			board->ClearBuffer();
			int show = win + WIN_OFFSET;

			//bot win
			if (win >= 2 && player2->GetCode() > 0)
				show++;

			Congratulate(show);
		}


		confirmOut->StartFunction();
		if (confirmOut->EndFunction() == 0)
			return;
	}
}


int RoundManager::StartRound(const int& t)
{
	board->DrawBoard();
	for (int turn = t; !liveGame; turn = (turn + 1) % 2)
	{
		int iconIndex = turn == 0 ? ICON_OFFSET : player2Index;

		staticMenu->GetComponent(iconIndex)->SetColor(YELLOW_YELLOW);
		staticMenu->Show(iconIndex);
		staticMenu->GetComponent(iconIndex)->SetColor(GRAY_GRAY);
		//The next player can play
		int out = turn == 0 ? player1->GetMove() : player2->GetMove();
		staticMenu->Show(iconIndex);

		if (out == SAVE)
		{
			board->Clear();
			SaveFunction::GetInit()->StartFunction(mode, player2->GetName(), turn, board->GetTTW(), board->GetPoints());
			SaveFunction::GetInit()->EndFunction();
			board->DrawBoard();
		}

		if (out == EXIT)
			return -out;

		if (board->IsEndGame())
		{
			board->ShowEndGame();
			return turn + 1;
		}
		else if (board->IsFull())
			return 0;
	}

	return 0;
}

void RoundManager::Congratulate(const int& winner)
{
	EndFunction();
	UIComponent* winnerShow = staticMenu->GetComponent(winner);
	for (int i = 0; i < 50; i++)
	{
		winnerShow->SetColor((i * 17) % 255);
		winnerShow->Show();
		Sleep(WAITTODRAW);
	}
	winnerShow->Hide();
}

RoundManager::~RoundManager()
{
	delete player1;
	delete player2;
	delete board;
	delete confirmOut;
}