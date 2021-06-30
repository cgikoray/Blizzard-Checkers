#ifndef I_CHECKERS_BASE_MOVE_H
#define I_CHECKERS_BASE_MOVE_H
#pragma once

#include "CheckersBoard.h"

class ICheckersBaseMove
{
public: 
    ICheckersBaseMove() { }
    virtual ~ICheckersBaseMove() { }

    virtual void UpdateBoard(CheckersBoard& board, PieceType pieceType) = 0;
    virtual const BoardPosition& GetSourcePosition() const = 0;
    virtual const BoardPosition& GetDestinationPosition() const = 0;
};

typedef std::vector<ICheckersBaseMove*> BaseMoveList;

#endif // I_CHECKERS_BASE_MOVE_H