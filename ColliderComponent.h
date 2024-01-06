#pragma once
#include "Bounds.h"
#include "Component.h"
#include "surface.h"

class ColliderComponent : public Component
{
public:
    Bounds bounds;
    bool isTrigger;

    ColliderComponent(const Bounds& bounds, bool isTrigger = false)
        : bounds(bounds), isTrigger(isTrigger)
    {}

    void Draw(Tmpl8::Surface* target, Tmpl8::Pixel color) const
    {
        target->Box(bounds.Left(), bounds.Top(), bounds.Right(), bounds.Bottom(), color);
    }
};
