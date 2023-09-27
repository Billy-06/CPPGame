#pragma once
#include "Character.h"
#include "Tool.h"

/**
 * @file Weapon.h
 * @author Billy Ndegwah Micah
 *
 * Description: This class represents a weapon in the game. This class is a child of the Tool class.
 *
 * Properties:
 * ----------
 * > AttackRage {int}: this is the range of attack of the weapon.
 * > AttackInterval {float}: this is the time interval between attacks.
 * > AttackDamage {int}: this is the damage of the weapon.
 *
 * Methods:
 * --------
 * > Getters and Setters for the properties.
 * > Weapon(): default constructor.
 * > Weapon(string name, string category, Position* position,
 *    int attackRange, int attackInterval, int attackDamage) - This is an overloaded constructor.
 * > ~Weapon(): default destructor.
 * > virtual void InflictDamage(Character& character) - This method is used to inflict damage to an enemy.
 * > virtual void Upgrade() - This method is used to upgrade the weapon.
 * > virtual void Use() - This method is used to use the weapon.
 */
class Weapon : public Tool
{
private:
	int attackRange;
	float attackInterval;
	int attackDamage;

public:
	/**
	 * @brief The default constructor of the Weapon class.
	 */
	Weapon();

	/**
	 * @brief The overloaded constructor of the Weapon class.
	 * @param newName - The name of the weapon.
	 * @param newCat - The category of the weapon.
	 * @param newPos - The position of the weapon.
	 * @param attckRange - The attack range of the weapon.
	 * @param attckInterval -	The attack interval of the weapon.
	 * @param attckDamage - The attack damage of the weapon.
	*/
	Weapon(std::string& newName, std::string& newCat, Position* newPos, int attckRange, float attckInterval, int attckDamage);

	/**
	 * @brief The default destructor of the Weapon class.
	*/
	~Weapon() override;

	/**
	 * @brief Getter for the attack range of the weapon.
	 * @return an integer representing the attack range of the weapon.
	*/
	int GetAttackRange() const;

	/**
	 * @brief Setter for the attack range of the weapon.
	 * @param attckRange - the desired attack range of the weapon.
	*/
	void SetAttackRange(int attckRange);

	/**
	 * @brief Getter for the attack interval of the weapon.
	 * @return an integer representing the attack interval of the weapon.
	*/
	float GetAttackInterval() const;

	/**
	 * @brief Setter for the attack interval of the weapon.
	 * @param attckInterval - the desired attack interval of the weapon.
	*/
	void SetAttackInterval(float attckInterval);

	/**
	 * @brief Getter for teh attack damage of the weapon.
	 * @return an integer representing the attack damage of the weapon.
	*/
	int GetAttackDamage() const;

	/**
	 * @brief Setter for the attack damage of the weapon.
	 * @param attckDamage - the desired attack damage of the weapon.
	*/
	void SetAttackDamage(int attckDamage);

	/**
	 * @brief This function allows the player to use the weapon in inflicting damage to another character or an enemy
	 * @param chrcter - the target character or enemy on whom to inflict the damage.
	*/
	virtual void InflictDamage(Character& chrcter);

	/**
	 * @brief This function enables the player to upgrade the weapon.
	*/
	void Upgrade() override;

	/**
	 * @brief This function enables the player to use the weapon.
	*/
	void Use() override;
};