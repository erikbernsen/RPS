//
//  HumanPlayer.hpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//

#ifndef HumanPlayer_hpp
#define HumanPlayer_hpp

#include <iostream>

#include "IPlayer.hpp"

/** Exception thrown by Humand player in case input from user couldn't be obtained. */
class HumanPlayerNoInput : public std::runtime_error
{
public:
    HumanPlayerNoInput(const char * what) : runtime_error(what) {};
};

/** Implements IPlayer interface for a computer player that plays random moves. */
class HumanPlayer : public IPlayer
{
public:
    /** Constructor. We communicate with the human using std::cin and std::cout. For easier testing we allow to pass arbitrary streams in the constructor.*/
    HumanPlayer(std::istream &is = std::cin, std::ostream &os = std::cout);
    
    /** Send a message to the user that we are going to start a match. */
    virtual void start_match(unsigned n);
    
    /** Asks the user to show a symbol. */
    virtual Symbol request_symbol();
    
    /** Tells the user the symbol of the opponent and the result of the game. */
    virtual void tell_result(Symbol opponent);
    
    /** This function is ignored in this implementation. */
    virtual void finish_match();
    
private:
    std::istream &m_is;
    std::ostream &m_os;
    Symbol m_my_symbol;
};


#endif /* HumanPlayer_hpp */
