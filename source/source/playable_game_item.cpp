#include <playable_game_item.h>


void playable_game_item::move_up()
{
	item_rect.miny += 10;
}

void playable_game_item::move_down()
{
	item_rect.miny -= 10;
}

void playable_game_item::move_left()
{
	item_rect.minx -= 10;
}

void playable_game_item::move_right()
{
	item_rect.minx += 10;
}

std::string playable_game_item::image_id() 
{
	return "";
}