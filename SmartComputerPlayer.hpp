//
//  SmartComputerPlayer.hpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//

#ifndef SmartComputerPlayer_hpp
#define SmartComputerPlayer_hpp

#include <random>

#include "IPlayer.hpp"
#include "Game.hpp"

/** Implements a 'smart' computer player according to the scheme described here: https://arstechnica.com/science/2014/05/win-at-rock-paper-scissors-by-knowing-thy-opponent/
    If the last game was a tie or this is the first game, then choose a random symbol.
    If it lost the last game, then it will assume the opponent will repeat its strategy. Hence it will choose the symbol for the coming game that would have made it win the previous game.
    If it won the last game, then play the hand that your opponent last played. */
class SmartComputerPlayer : public IPlayer
{
public:
    /** Constructor. */
    SmartComputerPlayer();
    
    /** This function is ignored in this implementation. */
    virtual void start_match(unsigned n);
    
    /** This implementation returns a random symbol. */
    virtual Symbol request_symbol();
    
    /** This function is ignored in this implementation. */
    virtual void tell_result(Symbol opponent);
    
    /** This function is ignored in this implementation. */
    virtual void finish_match();
    
private:
    std::uniform_int_distribution<> m_uniform_distribution;
    std::default_random_engine m_random_generator;
    Symbol m_opponent_symbol;
    Symbol m_my_symbol;
};


#endif /* SmartComputerPlayer_hpp */
