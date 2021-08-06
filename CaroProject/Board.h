#ifndef BOARD_H
#define BOARD_H
#define SPACE_X 10
#define SPACE_Y 7
#define WAITTODRAW 50
#include "SlotBoard.h"
#include "PairIndex.h"
#include "KeyMapping.h"
#include "Screen.h"
#include "FileManager.h"
#include <Windows.h>
#include "SettingFunction.h"

class Board
{
	private:
		int size;
		//Determine the board is full or not
		int countInput;
		//Top left anchor to print the board
		Point anchor; 
		//Points to be marked by users
		vector<vector<SlotBoard*>> markedPoints; 
		vector<PairIndex> winSlots;
		PairIndex currentIndex;
		int timeToWin;
		int winner = 0;
		//Receiving mark of the player (1, 2)
		//And what dimenstion need to be active => (1, 0) => hor, (0, 1) => ver, (1, 1) => dia
		bool CheckByDimension(const int& mark, const PairIndex&, const int&, const int&);
		bool CheckState(const int&, const PairIndex&);
	public:
		Board(const int& size, const int& timeToWin);
		Board(const int& size, const int& timeToWin, const vector<vector<int>> points);
		~Board();
		bool IsFull() const;
		bool IsEndGame() const;
		int GetTTW() const;
		int GetWinner() const;
		int GetSize();
		Point GetAnchor();
		vector<PairIndex> AvailableSlots() const;
		void SetMarks(const vector<vector<int>>& marks);
		vector<vector<SlotBoard*>>* GetPoints();
		void DrawBoard();
		void ShowEndGame();
		void MoveCursor(const int& offsetRow, const int& offsetCol);
		void SetCurrentIndex(const int& row, const int& col);
		bool Input(const int&); //Draw user's move and return the state of the board after moving
		bool InputNotAffect(const int& order, const PairIndex& index);
		bool RetriveInput(const PairIndex& index);
		void ClearBuffer();
		void Clear(); //Clear previous data
};

#endif // !BOARD_H

