#include "CheckersBoard.h"
#include <iostream>

namespace
{
    const char PLAYER_ONE_PIECE = 'X';
    const char PLAYER_TWO_PIECE = 'O';
    const char EMPTY_PIECE_SLOT = '-';
}

CheckersBoard::CheckersBoard(void)
{
    // Initialize the board cleared
    for(unsigned int row = 0; row < ROW_COLUMN_LENGTH; ++row)
    {
        for (unsigned int column = 0; column < ROW_COLUMN_LENGTH; ++column)
        {
            mBoard[row][column] = NO_PIECE;
        }
    }

    // Initialize all the white pieces
    mBoard[0][1] = WHITE_PIECE;
    mBoard[0][3] = WHITE_PIECE;
    mBoard[0][5] = WHITE_PIECE;
    mBoard[0][7] = WHITE_PIECE;
    mBoard[1][0] = WHITE_PIECE;
    mBoard[1][2] = WHITE_PIECE;
    mBoard[1][4] = WHITE_PIECE;
    mBoard[1][6] = WHITE_PIECE;
    mBoard[2][1] = WHITE_PIECE;
    mBoard[2][3] = WHITE_PIECE;
    mBoard[2][5] = WHITE_PIECE;
    mBoard[2][7] = WHITE_PIECE;

    // Initialize all black pieces
    mBoard[5][0] = BLACK_PIECE;
    mBoard[5][2] = BLACK_PIECE;
    mBoard[5][4] = BLACK_PIECE;
    mBoard[5][6] = BLACK_PIECE;
    mBoard[6][1] = BLACK_PIECE;
    mBoard[6][3] = BLACK_PIECE;
    mBoard[6][5] = BLACK_PIECE;
    mBoard[6][7] = BLACK_PIECE;
    mBoard[7][0] = BLACK_PIECE;
    mBoard[7][2] = BLACK_PIECE;
    mBoard[7][4] = BLACK_PIECE;
    mBoard[7][6] = BLACK_PIECE;
}

CheckersBoard::CheckersBoard(const CheckersBoard& checkersBoard)
{
    for(unsigned int row = 0; row < ROW_COLUMN_LENGTH; ++row)
    {
        for (unsigned int column = 0; column < ROW_COLUMN_LENGTH; ++column)
        {
            mBoard[row][column] = checkersBoard.mBoard[row][column];
        }
    }
}
CheckersBoard& CheckersBoard::operator=(const CheckersBoard& checkersBoard)
{
    for(unsigned int row = 0; row < ROW_COLUMN_LENGTH; ++row)
    {
        for (unsigned int column = 0; column < ROW_COLUMN_LENGTH; ++column)
        {
            mBoard[row][column] = checkersBoard.mBoard[row][column];
        }
    }
    return *this;
}

void CheckersBoard::PrintBoard() const
{
    std::cout << "   1 2 3 4 5 6 7 8\n" << std::endl;

    for(unsigned int row = 0; row < ROW_COLUMN_LENGTH; ++row)
    {
        std::cout << row + 1 << "  ";

        for (unsigned int column = 0; column < ROW_COLUMN_LENGTH; ++column)
        {
            PieceType pieceType = mBoard[row][column];

            switch(pieceType)
            {
                case NO_PIECE:
                {
                    std::cout << ::EMPTY_PIECE_SLOT << " ";
                    break;
                }
                case BLACK_PIECE :
                {
                    std::cout << ::PLAYER_TWO_PIECE << " ";
                    break;
                }
                case WHITE_PIECE :
                {
                    std::cout << ::PLAYER_ONE_PIECE << " ";
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

void CheckersBoard::SetPieceAtPosition(PieceType pieceType, const BoardPosition& boardPosition)
{
    mBoard[boardPosition.mRow][boardPosition.mColumn] = pieceType;
}

BoardPositionList CheckersBoard::GetAllPiecePositions(PieceType pieceType) const
{ 
    BoardPositionList positionList;

    for(unsigned int row = 0; row < ROW_COLUMN_LENGTH; ++row)
    {
        for (unsigned int column = 0; column < ROW_COLUMN_LENGTH; ++column)
        {
            if(mBoard[row][column] == pieceType)
            {
                positionList.push_back(BoardPosition(row, column));
            }
        }
    }
    return positionList;
}

PieceType CheckersBoard::GetPieceTypeAtPosition(const BoardPosition& boardPosition) const
{
    return mBoard[boardPosition.mRow][boardPosition.mColumn];
}

bool CheckersBoard::IsPositionOutOfBounds(const BoardPosition& boardPosition) const
{
    return (boardPosition.mRow < 0 || boardPosition.mRow > ROW_COLUMN_LENGTH - 1) || (boardPosition.mColumn < 0 || boardPosition.mColumn > ROW_COLUMN_LENGTH - 1);
}