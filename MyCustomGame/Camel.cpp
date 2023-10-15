#include "Camel.h"

using namespace std;
/**
 * @file Camel.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the Camel class which derives from Character class defined in Weapon.h
 */
Camel::Camel(): Character()
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
	fMaxHealth_ = 100.0f;
	fCurrentHealth_ = 100.0f;
	fAttackPower_ = 10;
	shieldUp_ = false;

	hints_ = { "I am" };
	waterReserve_ = 100;

	cout << "<Creation Message> Default Camel Created" << endl;
}

Camel::Camel(string& name, float health, bool friendly, string& hints, int waterReserve)
: Character(name, health, friendly), hints_(hints), waterReserve_(waterReserve)
{
	cout << "<Creation Message> Camel Created" << endl;
}

Camel::Camel(const Camel& camel)
 : Character(camel) {
	fID_ = camel.fID_;
	name_ = camel.name_;
	attackMoves_ = camel.attackMoves_;
	strengths_ = camel.strengths_;
	weaknesses_ = camel.weaknesses_;
	fears_ = camel.fears_;

	hydration_ = camel.hydration_;
	friendly_ = camel.friendly_;
	backpack_ = camel.backpack_;
	fPosition_ = camel.fPosition_;
	fMaxHealth_ = camel.fMaxHealth_;
	fCurrentHealth_ = camel.fCurrentHealth_;
	fAttackPower_ = camel.fAttackPower_;
	shieldUp_ = camel.shieldUp_;

	hints_ = camel.hints_;
	waterReserve_ = camel.waterReserve_;
}

Camel::~Camel()= default;

int Camel::GetWaterReserve() const
{
	return waterReserve_;
}

void Camel::SetWaterReserve(int waterReserve)
{
	waterReserve_ = waterReserve;
}

string Camel::GetHints() const
{
	return hints_;
}

void Camel::SetHints(string& hints)
{
	hints_ = hints;
}

void Camel::DrinkWater()
{
	if (waterReserve_ < 150)
	{
		hydration_ += 10;
		waterReserve_ += 10;
		cout << "--------------------------------"<< endl;
		cout << "Drinking Water" << endl;
		cout << "Water Reserve Replenished, now at: " << waterReserve_ << endl;
		cout << "--------------------------------"<< endl;
	}
	else
	{
		cout << "--------------------------------"<< endl;
		cout << "You've drank to your fill" << endl;
		cout << "Water Reserve now at: "<< waterReserve_ << endl;
		cout << "--------------------------------"<< endl;
	}
}

void Camel::ShowHint() const
{
	cout << "--------------------------------"<< endl;
	cout << "Hint: " << hints_ << endl;
	cout << "--------------------------------"<< endl;
}

void Camel::Run(std::string& direction)
{
	const vector<string> directions = { "north", "east", "south", "west" };

	if (direction == directions[0])
	{
		fPosition_->SetY(fPosition_->GetY() + 3);
		cout << name_ << " is running " << direction << "at speed " << 3 << endl;
	}
	else if (direction == directions[1])
	{
		fPosition_->SetX(fPosition_->GetX() + 3);
		cout << name_ << " is running " << direction << "at speed " << 3 << endl;
	}
	else if (direction == directions[2])
	{
		fPosition_->SetY(fPosition_->GetY() - 3);
		cout << name_ << " is running " << direction << "at speed " << 3 << endl;
	}
	else if (direction == directions[3])
	{
		fPosition_->SetX(fPosition_->GetX() - 3);
		cout << name_ << " is running " << direction << "at speed " << 3 << endl;
	}
	else
	{
		cout << "Invalid Direction" << endl;
	}
}

void Camel::ExpendWater()
{
	if (waterReserve_ > 10)
	{
		waterReserve_ -= 10;
		cout << "--------------------------------"<< endl;
		cout << "Camel Expended Water to player" << endl;
		cout << "Water Reserve now at: "<< waterReserve_ << endl;
		cout << "--------------------------------"<< endl;
		
	}else
	{
		cout << "--------------------------------"<< endl;
		cout << "Camel has limited water in the reserve" << endl;
		cout << "Water Reserve now at: "<< waterReserve_ << endl;
		cout << "Have the Camel drink some water" << endl;
		cout << "--------------------------------"<< endl;
	}
}
