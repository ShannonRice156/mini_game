#include <stage.h>

stage::stage()
{
	player_item.item_rect = rect(20, 20, 10, 10);
	items.push_back(game_item(20, 20, 100, 100));
}

void stage::render(ui_helper& ui)
{
	player_item.render(ui);

	for (auto &item : items) {
		item.render(ui);
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



void stage::collision_check() {
	for (int i = 0; i < items.size(); i++)
	{
		int tf = 0;
		if (player_item.touches(items[i].item_rect)) {
			items.erase(items.begin() + i);
			return;
		}
	}

	return;
}

void stage::handle_keydown(SDL_Keycode sym)
{
	switch (sym) {
	case SDLK_LEFT:
		player_item.move_left();
		collision_check();
		break;

	case SDLK_RIGHT:
		player_item.move_right();
		collision_check();
		break;

	case SDLK_UP:
		player_item.move_up();
		collision_check();
		break;

	case SDLK_DOWN:
		player_item.move_down();
		collision_check();
		break;
	}

}

void stage::handle_keyup()
{
}