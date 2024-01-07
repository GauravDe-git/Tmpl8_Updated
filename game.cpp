#include "game.h"

#include "PhysicsComponent.h"
#include "surface.h"

namespace Tmpl8
{
	void Game::Init()
	{
		player = new Player("assets/ball.png",1,100,0);
		entities.push_back(player);
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
		// Update and draw all entities
		for (Entity* entity : entities)
		{
			SpriteComponent* sprite = entity->GetComponent<SpriteComponent>();
			PhysicsComponent* physics = entity->GetComponent<PhysicsComponent>();
			Transform2DComponent* transform = entity->GetComponent<Transform2DComponent>();
			ColliderComponent* collider = entity->GetComponent<ColliderComponent>();

			if (sprite && transform)
			{
				sprite->Update(deltaTime);
				sprite->Draw(screen, transform->position.x, transform->position.y, 1.0f);
			}
			if (physics)
			{
				physics->Update(deltaTime);
				transform->position += physics->velocity * deltaTime;
			}
			// Check for collision with the bottom of the screen
			if (transform->position.y + collider->bounds.Height() > screen->GetHeight())
			{
				transform->position.y = screen->GetHeight() - collider->bounds.Height();
				physics->velocity.y = 0.0f;
			}
			renderSystem.Update(*entity, *screen);
		}
	}
};