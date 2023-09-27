#include "Character.h"
#include <iostream>
#include <cstdlib>

using namespace std;
/**
 * @file Character.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the Character class defined in Character.h
 *
 */

Character::Character()
{
	fID_ = static_cast<float>(rand());
	name_ = "";
	attackMoves_ = { };
	strengths_ = { };
	weaknesses_ = { };
	fears_ = { };

	hydration_ = 100;
	friendly_ = true;
	backpack_ = Backpack();
	fPosition_ = new Position();
	fMaxHealth_ = 100;
	fCurrentHealth_ = 100;
	fAttackPower_ = 10;
	shieldUp_ = false;
}

Character::Character(string& name, float maxHealth, bool friendly) : name_(name), fMaxHealth_(maxHealth), friendly_(friendly)
{
	fID_ = static_cast<float>(rand());
	attackMoves_ = { };
	strengths_ = { };
	weaknesses_ = { };
	fears_ = { };

	hydration_ = 100;
	backpack_ = Backpack();
	fPosition_ = new Position();
	fCurrentHealth_ = maxHealth;
	fAttackPower_ = 10;
	shieldUp_ = false;
}

Character::Character(const Character& character)
{
	fID_ = character.fID_;
	name_ = character.name_;
	attackMoves_ = character.attackMoves_;
	strengths_ = character.strengths_;
	weaknesses_ = character.weaknesses_;
	fears_ = character.fears_;

	hydration_ = character.hydration_;
	friendly_ = character.friendly_;
	backpack_ = character.backpack_;
	fPosition_ = character.fPosition_;
	fMaxHealth_ = character.fMaxHealth_;
	fCurrentHealth_ = character.fCurrentHealth_;
	fAttackPower_ = character.fAttackPower_;
	shieldUp_ = character.shieldUp_;
}

Character::~Character()
{
	delete fPosition_;
	delete this;

}

string Character::GetName() const
{
	return name_;
}

void Character::SetName(const string& name)
{
	name_ = name;
}

bool Character::GetShieldUp() const
{
	return shieldUp_;
}

void Character::SetShieldUp(bool shieldUp)
{
	shieldUp_ = shieldUp;
}

vector<string> Character::GetAttackMoves() const
{
	return attackMoves_;
}

void Character::SetAttackMoves(const std::vector<std::string>& attackMoves)
{
	attackMoves_ = attackMoves;
}

std::vector<std::string> Character::GetStrengths() const
{
	return strengths_;
}

void Character::SetStrengths(const std::vector<std::string>& strengths)
{
	strengths_ = strengths;
}

std::vector<std::string> Character::GetWeaknesses() const
{
	return weaknesses_;
}

void Character::SetWeaknesses(const std::vector<std::string>& weaknesses)
{
	weaknesses_ = weaknesses;
}

std::vector<std::string> Character::GetFears() const
{
	return fears_;
}

void Character::SetFears(const std::vector<std::string>& fears)
{
	fears_ = fears;
}


int Character::GetHydration() const
{
	return hydration_;
}

bool Character::GetFriendly() const
{
	return friendly_;
}

Backpack Character::GetBackpack() const
{
	return backpack_;
}

void Character::SetBackpack(const Backpack& backpack) 
{
	backpack_ = backpack;
}

float Character::GetID() const
{
	return fID_;
}

void Character::SetID(float id)
{
	fID_ = id;
}

Position& Character::GetPosition() const
{
	return *fPosition_;
}

void Character::SetPosition(const Position& position)
{
	fPosition_ = new Position(position);
}

float Character::GetMaxHealth() const
{
	return fMaxHealth_;
}

void Character::SetMaxHealth(float maxHealth)
{
	fMaxHealth_ = maxHealth;
}

float Character::GetCurrentHealth() const
{
	return fCurrentHealth_;
}

void Character::SetCurrentHealth(float currentHealth)
{
	fCurrentHealth_ = currentHealth;
}

float Character::GetAttackPower() const
{
	return fAttackPower_;
}

void Character::SetAttackPower(float attackPower)
{
	fAttackPower_ = attackPower;
}

void Character::ShowAttributes() const
{
	cout << "Name: " << name_ << endl;
	cout << "ID: " << fID_ << endl;
	cout << "Attack Moves: ";
	for (auto& move : attackMoves_)
	{
		cout << move << " ";
	}
	cout << "--------------";
	cout << endl;
	cout << "Strengths: ";
	for (auto& strength : strengths_)
	{
		cout << strength << " ";
	}
	cout << "--------------";
	cout << endl;
	cout << "Weaknesses: ";
	for (auto& weakness : weaknesses_)
	{
		cout << weakness << " ";
	}
	cout << "--------------";
	cout << endl;
	cout << "Fears: ";
	for (auto& fear : fears_)
	{
		cout << fear << " ";
	}
	cout << "--------------";
	cout << endl;
	cout << "Hydration: " << hydration_ << endl;
	cout << "Friendly: " << friendly_ << endl;
	cout << "Backpack: " << endl;
	backpack_.ShowItems();
	cout << "Position: " << endl;
	fPosition_->ShowPosition();
	cout << "Max Health: " << fMaxHealth_ << endl;
	cout << "Current Health: " << fCurrentHealth_ << endl;
	cout << "Attack Power: " << fAttackPower_ << endl;
}

