/**
 *
 * File Name: Game.h
 *
 * Description:
 *      This file serve as a header file for
 *      Game.cpp.
 *
 */

#ifndef _GAME_H_
#define _GAME_H_

#include "Common.h"
#include "Defs.h"
#include "utils.h"

namespace AcerEngine
{
    struct App
    {
        SDL_Window* window;
        SDL_Renderer* renderer;

        bool isProgramRunning;
    };
    
    class Game
    {
    private:
        App app;
        int last_frame_time = 0;

    public:
        /// Instance():
        ///
        /// Description:
        ///     This class is to hold a
        ///     singleton, to limit the
        ///     declaration of the object
        static Game& Instance()
        {
            static Game instance;
            return instance;
        }
        /// Run():
        /// 
        /// Description:
        ///     This function is the main
        ///     entry point of the game
        ///     itself. It is declared
        ///     inside the main function
        int Run();
    private:
        /// GameInit():
        ///
        /// Description:
        ///     This function initializes
        ///     components which are needed
        ///     in the game such as SDL2 and
        ///     more
        bool GameInit();
        /// ProcessInput():
        ///
        /// Description:
        ///     This function processes the
        ///     window input of the program
        ///     such as mouse, keyboard, and
        ///     etc.
        void ProcessInput();
        /// ProcessKey():
        ///
        /// Args: SDL_Event e
        ///     Holds the event variable of
        ///     the program
        ///
        /// Description:
        ///     This function processes the
        ///     keyboard input and its sym-
        ///     bols
        void ProcessKey(SDL_Event &e);
        /// Update():
        ///
        /// Description:
        ///     This function is one of the
        ///     essential component to the
        ///     program. It updates every
        ///     values of the game in every
        ///     frame passes.
        void Update();
        /// Render():
        /// 
        /// Description:
        ///     This function draws the
        ///     gfx such as sprites, back-
        ///     ground, and more related to
        ///     graphics.
        void Render();
        /// Destroy():
        ///
        /// Description:
        ///     This function is used to
        ///     deallocate memory before
        ///     quitting the game program
        void Destroy();
    };
}

#endif // _GAME_H_
