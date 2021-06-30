#ifndef CHECKERS_GAME_H
#define CHECKERS_GAME_H
#pragma once

#include "CheckersRulesEngine.h"
#include "IPlayer.h"

class CheckersGame
{
public:
    CheckersGame(void);
    
    void PrintIntro() const;
    void PrintGame() const;
    void ClearScreen() const;
    void SetPlayers(const IPlayer& playerOne, const IPlayer& playerTwo);
    void SetCheckersBoard(const CheckersBoard& checkersBoard);
    void PlayTurn();
    bool IsGameOver() const;

private:
    CheckersGame(const CheckersGame& checkersGame);
    CheckersGame& operator=(const CheckersGame& checkersGame);

    void CleanUpMovesList(BaseMoveList& moveList) const;

    CheckersBoard mCheckersBoard;
    CheckersRulesEngine mRulesEngine;
    const IPlayer* mPlayerOne;
    const IPlayer* mPlayerTwo;
    bool mGameover;
};

#endif // CHECKERS_GAME_H