#pragma once
#include <string>
#include <vector>
#include "Backpack.h"
#include "Environ.h"
#include "Tool.h"
#include "Iterator1D.h"
#include "Iterator2D.h"
#include "SkillAdvancement.h"


/**
 * @file CharacterTask3.h
 * @author Billy Ndegwah Micah
 *
 * CharacterTask3.h (Definition of the CharacterTask3 Class)
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
 * > _shieldUp {bool} : The shield status of the character
 * > _bag1D {Iterator1D} : The 1D bag of the character
 * > _bag2D {Iterator2D} : The 2D bag of the character
 * > _skillNodes {SkillAdvancement}: The skill nodes of the character
 * // Additional traits for Task 3
 * > _fMessage {string}
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
 * > InventoryNext() {string} : Returns the next item in the character's inventory
 * > InventoryPrev() {string} : Returns the previous item in the character's inventory
 * > InventoryGet() {void} : Prints out the current item in the character's inventory
 * > SwapBags1D(character Character) {void} : Swaps the contents of the character's 1D bags with another character's bags
 * > SwapBags2D(character Character) {void} : Swaps the contents of the character's 2D bags with another character's bags
 * > InventoryNext2D() {string} : Returns the next item in the character's 2D bags
 * > InventoryPrev2D() {string} : Returns the previous item in the character's 2D bags
 * > InventoryGet2D() {void} : Prints out the current item in the character's 2D bags
 * > operator>>(character Character) {void} : Allows the characters to battle
 * > operator>>(in istream, character Character) {void} : Allows the user to send a message to the character
 * > operator<<(out ostream, character Character) {void} : Prints out the character's attributes
 * > PrintVector(vector vector<string>) {string} : Prints out the contents of a vector
 * > Attack(character Character) {void} : Attacks another character
 * > Print() {void} : Prints the character's attributes
 * // Additonal methods for Task 3
 * > operator<<() {void}: This operator calls the PrintStat method.
 * > operator>>() {void}: This operator is used to accept messages from the user.
 * > PrintStat() {void}: This method when called, this CharacterTask3 will return a string that lists the contents of all its current fields
 *
 */
class CharacterTask3
{
protected:
	float fID_;
	std::string name_;
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
	// Additional field for Character task 3
	std::string fMessage_;

	Iterator1D* bag1D_;
	Iterator2D* bag2D_;

	SkillAdvancement* skillNodes_;


public:
	/**
	 * @brief This radius helps the character in sensing the environment adn enemies. The default value is 0.0f
	*/
	float sensingRadius_ = 0.0f;
	/**
	 * @brief The default constructor of the character class
	*/
	CharacterTask3();

	/**
	 * @brief The overloaded constructor of the character class, takes parameters:
	 * name, maxHealth, and friendly
	 * @param name - the name of the character
	 * @param maxHealth - the maximum heath of a character
	 * @param friendly - the friendship status of the character
	*/
	CharacterTask3(std::string& name, float maxHealth, bool friendly);

	/**
	 * @brief Copy constructor of the character class
	 * @param character - Reference to the character to be copied
	*/
	CharacterTask3(const CharacterTask3& character);

	/**
	 * @brief The destructor of the character class
	*/
	virtual ~CharacterTask3();

	/**
	 * @brief Getter for the skill nodes of the character
	 * @return a pointer to the head of the SkillAdvancement (double linked list)
	*/
	SkillAdvancement* GetSkillNodes() const;

	/**
	 * @brief Setter for the skill nodes of the character
	 * @param skillNodes a pointer to the head of the SkillAdvancement (double linked list)
	*/
	void SetSkillNodes(SkillAdvancement* skillNodes);

	/**
	 * @brief This method is used to add a skill node to the character's skill nodes
	 * @param skillNode - the skill node to be added
	*/
	void AddSkillNode(SkillNode* skillNode) const;

	/**
	 * @brief This method is used to add a skill node to the character's skill nodes
	 * @param skillNode - the name of the skill node to be added
	*/
	void AddSkillNode(std::string& skillNode) const;

	/**
	 * @brief This method is used to remove a skill node from the character's skill nodes
	 * @param skillNodeName - the name of the skill node to be removed
	*/
	void RemoveSkillNode(std::string& skillNodeName) const;

