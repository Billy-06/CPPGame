#pragma once
#include <iostream>
#include <cmath>

struct fPosition
{
	float x;
	float y;
};

class Position
{
public:
	/**
	 * @brief fPos is a struct that holds the x and y coordinates of the position.
	*/
	fPosition fPos;

	/**
	 * @brief This is the default constructor for the Position class.
	*/
	Position();

	/**
	 * @brief This is the overloaded constructor for the Position class.
	 * @param x - The x coordinate of the position.
	 * @param y - the y coordinate of the position.
	*/
	Position(float x, float y);

	/**
	 * @brief This is the destructor for the Position class.
	*/
	~Position();

	/**
	 * @brief This is the overridden subtraction operator for the Position class. It computes the
	 * distance between two positions using the pythagorean theorem.
	 * @param pos1 - the position to be subtracted from the current position.
	 * @return a float value representing the distance between the two positions.
	*/
	float operator-(Position& pos1) const
	{
		return static_cast<float>(std::sqrt(std::pow(pos1.fPos.x - this->fPos.x, 2) + std::pow(pos1.fPos.y - this->fPos.y, 2)));
	}

	/**
	 * @brief This is the overridden equality operator for the Position class. It checks if two positions are equal.
	 * This comparison is done by checking if the x and y coordinates of the two positions are equal.
	 * @param pos1 - the position to be compared with the current position.
	 * @return a boolean values representing the equality of the two positions.
	*/
	bool operator==(Position& pos1) const
	{
		return (pos1.fPos.x == this->fPos.x && pos1.fPos.y == this->fPos.y);
	}

	/**
	 * @brief This is the overridden assignment operator meant to serve as the copy constructor for the Position class.
	 * The assignment operator is used to copy the values of the x and y coordinates of the position to another position.
	 * @param pos1 - the position to be copied.
	 * @return reference the copied position.
	*/
	Position& operator=(const Position* pos1)
	{
		if (this == pos1)
			return *this;

		this->fPos.x = pos1->fPos.x;
		this->fPos.y = pos1->fPos.y;
		return *this;
	}

	/**
	 * @brief Getter for the x coordinate of the position.
	 * @return a float value representing the x coordinate of the position.
	*/
	float GetX() const { return fPos.x; }

	/**
	 * @brief Getter for the y coordinate of the position.
	 * @return a float value representing the y coordinate of the position.
	*/
	float GetY() const { return fPos.y; }

	/**
	 * @brief Setter for the x coordinate of the position.
	 * @param x - a float value representing the x coordinate of the position.
	*/
	void SetX(float x) { this->fPos.x = x; }

	/**
	 * @brief Setter for the y coordinate of the position.
	 * @param y - a float value representing the y coordinate of the position.
	*/
	void SetY(float y) { this->fPos.y = y; }

	/**
	 * @brief This method is used in retrieving the position of an item in the 2D space
	*/
	void ShowPosition() const;

	std::string ToString() const;

};


