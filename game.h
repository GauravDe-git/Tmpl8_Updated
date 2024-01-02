#pragma once
#include <SDL_keyboard.h>
#include <SDL_scancode.h>

namespace Tmpl8 {

class Surface;
class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyDown(SDL_Scancode scancode);
	void KeyUp(SDL_Scancode scancode){};
private:
	Surface* screen;
	int px = 150;
	int py = 150;
	const Uint8* state = SDL_GetKeyboardState(NULL);
};

}; // namespace Tmpl8