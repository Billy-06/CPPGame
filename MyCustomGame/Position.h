#pragma once
#include <iostream>

using namespace std;

struct Position
{
	float x;
	float y;

	Position() : x(0), y(0) {}
	Position(float x, float y) : x(x), y(y) {}

	float GetX() const { return x; }
	float GetY() const { return y; }
	void SetX(float x) { this->x = x; }
	void SetY(float y) { this->y = y; }

	void ShowPosition() const
	{
		std::cout << "x : " << x << " y : " << y << std::endl;
	}
};