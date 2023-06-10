#include <game_ui_item.h>

void game_ui_item::render(ui_helper& ui, rect item_rect)
{
	ui.draw_square(item_rect, SkPaint::kFill_Style, SkColorSetRGB(255, 0, 0));
}
