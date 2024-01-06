#pragma once
#include <iostream>

#include "Entity.h"
#include "SpriteComponent.h"
#include "Transform2DComponent.h"

class RenderSystem
{
public:
    void Update(Entity& entity, Tmpl8::Surface& screen)
    {
        Transform2DComponent* transform = entity.GetComponent<Transform2DComponent>();
        SpriteComponent* sprite = entity.GetComponent<SpriteComponent>();
        ColliderComponent* collider = entity.GetComponent<ColliderComponent>();

        if (transform && sprite)
        {
            sprite->Draw(&screen, transform->position.x, transform->position.y, 1.0f);
        }

        if (collider)
        {
            collider->bounds.min += transform->position;
            collider->bounds.max += transform->position;
#ifdef _DEBUG
            collider->Draw(&screen, 0xff0000);  // Draw the collider in red
#endif
            collider->bounds.min -= transform->position;
            collider->bounds.max -= transform->position;

        }
    }
};

