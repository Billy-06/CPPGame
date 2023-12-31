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

	bag1D_ = new Iterator1D();
	bag2D_ = new Iterator2D();

	skillNodes_ = new SkillAdvancement();

	// Additional message field for the chracter task 3
	fMessage_ = "";
}

CharacterTask3::CharacterTask3(string& name, float maxHealth, bool friendly)
	: name_(name), friendly_(friendly), fMaxHealth_(maxHealth)
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
	bag1D_ = new Iterator1D();
	bag2D_ = new Iterator2D();

	skillNodes_ = new SkillAdvancement();

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

	bag1D_ = character.bag1D_;
	bag2D_ = character.bag2D_;

	skillNodes_ = character.skillNodes_;

	// Additional message field for the chracter task 3
	fMessage_ = character.fMessage_;
}

CharacterTask3::~CharacterTask3()
{
	delete fPosition_;

	delete bag1D_;
	delete bag2D_;

	delete skillNodes_;
}

SkillAdvancement* CharacterTask3::GetSkillNodes() const
{
	return skillNodes_;
}

void CharacterTask3::SetSkillNodes(SkillAdvancement* skillNodes)
{
	skillNodes_ = skillNodes;
}

void CharacterTask3::AddSkillNode(SkillNode* skillNode) const
{
	skillNodes_->AppendSkill(skillNode);
}

void CharacterTask3::AddSkillNode(string& skillNode) const
{
	int level = 1;
	SkillNode* skill = new SkillNode(skillNode, level);
	skillNodes_->AppendSkill(skill);
}

void CharacterTask3::RemoveSkillNode(string& skillNode) const
{
	SkillNode* skill = skillNodes_->FindSkill(skillNode);
	skillNodes_->RemoveSkill(skill);
}

void CharacterTask3::UpgradeSkillNode(std::string& skillNodeName) const
{
	SkillNode* skillNode = skillNodes_->FindSkill(skillNodeName);
	skillNode->LevelUp();
}

SkillNode* CharacterTask3::FindSkillNode(std::string& skillName) const
{
	return skillNodes_->FindSkill(skillName);
}

void CharacterTask3::ShowSkillNodes() const
{
	SkillNode* temp = skillNodes_->GetHeadSkill();
	while (temp->GetUpgrade() != nullptr)
	{
		temp->PrintDetails();
		temp = temp->GetUpgrade();
	}
	temp->PrintDetails();
}

