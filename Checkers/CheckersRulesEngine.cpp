#include "CheckersRulesEngine.h"

CheckersRulesEngine::CheckersRulesEngine(void)
{
}

BaseMoveList CheckersRulesEngine::GetPossibleMoves(const CheckersBoard& board, PieceType pieceType) const
{
    BoardPositionList currentPiecePositions = board.GetAllPiecePositions(pieceType);
    BaseMoveList totalPossibleMoves;

	// Check if jumps are available
    for(unsigned int i = 0; i < currentPiecePositions.size(); ++i)
    {
        const SingleJumpList& possibleJumps = GetAvailableBoardJumps(board, currentPiecePositions[i], pieceType);

        if(!possibleJumps.empty())
        {
            totalPossibleMoves.insert(totalPossibleMoves.end(), possibleJumps.begin(), possibleJumps.end());
        }
    }

	// If jumps are available, a jump must be made, therefore we should return those moves early
    if(!totalPossibleMoves.empty())
    {
        return totalPossibleMoves;
    }

	// Check if normal moves are available
    for(unsigned int i = 0; i < currentPiecePositions.size(); ++i)
    {
        const SingleMoveList& possibleMoves = GetAvailableBoardMoves(board, currentPiecePositions[i], pieceType);

        if(!possibleMoves.empty())
        {
            totalPossibleMoves.insert(totalPossibleMoves.end(), possibleMoves.begin(), possibleMoves.end());
        }
    }
    return totalPossibleMoves;
}

SingleMoveList CheckersRulesEngine::GetAvailableBoardMoves(const CheckersBoard& board, const BoardPosition& piecePosition, PieceType pieceType) const
{
    SingleMoveList singleMovesAvailable;

    if(pieceType == WHITE_PIECE)
    {
        BoardPosition bottomLeft(piecePosition.mRow + 1, piecePosition.mColumn - 1);

		// Is the bottom left square available
        if(IsValidMove(board, bottomLeft))
        {
            singleMovesAvailable.push_back(new CheckersSingleMove(piecePosition, bottomLeft));
        }

        BoardPosition bottomRight(piecePosition.mRow + 1, piecePosition.mColumn + 1);

		// Is the bottom right square available
        if(IsValidMove(board, bottomRight))
        {
            singleMovesAvailable.push_back(new CheckersSingleMove(piecePosition, bottomRight));
        }
    }
    else if(pieceType == BLACK_PIECE)
    {
        BoardPosition topLeft(piecePosition.mRow - 1, piecePosition.mColumn - 1);

		// Is the top left square available
        if(IsValidMove(board, topLeft))
        {
            singleMovesAvailable.push_back(new CheckersSingleMove(piecePosition, topLeft));
        }

        BoardPosition topRight(piecePosition.mRow - 1, piecePosition.mColumn + 1);

		// Is the top right square available
        if(IsValidMove(board, topRight))
        {
            singleMovesAvailable.push_back(new CheckersSingleMove(piecePosition, topRight));
        }
    }
    return singleMovesAvailable;
}

SingleJumpList CheckersRulesEngine::GetAvailableBoardJumps(const CheckersBoard& board, const BoardPosition& piecePosition, PieceType pieceType) const
{
    SingleJumpList singleJumpsAvailable;

    if(pieceType == WHITE_PIECE)
    {
        BoardPosition bottomLeftJump(piecePosition.mRow + 2, piecePosition.mColumn - 2);

		// Is the bottom left jump available
        if(IsValidMove(board, bottomLeftJump))
        {
            BoardPosition bottomLeft(piecePosition.mRow + 1, piecePosition.mColumn - 1);

			// Is the bottom left square an enemy
            if(board.GetPieceTypeAtPosition(bottomLeft) == BLACK_PIECE)
            {
                singleJumpsAvailable.push_back(new CheckersSingleJump(piecePosition, bottomLeftJump, bottomLeft));
            }
        }

        BoardPosition bottomRightJump(piecePosition.mRow + 2, piecePosition.mColumn + 2);

		// Is the bottom right jump available
        if(IsValidMove(board, bottomRightJump))
        {
            BoardPosition bottomRight(piecePosition.mRow + 1, piecePosition.mColumn + 1);

			// Is the bottom right square an enemy
            if(board.GetPieceTypeAtPosition(bottomRight) == BLACK_PIECE)
            {
                singleJumpsAvailable.push_back(new CheckersSingleJump(piecePosition, bottomRightJump, bottomRight));
            }
        }
    }
    else if(pieceType == BLACK_PIECE)
    {
        BoardPosition topLeftJump(piecePosition.mRow - 2, piecePosition.mColumn - 2);

		// Is the top left jump available
        if(IsValidMove(board, topLeftJump))
        {
            BoardPosition topLeft(piecePosition.mRow - 1, piecePosition.mColumn - 1);

			// Is the top left square an enemy
            if(board.GetPieceTypeAtPosition(topLeft) == WHITE_PIECE)
            {
                singleJumpsAvailable.push_back(new CheckersSingleJump(piecePosition, topLeftJump, topLeft));
            }
        }

        BoardPosition topRightJump(piecePosition.mRow - 2, piecePosition.mColumn + 2);

		// Is the top right jump available
        if(IsValidMove(board, topRightJump))
        {
            BoardPosition topRight(piecePosition.mRow - 1, piecePosition.mColumn + 1);

			// Is the top right square an enemy
            if(board.GetPieceTypeAtPosition(topRight) == WHITE_PIECE)
            {
                singleJumpsAvailable.push_back(new CheckersSingleJump(piecePosition, topRightJump, topRight));
            }
        }
    }
    return singleJumpsAvailable;
}

bool CheckersRulesEngine::IsValidMove(const CheckersBoard& board, const BoardPosition& destinationPosition) const
{
	// Are we within the bounds of the board
    if(!board.IsPositionOutOfBounds(destinationPosition))
    {
		// Is that piece an empty spot
        if(board.GetPieceTypeAtPosition(destinationPosition) == NO_PIECE)
        {
            return true;
        }
    }
    return false;
}