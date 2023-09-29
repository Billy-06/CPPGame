#include "Tool.h"
#include <vector>
#include <string>

using namespace std;
/**
 * @file Tool.cpp
 * @author Billy Ndegwah Micah
 *
 * This is the implementation of the Tool class defined in Tool.h
 */
Tool::Tool()
{
	name= "Unnamed Tool";
	category = "Default Category";
	position = new Position();
	enhancements = {  };

	cout << "<Creation Message> Default Tool Created Successfully" << endl;
};

Tool::Tool(string& newName, string& newCat, Position* newPos):
name(newName), category(newCat), position(newPos)
{
	enhancements = {  };
	cout << "<Creation Message> Tool Created Successfully" << endl;
};

Tool::~Tool()
{
	delete position;
};

bool operator==(const Tool& firstTool, const Tool& secTool)
{
	return firstTool.name == secTool.name && firstTool.category == secTool.category && firstTool.position == secTool.position && firstTool.enhancements == secTool.enhancements;
};

bool operator!=(const Tool& firstTool, const Tool& secTool)
{
	return !(firstTool == secTool);
};

string Tool::GetName() const
{
	return name;
};

void Tool::SetName(string& newName)
{
	this->name = newName;
};

std::string Tool::GetCategory() const
{
	return category;
};

void Tool::SetCategory(string& newCat)
{
	this->category = newCat;
};

Position& Tool::GetPosition() const
{
	return *position;
};

void Tool::SetPosition(Position* newPos)
{
	this->position = newPos;
};

vector<string> Tool::GetEnhancements() const
{
	return enhancements;
};

void Tool::AddEnhancement(string& enhancement)
{
	enhancements.push_back(enhancement);
};

void Tool::Upgrade()
{
	cout << "Tool Upgraded Successfully" << endl;
};

void Tool::Use()
{
	cout << name << " tool is now in hand" << endl;
};
