
#ifndef CHECKERS_RULES_ENGINE_H
#define CHECKERS_RULES_ENGINE_H
#pragma once

#include "CheckersMoves.h"
#include "CheckersTypes.h"
#include "CheckersBoard.h"

class CheckersRulesEngine
{
public:
    CheckersRulesEngine(void);

    BaseMoveList GetPossibleMoves(const CheckersBoard& board, PieceType pieceType) const;

private:
    CheckersRulesEngine(const CheckersRulesEngine& rulesEngine);
    CheckersRulesEngine& operator=(const CheckersRulesEngine& rulesEngine);

    SingleMoveList GetAvailableBoardMoves(const CheckersBoard& board, const BoardPosition& piecePosition, PieceType pieceType) const;
    SingleJumpList GetAvailableBoardJumps(const CheckersBoard& board, const BoardPosition& piecePosition, PieceType pieceType) const;
    bool IsValidMove(const CheckersBoard& board, const BoardPosition& destinationPosition) const;
};

#endif // CHECKERS_RULES_ENGINE_H