#include "Menu.h"

Menu::~Menu()
{
	for (int i = 0; i < components.size(); i++)
		if (components[i])
			delete components[i];
}

Menu::Menu()
{
}

Menu::Menu(const vector<string>& paths)
{
	for (const string& path : paths)
	{
		UIComponent* temp = new UIComponent();
		FileManager::ReadComponent(path, *temp);
		components.push_back(temp);
	}
}

void Menu::GraduallyShow(const float& timeStep)
{
	for (UIComponent* com : components)
	{
		com->Show();
		Sleep(timeStep);
	}
}

void Menu::GraduallyHide(const float& timeStep)
{
	for (UIComponent* com : components)
	{
		com->Hide();
		Sleep(timeStep);
	}
}

UIComponent* Menu::GetComponent(const int& index) const
{
	return components[index];
}

void Menu::Show()
{
	for (size_t i = 0; i < components.size(); i++)
	{
		if (components[i])
			components[i]->Show();
	}
}


void Menu::Show(const int& comIndex)
{
	if (comIndex >= 0 && comIndex < components.size())
		components[comIndex]->Show();
}

void Menu::Hide()
{
	for (size_t i = 0; i < components.size(); i++)
		if (components[i])
			components[i]->Hide();
}

void Menu::Hide(const int& hide)
{
	if (hide >= 0 && hide < components.size())
		components[hide]->Hide();
}

