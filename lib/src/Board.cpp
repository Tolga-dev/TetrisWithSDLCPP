#include "Board.h"


Board::Board()
{

    data = new bool*[Width];

    // Allocate memory for each row (array of boolean values)
    for (int i = 0; i < Width; ++i) {
        data[i] = new bool[Height];
    }

    // Initialize the data to false using memset
    for (int i = 0; i < Width; ++i) {
        memset(data[i], 0, Height * sizeof(bool));
    }

}
void Board::Clean()
{
    for (int i = 0; i < Width; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

void Board::Draw(SDL_Renderer *renderer) {

    for (int i = 0; i < Width; ++i) {
        for (int j = 0; j < Height; ++j) {
            if (data[i][j])
                SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff); // set white
            else
                SDL_SetRenderDrawColor(renderer, 204, 51, 51, 0xff); // set random color

            SDL_Rect rect{ i * ELEMENT_WIDTH + 1,
                           j * ELEMENT_WIDTH + 1,
                           ELEMENT_WIDTH - 2,
                           ELEMENT_WIDTH - 2
            };

            SDL_RenderFillRect(renderer, &rect);
        }

    }
}

bool Board::isCollision(const Tetromino &t)
{
    const int tetrominoX = t.x();
    const int tetrominoY = t.y();

    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            if (t.isBlock(x, y)) {
                int wx = tetrominoX + x;
                int wy = tetrominoY + y;

                if (wx < 0 || wx >= Width || wy < 0 || wy >= Height || data[wx][wy]) {
                    return true;
                }
            }
        }
    }
    return false;
}


void Board::Unite(const Tetromino &t)
{
    int tetrominoX = t.x();
    int tetrominoY = t.y();

    for (int x = 0; x < 4; ++x)
    {
        for (int y = 0; y < 4; ++y)
        {
            if (t.isBlock(x, y))
            {
                data[tetrominoX + x][tetrominoY + y] = true;
            }
        }
    }

    for (int y = Height - 1; y >= 0; --y) // the bottom element
    {
        bool isSolid = true;
        for (int x = 0; x < Width; ++x) // from right to left
            if (!data[x][y]) // if there is no element passed
            {
                isSolid = false;
                break;
            }

        if (isSolid)
        {

            for (int yy = y - 1; yy >= 0; --yy) // copy from n to m
                for (int x = 0; x < Width; ++x)
                {
                    data[x][yy + 1] = data[x][yy];
                }

            for (int x = 0; x < Width; ++x)
                data[x][0] = false;
        }
    }
}