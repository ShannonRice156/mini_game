#include <geometry.h>

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

bool rect::contains(vector pos) const
{
	if ((pos.x >= minx && pos.x <= (minx + width)) || (pos.y >= miny && pos.y <= (miny + height))) {
		return true;
	}
}

vector::vector()
	:x{ 0 }, y{ 0 }{}


vector::vector(float x, float y)
	: x{ x }, y{ y }{}
