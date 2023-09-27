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
	 * @param name - The name of the weapon.
	 * @param category - The category of the weapon.
	 * @param position - The position of the weapon.
	 * @param attackRange - The attack range of the weapon.
	 * @param attackInterval -	The attack interval of the weapon.
	 * @param attackDamage - The attack damage of the weapon.
	*/
	Weapon(string name, string category, Position* position, int attackRange, int attackInterval, int attackDamage);

	/**
	 * @brief The default destructor of the Weapon class.
	*/
	~Weapon();

	/**
	 * @brief Getter for the attack range of the weapon.
	 * @return an integer representing the attack range of the weapon.
	*/
	int GetAttackRange() const;

	/**
	 * @brief Setter for the attack range of the weapon.
	 * @param attackRange - the desired attack range of the weapon.
	*/
	void SetAttackRange(int attackRange);

	/**
	 * @brief Getter for the attack interval of the weapon.
	 * @return an integer representing the attack interval of the weapon.
	*/
	int GetAttackInterval() const;

	/**
	 * @brief Setter for the attack interval of the weapon.
	 * @param attackInterval - the desired attack interval of the weapon.
	*/
	void SetAttackInterval(float attackInterval);

	/**
	 * @brief Getter for teh attack damage of the weapon.
	 * @return an integer representing the attack damage of the weapon.
	*/
	int GetAttackDamage() const;

	/**
	 * @brief Setter for the attack damage of the weapon.
	 * @param attackDamage - the desired attack damage of the weapon.
	*/
	void SetAttackDamage(int attackDamage);

	/**
	 * @brief This function allows the player to use the weapon in inflicting damage to another character or an enemy
	 * @param character - the target character or enemy on whom to inflict the damage.
	*/
	virtual void InflictDamage(Character& character);

	/**
	 * @brief This function enables the player to upgrade the weapon.
	*/
	virtual void Upgrade();

	/**
	 * @brief This function enables the player to use the weapon.
	*/
	virtual void Use();
};