
#ifndef _RECTANGLESHAPE_H
#define _RECTANGLESHAPE_H
#include "raylib.h"

class RectangleShape
{
public:
	float x;
	float y;
	float width;
	float height;

	RectangleShape()
	{
		x = y = width = height = 0;
	}
	RectangleShape(float x, float y, float width, float height)
	{
		this->x = x;
		this->y = y;
		this->height = height;
		this->width = width;
	}
};
#endif