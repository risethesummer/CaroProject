#include "InteractiveMenu.h"

InteractiveMenu::InteractiveMenu(const vector<string>& paths)
{
	currentPos = 0;
	for (const string& path : paths)
	{
		UIComponent* cur = new UIBound();
		FileManager::ReadComponent(path, *cur);
		UIBound* cast = dynamic_cast<UIBound*>(cur);
		if (cast)
		{
			cast->MakeBound(Point(2, 2), YELLOW_YELLOW);
			boundedComs.push_back(cast);
		}
	}
}

InteractiveMenu::~InteractiveMenu()
{
	for (int i = 0; i < boundedComs.size(); i++)
		if (boundedComs[i])
			delete boundedComs[i];
}

UIComponent* InteractiveMenu::GetComponent(const int& index) const
{
	return boundedComs[index];
}

int InteractiveMenu::CountComponents() const
{
	return boundedComs.size();
}

int InteractiveMenu::Interact()
{
	char temp;
	vector<char>* keys = KeyMapping::GetMenuKeys();
	while (true)
	{
		temp = Input::GetInput(*keys);
		switch (temp)
		{
		case 'W':
		case ARROW_UP:
			SwitchComponent(-1);
			break;
		case 'S':
		case ARROW_DOWN:
			SwitchComponent(1);
			break;
		case 'E':
		case ENTER:
			return currentPos;
		}
	}
}

void InteractiveMenu::SetColor(const int& color)
{
	for (UIBound* bound : boundedComs)
		bound->MakeBound(Point(2, 2), color);
}

void InteractiveMenu::SwitchComponent(const int& off)
{

	boundedComs[currentPos]->ClearBound();

	int newPos = currentPos + off;
	//Out of top
	if (newPos < 0)
		currentPos = boundedComs.size() - 1;
	//Out of bottom
	else if (newPos >= boundedComs.size())
		currentPos = 0;
	else
		currentPos = newPos;

	boundedComs[currentPos]->DrawBound();
}

void InteractiveMenu::Show()
{
	for (size_t i = 0; i < boundedComs.size(); i++)
		boundedComs[i]->Show();
	boundedComs[0]->DrawBound();
}

void InteractiveMenu::Show(const int& show)
{
	if (show >= 0 && show < boundedComs.size())
		boundedComs[show]->Show();
}

void InteractiveMenu::DrawBound(const int& bound)
{
	if (bound >= 0 && bound < boundedComs.size())
	{
		boundedComs[currentPos]->ClearBound();
		currentPos = bound;
		boundedComs[bound]->DrawBound();
	}
}

void InteractiveMenu::HideBound(const int& bound)
{
	if (bound >= 0 && bound < boundedComs.size())
	{
		currentPos = bound;
		boundedComs[bound]->ClearBound();
	}
}


void InteractiveMenu::Hide()
{
	//Not contains any element
	if (boundedComs.size() > 0)
	{
		boundedComs[currentPos]->ClearBound();
		for (size_t i = 0; i < boundedComs.size(); i++)
			boundedComs[i]->Hide();
		currentPos = 0;
	}
}

void InteractiveMenu::Hide(const int& hide)
{
	if (hide >= 0 && hide < boundedComs.size())
		boundedComs[hide]->Hide();
}
