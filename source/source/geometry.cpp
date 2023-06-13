#include <geometry.h>

rect::rect()
	:minx{ 0 }, miny{ 0 }, width{ 0 }, height{ 0 }{}

rect::rect(float minx, float miny, float width, float height)
	: minx{ minx }, miny{ miny }, width{ width }, height{ height }{}

bool rect::touches(rect item) const
{
    if ((minx >= (item.minx + item.width)) || (miny >= (item.miny + item.height)) || ((minx + width) <= item.minx) || ((miny + height) <= item.miny))
        return false;

    return true;
}

bool rect::contains(vector pos) const
{
    if ((pos.x < minx) || (pos.y < miny) || (pos.x > (minx + width)) || (pos.y > (miny + height))) {
        return false;
    }

    return true;
	
}

vector::vector()
	:x{ 0 }, y{ 0 }{}


vector::vector(float x, float y)
	: x{ x }, y{ y }{}
