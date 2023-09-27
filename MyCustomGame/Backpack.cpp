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
	delete this;
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

void Backpack::AddItem(Tool& item)
{
	if (static_cast<int>(items_.size()) < size_)
	{
		items_.push_back(&item);
	}
}

void Backpack::AddItem(Environ& environ_)
{
	if (static_cast<int>(items_.size()) < size_)
	{
		items_.push_back(&environ_);
	}
}