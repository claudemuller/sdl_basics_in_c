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

SDL_Texture* gfx_buildSpr(int w, int h, int** grid);
void gfx_destroySpr(SDL_Texture* spr);

void screen_drawSpr(SDL_Texture* spr, SDL_Rect* rect);

// Globally defined Game "object"
struct {
    // Define attributes
    SDL_bool running;

    struct {
        unsigned int w;
        unsigned int h;
        const char* name;
        SDL_Window* window;
        SDL_Renderer* renderer;
        void (*drawSpr)(SDL_Texture* spr, SDL_Rect* rect);
    } screen;

    struct {
        unsigned int n;
        SDL_Surface** spritesheet;
        SDL_Texture* (*buildSpr)(int w, int h, int** grid);
        void (*destroySpr)(SDL_Texture* spr);
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
        NULL,
        screen_drawSpr
    },
    {
        0,
        NULL,
        gfx_buildSpr,
        gfx_destroySpr
    },
    game_init,
    game_quit
};

#endif // __SDL_GAME_H__
