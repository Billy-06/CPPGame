#pragma once
#include <string>
#include <vector>

/**
 * @file SkillNode.h
 * @author Billy Ndegwah Micah
 *
 * SkillNode class.
 * This class represents a single node of a skill that lies in a double-link list. The 
 * Player's skills advance as they progress through the game levels.
 *
 * Properties
 * ----------
 * > _name : string - name of the skill
 * > _level : int - level of the skill
 * > _statements : vector<string> - statements that apply the skill to the target player
 * > _downgrade :SkillNode* - pointer to the previous skill node
 * > _upgrade : SkillNode* - pointer to the next skill node
 *
 * Methods
 * -------
 * > SkillNode(string name, int level) - constructor
 * > Getters and setters for the properties
 * > void ApplySkill() - applies the skill to the target player
 * > void LevelUp() - increases the skill level by 1
 */
class SkillNode
{
private:
	std::string _name;
	std::vector<std::string> _statements;
	int _level;
	SkillNode* _downgrade;
	SkillNode* _upgrade;

public:
	/**
	 * @brief This is the default constructor for the SkillNode class.
	 * @param name - the name of the skill
	 * @param level - the level of the skill
	*/
	SkillNode(std::string& name, int level);

	/**
	 * @brief This is the default destructor for the SkillNode class.
	*/
	~SkillNode();

	/**
	 * @brief Getter for the name property of the SkillNode class.
	 * @return a string value representing the name of the skill
	*/
	std::string GetName() const;

	/**
	 * @brief Setter for the name property of the SkillNode class.
	 * @param name - the desired name of the skill
	*/
	void SetName(std::string& name);

	/**
	 * @brief Setter for the level property of the SkillNode class.
	 * @return an integer value representing the level of the skill
	*/
	int GetLevel() const;

	/**
	 * @brief Getter for the persuasion statements property of the SkillNode class.
	 * @return a vector of strings representing the statements that apply the skill
	*/
	std::vector<std::string> GetStatements() const;

	/**
	 * @brief Setter for the persuasion statements property of the SkillNode class.
	 * @param statements - the desired statements that apply the skill
	*/
	void SetStatements(std::vector<std::string>& statements);

	/**
	 * @brief Adds a statement to the persuasion statements property of the SkillNode class.
	 * @param statement - the desired statement that applies the skill
	*/
	void AddStatement(std::string& statement);

	/**
	 * @brief Removes a statement from the persuasion statements property of the SkillNode class.
	 * @param statementIdx - the index of the statement to be removed
	*/
	void RemoveStatement(int statementIdx);

	/**
	 * @brief Setter for the level property of the SkillNode class.
	 * @param level - the desired level of the skill
	*/
	void SetLevel(int level);

	/**
	 * @brief Getter for the downgrade property of the SkillNode class.
	 * @return a pointer to the previous skill node
	*/
	SkillNode* GetDowngrade() const;

	/**
	 * @brief Getter for the upgrade property of the SkillNode class.
	 * @return a pointer to the next skill node
	*/
	SkillNode* GetUpgrade() const;

	/**
	 * @brief Setter for the downgrade property of the SkillNode class.
	 * @param node - the intended previous skill node
	*/
	void SetDowngrade(SkillNode* node);

	/**
	 * @brief Setter for the upgrade property of the SkillNode class.
	 * @param node - the intended next skill node
	*/
	void SetUpgrade(SkillNode* node);

	/**
	 * @brief This method prints to the console the statements that apply the respective
	 * persuasion skill to the target player.
	*/
	void ApplySkill();

	/**
	 * @brief This method increases the persuasion power by 1.
	*/
	void LevelUp();

	/**
	 * @brief This method is used in printing the details of the skill to the console.
	*/
	void PrintDetails() const;
};