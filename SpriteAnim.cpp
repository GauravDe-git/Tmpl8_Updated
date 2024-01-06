#include "SpriteAnim.h"

SpriteAnim::SpriteAnim(Tmpl8::Sprite* _sprite, float fps)
    : sprite(_sprite)
    , fps(fps)
{}

void SpriteAnim::Draw(Tmpl8::Surface* target, int x, int y,float alpha,bool flip) const
{
    if (sprite && target)
    {
        sprite->SetFrame(GetCurrentFrame());
        sprite->Draw(target, x, y, alpha,flip);
    }
}
