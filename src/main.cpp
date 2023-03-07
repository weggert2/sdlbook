/**
 * @Author: Bill Eggert
 * @Date: 06-Mar-2023 18:33
 * @Last Modified by: Bill Eggert
 */

#include <SDL2/SDL.h>

SDL_Window *g_pWindow = nullptr;
SDL_Renderer *g_pRenderer = 0;

int main()
{
    // initialize.
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        // Failure.
        return EXIT_FAILURE;
    }

    // title, x, y, width, height, flags
    g_pWindow = SDL_CreateWindow(
        "Hello SDL",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_SHOWN);

    // window, index, flags.
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);

    // Sets the color used for drawing operations (rect, line, clear)
    // renderer, r, g, b, alpha.
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

    // Clear the rendering target. Uses the color set above.
    SDL_RenderClear(g_pRenderer);

    // Update the screen with any rendering performed since the previous call.
    SDL_RenderPresent(g_pRenderer);

    SDL_Delay(5000); // ms -- 5 second delay
    SDL_Quit();

    return EXIT_SUCCESS;
}