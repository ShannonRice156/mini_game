#include <game_item.h>
#include <window.h>

game_item::game_item(int width, int height, float minx, float miny)
{
	item_rect = rect(minx, miny, width, height);
}

void game_item::render(ui_helper& ui)
{
	ui_item.render(ui, item_rect);
}

void game_item::poll()
{
	
}


bool game_item::contains(vector pos) const
{
	return item_rect.contains(pos);
}

bool game_item::contains(rect r) const
{
	return item_rect.contains(r);
}

std::string game_item::image_id()
{
	return "";
}
