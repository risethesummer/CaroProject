#include "Board.h"

Board::Board(const int& size, const int& timeToWin)
{
	this->size = size;
	this->timeToWin = timeToWin;
	this->winner = 0;
	this->countInput = 0;

	string pathSize = "BoardSize_";
	pathSize += to_string(size);
	pathSize += ".txt";
	vector<int> boardInfor = FileManager::ReadNumberFile(pathSize);

	this->anchor = Point(boardInfor[0], boardInfor[1]);

	vector<string> xContent = FileManager::ReadTextFile("MarkX.txt");
	vector<string> oContent = FileManager::ReadTextFile("MarkO.txt");
	vector<string> shellContent = FileManager::ReadTextFile("MarkSlot.txt");

	int oldX = anchor.GetX() - (size / 2) * SPACE_X;
	Point clone(oldX, anchor.GetY());
	int color;

	markedPoints.resize(size);
	for (int i = 0; i < size; i++)
	{
		markedPoints[i].resize(size);
		//Assign fixed coordinates for markedPoints
		for (int j = 0; j < size; j++)
		{
			SlotBoard* temp = new SlotBoard(shellContent, xContent, oContent, clone, WHITEGRAY_WHITEGRAY);
			markedPoints[i][j] = temp;
			clone.MoveX(SPACE_X);
		}
		clone.SetX(oldX);
		clone.MoveY(SPACE_Y);
	}

	//Draw the first shell
	currentIndex.Default();
}

Board::Board(const int& size, const int& timeToWin, const vector<vector<int>> points)
	: Board(size, timeToWin)
{
	for (size_t i = 0; i < points.size(); i++)
	{
		for (size_t j = 0; j < points[i].size(); j++)
		{
			if (points[i][j])
			{
				markedPoints[i][j]->SetMark(points[i][j]);
				countInput++;
			}
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			delete markedPoints[i][j];
}

bool Board::IsFull() const
{
	return countInput == size * size;
}

bool Board::IsEndGame() const
{
	return winner != 0;
}

int Board::GetTTW() const
{
	return timeToWin;
}

int Board::GetWinner() const
{
	return winner;
}

int Board::GetSize()
{
	return size;
}

Point Board::GetAnchor()
{
	return this->anchor;
}

vector<PairIndex> Board::AvailableSlots() const
{
	vector<PairIndex> avalableSlots;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (markedPoints[i][j]->GetMark() == 0)
				avalableSlots.push_back(PairIndex(i, j));
		}
	}

	return avalableSlots;
}

void Board::SetMarks(const vector<vector<int>>& marks)
{
	for (int i = 0; i < marks.size(); i++)
	{
		for (int j = 0; j < marks[i].size(); j++)
		{
			markedPoints[i][j]->SetMark(marks[i][j]);
		}
	}
}

vector<vector<SlotBoard*>>* Board::GetPoints()
{
	return &markedPoints;
}

void Board::DrawBoard()
{
	SlotBoard* endPos = markedPoints[size - 1][size - 1];
	SlotBoard* startPos = markedPoints[0][0];
	if (endPos && startPos)
	{
		Point endAnchor = endPos->GetAnchor() + Point(5, 5);
		Screen::DrawArea(startPos->GetAnchor(), endAnchor, GRAY_GRAY);
	}
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			markedPoints[i][j]->Show();
			markedPoints[i][j]->DrawMark();
			Sleep(WAITTODRAW);
		}
	}

	startPos->DrawBound();
}

bool Board::Input(const int& who)
{
	SlotBoard* temp = markedPoints[currentIndex.GetRow()][currentIndex.GetCol()];
	//Is not marked
	if (temp->GetMark() == 0)
	{
		temp->SetMark(who);
		if (CheckState(who, currentIndex))
			winner = who;
		countInput++;
		temp->DrawMark();
		return true;
	}
	return false;
}

bool Board::InputNotAffect(const int& order, const PairIndex& index)
{
	markedPoints[index.GetRow()][index.GetCol()]->SetMark(order);
	if (CheckState(order, index))
		winner = order;
	countInput++;
	return true;
}

bool Board::RetriveInput(const PairIndex& index)
{
	markedPoints[index.GetRow()][index.GetCol()]->SetMark(0);
	countInput--;
	winner = 0;
	return false;
}

void Board::ClearBuffer()
{
	winner = 0;
	countInput = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			markedPoints[i][j]->SetMark(0);
		}
	}
}

void Board::Clear()
{
	SlotBoard* endPos = markedPoints[size - 1][size - 1];
	SlotBoard* startPos = markedPoints[0][0];
	currentIndex.Default();
	if (endPos && startPos)
	{
		Point endAnchor = endPos->GetAnchor() + Point(5, 5);
		Screen::DrawArea(startPos->GetAnchor(), endAnchor, WHITE_WHITE);
	}
}

bool Board::CheckState(const int& mark, const PairIndex& index)
{
	//Need at least 1 of 3 dimension fitting the conditionr
	return CheckByDimension(mark, index, -1, 1)
	|| CheckByDimension(mark, index, 0, 1)
	|| CheckByDimension(mark, index, 1, 0)
	|| CheckByDimension(mark, index, -1, -1);
}

bool Board::CheckByDimension(const int& mark, const PairIndex& index, const int& dimRow, const int& dimCol)
{
	int count = 0;
	PairIndex offset(index);
	//Move to the top left anchor
	offset.Move(-(timeToWin-1)* dimRow, -(timeToWin-1)* dimCol);
	for (int i = -timeToWin + 1; i < timeToWin; i++)
	{
		//Can not go any further
		if ((offset.GetRow() >= size && dimRow >=0)
			|| (offset.GetCol() >= size && dimCol >= 0)
			|| (offset.GetRow() < 0 && dimRow <= 0)
			|| (offset.GetCol() < 0 && dimCol <= 0))
				return false;

		//Still have chance
		if (offset.GetRow() < 0 || offset.GetRow() >= size || offset.GetCol() < 0 || offset.GetCol() >= size)
		{
			//Current offset from the point
			offset.Move(dimRow, dimCol);
			continue;
		}

		if (markedPoints[offset.GetRow()][offset.GetCol()]->GetMark() == mark)
		{
			count++;
			if (count >= timeToWin) //TIMETOWIN continous marks 
				return true;
		}
		else
			count = 0; //Not continous => reset to 0

		//Current offset from the point
		offset.Move(dimRow, dimCol);
	}

	return false; //Not exist a vertical meeting the condition
}

void Board::MoveCursor(const int& offsetRow, const int& offsetCol)
{
	if (offsetRow != 0 || offsetCol != 0)
	{
		PairIndex temp(currentIndex.GetRow() + offsetCol, currentIndex.GetCol() + offsetRow);
		if (temp.IsValid(size, size))
		{
			//Draw new bound
			markedPoints[currentIndex.GetRow()][currentIndex.GetCol()]->ClearBound(GRAY_GRAY);
			markedPoints[temp.GetRow()][temp.GetCol()]->DrawBound();
			currentIndex = temp;
		}
	}
}

void Board::SetCurrentIndex(const int& row, const int& col)
{
	if (row < size && col < size && row >= 0 && col >= 0)
	{
		//Draw new bound
		markedPoints[currentIndex.GetRow()][currentIndex.GetCol()]->ClearBound(GRAY_GRAY);
		markedPoints[row][col]->DrawBound();
		currentIndex.SetRow(row);
		currentIndex.SetCol(col);
	}
}

