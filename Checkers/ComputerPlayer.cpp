#include "ComputerPlayer.h"
#include <iostream>
#include <time.h>

ComputerPlayer::ComputerPlayer()
{
}

ICheckersBaseMove* ComputerPlayer::RequestAction(const BaseMoveList& availableMoves) const
{
    return availableMoves[RandomIndex(0, availableMoves.size())];
}


unsigned int ComputerPlayer::RandomIndex(unsigned int minimum, unsigned int maximum) const
{
    ::srand(static_cast<unsigned int>(::time(NULL)));
    return (::rand() % maximum) + minimum;
}