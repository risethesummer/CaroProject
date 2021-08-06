#ifndef MENU_H
#define MENU_H
#include "UIComponent.h"
#include "FileManager.h"

class Menu
{
private:
	vector<UIComponent*> components;
public:
	virtual ~Menu();
	Menu();
	Menu(const vector<string>& paths);
	virtual void GraduallyShow(const float& timeStep);
	virtual void GraduallyHide(const float& timeStep);
	virtual UIComponent* GetComponent(const int& index) const;
	virtual void Show();
	virtual void Show(const int& comIndex);
	virtual void Hide();
	virtual void Hide(const int& hide);
};

#endif
