#pragma once
#include "Component.h"
#include "template.h"

constexpr float gravityScale = 70.f;

class PhysicsComponent : public Component
{
public:
    Tmpl8::vec2 velocity;
    Tmpl8::vec2 acceleration;

    PhysicsComponent()
        : velocity(0.0f, 0.0f), acceleration(0.0f, 9.8f * gravityScale)
    {}

    void Update(float deltaTime)
    {
        velocity += acceleration * deltaTime;
    }
};
