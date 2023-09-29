#pragma once
#include <string>
#include <vector>
#include "Backpack.h"
#include "Environ.h"
#include "Tool.h"


/**
 * 
 * @file Character.h
 * @author Billy Ndegwah Micah
 *
 * Character.h (Definition of the Character Class)
 * Definition: A character is a player, animal, or object that is used in game
 *		story with the below default traits and behaviour
 *
 * Traits
 * ------
 * > _Name {string} : The name of the character
 * > _AttackMoves {vector<string>} : The attack moves of the character
 * > _Strengths {vector<string>} : The strengths of the character
 * > _Weaknesses {vector<string>} : The weaknesses of the character
 * > _Fears {vector<string>} : The fears of the character
 * > _Hydration {int} : The hydration of the character
 * > _Friendly {bool} : The friendship status of the character
 * > _Backpack {Backpack} : The backpack of the character
 * > _fID {float} : The ID of the character in the game
 * > _fPosition {Position} : The position of the character in the game
 * > _fMaxHealth {float} : The maximum health of the character
 * > _fCurrentHealth {float} : The current health of the character
 * > _fAttackPower {float} : The attack power of the character
 * > _sensingRadius {float} : The sensing radius of the character
 * > _shielsUp {bool} : The shield status of the character
 *
 * Methods
 * -------
 * > Getters and Setters for the above traits
 * > Character() {void} : Default constructor of the character class
 * > Character(Character&) {Character}: Copy constructor of the character class
 * > Character(name {string}, maxHealth {float}, friendly {bool})
 * > ShowAttributes() {void} : Displays the attributes, weaknesses, fears, and strengths of the character
 * > ShowAttackMoves() {void} : Displays the attack moves of the character
 * > Shield() {void} : Shields the character from an attack
 * > ShowBackpack() {void} : Displays the backpack of the character
 * > Move(direction string) {void} : Moves the character to a new position
 * > TakeDamage(damage float) {void} : Reduces the character's health by the damage amount
 * > Interact(environ Environ&) {int} : Interacts with the environment. Returns either an increased or decreased health level
 * > PickItem(item Item) {void} : Adds an item to the character's backpack
 * > DropItem(item Item) {void} : Removes an item from the character's backpack
 * > Attack(character Character) {void} : Attacks another character
 * > Print() {void} : Prints the character's attributes
 * 
 */
class Character
{
protected:
	float fID_;
	std:: string name_;
	std::vector<std::string> attackMoves_;
	std::vector<std::string> strengths_;
	std::vector<std::string> weaknesses_;
	std::vector<std::string> fears_;
	int hydration_;
	bool friendly_;
	Backpack backpack_;
	Position* fPosition_;
	float fMaxHealth_;
	float fCurrentHealth_;
	float fAttackPower_;
	bool shieldUp_;

public:
	/**
	 * @brief This radius helps the character in sensing the environment adn enemies. The default value is 0.0f
	*/
	float sensingRadius_ = 0.0f;
	/**
	 * @brief The default constructor of the character class
	*/
	Character();

	/**
	 * @brief The overloaded constructor of the character class, takes parameters:
	 * name, maxHealth, and friendly
	 * @param name - the name of the character
	 * @param maxHealth - the maximum heath of a character
	 * @param friendly - the friendship status of the character
	*/
	Character(std::string& name, float maxHealth, bool friendly);

	/**
	 * @brief Copy constructor of the character class
	 * @param character - Reference to the character to be copied
	*/
	Character(const Character& character);

	/**
	 * @brief The destructor of the character class
	*/
	virtual ~Character();

	/**
	 * @brief Getter for the name of the character
	 * @return a string type of the name of the character
	*/
	std::string GetName() const;

	/**
	 * @brief Getter for the shield status of the character
	 * @return a boolean value representing whether the shields are up 
	*/
	bool GetShieldUp() const;

	/**
	 * @brief Setter for the shield status of the character
	*/
	void SetShieldUp(bool shieldUp);

	/**
	 * @brief Setter for the name of the character
	 * @param name - the desired name of the character
	*/
	void SetName(const std::string& name);

	/**
	 * @brief Getter for the attack moves of the character
	 * @return a vector<string> type of the attack moves of the character
	*/
	std::vector<std::string> GetAttackMoves() const;

	/**
	 * @brief Setter for the attack moves of the character
	 * @param attackMoves  - the desired list of attack moves assigned to the character
	*/
	void SetAttackMoves(const std::vector<std::string>& attackMoves);

	/**
	 * @brief Getter for the list of the character strengths
	 * @return a vector<string> type of the strengths of the character
	*/
	std::vector<std::string> GetStrengths() const;

	/**
	 * @brief Setter for the list of the character strengths
	 * @param strengths - The desired list of strengths assigned to the character
	*/
	void SetStrengths(const std::vector<std::string>& strengths);

