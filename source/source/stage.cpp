#include <stage.h>

stage::stage()
{
	items.push_back(game_item( 10, 10, 100, 100));
}

void stage::render()
{
	player_item.render();

	for (game_item item : items) {
		item.render();
	}
}

void stage::poll()
{
	player_item.poll();

	for (game_item item : items) {
		item.poll();
	}

	collision_check();
}

bool stage::collision_check() {
	for (game_item item : items) {
		if (player_item.contains(item.item_rect)) {
			return true;
		}
	}
}

void stage::handle_keydown(SDL_Keycode sym)
{
	switch (sym) {
	case SDLK_LEFT:
		player_item.move_left();
		break;

	case SDLK_RIGHT:
		player_item.move_right();
		break;

	case SDLK_UP:
		player_item.move_up();
		break;

	case SDLK_DOWN:
		player_item.move_down();
		break;
	}
}

void stage::handle_keyup()
{
}