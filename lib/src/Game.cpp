#include "Game.h"
#include "Tertomino.h"
#include <stdexcept>
#include <iostream>

Game::Game() : tetromino(static_cast<Tetromino::Type>(GenerateRandomTetrominoType())) , tickTime_(SDL_GetTicks())
{
    
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error("SDL_INIT ERROR");
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_OPENGL,&window_,&renderer_);

}

Game::~Game() {

    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
}


bool Game::tick()
{

    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0xff);
    SDL_RenderClear(renderer_);
    board.Draw(renderer_);
    tetromino.draw(renderer_);



    Tetromino t = tetromino; // temp key to check collisions
    // event handle
    if (SDL_WaitEventTimeout(&e, 250))
    {
        switch (e.type)
        {
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) // movement
                {
                    case SDLK_DOWN:
                        t.move(0, 1);
                        break;
                    case SDLK_RIGHT:
                        t.move(1, 0);
                        break;
                    case SDLK_LEFT:
                        t.move(-1, 0);
                        break;
                    case SDLK_UP:
                        t.rotate();
                        break;
                }
                if (!board.isCollision(t)) // check collision, if not a collision stay, get moved temp
                    tetromino = t;

                break;
            case SDL_QUIT:
                return false;
        }
    }


    if (SDL_GetTicks() > tickTime_) // down just
    {
        tickTime_ += 500;
        t.move(0, 1);
        checkAndPerform(t);
    }

    SDL_RenderPresent(renderer_);
    return true;
}

void Game::checkAndPerform(const Tetromino &t)
{
    if (board.isCollision(t)) // check are we at bottom, if we not, get temp object
    {
        board.Unite(tetromino); // at bottom
        tetromino = Tetromino{static_cast<Tetromino::Type>(GenerateRandomTetrominoType())}; // create new one

        if (board.isCollision(tetromino)) // if we damage with current one, game over
        {
            std::cout << " You are dead " << std::endl;
            board.Clean();
            board = Board();
        }

    }
    else
        tetromino = t;



}

int Game::GenerateRandomTetrominoType()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, Number_Of_Types - 1); // Range [0, Number_Of_Types - 1]
    return distribution(gen); // Generate a random integer within the specified range

}