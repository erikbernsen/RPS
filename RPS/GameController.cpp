//
//  GameController.cpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//
#include <stdexcept>

#include "GameController.hpp"
#include "Game.hpp"
#include "IPlayer.hpp"

GameController::GameController(unsigned number_of_games, const std::shared_ptr<IPlayer> &player1, const std::shared_ptr<IPlayer> &player2)
: m_player1(player1)
, m_player2(player2)
, m_number_of_games(number_of_games)
{
    if (!m_player1 || !m_player2) throw std::invalid_argument("Player must be specified.");
}

void GameController::play_game()
{
    Symbol sym1 = m_player1->request_symbol();
    Symbol sym2 = m_player2->request_symbol();
    
    m_player1->tell_result(sym2);
    m_player2->tell_result(sym1);
    
}


void GameController::play_match()
{
    
    m_player1->start_match(m_number_of_games);
    m_player2->start_match(m_number_of_games);
    for(unsigned i=0; i<m_number_of_games; ++i)
    {
        play_game();
    }
    m_player1->finish_match();
    m_player2->finish_match();
}
