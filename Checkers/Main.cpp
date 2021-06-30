#include "CheckersGame.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"

int main()
{
	/**
	You can swap what type of players you would like to play in the game.
	Combinations such as AI vs. AI or Human vs. AI are valid.
	*/

    CheckersGame game;
    CheckersBoard board;
    ComputerPlayer playerOne;
    HumanPlayer playerTwo; // Can also be set to another ComputerPlayer

    game.SetCheckersBoard(board);
    game.SetPlayers(playerOne, playerTwo);

    game.PrintIntro();
    game.ClearScreen();

    while(!game.IsGameOver())
    {
        game.PrintGame();
        game.PlayTurn();
        game.ClearScreen();
    }

    return 0;
}