//
//  Game.cpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//

#include <cassert>
#include <string>

#include "Game.hpp"

static const char * ROCK_STRING = "Rock";
static const char * PAPER_STRING = "Paper";
static const char * SCISSORS_STRING = "Scissors";

std::istream &operator>>(std::istream &is, Symbol &symbol)
{
    std::string str;
    
    if (is >> str)
    {
        if (str.compare(ROCK_STRING) == 0)
        {
            symbol = Symbol::ROCK;
        } else if (str.compare(PAPER_STRING) == 0)
        {
            symbol = Symbol::PAPER;
        }
        else if (str.compare(SCISSORS_STRING) == 0)
        {
            symbol = Symbol::SCISSORS;
        }
        else
        {
            is.setstate(std::ios::failbit);
        }
    }
    
    return is;
}

std::ostream &operator<<(std::ostream &os, Symbol symbol)
{
    switch(symbol)
    {
        case Symbol::ROCK:
            os << ROCK_STRING;
            break;
        case Symbol::PAPER:
            os << PAPER_STRING;
            break;
        case Symbol::SCISSORS:
            os << SCISSORS_STRING;
            break;
        default:
            assert(false);
    }
    
    return os;
    
}

int compare(Symbol sym1, Symbol sym2)
{
    if (sym1 < sym2)
    {
        // The function should be anti symmetric:
        return -compare(sym2, sym1);
    }
    else if (sym1 == sym2)
    {
        // Equal symbols result in a tie
        return 0;
    }
    else
    {
        // Now there are only three possibilities left. (sym1,sym2) = (Scissors,Paper), (Rock,Paper), (Rock, Scissors):
        if (sym1 == ROCK && sym2 == PAPER)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
}

