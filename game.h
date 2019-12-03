#ifndef __SDL_GAME_H__
#define __SDL_GAME_H__

// Stop custom SDL entry points from being created during preprocessor phase
#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

#define SCREEN_SCALE 1
#define SCREEN_W 640
#define SCREEN_H 480
#define SCREEN_NAME "Prototype"

void game_init(void);
void game_quit(void);
void report_error(void);

// Singleton in c if static keyword is used - globally defined Game "object"
struct {
    // Define attributes
    SDL_bool running;
    struct {
        unsigned int w;
        unsigned int h;
        const char* name;
        SDL_Window* window;
        SDL_Renderer* renderer;
    } screen;

    struct {
        unsigned int n;
        SDL_Surface** spritesheet;
    } gfx;

    // define "methods"
    void (*init)(void);
    void (*quit)(void);
} Game = {
    SDL_FALSE,
    {
        SCREEN_SCALE * SCREEN_W,
        SCREEN_SCALE * SCREEN_H,
        SCREEN_NAME,
        NULL,
        NULL
    },
    {
        0,
        NULL
    },
    game_init,
    game_quit
};

#endif // __SDL_GAME_H__
