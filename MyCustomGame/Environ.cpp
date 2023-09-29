#include "Environ.h"
#include "Backpack.h"

using namespace std;
/**
 * @file Environ.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the Environ class defined in Environ.h
 */
Environ::Environ()
{
	name = "Randomly Spawned Envrion";
	booster = Booster::BackpackBooster;
	spawnWeight = 3;
	position = Position();
}

Environ::Environ(string& name, Booster booster, int spawnWeight, Position& position):
name(name), booster(booster), spawnWeight(spawnWeight), position(position)
{
	cout << "Environ Instatiated Successfully" << endl;
}

Environ::~Environ()=default;

Environ::Environ(const Environ& environ_)
{
	name = environ_.name;
	booster = environ_.booster;
	spawnWeight = environ_.spawnWeight;
	position = environ_.position;
}

string Environ::GetName() const
{
	return name;
}

void Environ::SetName(string& newName)
{
	this->name = newName;
}

Booster Environ::GetBooster() const
{
	return booster;
}

void Environ::SetBooster(Booster newBoost)
{
	this->booster = newBoost;
}

int Environ::GetSpawnWeight() const
{
	return spawnWeight;
}

void Environ::SetSpawnWeight(int newWeight)
{
	this->spawnWeight = newWeight;
}

const Position* Environ::GetPosition() const
{
	return &position;
}

void Environ::SetPosition(const Position& newPos)
{
	this->position = newPos;
}

void Environ::Extract(Backpack& backpack)
{
	backpack.AddItem(this);

	cout << "You have picked up a " << GetName() << "!" << endl;
}

void Environ::Spawn() const
{
	cout << "You have found a " << GetName() << "!" << endl;
}
