#include "game.h"
#include "surface.h"

namespace Tmpl8
{
	void Game::Init()
	{
	}

	void Game::Shutdown()
	{
	}

	void Game::Tick(float deltaTime)
	{
		//convert dT to seconds
		deltaTime /= 1000;

		// clear the graphics window
		screen->Clear(0xffffff);
	}
};