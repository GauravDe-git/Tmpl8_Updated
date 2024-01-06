#pragma once
#include "Component.h"
#include "SpriteAnim.h"
#include "surface.h"

class SpriteComponent : public Component
{
public:
    Tmpl8::Sprite* sprite;
    SpriteAnim spriteAnim;
    bool isAnimated;

    SpriteComponent(const char* filename, int numFrames, float fps = 30.0f, bool isAnimated = true)
        : sprite(new Tmpl8::Sprite(new Tmpl8::Surface(filename), numFrames)),
        spriteAnim(sprite, fps),
        isAnimated(isAnimated)
    {}

    void Update(float deltaTime)
    {
        if (isAnimated)
        {
            spriteAnim.Update(deltaTime);
        }
    }

    void Draw(Tmpl8::Surface* target, int x, int y, float alpha, bool flip = false) const
    {
        if (isAnimated)
        {
            spriteAnim.Draw(target, x, y, alpha, flip);
        }
        else
        {
            sprite->Draw(target, x, y, alpha, flip);
        }
    }
};
