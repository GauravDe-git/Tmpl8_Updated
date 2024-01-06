#pragma once
#include "Bounds.h"
#include "ColliderComponent.h"
#include "Entity.h"
#include "SpriteComponent.h"
#include "Transform2DComponent.h"

class Player : public Entity
{
public:
    Player(const char* filename, int numFrames, float initialX = 0.0f, float initialY = 0.0f, float fps = 12.0f, bool isAnimated = true)
    {
        AddComponent(new Transform2DComponent());
        GetComponent<Transform2DComponent>()->position.x = initialX;
        GetComponent<Transform2DComponent>()->position.y = initialY;
        AddComponent(new SpriteComponent(filename, numFrames, fps, isAnimated));
        AddComponent(new ColliderComponent(Bounds(Tmpl8::vec2(0, 0), Tmpl8::vec2(250, 230))));
    }
};

