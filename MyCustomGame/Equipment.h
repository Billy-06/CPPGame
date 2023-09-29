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
 * > durability {float} - The durability of the equipment
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
 * > override void Use() - Use the equipment
 * > override void Update() - Update the equipment
 */
class Equipment : public Tool
{
private:
	int miningSpeed;
	float durability;
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
	 * @param newName - the name of the equipment
	 * @param newCat - the category of the equipment
	 * @param newPos - the position of the equipment
	 * @param miningSpeed - the mining speed of the equipment
	 * @param durability - the durability of the equipment
	 * @param range - the range of the equipment
	 * @param damage - the damage of the equipment
	*/
	Equipment(std::string& newName, std::string& newCat, Position* newPos, int miningSpeed, float durability, int range, int damage);

	/**
	 * @brief This is the destructor used to destroy the Equipment object
	*/
	~Equipment() override;

	/**
	 * @brief Getter for the mining speed of the equipment
	 * @return an integer representing the mining speed of the equipment
	*/
	int GetMiningSpeed() const;

	/**
	 * @brief Setter for the mining speed of the equipment
	 * @param mngSpeed - the desired mining speed of the equipment
	*/
	void SetMiningSpeed(int mngSpeed);

	/**
	 * @brief Getter for the durability of the equipment
	 * @return an integer value representing the durability of the equipment
	*/
	float GetDurability() const;

	/**
	 * @brief Setter for the durability of the equipment
	 * @param durable - the desired durability of the equipment
	*/
	void SetDurability(float durable);

	/**
	 * @brief Getter for the range of the equipment
	 * @return an integer value representing the range of the equipment
	*/
	int GetRange() const;

	/**
	 * @brief Setter for the range of the equipment
	 * @param rnge - the desired range of the equipment
	*/
	void SetRange(int rnge);

	/**
	 * @brief Getter for the damage of the equipment
	 * @return an integer value representing the damage of the equipment
	*/
	int GetDamage() const;

	/**
	 * @brief Setter for the damage of the equipment
	 * @param dmg - the desired value damage of the equipment
	*/
	void SetDamage(int dmg);

	/**
	 * @brief (Overriden) This method allows the player to use the equipment in either mining or interacting with the environment
	*/
	void Use() override;

	/**
	 * @brief This method allows the player to upgrade the equipment
	*/
	void Upgrade() override;
};