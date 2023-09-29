#include "CharacterTask3.h"

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;
/**
 * @file Character.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the Character class defined in Character.h
 *
 */

CharacterTask3::CharacterTask3()
{
	fID_ = static_cast<float>(rand());
	name_ = "[Default] Just a Dummy Character";

	// Create some dummy attack moves
	attackMoves_ = { "Punch", "Kick", "Headbutt", "Bite", "Scratch" };

	// Create some dummy strengths
	strengths_ = { "Running", "Sleeping" }; 
	weaknesses_ = { "Cake", "Strawberries" };
	fears_ = { "Sand", "Jokes" };

	hydration_ = 100;
	friendly_ = true;
	backpack_ = Backpack();
	fPosition_ = new Position();
	fMaxHealth_ = 100;
	fCurrentHealth_ = 100;
	fAttackPower_ = 10;
	shieldUp_ = false;

	// Additional message field for the chracter task 3
	fMessage_ = "";
}

CharacterTask3::CharacterTask3(string& name, float maxHealth, bool friendly) : name_(name), fMaxHealth_(maxHealth), friendly_(friendly)
{
	fID_ = static_cast<float>(rand());
	// Create some dummy attack moves
	attackMoves_ = { "Punch", "Kick", "Headbutt", "Bite", "Scratch" };

	// Create some dummy strengths
	strengths_ = { "Running", "Sleeping" };
	weaknesses_ = { "Cake", "Strawberries" };
	fears_ = { "Sand", "Jokes" };

	hydration_ = 100;
	backpack_ = Backpack();
	fPosition_ = new Position();
	fCurrentHealth_ = maxHealth;
	fAttackPower_ = 10;
	shieldUp_ = false;

	// Additional message field for the chracter task 3
	fMessage_ = "";
}

CharacterTask3::CharacterTask3(const CharacterTask3& character)
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

	// Additional message field for the chracter task 3
	fMessage_ = character.fMessage_;
}

CharacterTask3::~CharacterTask3()
{
	delete fPosition_;
}

string CharacterTask3::GetName() const
{
	return name_;
}

void CharacterTask3::SetName(const string& name)
{
	name_ = name;
}

bool CharacterTask3::GetShieldUp() const
{
	return shieldUp_;
}

void CharacterTask3::SetShieldUp(bool shieldUp)
{
	shieldUp_ = shieldUp;
}

vector<string> CharacterTask3::GetAttackMoves() const
{
	return attackMoves_;
}

void CharacterTask3::SetAttackMoves(const std::vector<std::string>& attackMoves)
{
	attackMoves_ = attackMoves;
}

std::vector<std::string> CharacterTask3::GetStrengths() const
{
	return strengths_;
}

void CharacterTask3::SetStrengths(const std::vector<std::string>& strengths)
{
	strengths_ = strengths;
}

std::vector<std::string> CharacterTask3::GetWeaknesses() const
{
	return weaknesses_;
}

void CharacterTask3::SetWeaknesses(const std::vector<std::string>& weaknesses)
{
	weaknesses_ = weaknesses;
}

std::vector<std::string> CharacterTask3::GetFears() const
{
	return fears_;
}

void CharacterTask3::SetFears(const std::vector<std::string>& fears)
{
	fears_ = fears;
}


int CharacterTask3::GetHydration() const
{
	return hydration_;
}

bool CharacterTask3::GetFriendly() const
{
	return friendly_;
}

Backpack CharacterTask3::GetBackpack() const
{
	return backpack_;
}

void CharacterTask3::SetBackpack(const Backpack& backpack)
{
	backpack_ = backpack;
}

float CharacterTask3::GetID() const
{
	return fID_;
}

void CharacterTask3::SetID(float id)
{
	fID_ = id;
}

Position& CharacterTask3::GetPosition() const
{
	return *fPosition_;
}

void CharacterTask3::SetPosition(const Position& position)
{
	fPosition_ = new Position(position);
}

ostream& operator<<(ostream& out, const CharacterTask3& character)
{
	return out << "CharacterTask3 Stats" << character.PrintStat() << endl;
}