	/**
	 * @brief This method is used to upgrade a skill node in the character's skill nodes
	 * @param skillNodeName - the name of the skill node to be upgraded
	*/
	void UpgradeSkillNode(std::string& skillNodeName) const;

	/**
	 * @brief This method is used to find a skill node in the character's skill nodes
	 * @param skillName - the name of the skill node to be found
	 * @return pointer to the skill node found
	*/
	SkillNode* FindSkillNode(std::string& skillName) const;

	/**
	 * @brief This method is used to show the skill nodes of the character
	*/
	void ShowSkillNodes() const;

	/**
	 * @brief This method allows the user to add a custom skill node to the character's skill nodes
	 */
	void AddUserCustomSkillNode() const;

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
	 * @brief Getter for the character's bag1D
	 * @return a pointer to the character's bag1D
	*/
	Iterator1D* GetBag1D() const;

	/**
	 * @brief Setter for the character's bag1D
	 * @param bag1D - the desired bag1D to be assigned to the character
	*/
	void SetBag1D(Iterator1D* bag1D);

	/**
	 * @brief This method is used to get the next item in the character's inventory
	 * @return a string value of the next item in the character's inventory
	*/
	std::string InventoryNext() const;

	/**
	 * @brief This method is used to get the previous item in the character's inventory
	 * @return a string value of the previous item in the character's inventory
	*/
	std::string InventoryPrev() const;

	/**
	 * @brief This method prints out the current item in the character's inventory
	*/
	void InventoryGet() const;

	/**
	 * @brief This method is used to swap the contents of the character's 1D bags with
	 * another character's bags
	 * @param chrcter - the character with whom to swap bags
	*/
	void SwapBags1D(CharacterTask3& chrcter);

	/**
	 * @brief This method is used to swap the contents of the character's 2D bags with
	 * another character's bags
	 * @param chrcter 
	*/
	void SwapBags2D(CharacterTask3& chrcter);

	/**
	 * @brief This method is used to retrieve the next items in the 2D bags
	 * @return a string value representing the next item in the 2D bags
	*/
	std::string InventoryNext2D() const;

	/**
	 * @brief This method is used to retrieve the previous items in the 2D bags
	 * @return a string value representing the previous item in the 2D bags
	*/
	std::string InventoryPrev2D() const;

	/**
	 * @brief This method prints out the current item in the character's 2D bags
	*/
	void InventoryGet2D() const;

	/**
	 * @brief Getter for the character's bag2D
	 * @return pointer to the character's bag2D
	*/
	Iterator2D* GetBag2D() const;

	/**
	 * @brief Setter fo the character's bag2D
	 * @param bag2D - the desired bag2D to be assigned to the character
	*/
	void SetBag2D(Iterator2D* bag2D);

	/**
	 * @brief This operator calls the PrintStat method.
	 * @param out - the ostream object to be used in printing out the message
	 * @param character - the character object to be printed
	*/
	friend std::ostream& operator<<(std::ostream& out, const CharacterTask3& character);

	/**
	 * @brief This method when called, this CharacterTask3 will return a string that lists the contents of all its current fields
	 * @return a string containing the contents of all the character's fields
	*/
	std::string PrintStat() const;

	/**
	 * @brief This operator is used to accept command or a message regarding the character from the user. 
	 * @param in - the istream object to be used in reading the message
	 * @param character - the character object to take the message
	 * @return an in stream object containing the message
	*/
	friend std::istream& operator>>(std::istream& in, CharacterTask3& character);

	/**
	 * @brief This method is used to allow the characters to battle
	 * @param character - the character with to initiate the attack
	 * @param character2 - the character with whom to battle
	*/
	friend std::istream& operator>>(CharacterTask3& character, CharacterTask3& character2);

	/**
	 * @brief This function is used to print the contents of a vector
	 * @param vector - the vector to be printed
	 * @return  a string containing the contents of the vector
	*/
	static std::string PrintVector(const std::vector<std::string>& vector);

	/**
	 * @brief Getter for the character's message
	 * @return a string value representing the character's message
	*/
	std::string GetMessage() const;

	/**
	 * @brief Setter for the character's message field
	 * @param message -  the desire message to be assigned to the character
	*/
	void SetMessage(std::string& message);

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
	virtual void Attack(CharacterTask3& character);

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

