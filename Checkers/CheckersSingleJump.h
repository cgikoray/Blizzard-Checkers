#ifndef CHECKERS_SINGLE_JUMP_H
#define CHECKERS_SINGLE_JUMP_H
#pragma once

#include "ICheckersBaseMove.h"

class CheckersSingleJump : public ICheckersBaseMove
{
public: 
    CheckersSingleJump(BoardPosition source, BoardPosition destination, BoardPosition elimination);

    virtual void UpdateBoard(CheckersBoard& board, PieceType pieceType);
    virtual const BoardPosition& GetSourcePosition() const ;
    virtual const BoardPosition& GetDestinationPosition() const;

private:
    BoardPosition mSource;
    BoardPosition mDestination;
    BoardPosition mElimination;
};

typedef std::vector<CheckersSingleJump*> SingleJumpList;

#endif // CHECKERS_SINGLE_JUMP_H