#include "game.h"

#include <iterator>

#include "surface.h"

namespace Tmpl8
{
	constexpr Pixel Red = { 0xff0000 };
	constexpr Pixel Green = { 0x00ff00 };
	constexpr Pixel Blue = { 0x0000ff };
	constexpr Pixel Yellow = { 0xffff00 };
	struct Point
	{
		int x, y;
		Pixel color;
	};

	// Define a special Point that signifies the end of a letter
	constexpr Point endOfLetter = { -1, -1, { 0x000000 } };

	constexpr Point points[] = {
		//Points to plot letter C
		{ 167, 117, Red },
		{ 78, 235, Red },
		{ 167, 358, Red },
		endOfLetter,

		// Points to plot letter O
		{ 220, 235, Green },
		{ 220, 117, Green },
		{ 300, 117, Green },
		{ 300, 235, Green },
		{ 220, 235, Green },
		endOfLetter,

		// Points to plot letter D
		{ 350, 117, Blue },
		{ 350, 358, Blue },
		{ 400, 235, Blue },
		{ 400, 117, Blue },
		{ 350, 117, Blue },
		endOfLetter,

			// Points to plot letter E
		{ 450, 117, Yellow },
		{ 450, 358, Yellow },
		{ 450, 235, Yellow },
		{ 500, 235, Yellow },
		{ 450, 235, Yellow },
		{ 450, 117, Yellow },
		endOfLetter,
	};

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
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
		// clear the graphics window
		screen->Clear(0);

		for (int i = 1; i < std::size(points); i++)
		{
			auto p0 = points[i - 1];
			auto p1 = points[i];

			// Skip drawing a line if the next point is endOfLetter
			if (p1.x == endOfLetter.x && p1.y == endOfLetter.y) continue;
			
			screen->Line(p0.x, p0.y, p1.x, p1.y, p0.color);
		}
	}
};