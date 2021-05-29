#include "Round.h"

RoundManager::RoundManager(int sizeBoard, Point anchor)
{
	board = new Board(sizeBoard, anchor);
	currentMousePosition = anchor;
}

RoundManager::~RoundManager()
{
	delete board;
}