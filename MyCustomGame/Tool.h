#pragma once
#include <string>
#include <vector>
#include "Position.h"

/**
 * @file Tool.h
 * @author Billy Ndegwah Micah
 *
 * Description: This is the header file for the Tool class. It contains the
 * definitions for the tool object.
 *
 * Properties:
 * -----------
 * > Name {string}: the name of the tool
 * > Category {string}: the category of the tool
 * > Position {Position}: the position of the tool. If the tool is in the backpack,
 *  the position is shared with the backpack as well as the player.
 * > Enhancement {vector<string>}: additional enhancements to the tool.
 *
 *	Methods:
 *	> Constructor: creates a tool object
 *	> Destructor: destroys a tool object
 *	> Getters and Setters
 *	> Upgrade: enables player to upgrade the tool
 *	> Use: enables player to use the tool
 *
 */
class Tool
{
protected:
	std::string name;
	std::string category;
	Position* position;
	std::vector<std::string> enhancements;

public:
	/**
	 * @brief This is the constructor for the Tool class. It creates a tool object.
	*/
	Tool();

	/**
	 * @brief This overload constructor for the Tool class takes the parameters, name, category and position.
	 * @param newName - the name of the tool.
	 * @param newCat - the category of the tool.
	 * @param newPos - pointer to the position of the tool.
	*/
	Tool(std::string& newName, std::string& newCat, Position* newPos);

	/**
	 * @brief This is the destructor for the Tool class. It destroys a tool object.
	*/
	virtual ~Tool();

	/**
	 * @brief Comparators for the Tool class. They compare two tools based on their properties.
	 * @param firstTool - the first tool to be compared.
	 * @param secTool - the second tool to be compared.
	 * @return a boolean value representing whether the two tools are equal.
	*/
	friend bool operator== (const Tool& firstTool, const Tool& secTool);

	/**
	 * @brief Negative comparator for the Tool class. It compares two tools based on their properties.
	 * @param firstTool - the first tool to be compared.
	 * @param secTool - the second tool to be compared.
	 * @return a boolean value representing whether the two tools are not equal.
	*/
	friend bool operator!= (const Tool& firstTool, const Tool& secTool);

	/**
	 * @brief Getter for the name of the tool.
	 * @return a string representing the name of the tool.
	*/
	std::string GetName() const;

	/**
	 * @brief Setter for the name of the tool.
	 * @param newName - the desired name of the tool.
	*/
	void SetName(std::string& newName);

	/**
	 * @brief Getter for the category of the tool.
	 * @return a string representing the category of the tool.
	*/
	std::string GetCategory() const;

	/**
	 * @brief Setter for the category of the tool.
	 * @param newCat - the desired category of the tool.
	*/
	void SetCategory(std::string& newCat);

	/**
	 * @brief Getter for the position of the tool.
	 * @return A reference to the position of the tool.
	*/
	Position& GetPosition() const;

	/**
	 * @brief Setter for the position of the tool.
	 * @param newPos - the desired position of the tool.
	*/
	void SetPosition(Position* newPos);

	/**
	 * @brief Getter for enhancement property
	 * @return a vector of strings representing the enhancements the tool has
	*/
	std::vector<std::string> GetEnhancements() const;

	/**
	 * @brief A functions used to add enhancements to the tool
	 * @param enhancement - string value taken to be the name of the enhancement
	*/
	void AddEnhancement(std::string& enhancement);

	/**
	 * @brief This method enables the player to upgrade the tool.
	*/
	virtual void Upgrade();

	/**
	 * @brief This method enables the player to use the tool.
	*/
	virtual void Use();
};