#include "Backpack.h"
#include <cstdlib>

using namespace std;
/**
 * @file Backpack.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the Backpack class defined in Backpack.h
 */
Backpack::Backpack() {
	size_ = 0;
	items_ = { };
}

Backpack::Backpack(int size) {
	size_ = size;
	items_ = { };
}

Backpack::~Backpack() {
	for (const Tool* item : items_) {
		delete item;
	}
}

int Backpack::GetSize() const {
	return size_;
}

void Backpack::SetSize(int size) {
	size_ = size;
}

vector<Tool*> Backpack::GetItems() const {
	return items_;
}

void Backpack::SetItems(vector<Tool*>& items) {
	items_ = items;
}

void Backpack::AddItem(Tool* item)
{
	if (static_cast<int>(items_.size()) < size_)
	{
		items_.push_back(item);
	}
}

void Backpack::AddItem(Environ* environ_)
{

	Position* pos = new Position();

	switch(environ_->GetBooster())
	{
	case Booster::AttackBooster:
		{
			string attackCat = "AttackBooster";
			string attackName = environ_->GetName();

			Tool* toolAttack = new Tool(attackName, attackCat, pos);

			toolAttack->AddEnhancement(attackName);

			// Add he enhancement to the tool's list of enhancements
			toolAttack->AddEnhancement(attackCat);
			AddItem(toolAttack);

			cout << "Custom tool of category: " << attackCat << " created" << endl;
			break;
			
		}
	case Booster::ShieldBooster:
		{
			string shieldCat = "ShieldBooster";
			string shieldName = environ_->GetName();

			Tool* toolShield = new Tool(shieldName, shieldCat, pos);

			// Add the enhancement to the enhancement list
			toolShield->AddEnhancement(shieldName);
			AddItem(toolShield);
			cout << "Custom tool of category: " << shieldCat << " created" << endl;
			break;
		}

	case Booster::HydrationBooster:
		{
			string hydroCat = "HydrationBooster";
			string hydroName = environ_->GetName();

			Tool* toolHydro = new Tool(hydroName, hydroCat, pos);

			// Add the enhancement to the enhancement list
			toolHydro->AddEnhancement(hydroName);
			AddItem(toolHydro);
			cout << "Custom tool of category: " << hydroCat << " created" << endl;
			break;
		}

	case Booster::HealthBooster:
		{
			string healthCat = "HealthBooster";
			string healthName = environ_->GetName();

			Tool* toolHealth = new Tool(healthName, healthCat, pos);

			// Add the enhancement to the enhancement list
			toolHealth->AddEnhancement(healthName);
			AddItem(toolHealth);
			cout << "Custom tool of category: " << healthCat << " created" << endl;
			break;
		}

	case Booster::BackpackBooster:
		{
			string backpackCat = "BackpackBooster";
			string backpackName = environ_->GetName();

			Tool* toolBackpack = new Tool(backpackName, backpackCat, pos);

			// Add the enhancement to the enhancement list
			toolBackpack->AddEnhancement(backpackName);
			AddItem(toolBackpack);
			cout << "Custom tool of category: " << backpackCat << " created" << endl;
			break;
		}
	}

	delete environ_;
}

void Backpack::RemoveItem(Tool* item) const
{
	if (item != nullptr) {

		for (const auto itm : items_)
		{
			if (itm == item) delete item;
			cout << "Item removed" << endl;
		}
	}
	else {
		 cout << "Item is null" << endl;
	}
}

void Backpack::RemoveItem(int index)
{
	if (index < static_cast<int>(items_.size()))
	{
		items_.erase(items_.begin() + index);
	}
}

void Backpack::ShowItems() const
{
	for (const auto item : items_)
	{
		cout << item->GetName() << endl;
	}
}

string Backpack::ShowItemsToString() const
{
		string items = "";
	for (const auto item : items_)
	{
				items += item->GetName() + "\n";
	}
	return items;
}

Tool* Backpack::GetItem(int index) const
{
	if (index < static_cast<int>( items_.size() ))
	{
		return items_[index];
	}
	else
	{
		return nullptr;
	}
}

void Backpack::Clear()
{
	for (const auto item : items_)
	{
		delete item;
	}
	items_.clear();
	cout << "Backpack cleared" << endl;
}


