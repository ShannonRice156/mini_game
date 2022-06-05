#pragma once
#include <iostream>

class rect
{
public:
	rect();
	rect(float minx, float miny, float width, float height);
	
	bool contains(rect item) const;
	bool contains(float x, float y) const;

	float minx, miny, width, height;

private:
};