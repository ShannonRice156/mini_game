#pragma once
#include <iostream>

class vector
{
public:
	vector();
	vector(float x, float y);

	float x, y;

private:
};

class rect
{
public:
	rect();
	rect(float minx, float miny, float width, float height);
	
	bool contains(rect item) const;
	bool contains(vector pos) const;

	float minx, miny, width, height;

private:
};

