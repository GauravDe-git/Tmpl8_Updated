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

	static Sprite rotatingGun(new Surface("assets/aagun.tga"), 36);
	SpriteAnim rotatingGunAnim(&rotatingGun, 50.f);

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		//convert dT to seconds
		deltaTime /= 1000;

//======Update Loop=================//

		rotatingGunAnim.Update(deltaTime);

//======Render Loop=================//
		// clear the graphics window
		screen->Clear(0);
		
		// draw the animation
		rotatingGunAnim.Draw(screen, 0, 0);
	}
};