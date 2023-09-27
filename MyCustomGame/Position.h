#pragma once
#include <iostream>
#include <cmath>


struct Position
{
	float x;
	float y;

	Position()
	{
		// provide random positions for x and y each time a Position object is created
		x = static_cast<float>(std::rand());
		y = static_cast<float>(std::rand());
	}
	Position(float x, float y) : x(x), y(y) {}
	friend float operator-(Position& pos1, Position& pos2)
	{
		return static_cast<float>(std::sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2)));
	}

	float GetX() const { return x; }
	float GetY() const { return y; }
	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }

	void ShowPosition() const
	{
		std::cout << "x : " << x << " y : " << y << std::endl;
	}
};