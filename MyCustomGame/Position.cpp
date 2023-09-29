#include "Position.h"

#include <string>

using namespace std;
/**
 * @file Position.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the Position class defined in Position.h
 */
Position::Position()
{
	// provide random positions for x and y each time a Position object is created
	fPos.x = static_cast<float>(std::rand());
	fPos.y = static_cast<float>(std::rand());
}

Position::Position(float x, float y)
{
	fPos.x = x;
	fPos.y = y;
}

Position::~Position() = default;


void Position::ShowPosition() const
{
	std::cout << "x : " << fPos.x << " y : " << fPos.y << std::endl;
}

string Position::ToString() const
{
		return "x : " + to_string(fPos.x) + " y : " + to_string(fPos.y);
}