#include "CheckersSingleMove.h"

CheckersSingleMove::CheckersSingleMove(BoardPosition source, BoardPosition destination)
:   mSource(source),
    mDestination(destination)
{
}

void CheckersSingleMove::UpdateBoard(CheckersBoard& board, PieceType pieceType)
{
    board.SetPieceAtPosition(pieceType, mDestination);
    board.SetPieceAtPosition(NO_PIECE, mSource);
}

const BoardPosition& CheckersSingleMove::GetSourcePosition() const
{
    return mSource;
}

const BoardPosition& CheckersSingleMove::GetDestinationPosition() const
{
    return mDestination;
}