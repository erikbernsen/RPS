//
//  GameController.hpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//

#ifndef GameController_hpp
#define GameController_hpp

#include <memory>

#include "IPlayer.hpp"

/* This class controls the players of the game. The class is constructed with a number of games and two players (either human or computer). 
 * Then in the play_match method the IPlayer interface is used to have the two players play a match against each other. */
class GameController
{
public:
    /* Constructor. The two players must be non-null pointers. */
    GameController(unsigned number_of_games, const std::shared_ptr<IPlayer> &player1, const std::shared_ptr<IPlayer> &player2);
    
    /* Let the two players play a match against each other. */
    void play_match();

private:

    void play_game();
    
    std::shared_ptr<IPlayer> m_player1;
    std::shared_ptr<IPlayer> m_player2;
    unsigned m_number_of_games;
};

#endif /* GameController_hpp */
