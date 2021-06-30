#include "HumanPlayer.h"
#include <iostream>
#include <string>

namespace
{
    const char* const INVALID_MOVE = "\nThat is not a valid move, please try again.\n";
}

HumanPlayer::HumanPlayer()
{
}

ICheckersBaseMove* HumanPlayer::RequestAction(const BaseMoveList& availableMoves) const
{
    std::cout << "Enter a move to perform.\n\n" 
              << "Format should be like the example: 1 1 2 2\n"
              << "First two numbers are source row and column\n"
              << "Second two numbers are destination row and column.\n" << std::endl;

    BoardPosition sourcePosition;
    BoardPosition destinationPosition;
    std::string input;

    while(true)
    {
        std::cout << "Move: ";
        std::getline(std::cin, input);
       
        int inputResult = sscanf_s(input.c_str(), "%u %u %u %u", &sourcePosition.mRow, &sourcePosition.mColumn, &destinationPosition.mRow, &destinationPosition.mColumn);

        if(inputResult != 4)
        {
            std::cout << ::INVALID_MOVE;
            continue;
        }

        // Remove zero-indexing
        sourcePosition.mRow -= 1;
        sourcePosition.mColumn -= 1;
        destinationPosition.mRow -= 1;
        destinationPosition.mColumn -= 1;

        for(unsigned int i = 0; i < availableMoves.size(); ++i)
        {
            if((availableMoves[i]->GetSourcePosition() == sourcePosition) 
                && (availableMoves[i]->GetDestinationPosition() == destinationPosition))
            {
                return availableMoves[i];
            }
        }

        std::cout << ::INVALID_MOVE;
    }
}