void Character::ShowAttackMoves() const
{
	cout << "Attack Moves: ";
	cout << "===============";
	for (auto& move : attackMoves_)
	{
		cout << move << " ";
	}
	cout << "===============" << endl;
}

void Character::ShowBackpack() const
{
	cout << "Backpack: " << endl;
	cout << "===============";
	backpack_.ShowItems();
	cout << "===============" << endl;
}

void Character::Shield()
{
	shieldUp_ = true;
	cout << "Shield Up." << endl;
	cout << "No Damage Inflicted on Character" << endl;
	cout << "Shields Back Down." << endl;
	cout << "Combat Mode." << endl;
	cout << "-----------------" << endl;

}

void Character::Move(const std::string& direction)
{
	switch (direction)
	{
	case "north":
		fPosition_->SetY(fPosition_->GetY() + 1);
		break;
	case "east":
		fPosition_->SetX(fPosition_->GetX() + 1);
		break;
	case "south":
		fPosition_->SetY(fPosition_->GetY() - 1);
		break;
	case "west":
		fPosition_->SetX(fPosition_->GetX() - 1);
		break;
	default:
		cout << "Invalid Direction" << endl;
		break;
	}
}

void Character::Attack(Character& character)
{
	shieldUp_ = false;
	if (character.GetShieldUp())
	{
		cout << character.GetName() << " has Shields Up." << endl;
		cout << "No Damage Inflicted on Character" << endl;
		cout << "------------------------------------" << endl;
	}
	else
	{
		character.TakeDamage(fAttackPower_);
		cout << character.GetName() << " has taken " << fAttackPower_ << " damage." << endl;
		cout << "------------------------------------" << endl;

	}
}

void Character::TakeDamage(float damage)
{
	fCurrentHealth_ -= damage;
	if (fCurrentHealth_ <= 0)
	{
		fCurrentHealth_ = 0;
		cout << name_ << " has died." << endl;
	}
}

int Character::Interact(Environ& environ_)
{
	if (environ_.GetBooster() == Booster::HealthBooster)
	{
		fCurrentHealth_ += 10;
		if (fCurrentHealth_ > fMaxHealth_)
		{
			fCurrentHealth_ = fMaxHealth_;
			cout << "Health is full." << endl;
		}
		cout << "Health is now " << fCurrentHealth_ << endl;

		return 1;
	}
	if (environ_.GetBooster() == Booster::HydrationBooster)
	{
		hydration_ += 10;
		if (hydration_ > 100)
		{
			hydration_ = 100;
			cout << "Hydration is full." << endl;
		}
		cout << "Hydration is now " << hydration_ << endl;

		return hydration_;
	}
	if (environ_.GetBooster() == Booster::AttackBooster)
	{
		fAttackPower_ += 5.0;
		cout << "Your Attack Power was Boosted" << endl;
		cout << "Attack Power is now " << fAttackPower_ << endl;

		return static_cast<int>(fAttackPower_);
	}
	if (environ_.GetBooster() == Booster::ShieldBooster)
	{
		shieldUp_ = true;
		cout << "Shields Repaired. Your Shields are now re-brandished." << endl;
		cout << "You're more than ready for battle." << endl;

		return 4;
	}
	if (environ_.GetBooster() == Booster::BackpackBooster)
	{
		Environ* envPointer = &environ_;

		backpack_.AddItem(envPointer);

		cout << "You have picked up a " << environ_.GetName() << endl;
		cout << "Packed up for the journey ahead." << endl;

		return 5;
	}

	return 0;
}

void Character::PickItem(Tool& item)
{
	Tool* itemPointer = &item;

	backpack_.AddItem(itemPointer);
	cout << "You have picked up a " << item.GetName() << endl;
	cout << "Packed up for the journey ahead." << endl;
}

void Character::DropItem(Tool& item)
{
	Tool* itemPointer = &item;

	backpack_.RemoveItem(itemPointer);
	cout << "You have dropped a " << item.GetName() << endl;
	cout << "Packed up for the journey ahead." << endl;
}

void Character::Print() const
{
	this->ShowAttributes();
}



