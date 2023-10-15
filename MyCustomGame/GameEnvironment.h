#pragma once
#include "Character.h"
#include "CharacterTask3.h"
#include "RattleSnake.h"
#include "CamelSpider.h"
#include "Camel.h"
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
 * > GameEnvironment() :default Constructor that initializes the game environment
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
	std::vector<Character*> characters;
	Character* player;
	std::vector<Environ*> environs;
	Position* playerSpawn;
	Position* playerDestination;

	/**
	 * @brief Function used for printing out the items in the game environment,
	 * after their creation in the constructor.
	*/
	void CreationMessage() const;

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
	GameEnvironment(std::vector<Character*>& characters, Character* player, std::vector<Environ*>& environs, Position* playerSpawn, Position* playerDestination);

	/**
	 * @brief This is the destructor that deletes the game environment.
	*/
	~GameEnvironment();

	/**
	 * @brief This method is used to initialise teh items needed by the default constructor
	*/
	void BasicUtils();

	/**
	 * @brief Getter for the character names in the game environment.
	 * @return vector<string> - the list of character names in the game, including ones with enemy status
	*/
	std::vector<std::string> GetCharacterNames() const;

	/**
	 * @brief Getter for the characters property.
	 * @return vector<Character*> - the list of characters in the game, including ones with enemy status
	*/
	std::vector<Character*> GetCharacters() const;

	/**
	 * @brief Getter for the player property.
	 * @return Character* - pointer to the player character
	*/
	Character* GetPlayer() const;

	/**
	 * @brief Getter for the environs property.
	 * @return vector<Environ*> - the interactable objects in the game (shrubs, oasis, cact etc.)
	*/
	std::vector<Environ*> GetEnvirons() const;

	/**
	 * @brief Getter for the playerSpawn property.
	 * @return Position* - pointer to the position where the player spawns
	*/
	Position* GetPlayerSpawn() const;

	/**
	 * @brief Getter for the playerDestination property.
	 * @return Position* - pointer to the position where the player is headed
	*/
	Position* GetPlayerDestination() const;

	/**
	 * @brief Setter for the characters property.
	 * @param chrcters - the list of pointers to characters in the game, including ones with enemy status
	*/
	void SetCharacters(std::vector<Character*>& chrcters);

	/**
	 * @brief Setter for the player property.
	 * @param player - pointer to the player character
	*/
	void SetPlayer(Character* player);

	/**
	 * @brief Setter for the environs property.
	 * @param envs - the list of pointers to interactable objects in the game (shrubs, oasis, cact etc.)
	*/
	void SetEnvirons(std::vector<Environ*>& envs);

	/**
	 * @brief Setter for the playerSpawn property.
	 * @param plyerSpawn - pointer to the position where the player spawns
	*/
	void SetPlayerSpawn(Position* plyerSpawn);

	/**
	 * @brief Setter for the player's position property.
	 * @param plyerPosition - pointer to the position where the player spawns
	*/
	void SetPlayerPosition(Position* plyerPosition) const;

	/**
	 * @brief Setter for the playerDestination property.
	 * @param plyrDestination - pointer to the position where the player is headed
	*/
	void SetPlayerDestination(Position* plyrDestination);

	/**
	 * @brief This method adds a character to the game environment.
	 * @param chrcter - pointer to the character to be added
	*/
	void AddCharacter(Character* chrcter);

	/**
	 * @brief This function is used to add an environ to the game environment.
	 * @param env - pointer to the environ to be added
	*/
	void AddEnviron(Environ* env);

	/**
	 * @brief This method removes a character from the game environment if slain.
	 * @param chrcter - pointer to the character to be removed
	*/
	void DropCharacter(Character* chrcter);

	/**
	 * @brief This function is used to remove an environ from the game environment.
	 * @param env - pointer to the environ to be removed
	*/
	void DropEnviron(Environ* env);

	/**
	 * @brief This method shuffles the spawn position of the player.
	*/
	void ShuffleSpawnPoint() const;

	/**
	 * @brief This methods answers the questions in Problem Set 1 of the assignment.
	*/
	static void ProblemSet1();

	/**
	 * @brief This methods answers the questions in Problem Set 2 of the assignment. it creates
	 * two new characters and two new bags the demonstrates the bag swapping affair. It also
	 * prints the characters and their bags to the console.
	*/
	static void ProblemSet2();

	/**
	 * @brief This method shuffles the destination position of the player.
	*/
	void ShuffleDestination() const;

	/**
	 * @brief This method prints the game environment to the console
	*/
	void ShowEnvirons() const;

	/**
	 * @brief This method prints the characters in the list of characters left in the game, to the console
	*/
	void ShowCharacters() const;

	/**
	 * @brief This method takes commands from the user and executes them, while managing the game loop.
	*/
	void TakeCommands() const;

	/**
	 * @brief This method is used to convert strings to lowercase.
	*/
	static std::string StringToLower(std::string& str);
};