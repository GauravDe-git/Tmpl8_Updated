#include "game.h"

#include "surface.h"

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		player = new Player("assets/Gargoyle_Chase.png",4,100,100);
		entities.push_back(player);
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		//convert dT to seconds
		deltaTime /= 1000;

		

		// clear the graphics window
		screen->Clear(0xffffff);

		// Update and draw all entities
		for (Entity* entity : entities)
		{
			SpriteComponent* sprite = entity->GetComponent<SpriteComponent>();
			if (sprite)
			{
				sprite->Update(deltaTime);
				sprite->Draw(screen, entity->GetComponent<Transform2DComponent>()->position.x, entity->GetComponent<Transform2DComponent>()->position.y, 1.0f);
				renderSystem.Update(*entity, *screen);
			}
		}
		player->GetComponent<Transform2DComponent>()->Translate(0.5f, 0);
		
	}
};