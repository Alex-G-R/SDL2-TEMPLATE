#include <SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    constexpr int window_width = 1920;
    constexpr int window_height = 1080;

    // Create a window
    SDL_Window* window = SDL_CreateWindow("SDL2 TEMPLATE",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,window_width, window_height,SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main loop flag
    bool quit = false;

    // Event handler
    SDL_Event event;

    // While application is running
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&event) != 0) {
            // User requests quit
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Set render color to black (background color)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Set render color to red (for the rectangle)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        // Create a rectangle
        SDL_Rect rect;
        rect.w = 200;
        rect.h = 200;
        rect.x = (window_width - rect.w) / 2;
        rect.y = (window_height - rect.h) / 2;

        // Fill the rectangle
        SDL_RenderFillRect(renderer, &rect);

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
