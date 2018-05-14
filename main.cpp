//
//  main.cpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//

#include <iostream>
#include <string>

#include "GameController.hpp"
#include "HumanPlayer.hpp"
#include "RandomComputerPlayer.hpp"
#include "SmartComputerPlayer.hpp"

// Message to display if an error is found in the command line arguments.
static void print_usage(const char * argv)
{
    std::cout << "Usage: " << argv << " <number_of_games> <computer>" << std::endl;
    std::cout << "<number_of_games> is the number of games to play. It must be a positive number." << std::endl;
    std::cout << "<computer> is the type of computer opponent. It must be either \"random\" or \"smart\"" << std::endl;
}

// Used to parse the second command line argument and convert it to an instance of the type of computer player that is requested. Returns nullptr on parse error.
static std::shared_ptr<IPlayer> parse_computer_player(const char * argv)
{
    if (std::strcmp("random", argv) == 0)
    {
        return std::make_shared<RandomComputerPlayer>();
    }
    else if(std::strcmp("smart", argv) == 0)
    {
        return std::make_shared<SmartComputerPlayer>();
    }
    else
    {
        return nullptr;
    }
}

// Used to parse the first command line argument and convert it to the number of games. Returns 0 on parse error.
static unsigned parse_number_of_games(const char * argv)
{
    int nr_of_games;
    try
    {
        size_t pos;
        nr_of_games = std::max(0, std::stoi(argv, &pos));
        if (pos != strlen(argv))
        {
            nr_of_games = 0;
        }
    } catch(std::exception &)
    {
        nr_of_games = 0;
    }
    
    return nr_of_games;
}

int main(int argc, const char * argv[])
{
    // Parse command line arguments
    if (argc != 3)
    {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    auto nr_of_games = parse_number_of_games(argv[1]);
    if (nr_of_games == 0)
    {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    auto computer_player = parse_computer_player(argv[2]);
    if (computer_player == nullptr)
    {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    // Here we start actual playing the game.
    try
    {
        GameController controller(nr_of_games,  computer_player, std::make_shared<HumanPlayer>());
        controller.play_match();
        return EXIT_SUCCESS;
    }
    catch(std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
