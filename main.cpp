#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"


int main() {

    Game game;
    while(game.tick());

    return 0;
}
