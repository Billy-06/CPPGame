#pragma once
#include "Tool.h"

/**
 * @file Equipment.h
 * @author Billy Ndegwah Micah
 *
 * Description: This class represents an equipment the player can use to mine or
 * interact with the environment. This class is a subclass of Tool.
 *
 * Properties:
 * > miningSpeed {int} - The speed at which the equipment can mine
 * > durability {int} - The durability of the equipment
 * > range {int} - The range of the equipment
 * > damage {int} - The damage of the equipment
 *
 *
 * Methods:
 * -------
 * > Equipment() - Default constructor
 * > Equipment(string name, string category, Position* position,
 *    int miningSpeed, int durability, int range, int damage) - Parameterized constructor
 * > ~Equipment() - Destructor
 * > Getters and Setters
 * > virtual void Use() - Use the equipment
 * > virtual void Update() - Update the equipment
 */
class Equipment : public Tool
{
private:
	int miningSpeed;
	int durability;
	int range;
	int damage;

public:
	/**
	 * @brief This is the default constructor for the Equipment class
	 */
	Equipment();

	/**
	 * @brief This is the overloaded constructor of the Equipment object that takes in parameters:
	 *   name, category, position, miningSpeed, name, durability, range and damage
	 * @param name - the name of the equipment
	 * @param category - the category of the equipment
	 * @param position - the position of the equipment
	 * @param miningSpeed - the mining speed of the equipment
	 * @param durability - the durability of the equipment
	 * @param range - the range of the equipment
	 * @param damage - the damage of the equipment
	*/
	Equipment(string name, string category, Position* position, int miningSpeed, int durability, int range, int damage);

	/**
	 * @brief This is the destructor used to destroy the Equipment object
	*/
	~Equipment();

	/**
	 * @brief Getter for the mining speed of the equipment
	 * @return an integer representing the mining speed of the equipment
	*/
	int GetMiningSpeed();

	/**
	 * @brief Setter for the mining speed of the equipment
	 * @param miningSpeed - the desired mining speed of the equipment
	*/
	void SetMiningSpeed(int miningSpeed);

	/**
	 * @brief Getter for the durability of the equipment
	 * @return an integer value representing the durability of the equipment
	*/
	int GetDurability();

	/**
	 * @brief Setter for the durability of the equipment
	 * @param durability - the desired durability of the equipment
	*/
	void SetDurability(int durability);

	/**
	 * @brief Getter for the range of the equipment
	 * @return an integer value representing the range of the equipment
	*/
	int GetRange();

	/**
	 * @brief Setter for the range of the equipment
	 * @param range - the desired range of the equipment
	*/
	void SetRange(int range);

	/**
	 * @brief Getter for the damage of the equipment
	 * @return an integer value representing the damage of the equipment
	*/
	int GetDamage();

	/**
	 * @brief Setter for the damage of the equipment
	 * @param damage - the desired value damage of the equipment
	*/
	void SetDamage(int damage);

	/**
	 * @brief This method allows the player to use the equipment in either mining or interacting with the environment
	*/
	virtual void Use();

	/**
	 * @brief This method allows the player to upgrade the equipment
	*/
	virtual void Upgrade();
};