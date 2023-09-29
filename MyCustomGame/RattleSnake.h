#pragma once
#include "Character.h"

/**
 * @file RattleSnake.h
 * @author Billy Ndegwah Micah
 *
 * Definition:
 * This is the definition of the RattleSnake class. The RattleSnake class is a derived class of the Character class.
 *
 * Properties:
 * -----------
 * > venomReserve {int}: This is the venom reserve of the RattleSnake.
 *
 * Methods:
 * --------
 * > Default Constructor
 * > Constructor (overload)
 * > Destructor
 * > Copy Constructor
 * > Getters and setters for the properties
 * > Slither(direction {string}) {void} - This method makes the RattleSnake slither in a given direction.
 * > SpitVenom() {void} - This method makes the RattleSnake spit venom.
 * > SenseEnviron() {void} - This method makes the RattleSnake sense the environment.
 * 
 */
class RattleSnake : public Character
{
	private:
	int venomReserve_;

public:
	/**
	 * @brief This is the default constructor for the RattleSnake class.
	*/
	RattleSnake();

	/**
	 * @brief This is the overloaded constructor for the RattleSnake class.
	 * @param name - the name of the RattleSnake
	 * @param health - the health of the RattleSnake
	 * @param friendly - the friendly status of the RattleSnake
	 * @param venomReserve - the venom reserve of the RattleSnake
	*/
	RattleSnake(std::string& name, float health, bool friendly, int venomReserve);

	/**
	 * @brief This is the copy constructor for the RattleSnake class.
	 * @param rattleSnake - reference to the RattleSnake object to be copied
	*/
	RattleSnake(const RattleSnake& rattleSnake);

	/**
	 * @brief This is the destructor for the RattleSnake class.
	*/
	~RattleSnake() override;

	/**
	 * @brief Getter for the venomReserve property.
	 * @return an integer value representing the venom reserve of the RattleSnake.
	*/
	int GetVenomReserve() const;

	/**
	 * @brief Setter for the venomReserve property.
	 * @param venomReserve - an integer value representing the venom reserve of the RattleSnake.
	*/
	void SetVenomReserve(int venomReserve);

	/**
	 * @brief This method allows the RattleSnake to slither in a given direction.
	 * @param direction - the desired direction of slithering.
	*/
	void Slither(std::string& direction);

	/**
	 * @brief This method allows the RattleSnake to spit venom. Usually after sensing danger.
	*/
	void SpitVenom();

	/**
	 * @brief This method allows the RattleSnake to sense the environment for danger or food.
	*/
	void SenseEnviron() const;

};