void CharacterTask3::AddUserCustomSkillNode() const
{
	string response;

	while (true)
	{
		cout << "Please select what you would like to do from the below options:\n";
		cout << "Enter the letter encircled in the square brackets e.g type f for option [f]\n";
		cout << "Type back or leave to go back to the main Menu\n";
		cout << "1). Find a Skill [f]\n";
		cout << "2). Add a Skill [a]\n";
		cout << "3). Remove a Skill [r]\n";
		cout << "4). View Skills [v]\n";
		cout << "5). Edit a Skill [e]\n";

		vector<string> skillNames;
		SkillNode* temp = skillNodes_->GetHeadSkill();
		while (temp != nullptr)
		{
			skillNames.push_back(temp->GetName());
			temp = temp->GetUpgrade();
		}

		string findSkl = "f", addSkl = "a", removeSkl = "r", viewSkl = "v", editSkl = "e",
			leaveSkl = "leave", exitSkl="exit";

		getline(cin, response);

		
		if (response == findSkl)
		{
			cout << "Please enter the name of the skill you would like to find" << endl;
			getline(cin, response);
			if (find(skillNames.begin(), skillNames.end(), response) == skillNames.end())
			{
				cout << "Skill not found" << endl;
				cout << "Please Make sure to type the full name (case sensitive)" << endl;
			}
			else
			{
				cout << "Skill found" << endl;
				FindSkillNode(response)->PrintDetails();
			}
		}
		else if (response == addSkl)
		{
			cout << "Please enter the name of the skill you would like to add" << endl;
			getline(cin, response);
			if (find(skillNames.begin(), skillNames.end(), response) != skillNames.end())
			{
				cout << "Skill already Exists found" << endl;
				cout << "Please Provide a skill name that does not already exist" << endl;
			}
			else
			{
				string skillName = response;
				AddSkillNode(skillName);
				cout << "Skill Added successfully" << endl;
				cout << "\n" << endl;
				cout << "\n" << endl;
				ShowSkillNodes();
			}
		}
		else if (response == removeSkl)
		{
			cout << "Please enter the name of the skill you would like to remove" << endl;
			getline(cin, response);
			if (find(skillNames.begin(), skillNames.end(), response) == skillNames.end())
			{
				cout << "Skill not found" << endl;
				cout << "Please Make sure to type the full name (case sensitive)" << endl;
			}
			else
			{
				cout << "Skill found" << endl;
				RemoveSkillNode(response);
				cout << "Deletion Successful" << endl;
			}
		}
		else if (response == viewSkl)
		{
			ShowSkillNodes();
		}
		else if (response == editSkl)
		{
			cout << "Please enter the full name of the skill you would like to edit" << endl;
			cout << "You can view skill to check what skills are available" << endl;
			getline(cin, response);
			if (find(skillNames.begin(), skillNames.end(), response) == skillNames.end())
			{
				cout << "Skill not found" << endl;
				cout << "Please Make sure to type the full name (case sensitive)" << endl;
			}
			else
			{
				cout << "Skill found" << endl;
				FindSkillNode(response)->PrintDetails();

				bool changed = false;
				string change;
				string option1 = "c", option2 = "u";

				while (!changed)
				{
					cout << "What would you like to change about the Skill?" << endl;
					cout << "Type the letter enclosed in square brackets e.g c for option [c]\n" << endl;
					cout << "1). Change Name [c]\n";
					cout << "2). Upgrade [u]" << endl;
					getline(cin, change);
					if (change == option1)
					{
						cout << "Please enter the new name of the skill" << endl;
						getline(cin, change);
						FindSkillNode(response)->SetName(change);
						cout << "Name Change Successful" << endl;
						changed = true;
					}
					else if (change == option2)
					{
						UpgradeSkillNode(response);
						cout << "Upgrade Successful" << endl;
						changed = true;
					}
					else if ( change == leaveSkl || change == exitSkl)
					{
						break;
					}
					else
					{
						cout << "Invalid Response" << endl;
					}
				}

			}
		}
		else if (response == leaveSkl || response == exitSkl)
		{
			break;
		}
		else
		{
			cout << "Invalid Response" << endl;
		}
	}
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

Iterator1D* CharacterTask3::GetBag1D() const
{
	return bag1D_;
}

void CharacterTask3::SetBag1D(Iterator1D* bag1D)
{
	bag1D_ = bag1D;
}

string CharacterTask3::InventoryNext() const
{
	++*bag1D_;
	return bag1D_->GetCurrentItem();
}

string CharacterTask3::InventoryPrev() const
{
	--*bag1D_;
	return bag1D_->GetCurrentItem();
}

void CharacterTask3::InventoryGet() const
{
	cout <<  bag1D_->GetCurrentItem() << endl;
}

void CharacterTask3::SwapBags1D(CharacterTask3& chrcter)
{
	Iterator1D* temp = bag1D_;
	this->SetBag1D(chrcter.GetBag1D());
	chrcter.SetBag1D(temp);
	cout << GetName() << " has swapped Bags with" << chrcter.GetName() << endl;
}

void CharacterTask3::SwapBags2D(CharacterTask3& chrcter)
{
	Iterator2D* temp = bag2D_;
	this->SetBag2D(chrcter.GetBag2D());
	chrcter.SetBag2D(temp);
	cout << GetName() << " has swapped Bags with" << chrcter.GetName() << endl;
}


Iterator2D* CharacterTask3::GetBag2D() const
{
	return bag2D_;
}

string CharacterTask3::InventoryNext2D() const
{
	++*bag2D_;
	return bag2D_->GetCurrentItem();
}

string CharacterTask3::InventoryPrev2D() const
{
	--*bag2D_;
	return bag2D_->GetCurrentItem();
}

void CharacterTask3::InventoryGet2D() const
{
	cout << bag2D_->GetCurrentItem() << endl;
}

void CharacterTask3::SetBag2D(Iterator2D* bag2D)
{
	bag2D_ = bag2D;
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


string CharacterTask3::PrintVector(const vector<string>& vector)
{
	string result = "";
	for (auto& item : vector)
	{
		result += "> " + item + " \n";
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

