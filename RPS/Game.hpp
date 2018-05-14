//
//  game.hpp
//  IMC_RPS
//
//  Created by Erik Bernsen on 13/08/2017.
//  Copyright © 2017 Erik. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>

/* Enumeration for the symbols a player can give. */
enum Symbol
{
    PAPER,
    SCISSORS,
    ROCK
};

/* Write a symbol to a stream. */
std::istream &operator>>(std::istream &is, Symbol &symbol);

/* Read a Symbol from a stream. */
std::ostream &operator<<(std::ostream &os, Symbol symbol);

/*  Compare two symbols and return which one is stronger.
    If symbols are equally strong then return 0.
    If sym1 beats sym2 then return 1;
    If sym2 beats sym1 then return -1; */
int compare(Symbol sym1, Symbol sym2);

#endif /* Game_hpp */
