//
//  RandomComputerPlayer.hpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//

#ifndef RandomComputerPlayer_h
#define RandomComputerPlayer_h

#include <random>

#include "IPlayer.hpp"

/** Implements IPlayer interface for a computer player that plays random moves. */
class RandomComputerPlayer : public IPlayer
{
public:
    /** Constructor. */
    RandomComputerPlayer();
    
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
};

#endif /* RandomComputerPlayer_hpp */
