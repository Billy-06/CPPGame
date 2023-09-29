#include "RattleSnake.h"

using namespace std;
/**
 * @file RattleSnake.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the RattleSnake class which derives from Character class defined in Weapon.h
 */
RattleSnake::RattleSnake(): Character()
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

	venomReserve_ = 100;

	cout << "<Creation Message> Default RattleSnake Created" << endl;
}

RattleSnake::RattleSnake(string& name, float health, bool friendly, int venomReserve)
	: Character(name, health, friendly), venomReserve_(venomReserve)
{
			cout << "<Creation Message> RattleSnake Created" << endl;
}

RattleSnake::RattleSnake(const RattleSnake& rattleSnake)
	: Character(rattleSnake)
{
		fID_ = rattleSnake.fID_;
	name_ = rattleSnake.name_;
	attackMoves_ = rattleSnake.attackMoves_;
	strengths_ = rattleSnake.strengths_;
	weaknesses_ = rattleSnake.weaknesses_;
	fears_ = rattleSnake.fears_;

	hydration_ = rattleSnake.hydration_;
	friendly_ = rattleSnake.friendly_;
	backpack_ = rattleSnake.backpack_;
	fPosition_ = rattleSnake.fPosition_;
	fMaxHealth_ = rattleSnake.fMaxHealth_;
	fCurrentHealth_ = rattleSnake.fCurrentHealth_;
	fAttackPower_ = rattleSnake.fAttackPower_;
	shieldUp_ = rattleSnake.shieldUp_;

	venomReserve_ = rattleSnake.venomReserve_;
}

RattleSnake::~RattleSnake()
{
	delete fPosition_;
}


int RattleSnake::GetVenomReserve() const
{
	return venomReserve_;
}

void RattleSnake::SetVenomReserve(int venomReserve)
{
	this->venomReserve_ = venomReserve;
}

void RattleSnake::Slither(string& direction)
{
	Move(direction);
}

void RattleSnake::SpitVenom()
{
	if (venomReserve_ > 0)
	{
		cout << "Spitting Venom" << endl;
		venomReserve_ -= 10;
	}
	else
	{
		cout << "Ran out of venom, you've tamed you're sense" << endl;
	}
}


void RattleSnake::SenseEnviron() const
{
	cout << "Snake position " << fPosition_->GetX() << ", " << fPosition_->GetY() << endl;

	cout << "-------------------------------------------------------"<< endl;
	cout << "SSSSSS Sensing the environs around the current position" << endl;
	cout << "---------------------------------------------------------"<< endl;
}
