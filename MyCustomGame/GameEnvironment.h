#pragma once
#include "Character.h"
#include "Position.h"
#include "Environ.h"

/**
 * @file GameEnvironment.h
 * @author Billy Ndegwah Micah
 *
 * Description: This file defines the game environment class that contains the player
 *  and the interactables in the game.
 *
 * Properties:
 * -----------
 * > characters {vector<Character*>} the list of characters in the game, including ones with enemy status
 * > player {Character*} the player character
 * > environs {vector<Environ*>} the interactable objects in the game (shrubs, oasis, cact etc.)
 * > playerSpawn {Position*} the position where the player spawns
 * > playerDestination {Position*} the position where the player is headed
 *
 * Methods:
 * --------
 * > GameEnvironment() :defualt Constructor that initializes the game environment
 * > GameEnvironment(vector<Character*> characters, Character* player, vector<Environ*> environs,
 *    Position* playerSpawn, Position* playerDestination) : Overloaded constructor that initializes the game environment
 * > ~GameEnvironment() : Destructor that deletes the game environment
 * > Getters and setters for the properties
 * > void AddCharacter(Character* character) : adds a character to the game environment
 * > void DropCharacter(Character* character) : removes a character from the game environment
 * > ShuffleSpawnPoint() : shuffles the spawn position of the player
 * > ShuffleDestination() : shuffles the destination position of the player
 * > ShowEnvirons() : prints the game environment
 * > ShowCharacters() : prints the characters in the game environment
 */
class GameEnvironment
{
private:
	vector<Character*> characters;
	Character* player;
	vector<Environ*> environs;
	Position* playerSpawn;
	Position* playerDestination;

public:
	/**
	 * @brief This is the default constructor that initializes the game environment.
	*/
	GameEnvironment();

	/**
	 * @brief This is the overloaded constructor that initializes the game environment.
	 * @param characters - the list of characters in the game, including ones with enemy status
	 * @param player - the player character
	 * @param environs - the interactable objects in the game (shrubs, oasis, cact etc.)
	 * @param playerSpawn - the position where the player spawns
	 * @param playerDestination - the position where the player is headed
	*/
	GameEnvironment(vector<Character*> characters, Character* player, vector<Environ*> environs, Position* playerSpawn, Position* playerDestination);

	/**
	 * @brief This is the destructor that deletes the game environment.
	*/
	~GameEnvironment();

	/**
	 * @brief Getter for the characters property.
	 * @return vector<Character*> - the list of characters in the game, including ones with enemy status
	*/
	vector<Character*> GetCharacters();

	/**
	 * @brief Getter for the player property.
	 * @return Character* - pointer to the player character
	*/
	Character* GetPlayer();

	/**
	 * @brief Getter for the environs property.
	 * @return vector<Environ*> - the interactable objects in the game (shrubs, oasis, cact etc.)
	*/
	vector<Environ*> GetEnvirons();

	/**
	 * @brief Getter for the playerSpawn property.
	 * @return Position* - pointer to the position where the player spawns
	*/
	Position* GetPlayerSpawn();

	/**
	 * @brief Getter for the playerDestination property.
	 * @return Position* - pointer to the position where the player is headed
	*/
	Position* GetPlayerDestination();

	/**
	 * @brief Setter for the characters property.
	 * @param characters - the list of pointers to characters in the game, including ones with enemy status
	*/
	void SetCharacters(vector<Character*> characters);

	/**
	 * @brief Setter for the player property.
	 * @param player - pointer to the player character
	*/
	void SetPlayer(Character* player);

	/**
	 * @brief Setter for the environs property.
	 * @param environs - the list of pointers to interactable objects in the game (shrubs, oasis, cact etc.)
	*/
	void SetEnvirons(vector<Environ*> environs);

	/**
	 * @brief Setter for the playerSpawn property.
	 * @param playerSpawn - pointer to the position where the player spawns
	*/
	void SetPlayerSpawn(Position* playerSpawn);

	/**
	 * @brief Setter for the playerDestination property.
	 * @param playerDestination - pointer to the position where the player is headed
	*/
	void SetPlayerDestination(Position* playerDestination);

	/**
	 * @brief This method adds a character to the game environment.
	 * @param character - pointer to the character to be added
	*/
	void AddCharacter(Character* character);

	/**
	 * @brief This method removes a character from the game environment if slain.
	 * @param character - pointer to the character to be removed
	*/
	void DropCharacter(Character* character);

	/**
	 * @brief This method shuffles the spawn position of the player.
	*/
	void ShuffleSpawnPoint();

	/**
	 * @brief This method shuffles the destination position of the player.
	*/
	void ShuffleDestination();

	/**
	 * @brief This method prints the game environment to the console
	*/
	void ShowEnvirons();

	/**
	 * @brief This method prints the characters in the list of characters left in the game, to the console
	*/
	void ShowCharacters();
};