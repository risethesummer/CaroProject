#ifndef INTERACTIVE_MENU_H
#define INTERACTIVE_MENU_H
#include "Menu.h"
#include "UIBound.h"
#include "Input.h"
#include "KeyMapping.h"

class InteractiveMenu : public Menu
{
private:
	int currentPos;
	vector<UIBound*> boundedComs;
public:
	InteractiveMenu(const vector<string>& path);
	~InteractiveMenu();
	UIComponent* GetComponent(const int& index) const;
	int CountComponents() const; 
	int Interact();
	void SetColor(const int& color);
	void SwitchComponent(const int&);
	void Show();
	void Show(const int& show);
	void DrawBound(const int& bound);
	void HideBound(const int& bound);
	void Hide();
	void Hide(const int& hide);
};

#endif  