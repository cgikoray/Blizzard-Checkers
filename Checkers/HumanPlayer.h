#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H
#pragma once

#include "IPlayer.h"

class HumanPlayer : public IPlayer
{
public:
    HumanPlayer(void);

    virtual ICheckersBaseMove* RequestAction(const BaseMoveList& availableMoves) const;
};

#endif // HUMAN_PLAYER_H