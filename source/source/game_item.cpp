#include <game_item.h>

game_item::game_item(int width, int height, float minx, float miny)
{
	item_rect = rect(minx, miny, width, height);

	//ui = new game_ui_item
}

void game_item::render()
{
	//ui.render()
}

void game_item::poll()
{
	//ui.poll()
}


bool game_item::contains(float x, float y) const
{
	return item_rect.contains(x, y);
}

bool game_item::contains(rect r) const
{
	return item_rect.contains(r);
}

std::string game_item::image_id()
{
	return "";
}
