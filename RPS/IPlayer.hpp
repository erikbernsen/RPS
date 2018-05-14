//
//  IPlayer.hpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//

#ifndef IPlayer_hpp
#define IPlayer_hpp

#include "Game.hpp"

/** Interface that needs to be implemented by a player of the game. */
class IPlayer
{
public:
    /** This function is called before a match starts. The number of games played during
      * a match is determined upfront and told to the player. */
    virtual void start_match(unsigned n) = 0;
    
    /** This function is called when the player needs to show a symbol for one game. */
    virtual Symbol request_symbol() = 0;
    
    /** This function is called to tell the player the result of the last game. The strategy
      * of the player for the next game will usually depend on the symbol that the opponent showed before. 
      */
    virtual void tell_result(Symbol opponent) = 0;
    
    /** This function is called at the end of the match. */
    virtual void finish_match() = 0;
    
    /** Virtual destructor. */
    virtual ~IPlayer() {};
};

#endif /* IPlayer_hpp */
