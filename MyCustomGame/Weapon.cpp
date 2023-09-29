#include "Weapon.h"
#include <cmath>

using namespace std;
/**
 * @file Weapon.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the Weapon class which derives from Tool class defined in Weapon.h
 */
Weapon::Weapon():Tool()
{
	attackRange = 4;
	attackDamage = 10;
	attackInterval = 1;
}

Weapon::Weapon(string& newName, string& newCat, Position* newPos, int attckRange, float attckInterval, int attckDamage)
: Tool(newName, newCat, newPos), attackRange(attckRange), attackInterval(attckInterval), attackDamage(attckDamage)
{
	cout << "<Creation Message> Weapon Created" << endl;
}

Weapon::~Weapon()
{
	delete position;
}

void Weapon::SetAttackRange(int attckRange)
{
	this->attackRange = attckRange;
}

int Weapon::GetAttackRange() const
{
	return attackRange;
}

void Weapon::SetAttackDamage(int attckDamage)
{
	this->attackDamage = attckDamage;
}

int Weapon::GetAttackDamage() const
{
	return attackDamage;
}

void Weapon::SetAttackInterval(float attckInterval)
{
	this->attackInterval = attckInterval;
}

float Weapon::GetAttackInterval() const
{
	return attackInterval;
}

void Weapon::InflictDamage(Character& chrcter)
{
	Use();
	// Check if the character is within attack range
	if (std::abs(*position - chrcter.GetPosition()) <= static_cast<float>(attackRange))
	{
		chrcter.SetCurrentHealth(chrcter.GetCurrentHealth() - static_cast<float>(attackDamage));
		cout << "--------------------------------"<< endl;
		cout << "Character Health: " << chrcter.GetCurrentHealth() << endl;
		cout << "--------------------------------"<< endl;
	}
	else
	{
		cout << "--------------------------------"<< endl;
		cout << "Character is out of range" << endl;
		cout << "--------------------------------"<< endl;
	}
}


void Weapon::Upgrade()
{
	attackRange += 2;
	attackDamage += 5;
	attackInterval -= 0.1f;

	cout << "Weapon Upgraded" << endl;
	cout << "--------------------------------"<< endl;
	cout << "Attack Range Upgraded to: " << attackRange << endl;
	cout << "Attack Damage Upgraded to: " << attackDamage << endl;
	cout << "Attack Interval Upgraded to: " << attackInterval << endl;
	cout << "--------------------------------"<< endl;
}

void Weapon::Use()
{
	cout << "Weapon Used" << endl;
	cout << "--------------------------------"<< endl;
	cout << "Strike Attack Range: " << attackRange << endl;
	cout << "Strike Attack Damage: " << attackDamage << endl;
	cout << "Strike Attack Interval: " << attackInterval << endl;
	cout << "--------------------------------"<< endl;
}