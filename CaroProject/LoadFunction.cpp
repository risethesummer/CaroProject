#include "LoadFunction.h"


LoadFunction::LoadFunction()
	: Function({"Load_None.txt", "Load_Has.txt"})
{
}


void LoadFunction::FirstCheck()
{
	string file = "Save_*.txt";
	string fileDes = "Save_Show_*.txt";

	int count = 0;
	for (size_t i = 0; i < 4; i++)
	{
		file[5] = i + '0';
		fileDes[10] = i + '0';
		ifstream temp(file);
		ifstream tempDes(fileDes);
		UIComponent* com = dynamicMenu->GetComponent(i);
		if (temp.good() && tempDes.good())
		{
			com->SetContent(FileManager::ReadTextFile(fileDes));
			com->SetColor(WHITE_BLACK);
		}
		else
			com->SetColor(BLACK_BLACK);
	}
}

void LoadFunction::StartFunction()
{

	while (true)
	{
		FirstCheck();
		//Get file name from the path
		staticMenu->Show();
		dynamicMenu->Show();
		int choice = dynamicMenu->Interact();
		//Play a round
		EndFunction();
		if (choice == LOAD_EXIT)
			return;
		LoadFile(choice);
	}
}

void LoadFunction::LoadFile(const int& choice)
{
	string file = "Save_*.txt";
	file[5] = choice + '0';

	ifstream stream(file);
	if (stream)
	{
		int mod, turn, size, ttw;
		vector<vector<int>> board;
		stream >> mod >> turn >> size >> ttw;

		board.resize(size);
		for (int i = 0; i < size; i++)
		{
			board[i].resize(size);
			for (int j = 0; j < size; j++)
				stream >> board[i][j];
		}

		
		RoundManager* newRound = new RoundManager(mod, size, ttw, board);
		newRound->StartFunction(turn);
		newRound->EndFunction();
		delete newRound;
	}
}