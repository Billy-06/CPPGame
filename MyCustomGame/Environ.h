#pragma once
#include "Position.h"
#include <string>

enum class Booster;
/**
 * @file Environ.h
 * @author Billy Ndegwah Micah
 *
 * Definition: The environ class represents the items in the environment that
 * the player is able to interact with. The player is able to pick up the items.
 *
 * Properties
 * ----------
 * > healthBooster {bool}: This boolean values determines whether the item is a health booster or not.
 * > spawnWeight {int}: This integer value determines the spawn weight of the item.
 * > position {Position} : This is the position of the item in the environment.
 *
 * Methods
 * -------
 * > Default Constructor
 * > Constructor (overload)
 * > Destructor
 * > Copy Constructor
 * > Extract(Backpack& backpack) {void} - This method extracts the item from the environment and adds it to the backpack
 * of the character.
 * > Spawn() {void} - This method spawns the item in the environment.
 *
 */
class Environ
{
private:
	std::string name;
	Booster booster;
	int spawnWeight;
	Position position;

public:
	/**
	 * @brief The default constructor for the Environ class.
	*/
	Environ();

	/**
	 * @brief The constructor for the Environ class. It takes the parameters, healthBooster, spawnWeight and position.
	 * @param booster - this boolean value determines whether the item is a health booster or not.
	 * @param spawnWeight - this integer value determines the spawn weight of the item.
	 * @param position - this is the position of the item in the environment.
	*/
	Environ(Booster booster, int spawnWeight, Position position);

	/**
	 * @brief The destructor for the Environ class.
	*/
	~Environ();

	/**
	 * @brief This is the copy constructor for the Environ class.
	 * @param environ_ - this is the Environ object to be copied.
	*/
	Environ(const Environ& environ_);

	/**
	 * @brief Getter for the name property.
	 * @return a string value representing the name of the item.
	*/
	string GetName() const;

	/**
	 * @brief Setter for the name property.
	 * @param name - this is the string value representing the name of the item.
	*/
	void SetName(string name);

	/**
	 * @brief Getter for the booster property.
	 * @return a booster enum value.
	*/
	Booster GetBooster() const;

	/**
	 * @brief Setter for the booster property.
	 * @param booster - this is the booster enum value to be set.
	*/
	void SetBooster(Booster booster);

	/**
	 * @brief Getter for the spawnWeight property.
	 * @return an integer value representing the spawn weight of the item.
	*/
	int GetSpawnWeight() const;

	/**
	 * @brief Setter for the spawnWeight property.
	 * @param spawnWeight - this is the integer value representing the spawn weight of the item.
	*/
	void SetSpawnWeight(int spawnWeight);

	/**
	 * @brief Getter for the position property.
	 * @return a pointer to the position of the item in the environment.
	*/
	Position* GetPosition() const;

	/**
	 * @brief Setter for the position property.
	 * @param position - this is the position of the item in the environment.
	*/
	void SetPosition(const Position& position);

	/**
	 * @brief This function allows the player to extract the item from the environment and add it to the backpack.
	 * @param backpack - this is the backpack of the character.
	*/
	void Extract(Backpack& backpack);

	/**
	 * @brief This function spawns the item in the environment.
	*/
	void Spawn();
};


/**
 * @file Environ.h
 * @author Billy Ndegwah Micah
 *
 * Enumeration for the Booster types
 */
enum class Booster
{
	HydrationBooster,
	HealthBooster,
	AttackBooster,
	ShieldBooster,
	BackpackBooster
};