	/**
	 * @brief Getter for teh Weaknesses of the character
	 * @return a vector<string> type of the weaknesses of the character
	*/
	std::vector<std::string> GetWeaknesses() const;

	/**
	 * @brief Setter for the list of the character weaknesses
	 * @param weaknesses - The desired list of weaknesses assigned to the character
	*/
	void SetWeaknesses(const std::vector<std::string>& weaknesses);

	/**
	 * @brief Getter for the fears of the character
	 * @return a vector<string> type of the fears of the character
	*/
	std::vector<std::string> GetFears() const;

	/**
	 * @brief Setter for the list of the character fears
	 * @param fears - The desired list of fears assigned to the character
	*/
	void SetFears(const std::vector<std::string>& fears);

	/**
	 * @brief Getter for the character hydration. This is a readonly value
	 * and therefore does not have a setter
	 * @return an integer value of the hydration level
	*/
	int GetHydration() const;

	/**
	 * @brief Getter for the character's firendliness. This  is a readonly value
	 * and therefore does not have a setter
	 * @return A boolean value showing whether or not the character is friendly
	*/
	bool GetFriendly() const;

	/**
	 * @brief Getter for the Character backpack items
	 * @return A Backpack object representing the inventory of the characters
	*/
	Backpack GetBackpack() const;

	/**
	 * @brief Setter for the Character Backpack
	 * @param backpack - A Backpack reference for the character's item storage
	*/
	void SetBackpack(const Backpack& backpack);

	/**
	 * @brief Getter for the character ID
	 * @return an integer value of the character ID
	*/
	float GetID() const;

	/**
	 * @brief Setter for the character ID
	 * @param fId - the desired ID to be assigned to the character
	*/
	void SetID(float fId);

	/**
	 * @brief Getter for the character position
	 * @return a reference to the position of the character
	*/
	Position& GetPosition() const;

	/**
	 * @brief Setter for the character position
	 * @param fPosition - the desired position to be assigned to the character
	*/
	void SetPosition(const Position& fPosition);

	/**
	 * @brief Getter to the character's maximum health
	 * @return a float value of the character's maximum health
	*/
	float GetMaxHealth() const;

	/**
	 * @brief Setter for the character's maximum health
	 * @param fMaxHealth - the desired maximum health to be assigned to the character
	*/
	void SetMaxHealth(float fMaxHealth);

	/**
	 * @brief Getter for the character's current health
	 * @return A float value of the character's current health
	*/
	float GetCurrentHealth() const;

	/**
	 * @brief Setter for the character's current health
	 * @param fCurrentHealth - the desired current health to be assigned to the character
	*/
	void SetCurrentHealth(float fCurrentHealth);

	/**
	 * @brief Getter for the character's attack power
	 * @return float value of the character's attack power
	*/
	float GetAttackPower() const;

	/**
	 * @brief Setter for the character's attack power
	 * @param fAttackPower - the desired attack power to be assigned to the character
	*/
	void SetAttackPower(float fAttackPower);

	/**
	 * @brief Shows the attributes, weaknesses, fears, and strengths of the character
	*/
	virtual void ShowAttributes() const;

	/**
	 * @brief Virtual function to show the attack moves of the character
	*/
	virtual void ShowAttackMoves() const;

	/**
	 * @brief Virtual function to shield the character from an attack
	*/
	virtual void Shield();

	/**
	 * @brief Virtual function to show the backpack of the character
	*/
	virtual void ShowBackpack() const;

	/**
	 * @brief Virtual function to move the character to a new position
	 * @param direction - the direction to move the character
	*/
	virtual void Move(const std::string& direction);

	/**
	 * @brief Virtual function to attack another character
	 * @param character - the character to be attacked
	*/
	virtual void Attack(Character& character);

	/**
	 * @brief Virtual function to take damage
	 * @param damage  - the amount of damage to be taken
	*/
	virtual void TakeDamage(float damage);

	/**
	 * @brief This function allows players ti interact with the environment. If the player
	 * interacts with the cacti, the player's health is reduced. If the player interacts with
	 * oasis, the player's health is increased, if the player interacts with a herbal shrub, the player's
	 * health is increased.
	 *
	 * @param environ_ - the environment object to be interacted with
	 * @return 
	*/
	int Interact(Environ& environ_);

	/**
	 * @brief Function to pick an item
	 * @param item - reference to the item to be picked
	*/
	void PickItem(Tool& item);

	/**
	 * @brief Function to drop an item
	 * @param item - reference to the item to be dropped
	*/
	void DropItem(Tool& item) const;

	/**
	 * @brief Virtual function to print the character's attributes
	*/
	virtual void Print() const;

	
};

