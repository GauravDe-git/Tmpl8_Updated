#include "game.h"

#include "SpriteAnim.h"
#include "surface.h"

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}

	Sprite theSprite(new Surface("assets/ctankbase.tga"), 16);
	SpriteAnim animatedTank(&theSprite, 30.f);

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		deltaTime /= 1000.0f;
		animatedTank.Update(deltaTime);

		// clear the graphics window
		screen->Clear(0);
		for (int j = 0; j < 10; j++) //rows
		{
			for (int i = 0; i < 16; i++) //columns
			{
				animatedTank.Draw(screen, i * 50, j * 50);
			}
		}
	}
};