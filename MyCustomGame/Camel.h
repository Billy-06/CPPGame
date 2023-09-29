#pragma once
#include "Character.h"

/**
 * @file Camel.h
 * @author Billy Ndegwah Micah
 *
 * Definition: This is the definition of the friendly character Camel. The Camel class is a derived class of the Character class.
 *
 * Properties:
 * -----------
 * > hints {string} - The hints that the Camel gives to the player.
 * > waterReserve {int} - The water reserve of the Camel from which it can expend water.
 *
 * Methods:
 * --------
 * > Default Constructor
 * > Constructor (overload)
 * > Copy Constructor
 * > Destructor
 * > Getters and setters for the properties
 * > DrinkWater() {void} - This method makes the Camel drink water.
 * > ShowHint() {void} - This method allows the Camel to give the player hints about which way to follow to avoid danger.
 * > Run(direction {string}) {void} - This method makes the Camel run in a given direction.
 * > ExpendWater() {void} - This method makes the Camel expend water.
 * 
 */
class Camel : public Character
{
private:
	std::string hints_;
	int waterReserve_;

public:
	/**
	 * @brief This is the default constructor for the Camel class.
	*/
	Camel();

	/**
	 * @brief This is the overloaded constructor for the Camel class.
	 * @param name - the name of the Camel
	 * @param health - the maximum health of the Camel
	 * @param friendly - the friendly status of the Camel
	 * @param hints - the hints that the Camel gives to the player
	 * @param waterReserve - the water reserve of the Camel
	*/
	Camel(std::string& name, float health, bool friendly, std::string& hints, int waterReserve);

	/**
	 * @brief This is the copy constructor for the Camel class.
	 * @param camel - reference to the Camel object to be copied
	*/
	Camel(const Camel& camel);

	/**
	 * @brief This is the destructor for the Camel class.
	*/
	~Camel() override;

	/**
	 * @brief Getter for the waterReserve property.
	 * @return an integer value representing the water reserve of the Camel.
	*/
	int GetWaterReserve() const;

	/**
	 * @brief Setter for the waterReserve property.
	 * @param waterReserve - the desire integer value representing the water reserve of the Camel.
	*/
	void SetWaterReserve(int waterReserve);

	/**
	 * @brief Getter for the hints property.
	 * @return a string value representing the hints that the Camel gives to the player.
	*/
	std::string GetHints() const;

	/**
	 * @brief Setter for the hints property.
	 * @param hints - the desire string value representing the hints that the Camel gives to the player.
	*/
	void SetHints(std::string& hints);

	/**
	 * @brief This method allows the Camel to drink water to replenish its water reserve.
	*/
	void DrinkWater();

	/**
	 * @brief This method allows the Camel to give the player hints about which way to follow to avoid danger.
	*/
	void ShowHint() const;

	/**
	 * @brief This method allows the Camel to run in a given direction.
	 * @param direction - the desired direction of running.
	*/
	void Run(std::string& direction);

	/**
	 * @brief This method allows the Camel to expend water.
	*/
	void ExpendWater();
};