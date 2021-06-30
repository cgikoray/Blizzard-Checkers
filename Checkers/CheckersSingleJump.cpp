#include "CheckersSingleJump.h"

CheckersSingleJump::CheckersSingleJump(BoardPosition source, BoardPosition destination, BoardPosition elimination)
:   mSource(source),
    mDestination(destination),
    mElimination(elimination)
{
}

void CheckersSingleJump::UpdateBoard(CheckersBoard& board, PieceType pieceType)
{
    board.SetPieceAtPosition(pieceType, mDestination);
    board.SetPieceAtPosition(NO_PIECE, mElimination);
    board.SetPieceAtPosition(NO_PIECE, mSource);
}

const BoardPosition& CheckersSingleJump::GetSourcePosition() const
{
    return mSource;
}

const BoardPosition& CheckersSingleJump::GetDestinationPosition() const
{
    return mDestination;
}