#pragma once
#include <game_item.h>

class playable_game_item : public game_item {
public:
	void move_down();
	void move_up();
	void move_left();
	void move_right();
	std::string image_id() override;
};