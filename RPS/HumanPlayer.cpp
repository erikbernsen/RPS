//
//  HumanPlayer.cpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>

#include "HumanPlayer.hpp"


HumanPlayer::HumanPlayer(std::istream &in, std::ostream &os)
: m_is(in)
, m_os(os)
{
    
}

void HumanPlayer::start_match(unsigned n)
{
    m_os << "We are going to play " << n << " games." << std::endl;
}

Symbol HumanPlayer::request_symbol()
{
    // Ask the user for a symbol and check that we could read it correctly.
    // In the following loop we keep asking the user until he entered a valid symbol.
    while(true)
    {
        m_os << "Please enter the symbol you want to play (" << Symbol::ROCK << "/" << Symbol::PAPER << "/" << Symbol::SCISSORS << "): " << std::endl;
        m_is >> m_my_symbol;
        
        // If no error flags were set it means that the user entered a valid symbol.
        if (m_is)
        {
            m_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore rest of input on this line.
            break;
        }
        
        // If the stream is bad there is something wrong with IO. We can only throw an exception.
        if (m_is.bad())
        {
            throw HumanPlayerNoInput("Could not obtain input from user");
        }
        
        // Streeam is in fail state. Clear it and retry
        m_os << "Failed to read your input." << std::endl;
        
        m_is.clear();
        m_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore rest of input on this line.
        
    }
    
    return m_my_symbol;
}

void HumanPlayer::tell_result(Symbol opponent_symbol)
{
    // Report to the user what the opponent played:
    m_os << "Your opponent played " << opponent_symbol << ". ";
    
    // Tell the user if he won or lost:
    int cmp = compare(m_my_symbol, opponent_symbol);
    if (cmp < 0)
    {
        m_os << "You lost this round." << std::endl;
    }
    else if (cmp > 0)
    {
        m_os << "You won this round!" << std::endl;
    }
    else
    {
        m_os << "This round was a tie." << std::endl;
    }
}

void HumanPlayer::finish_match()
{
    m_os << "This was the last game. We are done!" << std::endl;
}
