#ifndef CHECKERS_BOARD_H
#define CHECKERS_BOARD_H
#pragma once

#include "CheckersTypes.h"

class CheckersBoard
{
public:
    CheckersBoard(void);
    CheckersBoard(const CheckersBoard& checkersBoard);
    CheckersBoard& operator=(const CheckersBoard& checkersBoard);

    void PrintBoard() const;
    void SetPieceAtPosition(PieceType pieceType, const BoardPosition& boardPosition);
    BoardPositionList GetAllPiecePositions(PieceType pieceType) const;
    PieceType GetPieceTypeAtPosition(const BoardPosition& boardPosition) const;
    bool IsPositionOutOfBounds(const BoardPosition& boardPosition) const;

    static const unsigned int ROW_COLUMN_LENGTH = 8;

private:
    PieceType mBoard[ROW_COLUMN_LENGTH][ROW_COLUMN_LENGTH];
};

#endif // CHECKERS_BOARD_H