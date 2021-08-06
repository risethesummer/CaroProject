#ifndef PAIR_INDEX_H
#define PAIR_INDEX_H

class PairIndex
{
private:
	int row;
	int column;
public:
	PairIndex();
	PairIndex(const int&, const int&);
	PairIndex(const PairIndex&);
	void Default();
	int GetRow() const;
	int GetCol() const;
	void SetRow(const int&);
	void SetCol(const int&);
	void Move(const int& row, const int& col);
	void MoveRow(const int& offset);
	void MoveCol(const int& offset);
	bool IsValid(const int& maxRow, const int& maxCol) const;
	PairIndex operator+(const PairIndex&);
};

#endif
