#include "PairIndex.h"

PairIndex::PairIndex()
{
	column = 0;
	row = 0;
}

PairIndex::PairIndex(const int& r, const int& c)
{
	if (r >= 0)
		row = r;
	else
		row = 0;

	if (c >= 0)
		column = c;
	else
		column = 0;
}

PairIndex::PairIndex(const PairIndex& p)
{
	row = p.GetRow();
	column = p.GetCol();
}

void PairIndex::Default()
{
	row = 0;
	column = 0;
}

int PairIndex::GetCol() const
{
	return column;
}

int PairIndex::GetRow() const
{
	return row;
}

void PairIndex::SetRow(const int& r)
{
	if (r >= 0)
		row = r;
}

void PairIndex::SetCol(const int& c)
{
	if (c >= 0)
		column = c;
}

void PairIndex::Move(const int& row, const int& col)
{
	this->row += row;
	this->column += col;
}

void PairIndex::MoveCol(const int& off)
{
	column += off;
}

bool PairIndex::IsValid(const int& maxRow, const int& maxCol) const
{
	return row >= 0 && row < maxRow && column >= 0 && column < maxCol;
}

PairIndex PairIndex::operator+(const PairIndex& p)
{
	return PairIndex(row + p.GetRow(), column + p.GetCol());
}

void PairIndex::MoveRow(const int& off)
{
	row += off;
}