
#ifndef MAKINGTETRIS_BOARD_H
#define MAKINGTETRIS_BOARD_H

#pragma once
#include <SDL2/SDL.h>
#include <cstring>
#include "Tertomino.h"
#include "Defines.h"

class Board
{
public:
    Board();
    void Draw(SDL_Renderer *sdlRenderer);
    void Unite(const Tetromino & tetromino);
    bool isCollision(const Tetromino &tetromino);
    bool isBoardWallCollision(const Tetromino &tetromino);
    void Clean();
    enum
    {
        Width = Number_Of_Element_On_Column, // 10
        Height = Number_Of_Element_On_Row // 20
    };

private:
    bool **data;
};


#endif //MAKINGTETRIS_BOARD_H
