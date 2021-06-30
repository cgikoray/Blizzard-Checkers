#ifndef CHECKERS_ACTION_TYPES_H
#define CHECKERS_ACTION_TYPES_H
#pragma once

#include <vector>

struct BoardPosition
{
    BoardPosition()
    :   mRow(),
        mColumn()
    {
    }

    BoardPosition(unsigned int row, unsigned int column)
    :   mRow(row),
        mColumn(column)
    {
    }

    bool operator== (const BoardPosition& position) const
    {
        return (mRow == position.mRow) && (mColumn == position.mColumn);
    }

    unsigned int mRow;
    unsigned int mColumn;
};

typedef std::vector<BoardPosition> BoardPositionList;

#endif // CHECKERS_ACTION_TYPES_H