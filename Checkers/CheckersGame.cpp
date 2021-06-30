#include "CheckersGame.h"
#include <iostream>
#include <algorithm>
#include <memory>
#include <chrono>
#include <thread>

CheckersGame::CheckersGame(void)
:   mCheckersBoard(),
    mRulesEngine(),
    mPlayerOne(NULL),
    mPlayerTwo(NULL),
    mGameover(false)
{
}

void CheckersGame::PrintIntro() const
{
#pragma warning( push )
#pragma warning( disable : 4129 )
    std::cout << "  ____  _ _                      _        \n"
              << " | __ )| (_)__________ _ _ __ __| |       \n"
              << " |  _ \\| | |_  /_  / _` | '__/ _` |       \n"
              << " | |_) | | |/ / / / (_| | | | (_| |       \n"
              << " |____/|_|_/___/___\\__,_|_|  \\__,_|       \n"
              << "  / ___| |__   ___  ___| | _____ _ __ ___ \n"
              << " | |   | '_ \\ / _ \\/ __| |/ / _ \\ '__/ __|\n"
              << " | |___| | | |  __/ (__|   <  __/ |  \\__ \\\n"
              << "  \\____|_| |_|\\___|\\___|_|\\_\\___|_|  |___/\n";
#pragma warning( pop )
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}

void CheckersGame::PrintGame() const
{
    std::cout << "Blizzard Checkers!\n" << std::endl;
    mCheckersBoard.PrintBoard();
}

void CheckersGame::ClearScreen() const
{
#ifdef WIN32
    system("cls");
#endif
}

bool CheckersGame::IsGameOver() const
{
    return mGameover;
}

void CheckersGame::SetPlayers(const IPlayer& playerOne, const IPlayer& playerTwo)
{
    mPlayerOne = &playerOne;
    mPlayerTwo = &playerTwo;
}

void CheckersGame::SetCheckersBoard(const CheckersBoard& checkersBoard)
{
    mCheckersBoard = checkersBoard;
}

void CheckersGame::PlayTurn()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    if(NULL == mPlayerOne || NULL == mPlayerTwo)
    {
        mGameover = true;
        return;
    }

    BaseMoveList& playerOnePossibleMoves = mRulesEngine.GetPossibleMoves(mCheckersBoard, WHITE_PIECE);

    if(!playerOnePossibleMoves.empty())
    {
        ICheckersBaseMove* playerOneMove = mPlayerOne->RequestAction(playerOnePossibleMoves);
        playerOneMove->UpdateBoard(mCheckersBoard, WHITE_PIECE);
    }

    BaseMoveList& playerTwoPossibleMoves = mRulesEngine.GetPossibleMoves(mCheckersBoard, BLACK_PIECE);

    if(!playerTwoPossibleMoves.empty())
    {
        ICheckersBaseMove* playerTwoMove = mPlayerTwo->RequestAction(playerTwoPossibleMoves);
        playerTwoMove->UpdateBoard(mCheckersBoard, BLACK_PIECE);
    }

    if(playerOnePossibleMoves.empty() && playerTwoPossibleMoves.empty())
    {
        std::cout << "Draw! Press Enter to exit...";
        std::cin.get();
        mGameover = true;
    }

    if(!mGameover && playerOnePossibleMoves.empty())
    {
        std::cout << "Player two wins! Press Enter to exit...";
        std::cin.get();
        mGameover = true;
    }

    if(!mGameover && playerTwoPossibleMoves.empty())
    {
        std::cout << "Player One wins! Press Enter to exit...";
        std::cin.get();
        mGameover = true;
    }

    CleanUpMovesList(playerOnePossibleMoves);
    CleanUpMovesList(playerTwoPossibleMoves);
}

void CheckersGame::CleanUpMovesList(BaseMoveList& moveList) const
{
    std::for_each(moveList.begin(), moveList.end(), std::default_delete<ICheckersBaseMove>());
    moveList.clear();
}