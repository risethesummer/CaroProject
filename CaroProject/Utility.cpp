#include "Utility.h"

template <class T>
int Utility::GetMax(const vector<T>& v)
{
	int cur = 0;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] > v[cur])
			cur = i;
	}

	return cur;
}

int Utility::GetMaxLength(const vector<string>& strs)
{
	int cur = strs[0].length();
	for (int i = 1; i < strs.size(); i++)
	{
		if (strs[i].length() > cur)
			cur = strs[i].length();
	}
	return cur;
}

//Get a string with chchchchch
string Utility::GetCharString(const int& size, const char& ch)
{
	string str;
	for (int i = 0; i < size; i++)
		str += ch;
	return str;
}

vector<string> Utility::CreateRectangleContent(const vector<string>& content, const Point& offset)
{
	int width = GetMaxLength(content) + offset.GetX() * 2;
	int height = content.size() + offset.GetY() * 2;
	vector<string> recContent;
	recContent.resize(height);
	for (string& row : recContent)
		row.resize(width);
	for (int i = 0; i < height; i++)
	{
		//The first and the last is filled fully
		if (i == 0 || i == height - 1)
		{
			for (char& ch : recContent[i])
				ch = '*';
		}
		else
		{
			string& temp = recContent[i];
			temp[0] = '*';
			temp[temp.length() - 1] = '*';
			for (int j = 1; j < temp.length() - 1; j++)
				temp[j] = ' ';
		}
	}

	return recContent;
}
