#include "CamelSpider.h"
using namespace std;
/**
 * @file CamelSpider.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the CamelSpider class which derives from Character class defined in Weapon.h
 */
CamelSpider::CamelSpider(): Character()
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
	webStrength_ = 120;
	webReserve_ = 100;

	cout << "<Creation Message> Default CamelSpider Created" << endl;
}

CamelSpider::CamelSpider(string& name, float health, bool friendly, int venomReserve, int webStrength, int webReserve)
	: Character(name, health, friendly), venomReserve_(venomReserve), webStrength_(webStrength), webReserve_(webReserve)
{
		cout << "<Creation Message> CamelSpider Created" << endl;
}

CamelSpider::CamelSpider(const CamelSpider& camelSpider)
	: Character(camelSpider)
{
	fID_ = camelSpider.fID_;
	name_ = camelSpider.name_;
	attackMoves_ = camelSpider.attackMoves_;
	strengths_ = camelSpider.strengths_;
	weaknesses_ = camelSpider.weaknesses_;
	fears_ = camelSpider.fears_;

	hydration_ = camelSpider.hydration_;
	friendly_ = camelSpider.friendly_;
	backpack_ = camelSpider.backpack_;
	fPosition_ = camelSpider.fPosition_;
	fMaxHealth_ = camelSpider.fMaxHealth_;
	fCurrentHealth_ = camelSpider.fCurrentHealth_;
	fAttackPower_ = camelSpider.fAttackPower_;
	shieldUp_ = camelSpider.shieldUp_;

	venomReserve_ = camelSpider.venomReserve_;
	webStrength_ = camelSpider.webStrength_;
	webReserve_ = camelSpider.webReserve_;
}

CamelSpider::~CamelSpider()
{
	delete fPosition_;
}

int CamelSpider::GetVenomReserve() const
{
	return venomReserve_;
}

void CamelSpider::SetVenomReserve(int venomReserve)
{
	venomReserve_ = venomReserve;
}

int CamelSpider::GetWebStrength() const
{
	return webStrength_;
}

void CamelSpider::SetWebStrength(int webStrength)
{
	webStrength_ = webStrength;
}

int CamelSpider::GetWebReserve() const
{
	return webReserve_;
}

void CamelSpider::SetWebReserve(int webReserve)
{
	webReserve_ = webReserve;
}

void CamelSpider::InflictHarm()
{
	if (venomReserve_ > 0)
	{
		venomReserve_ -= 10;
		cout << "--------------------------------"<< endl;
		cout << "Injecting Venom" << endl;
		cout << "Venom Reserve Depleted, now at: " << venomReserve_ << endl;
		cout << "--------------------------------"<< endl;
	}
	else
	{
		cout << "--------------------------------"<< endl;
		cout << "Injecting Venom" << endl;
		cout << "Venom Reserve Depleted, now at: " << venomReserve_ << endl;
		cout << "--------------------------------"<< endl;
	}
}

void CamelSpider::SpinWeb()
{
	if (webReserve_ > 0)
	{
		webReserve_ -= 10;
		cout << "--------------------------------"<< endl;
		cout << "Spinning Web" << endl;
		cout << "Web Reserve Depleted, now at: " << webReserve_ << endl;
		cout << "--------------------------------"<< endl;
	}
	else
	{
		cout << "--------------------------------"<< endl;
		cout << "Spinning Web" << endl;
		cout << "Web Reserve Depleted, now at: " << webReserve_ << endl;
		cout << "--------------------------------"<< endl;
	}
}

void CamelSpider::Crawl(string& direction) const
{
	const vector<string> directions = { "north", "east", "south", "west" };

	if (direction == directions[0])
	{
		fPosition_->SetY(fPosition_->GetY() + 2);
		cout << name_ << " is crawling " << direction << "at speed " << 1 << endl;
	}
	else if (direction == directions[1])
	{
		fPosition_->SetX(fPosition_->GetX() + 2);
		cout << name_ << " is crawling " << direction << "at speed " << 1 << endl;
	}
	else if (direction == directions[2])
	{
		fPosition_->SetY(fPosition_->GetY() - 2);
		cout << name_ << " is crawling " << direction << "at speed " << 1 << endl;
	}
	else if (direction == directions[3])
	{
		fPosition_->SetX(fPosition_->GetX() - 2);
		cout << name_ << " is crawling " << direction << "at speed " << 1 << endl;
	}
	else
	{
		cout << "Invalid Direction" << endl;
	}	
}