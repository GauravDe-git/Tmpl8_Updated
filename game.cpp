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

	Sprite theSprite(new Surface("assets/ball.png"), 1);
	int spriteX = 0;
	int spriteY = 100;
	float speed = 1.f;
	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		//convert dT to seconds
		deltaTime /= 1000;

		// clear the graphics window
		screen->Clear(0);

		theSprite.Draw(screen, spriteX, spriteY,1);
		spriteY += speed;
		spriteX += speed;
		speed += 1.f;
		if (spriteY > (512 - 50))
		{
			spriteY = 512 - 50;
			speed = -speed;
		}
		else if(spriteX > (800 - 50))
		{
			spriteX = 800 - 50;
			speed = -speed;
		}
	}
};