string CharacterTask3::PrintStat() const
{
	const string friendly = friendly_ ? "[Status] Friend" : "[Status] No";
	const string shield = shieldUp_ ? "[Shield] Up" : "[Shield] Down";
	const string message = fMessage_.empty() ? "[Message] No Message" : "[Message] " + fMessage_;

	return "\nName: " + name_ + "\nID: " + to_string(fID_) + "\nAttack Moves: "
		+ PrintVector(attackMoves_) + "\nStrengths: " + PrintVector(strengths_) + "\nWeaknesses: "
		+ PrintVector(weaknesses_) + "\nFears: " + PrintVector(fears_) + "\nHydration: "
		+ to_string(hydration_) + "\nFriendly: " + friendly + "\nBackpack: " + backpack_.ShowItemsToString()
		+ "\nPosition: " + fPosition_->ToString() + "\nMax Health: " + to_string(fMaxHealth_)
		+ "\nCurrent Health: " + to_string(fCurrentHealth_) + "\nAttack Power: " + to_string(fAttackPower_)
		+ "\nShield: " + shield + "\n" + message;
}

istream& operator>>(istream& in, CharacterTask3& character)
{
	vector<string> commands = { "attack", "move", "shield", "jump" };
	string message;
	string parsedCommand[2];
	getline(in, message);

	while (message.empty())
	{
		cout << "Invalid Command" << endl;
		getline(in, message);
	}

	
	stringstream ss(message);
	for (auto& i : parsedCommand)
	{
		ss >> i;
	}

	if (find(commands.begin(), commands.end(), parsedCommand[0]) == commands.end())
	{
		cout << "Invalid Command" << endl;
		return in;
	}
	if (stoi(parsedCommand[1]))
	{
		const auto parsedVal = static_cast<float>(stoi(parsedCommand[1]));

		if (parsedCommand[0] == commands[0])
		{
			character.SetAttackPower(parsedVal);
			cout << character.GetName() << "'s Attack Power is now " << parsedVal << endl;
		}
		else if (parsedCommand[0] == commands[1])
		{
			cout << "Moving..." << endl;
			cout << character.GetName() << " has moved " << parsedVal << " steps forward" << endl;

		}
		else if (parsedCommand[0] == commands[2])
		{
			character.Shield();
			cout << "Shields Up." << endl;
			cout << character.GetName() << "'s Shield Power updated by" << parsedVal << endl;
		}
		else if (parsedCommand[0] == commands[3])
		{
			cout << "Jumping..." << endl;
			cout << character.GetName() << " has jumped " << parsedVal << " feet high" << endl;
		}
		else
		{
			cout << "Invalid Command" << endl;
			character.SetMessage(message);
			cout << character.GetMessage()  << " is now a message."<< endl;
		}
	}
	cout << endl;
	cout << endl;
	cout << "--------------------------------------------" <<  endl;

	return in;
}

istream& operator>>(CharacterTask3 & character, CharacterTask3& character2)
{
	character.Attack(character2);
	istream& in = cin;
	return in;
}


string CharacterTask3::PrintVector(const vector<string>& vector) const
{
	string result = "";
	for (auto& item : vector)
	{
		result += item + " ";
	}

	return result;
}

string CharacterTask3::GetMessage() const
{
	return fMessage_;
}

void CharacterTask3::SetMessage(string& message)
{
	fMessage_ = message;
}

float CharacterTask3::GetMaxHealth() const
{
	return fMaxHealth_;
}

void CharacterTask3::SetMaxHealth(float maxHealth)
{
	fMaxHealth_ = maxHealth;
}

float CharacterTask3::GetCurrentHealth() const
{
	return fCurrentHealth_;
}

void CharacterTask3::SetCurrentHealth(float currentHealth)
{
	fCurrentHealth_ = currentHealth;
}

float CharacterTask3::GetAttackPower() const
{
	return fAttackPower_;
}

void CharacterTask3::SetAttackPower(float attackPower)
{
	fAttackPower_ = attackPower;
}

