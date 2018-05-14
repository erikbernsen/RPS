//
//  RandomComputerPlayer.cpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//

#include <random>
#include <cassert>

#include "RandomComputerPlayer.hpp"
#include "Game.hpp"

RandomComputerPlayer::RandomComputerPlayer()
: m_uniform_distribution(0, 2)
{
}

void RandomComputerPlayer::start_match(unsigned n)
{
}

Symbol RandomComputerPlayer::request_symbol()
{
    switch(m_uniform_distribution(m_random_generator))
    {
        case 0: return Symbol::ROCK;
        case 1: return Symbol::PAPER;
        case 2: return Symbol::SCISSORS;
        default: assert(false);
    }
}

void RandomComputerPlayer::tell_result(Symbol opponent)
{
    
}

void RandomComputerPlayer::finish_match()
{
    
}
