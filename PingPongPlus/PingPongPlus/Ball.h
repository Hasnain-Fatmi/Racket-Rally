#pragma once
#ifndef _BALL_H
#define _BALL_H
#include "raylib.h"
#include "Vector2D.h"
class Ball
{
	Vector2D* Pos;
	Vector2D* Speed;
	float radius;
public:

	Ball()
	{
		Speed->x = 0.0;
		Speed->y = 0.0;
		Pos->x = 0.0;
		Pos->y = 0.0;
		radius = 0;
	}
	Ball(Vector2D* Pos, Vector2D* Speed, float Radius)
	{
		this->Pos = Pos;
		this->Speed = Speed;
		this->radius = Radius;
	}
	void SetSpeedX(float speedX)
	{
		Speed->x = speedX;
	}
	void SetSpeedY(float speedY)
	{
		Speed->y = speedY;
	}
	void SetX(float x)
	{
		Pos->x = x;
	}
	void SetY(float y)
	{
		Pos->y = y;
	}

	void SetRadius(float radius)
	{
		this->radius = radius;
	}

	float GetX()
	{
		return Pos->x;
	}
	float GetY()
	{
		return Pos->y;
	}
	float GetSpeedX()
	{
		return Speed->x;
	}
	float GetSpeedY()
	{
		return Speed->y;
	}
	float GetRadius()
	{
		return radius;
	}
	Vector2 Vect()
	{
		return Vector2{ Pos->x, Pos->y };
	}
	void Draw()
	{
		DrawCircle((int)Pos->x, (int)Pos->y, radius, YELLOW);
	}
};
#endif