void CharacterTask3::ShowAttributes() const
{
	string friendly = friendly_ ? "[Status] Friend" : "[Status] No";
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
	cout << "Friendly: " << friendly << endl;
	cout << "Backpack: " << endl;
	backpack_.ShowItems();
	cout << "Position: " << endl;
	fPosition_->ShowPosition();
	cout << "Max Health: " << fMaxHealth_ << endl;
	cout << "Current Health: " << fCurrentHealth_ << endl;
	cout << "Attack Power: " << fAttackPower_ << endl;

	cout << endl;
	cout << endl;
}

void CharacterTask3::ShowAttackMoves() const
{
	cout << "Attack Moves: ";
	cout << "===============";
	for (auto& move : attackMoves_)
	{
		cout << move << " ";
	}
	cout << "===============" << endl;
}

void CharacterTask3::ShowBackpack() const
{
	cout << "Backpack: " << endl;
	cout << "===============";
	backpack_.ShowItems();
	cout << "===============" << endl;
}

void CharacterTask3::Shield()
{
	shieldUp_ = true;
	cout << "Shield Up." << endl;
	cout << "No Damage Inflicted on" << name_ << endl;
	cout << "Shields Back Down." << endl;
	cout << "Combat Mode." << endl;
	cout << "-----------------" << endl;

}

void CharacterTask3::Move(const std::string& direction)
{
	const vector<string> directions = { "north", "east", "south", "west" };

	if (direction == directions[0])
	{
		fPosition_->SetY(fPosition_->GetY() + 1);
		cout << name_ << " is walking " << direction << "at speed " << 1 << endl;
	}
	else if (direction == directions[1])
	{
		fPosition_->SetX(fPosition_->GetX() + 1);
		cout << name_ << " is walking " << direction << "at speed " << 1 << endl;
	}
	else if (direction == directions[2])
	{
		fPosition_->SetY(fPosition_->GetY() - 1);
		cout << name_ << " is walking " << direction << "at speed " << 1 << endl;
	}
	else if (direction == directions[3])
	{
		fPosition_->SetX(fPosition_->GetX() - 1);
		cout << name_ << " is walking " << direction << "at speed " << 1 << endl;
	}
	else
	{
		cout << "Invalid Direction" << endl;
	}


	delete& directions;
}

void CharacterTask3::Attack(CharacterTask3& character)
{
	shieldUp_ = false;
	if (character.GetShieldUp())
	{
		cout << character.GetName() << " has Shields Up." << endl;
		cout << "No Damage Inflicted on CharacterTask3" << endl;
		cout << "------------------------------------" << endl;

		const int shield = rand() % 1;
		if (shield == 1)
		{
			Shield();
		} else cout << "Shields Down." << endl;
	}
	else
	{
		const int moveIndex = static_cast<int>(rand() % attackMoves_.size());

		cout << character.GetName() << " has Shields Down." << endl;
		character.TakeDamage(fAttackPower_);
		cout << "Attack move used: " << attackMoves_[moveIndex] << endl;
		cout << character.GetName() << " has taken " << fAttackPower_ << " damage." << endl;
		cout << character.GetName() << " has " << character.GetCurrentHealth() << " health left." << endl;
		cout << "------------------------------------" << endl;

	}
}

void CharacterTask3::TakeDamage(float damage)
{
	fCurrentHealth_ -= damage;
	if (fCurrentHealth_ <= 0)
	{
		fCurrentHealth_ = 0;
		cout << name_ << " has died." << endl;
	}
}

int CharacterTask3::Interact(Environ& environ_)
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

void CharacterTask3::PickItem(Tool& item)
{
	Tool* itemPointer = &item;

	backpack_.AddItem(itemPointer);
	cout << "You have picked up a " << item.GetName() << endl;
	cout << "Packed up for the journey ahead." << endl;
}

void CharacterTask3::DropItem(Tool& item) const
{
	Tool* itemPointer = &item;

	backpack_.RemoveItem(itemPointer);
	cout << "You have dropped a " << item.GetName() << endl;
	cout << "Packed up for the journey ahead." << endl;
}

void CharacterTask3::Print() const
{
	this->ShowAttributes();
}

