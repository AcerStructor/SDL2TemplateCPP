/**
 *
 * File Name: Game.cpp
 *
 * Description:
 *      This file holds the function implementations
 *      for the game singleton class.
 *
 */

#include "Game.h"

namespace AcerEngine {

    bool Game::GameInit() {

        const int windowFlags = SDL_WINDOW_MINIMIZED;
        const int rendererFlags = SDL_RENDERER_ACCELERATED;

        /* Initialize the components of SDL2 */
        DisplayLogMessage(CYAN, "Initializing SDL2");

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            fprintf(stderr, "[ERROR]: Couldn't initialize SDL2: %s\n", SDL_GetError());
            return false;
        }

        /* Create SDL2 Window */
        DisplayLogMessage(CYAN, "Initializing Program Window");

        app.window = SDL_CreateWindow(PROGRAM_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                WINDOW_WIDTH, WINDOW_HEIGHT, windowFlags);

        if (app.window == nullptr) {
            fprintf(stderr, "[ERROR]: Couldn't initialize SDL2 window: %s\n", SDL_GetError());
            return false;
        }

        /* Setting Hint */
        DisplayLogMessage(CYAN, "Setting hint to \"linear\"");

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

        /* initialize Renderer */
        DisplayLogMessage(CYAN, "Initializing Program Renderer");

        app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

        if (app.renderer == nullptr) {
            fprintf(stderr, "[ERROR]: Couldn't initialize SDL2 renderer: %s\n", SDL_GetError());
            return false;
        }

        DisplayLogMessage(GREEN, "SDL2 Initialization Successful!");

        /* Remaining Initializations  */
        DisplayLogMessage(CYAN, "Setting isProgramRunning to true");
        app.isProgramRunning = true;

        return true;
    }

    void Game::ProcessInput() {
        SDL_Event e;
        
        while (SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                    app.isProgramRunning = false;
                    break;

                case SDL_KEYDOWN:
                    ProcessKey(e);
                    break;
            }
        }
    }

    void Game::ProcessKey(SDL_Event& e) {
        switch(e.key.keysym.sym) {
            case SDLK_ESCAPE:
                app.isProgramRunning = false;
                break;
        }
    }

    void Game::Destroy() {
        DisplayLogMessage(GREEN, "Deallocating SDL2 Components");

        SDL_DestroyRenderer(app.renderer);
        DisplayLogMessage(CYAN, "Program Renderer has been deallocated");

        SDL_DestroyWindow(app.window);
        DisplayLogMessage(CYAN, "Program window  has been deallocated");

        SDL_Quit();
        DisplayLogMessage(CYAN, "SDL2 has been deallocated");
        DisplayLogMessage(GREEN, "Processing exit...");
    }

    void Game::Update() {
        int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

        if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
        {
            SDL_Delay(time_to_wait);
        }

        float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.f;

        last_frame_time = SDL_GetTicks();
    }

    void Game::Render() {
        SDL_SetRenderDrawColor(app.renderer, 13, 13, 11, 255);
        SDL_RenderClear(app.renderer);

        SDL_RenderPresent(app.renderer);
    }

    /* Game Main Entry Point */
    int Game::Run() {
        /* Process Initialization */
        DisplayLogMessage(YELLOW, "=====[ Program Initialization ]=====");
        
        if (!GameInit()) { // Initialize SDL2 Components
            DisplayLogMessage(RED, "Exiting Program");
            return EXIT_FAILURE;
        }

        /* Program Session */
        DisplayLogMessage(YELLOW, "=====[ Program Session Started ]=====");

        while (app.isProgramRunning) {
            ProcessInput();
            Update();
            Render();
        }

        DisplayLogMessage(YELLOW, "=====[ Program Session Done ]=====");

        /* Process Deallocations */
        Destroy(); // Destroy SDL2 Components

        DisplayLogMessage(WHITE, "Exiting Program");
        return EXIT_SUCCESS;
    }
}
