#pragma once
#include <iostream>
#include "SDL.h"
#include <ui_helper.h>
#include <rect.h>

class game_item
{
public:
	game_item() = default;
	game_item(int width, int height, float minx, float miny);
	virtual ~game_item() = default;
	void render();
	void poll();
	bool contains(float x, float y) const;
	bool contains(rect r) const;

	rect item_rect; // change into getter

private:
	virtual std::string image_id();
};