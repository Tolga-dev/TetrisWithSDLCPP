
#ifndef MAKINGTETRIS_TERTOMINO_H
#define MAKINGTETRIS_TERTOMINO_H

#pragma once
#include <SDL2/SDL.h>
#include "Defines.h"

class Tetromino
{
public:
    enum Type { I = 0, J, L, O, S, T, Z };
    explicit Tetromino(Type);
    void draw(SDL_Renderer *);
    void move(int dx, int dy);
    void rotate();
    bool isBlock(int x, int y) const;
    int x() const;
    int y() const;
private:
    Type type_;
    int x_;
    int y_;
    int angle_; // 0 - 0deg, 1 - 90deg, 2 - 180deg, 3 - 270deg
};
#endif //MAKINGTETRIS_TERTOMINO_H
