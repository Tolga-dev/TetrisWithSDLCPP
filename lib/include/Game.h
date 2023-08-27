
#ifndef MAKINGTETRIS_GAME_H
#define MAKINGTETRIS_GAME_H

#pragma once

#include <SDL2/SDL.h>
#include "Board.h"
#include "Tertomino.h"
#include "Defines.h"
#include <random>

class Game
{
public:
    Game();
    ~Game();
    bool tick();
    static int GenerateRandomTetrominoType();
private:
    Game(const Game &) = default;
    Game &operator=(const Game &) = default;
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    Board board;
    Tetromino tetromino;
    uint32_t tickTime_;
    SDL_Event e;
    std::random_device rd;  // a seed source for the random number engine
    void checkAndPerform(const Tetromino &tetro);
};

#endif //MAKINGTETRIS_GAME_H
