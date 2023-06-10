#pragma once
#include <iostream>
#include "SDL.h"
#include <ui_helper.h>
#include <geometry.h>
#include <game_ui_item.h>

class game_item
{
public:
	game_item() = default;
	game_item(int width, int height, float minx, float miny);
	virtual ~game_item() = default;
	void render(ui_helper& ui);
	void poll();
	bool contains(vector pos) const;
	bool contains(rect r) const;
	rect centre();
	rect item_rect;

private:
	virtual std::string image_id();
	game_ui_item ui_item;
	
};