#pragma once
#include "SkillNode.h"

/**
 * @file SkillAdvancement.h
 * @author Billy Ndegwah Micah
 *
 * Description:
 * This is a double linked list that shows which a player has available to them
 *
 * Properties:
 * -----------
 * > _headSkill: SkillNode* - pointer to the head of the list
 * > _tailSkill: SkillNode* - pointer to the tail of the list
 *
 * Methods:
 * --------
 * > SkillAdvancement() - constructor
 * > Getters and setters for the properties
 * > AppendSkill(SkillNode* skill) - adds a skill to the tail of the list
 * > RemoveSkill(SkillNode* skill) - removes a skill from the list
 * > PrependSkill(SkillNode* skill) - adds a skill to the head of the list
 * > FindSkill(std::string& skillName) - finds a skill in the list
 *
 */
class SkillAdvancement
{
private:
	SkillNode* _headSkill;
	SkillNode* _tailSkill;

public:
	/**
	 * @brief This is the default constructor for the SkillAdvancement class
	*/
	SkillAdvancement();

	/**
	 * @brief The overloaded constructor for the SkillAdvancement class
	 * @param headSkill - the initial skill node to be set as the head of the list
	*/
	SkillAdvancement(SkillNode* headSkill);

	/**
	 * @brief The default destructor for the SkillAdvancement class
	*/
	~SkillAdvancement();

	/**
	 * @brief Getter for the first skill in the list
	 * @return a pointer to the skill node at the head of the list
	*/
	SkillNode* GetHeadSkill() const;

	/**
	 * @brief Setter for the first skill in the list
	 * @param headSkill - the desired skill node to be set as the head of the list
	*/
	void SetHeadSkill(SkillNode* headSkill);

	/**
	 * @brief Getter for the last skill in the list
	 * @return a pointer to the last skill node in the list
	*/
	SkillNode* GetTailSkill() const;

	/**
	 * @brief Setter for the last skill in the list
	 * @param tailSkill - the desired skill node to be set as the tail of the list
	*/
	void SetTailSkill(SkillNode* tailSkill);

	/**
	 * @brief This methods allows adding a skill to the tail of the list
	 * @param skill - the skill to be added as the tail of the list
	*/
	void AppendSkill(SkillNode* skill);

	/**
	 * @brief This method allows removing a skill from the list
	 * @param skill - the skill to be removed from the list
	*/
	void RemoveSkill(SkillNode* skill);

	/**
	 * @brief This method prints the details of the skills in the list
	*/
	void PrintSkillAdvancements() const;

	/**
	 * @brief This method allows adding a skill to the head of the list
	 * @param skill - the skill to be added as the head of the list
	*/
	void PrependSkill(SkillNode* skill);

	/**
	 * @brief This method allows finding a skill in the list
	 * @param skillName - the name of the skill to be found
	 * @return a pointer to the skill node with the specified name
	*/
	SkillNode* FindSkill(std::string& skillName) const;
};



