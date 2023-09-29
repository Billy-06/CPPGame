#include "Equipment.h"

using namespace std;
/**
 * @file Equipment.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the Equipment class defined in Equipment.h
 */
Equipment::Equipment(): Tool()
{
	miningSpeed = 3;
	durability = 10;
	range= 4;
	damage = 10;

	cout << "<Creation Message> Default Equipment Created" << endl;
}

Equipment::Equipment(std::string& newName, std::string& newCat, Position* newPos, int miningSpeed, float durability, int range, int damage)
: Tool(newName, newCat, newPos), miningSpeed(miningSpeed), durability(durability), range(range), damage(damage)
{
	cout << "<Creation Message> Equipment Created" << endl;
}

Equipment::~Equipment()
{
	delete position;
}

int Equipment::GetMiningSpeed() const
{
	return miningSpeed;
}

void Equipment::SetMiningSpeed(int mngSpeed)
{
	this->miningSpeed = mngSpeed;
}

float Equipment::GetDurability() const
{
	return durability;
}

void Equipment::SetDurability(float durab)
{
	this->durability = durab;
}

int Equipment::GetRange() const
{
	return range;
}

void Equipment::SetRange(int rnge)
{
	this->range = rnge;
}

int Equipment::GetDamage() const
{
	return damage;
}

void Equipment::SetDamage(int dmg)
{
	this->damage = dmg;
}

void Equipment::Use()
{
	if (durability <= 0)
	{
		cout << "Equipment is broken" << endl;
	} else if (durability <= 2)
	{
		cout << "Equipment is about to break" << endl;
		durability -= 0.3f;

		cout << "Mining at speed: " << miningSpeed << endl;
		cout << "Durability is now at: " << durability << endl;
	}
	else
	{
		cout << "Equipment is in good condition" << endl;
		durability -= 0.3f;

		cout << "Mining at speed: " << miningSpeed << endl;
		cout << "Durability is now at: " << durability << endl;
	}
}

void Equipment::Upgrade()
{
	miningSpeed += 2;
	durability += 5;
	range += 2;
	damage += 5;

	cout << "--------------------------------"<< endl;
	cout << "Mining Speed set to: " << miningSpeed << endl;
	cout << "Durability set to: " << durability << endl;
	cout << "Range set to: " << range << endl;
	cout << "Damage set to: " << damage << endl;
	cout << endl;
	cout << "Equipment Upgraded Successfully" << endl;
	cout << "--------------------------------"<< endl;
}

