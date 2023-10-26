#include "SkillAdvancement.h"


using namespace std;

SkillAdvancement::SkillAdvancement()
{
	_headSkill = nullptr;
	_tailSkill = _headSkill;
}

SkillAdvancement::SkillAdvancement(SkillNode* headSkill)
{
	_headSkill = headSkill;
	_tailSkill = _headSkill;
}

SkillAdvancement::~SkillAdvancement()
{
	delete _headSkill;
	delete _tailSkill;
}

SkillNode* SkillAdvancement::GetHeadSkill() const
{
	return _headSkill;
}

void SkillAdvancement::SetHeadSkill(SkillNode* headSkill)
{
	_headSkill = headSkill;
}

SkillNode* SkillAdvancement::GetTailSkill() const
{
	return _tailSkill;
}

void SkillAdvancement::SetTailSkill(SkillNode* tailSkill)
{
	_tailSkill = tailSkill;
}

void SkillAdvancement::AppendSkill(SkillNode* skill)
{
	if (_headSkill == nullptr)
	{
		_headSkill = skill;
		_tailSkill = _headSkill;
	}
	else
	{
		// link the head node to the new node and the new node to the head node
		SkillNode* temp = _headSkill;
		while (temp->GetUpgrade() != nullptr)
		{
			temp = temp->GetUpgrade();
		}
		temp->SetUpgrade(skill);
		_tailSkill = skill;
		_tailSkill->SetDowngrade(temp);
	}
}

void SkillAdvancement::RemoveSkill(SkillNode* skill)
{
	if (_headSkill == skill)
	{
		if (_headSkill->GetUpgrade() == nullptr)
		{
			_headSkill = nullptr;
			_tailSkill = _headSkill;
		}
		else
		{
			_headSkill = _headSkill->GetUpgrade();
			_headSkill->SetDowngrade(nullptr);
		}
	}
	else
	{
		SkillNode* temp = _headSkill;
		while (temp->GetUpgrade() != skill)
		{
			temp = temp->GetUpgrade();
		}
		temp->SetUpgrade(skill->GetUpgrade());
		if (skill->GetUpgrade() != nullptr)
		{
			skill->GetUpgrade()->SetDowngrade(temp);
		}
		delete skill;
	}
}

void SkillAdvancement::PrependSkill(SkillNode* skill)
{
	if (_headSkill == nullptr)
	{
		_headSkill = skill;
	}
	else
	{
		_headSkill->SetDowngrade(skill);
		skill->SetUpgrade(_headSkill);
		_headSkill = skill;
	}
}

void SkillAdvancement::PrintSkillAdvancements() const
{
	SkillNode* temp = _headSkill;
	while (temp != nullptr)
	{
		temp->PrintDetails();

		temp = temp->GetUpgrade();
	}
}

SkillNode* SkillAdvancement::FindSkill(string& skillName) const
{
	SkillNode* temp = _headSkill;
	while (temp != nullptr)
	{
		if (temp->GetName() == skillName)
		{
			return temp;
		}
		temp = temp->GetUpgrade();
	}
	return nullptr;
}