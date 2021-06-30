#ifndef CHECKERS_SINGLE_MOVE_H
#define CHECKERS_SINGLE_MOVE_H
#pragma once

#include "ICheckersBaseMove.h"

class CheckersSingleMove : public ICheckersBaseMove
{
public: 
    CheckersSingleMove(BoardPosition source, BoardPosition destination);

    virtual void UpdateBoard(CheckersBoard& board, PieceType pieceType);
    virtual const BoardPosition& GetSourcePosition() const;
    virtual const BoardPosition& GetDestinationPosition() const;

private:
    BoardPosition mSource;
    BoardPosition mDestination;
};

typedef std::vector<CheckersSingleMove*> SingleMoveList;

#endif // CHECKERS_SINGLE_JUMP_H