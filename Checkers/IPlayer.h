#ifndef I_PLAYER_H
#define I_PLAYER_H
#pragma once

#include "CheckersBoardTypes.h"
#include "CheckersMoves.h"

class IPlayer
{
public:
    IPlayer(void) { }
    virtual ~IPlayer() { }

    virtual ICheckersBaseMove* RequestAction(const BaseMoveList& availableMoves) const = 0;
};

#endif // I_PLAYER_H