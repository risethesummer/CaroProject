#include "UIComponent.h"

UIComponent::UIComponent()
{
	color = DEFAULT;
	anchor.SetX(0);
	anchor.SetY(0);
}

UIComponent::UIComponent(const vector<std::string>& newContent, const Point& point, const int& color)
{
	this->content = newContent;
	this->anchor = point;
	this->color = color;
}

UIComponent::UIComponent(const UIComponent& u) : UIComponent(u.content, u.anchor, u.color)
{
}

Point UIComponent::GetAnchor() const
{
	return anchor;
}

vector<string> UIComponent::GetContent() const
{
	return content;
}

int UIComponent::GetColor() const
{
	return color;
}

void UIComponent::SetAnchor(const Point& p)
{
	this->anchor = p;
}

void UIComponent::SetAnchor(const int& x, const int& y)
{
	anchor.SetX(x);
	anchor.SetY(y);
}

void UIComponent::SetContent(const vector<string>& content)
{
	this->content = content;
}

void UIComponent::SetColor(const int& newColor)
{
	this->color = newColor;
}

void UIComponent::Show() const
{
	Screen::Draw(anchor, content, color);
}

void UIComponent::Hide(const int& replaceColor) const
{
	Screen::Draw(anchor, content, replaceColor);
}
