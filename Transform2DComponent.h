#pragma once
#include "Component.h"
#include "template.h"

class Transform2DComponent : public Component
{
public:
    Tmpl8::vec2 position;
    float rotation;
    Tmpl8::vec2 scale;

    Transform2DComponent()
        : position(0.0f, 0.0f), rotation(0.0f), scale(1.0f, 1.0f)
    {}

    void Translate(float dx, float dy)
    {
        position.x += dx;
        position.y += dy;
    }
};
