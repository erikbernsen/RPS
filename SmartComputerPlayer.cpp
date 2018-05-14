//
//  SmartComputerPlayer.cpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//
#include <cassert>

#include "SmartComputerPlayer.hpp"

SmartComputerPlayer::SmartComputerPlayer()
: m_uniform_distribution(0, 2)
{
}

void SmartComputerPlayer::start_match(unsigned n)
{
    m_my_symbol = Symbol::ROCK;
    m_opponent_symbol = Symbol::ROCK;
}

Symbol SmartComputerPlayer::request_symbol()
{
    int cmp = compare(m_my_symbol, m_opponent_symbol);
    if (cmp < 0) // Opponent won last round. Choose the symbol that would have made me won.
    {
        switch(m_opponent_symbol)
        {
            case Symbol::ROCK:
                m_my_symbol = Symbol::PAPER;
                break;
            case Symbol::PAPER:
                m_my_symbol = Symbol::SCISSORS;
                break;
            case Symbol::SCISSORS:
                m_my_symbol = Symbol::ROCK;
                break;
        }
    }
    else if (cmp > 0) // I won last game. Choose the symbol of your opponent
    {
        m_my_symbol = m_opponent_symbol;
    }
    else // Tie in last game, choose a random symbol.
    {
        switch(m_uniform_distribution(m_random_generator))
        {
            case 0:
                m_my_symbol = Symbol::ROCK;
                break;
            case 1:
                m_my_symbol = Symbol::PAPER;
                break;
            case 2:
                m_my_symbol = Symbol::SCISSORS;
                break;
            default: assert(false);
        }
    }
    
    return m_my_symbol;
}

void SmartComputerPlayer::tell_result(Symbol opponent_symbol)
{
    m_opponent_symbol = opponent_symbol;
}

void SmartComputerPlayer::finish_match()
{
    
}
