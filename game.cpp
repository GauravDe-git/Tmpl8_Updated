#include "game.h"
#include "surface.h"

namespace Tmpl8
{
    void Game::Init() {}
    void Game::Shutdown() {}

    Surface tiles("assets/nc2tiles.png");

    char map[5][30] = {
         "kcXkcXkcXkcXkcXkcXkcXkcXkcXkc",
         "kc fb fb fb kc kc kc kc kc kc",
         "kc fb fb fb fb fb kc kc kc kc",
         "kc lc lc fb fb fb kc kc kc kc",
         "kc kc kc lc lc lc kc kc kc kc"
    };

    bool CheckPos(int x, int y)
    {
        int tx = x / 32, ty = y / 32;
        return map[ty][tx * 3 + 2] != 'X';
    }

    void DrawTile(int tx, int ty, Surface* screen, int x, int y)
    {
        Pixel* src = tiles.GetBuffer() + 1 + tx * 33 + (1 + ty * 33) * 595;
        Pixel* dst = screen->GetBuffer() + x + y * 800;
        for (int i = 0; i < 32; i++, src += 595, dst += 800)
            for (int j = 0; j < 32; j++)
                dst[j] = src[j];
    }

    Sprite tank(new Surface("assets/ctankbase.tga"), 16);

    void Game::Tick(float deltaTime)
    {
        screen->Clear(0);
        for (int y = 0; y < 5; y++)
            for (int x = 0; x < 10; x++)
            {
                int tx = map[y][x * 3] - 'a';
                int ty = map[y][x * 3 + 1] - 'a';
                DrawTile(tx, ty, screen, x * 32, y * 32);
            }

        const Uint8* state = SDL_GetKeyboardState(NULL);
        int nx = px, ny = py;
        if (state[SDL_SCANCODE_LEFT]) {
            nx -= 2;
            tank.SetFrame(12);
        }
        if (state[SDL_SCANCODE_RIGHT]) {
            nx += 2;
            tank.SetFrame(4);
        }
        if (state[SDL_SCANCODE_UP]) {
            ny -= 2;
            tank.SetFrame(0);
        }
        if (state[SDL_SCANCODE_DOWN]) {
            ny += 2;
            tank.SetFrame(8);
        }

        if (CheckPos(nx, ny) && CheckPos(nx + 30, ny + 30) &&
            CheckPos(nx + 30, ny) && CheckPos(nx, ny + 30)) {
            px = nx;
            py = ny;
        }
        tank.Draw(screen, px, py);
        screen->Box(nx, ny, tank.GetWidth(), tank.GetHeight(), 0xffff00);
    }


    void Game::KeyDown(SDL_Scancode scancode)
    {
        switch (scancode)
        {
        case SDL_SCANCODE_LEFT:
            break;
        case SDL_SCANCODE_RIGHT:
            break;
        case SDL_SCANCODE_UP:
            break;
        case SDL_SCANCODE_DOWN:
            break;
        default:
            break;
        }
    }
    
    



};