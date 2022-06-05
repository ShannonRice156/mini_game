#include <rect.h>

rect::rect()
	:minx{ 0 }, miny{ 0 }, width{ 0 }, height{ 0 }{}

rect::rect(float minx, float miny, float width, float height)
	: minx{ minx }, miny{ miny }, width{ width }, height{ height }{}

bool rect::contains(rect item) const
{
	if ((item.minx >= minx && item.minx <= (minx + width)) || (item.miny >= miny && item.miny <= (miny + height))) {
		return true;
	}

}

bool rect::contains(float x, float y) const
{
	if ((x >= minx && x <= (minx + width)) || (y >= miny && y <= (miny + height))) {
		return true;
	}
}
