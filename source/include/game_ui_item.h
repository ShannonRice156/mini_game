#pragma once
#include <iostream>
#include "SDL.h"
#include <ui_helper.h>
#include <geometry.h>

class game_ui_item
{
public:
	game_ui_item() = default;
	game_ui_item(int width, int height, float minx, float miny);
	virtual ~game_ui_item() = default;
	void render(ui_helper& ui, rect item_rect);
};