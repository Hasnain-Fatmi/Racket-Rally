#pragma once
#ifndef _VECTOR2D_H
#define _VECTOR2D_H
#include "raylib.h"

class Vector2D
{
public:
	float x;
	float y;

	Vector2D()
	{
		x = y = 0;
	}

	Vector2D(float X, float Y)
	{
		this->x = X;
		this->y = Y;
	}

};
#endif