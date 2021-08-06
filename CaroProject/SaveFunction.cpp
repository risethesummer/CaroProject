#include "SaveFunction.h"

SaveFunction* SaveFunction::init = nullptr;

SaveFunction::SaveFunction()
	: Function({"Save_None.txt", "Save_Has.txt"})
{
}

SaveFunction* SaveFunction::GetInit()
{
	if (!init)
		init = new SaveFunction();
	return init;
}


void SaveFunction::StartFunction(const int& mode, const string& playerName, 
	const int& turn, const int& ttw, vector<vector<SlotBoard*>>* move)
{
	staticMenu->Show();
	for (int i = 0; i < MAX_SLOT; i++)
	{
		ifstream check("Save_" + to_string(i) + ".txt");
		if (check)
			dynamicMenu->GetComponent(i)->SetColor(RED_RED);
		dynamicMenu->Show(i);
		check.close();
	}

	dynamicMenu->GetComponent(MAX_SLOT)->Show();
	dynamicMenu->DrawBound(0);
	int choice = dynamicMenu->Interact();

	if (choice == MAX_SLOT)
		return;

	if (move)
	{
		ofstream stream("Save_" + to_string(choice) + ".txt");
		stream << mode << '\n' << turn << '\n' << move->size() << '\n' << ttw <<'\n';
		for (const vector<SlotBoard*>& moveVec : *move)
		{
			for (SlotBoard* const& m : moveVec)
				stream << m->GetMark() << " ";
			stream << '\n';
		}
		stream.close();

		//https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);
		ofstream streamShow("Save_Show_" + to_string(choice) + ".txt");
		streamShow 
			<< "Save slot: " << choice << "\n\n"
			<< "Time: " << newtime.tm_hour << ":" << newtime.tm_min << ":" << newtime.tm_sec
			<< "-" << 1900 + newtime.tm_year << ":" << 1 + newtime.tm_mon << ":" << newtime.tm_mday << "\n\n"
			<< "Mode: " << playerName;
		streamShow.close();
	}
}
