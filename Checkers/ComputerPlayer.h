#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H
#pragma once

#include "IPlayer.h"

class ComputerPlayer : public IPlayer
{
public:
    ComputerPlayer(void);

    virtual ICheckersBaseMove* RequestAction(const BaseMoveList& availableMoves) const;

private:
    unsigned int RandomIndex(unsigned int minimum, unsigned int maximum) const ;
};

#endif // COMPUTER_PLAYER_H