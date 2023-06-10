#pragma once
#include <iostream>
#include <game_item.h>
#include <playable_game_item.h>

class stage
{
public:
	stage();
	void render(ui_helper& ui);
	void poll();

	bool collision_check();

	void handle_keydown(SDL_Keycode sym);
	void handle_keyup();
	void handle_mousedown();
	void handle_mouseup();

private:
	playable_game_item player_item;
	std::vector<game_item> items;

};