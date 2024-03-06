#pragma once
#ifndef _PADDLE_H
#define _PADDLE_H
#include "raylib.h"
#include "RectangleShape.h"


class Paddle
{
	RectangleShape* pad;
	float speed;

public:

	Paddle()
	{
		pad->x = 0.0;
		pad->y = 0.0;
		pad->width = 0.0;
		pad->height = 0.0;
		speed= 0.0;
	}
	Paddle( RectangleShape* pad,float Speed)
	{
		this->pad = pad;
		speed = Speed;
	}
	void SetSpeed(float speed)
	{
		this->speed = speed;
	}
	void SetX(float x)
	{
		pad->x = x;
	}
	void SetY(float y)
	{
		pad->y = y;
	}

	void Setwidth(float width)
	{
		pad->width = width;
	}

	void Setheight(float height)
	{
		pad->height = height;
	}

	float GetX()
	{
		return pad->x;
	}
	float GetY()
	{
		return pad->y;
	}
	float GetWidth()
	{
		return pad->width;
	}
	float GetHeight()
	{
		return pad->height;
	}
	float GetSpeed()
	{
		return speed;
	}
	Rectangle GetRect()
	{
		return Rectangle{ pad->x - pad->width / 2, pad->y - pad->height / 2, 10, 100 };
	}
	void Draw()
	{
		DrawRectangleRec(GetRect(), WHITE);
	}

};
#endif