/**
 * Program Name: main.cpp
 * Description:
 *      This is the main entry point of the 
 *      the SDL2 program
 *
 * Written by:
 *      Jerico G. Despe
 *
 * Date:
 *      March 10, 2024
 */

#include "Game.h"

using namespace AcerEngine;

int main(int argc, char* argv[])
{
    Game game = Game::Instance();
    return game.Run();
}
