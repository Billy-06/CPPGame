#include "SkillNode.h"
#include <iostream>

using namespace std;

SkillNode::SkillNode(string& name, int level)
	: _name(name), _level(level)
{
	_statements = vector<string>();
	_downgrade = nullptr;
	_upgrade = nullptr;
}

SkillNode::~SkillNode() = default;

string SkillNode::GetName() const
{
	return _name;
}

void SkillNode::SetName(string& name)
{
	_name = name;
}

int SkillNode::GetLevel() const
{
	return _level;
}

void SkillNode::SetLevel(int level)
{
	_level = level;
}

vector<string> SkillNode::GetStatements() const
{
	return _statements;
}

void SkillNode::AddStatement(string& statement)
{
	_statements.push_back(statement);
}

void SkillNode::RemoveStatement(int statementIdx)
{
	_statements.erase(_statements.begin() + statementIdx);
}

void SkillNode::SetStatements(vector<string>& statements)
{
	_statements = statements;
}

SkillNode* SkillNode::GetDowngrade() const
{
	return _downgrade;
}

SkillNode* SkillNode::GetUpgrade() const
{
	return _upgrade;
}

void SkillNode::SetDowngrade(SkillNode* node)
{
	_downgrade = node;
}

void SkillNode::SetUpgrade(SkillNode* node)
{
	_upgrade = node;
}

void SkillNode::ApplySkill()
{
	// print to console
}

void SkillNode::LevelUp()
{
	_level++;
}

void SkillNode::PrintDetails() const
{
	cout << "Skill Name: " << "\t" << _name << endl;
	cout << "Skill Level: " << "\t" << _level << endl;
	cout << "Upgrade: " << "\t" << ( (_upgrade != nullptr) ? _upgrade->GetName() : "< Null >" ) << endl;
	cout << "Downgrade: " << "\t" << ( (_downgrade != nullptr) ? _downgrade->GetName() : "< Null >" ) << endl;
	
	cout << "Statements: " << endl;
	for (auto& statement : _statements)
	{
		cout << "\t" << statement << endl;
	}

	cout << endl;
}