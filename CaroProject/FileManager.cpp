#include "FileManager.h"


vector<string> FileManager::ReadTextFile(const string& path)
{
	ifstream fileStream(path);
	vector<string> result;
	if (fileStream)
	{
		string temp;
		while (getline(fileStream, temp))
			result.push_back(temp);
	}

	fileStream.close();
	return result;
}

vector<int> FileManager::ReadNumberFile(const string& path)
{
	ifstream fileStream(path);
	vector<int> result;
	int temp;
	while (!fileStream.eof())
	{
		fileStream >> temp;
		result.push_back(temp);
	}
	fileStream.close();
	return result;
}

void FileManager::ReadComponent(const string& path, UIComponent& com)
{
	ifstream stream(path);
	
	if (stream)
	{
		if (stream)
			stream >> com;
	}
	stream.close();
}


ifstream& operator>>(ifstream& stream, UIComponent& com)
{
	stream >> com.color;
	stream >> com.anchor;
	string temp;
	while (getline(stream, temp))
	{
		if (!temp.empty())
			com.content.push_back(temp);
	}
	return stream;
}

std::ifstream& operator>>(std::ifstream& stream, Point& point)
{
	stream >> point.x >> point.y;
	return stream;
}