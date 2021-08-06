#ifndef UI_COMPONENT_H
#define UI_COMPONENT_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Point.h"
#include "Screen.h"
#include "Color.h"

class UIComponent
{
protected:
	vector<std::string> content;
	int color;
	Point anchor;
public:
	UIComponent();
	UIComponent(const vector<std::string>& content, const Point& anchor, const int& color);
	UIComponent(const UIComponent&);
	Point GetAnchor() const;
	vector<string> GetContent() const;
	int GetColor() const;
	void SetAnchor(const Point&);
	void SetAnchor(const int&, const int&);
	void SetContent(const vector<string>& content);
	void SetColor(const int&);
	virtual void Show() const;
	virtual void Hide(const int& replaceColor = DEFAULT) const;
	friend ifstream& operator>>(ifstream& stream, UIComponent& com);
};

#endif // MENU_H

