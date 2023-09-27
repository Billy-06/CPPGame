#pragma once
#include <string>
#include "Position.h"

using namespace std;
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
	string name;
	string category;
	Position* position;

public:
	/**
	 * @brief This is the constructor for the Tool class. It creates a tool object.
	*/
	Tool();

	/**
	 * @brief This overload constructor for the Tool class takes the parameters, name, category and position.
	 * @param name - the name of the tool.
	 * @param category - the category of the tool.
	 * @param position - pointer to the position of the tool.
	*/
	Tool(string name, string category, Position* position);

	/**
	 * @brief This is the destructor for the Tool class. It destroys a tool object.
	*/
	virtual ~Tool();

	/**
	 * @brief Getter for the name of the tool.
	 * @return a string representing the name of the tool.
	*/
	string GetName() const;

	/**
	 * @brief Setter for the name of the tool.
	 * @param name - the desired name of the tool.
	*/
	void SetName(string name);

	/**
	 * @brief Getter for the category of the tool.
	 * @return a string representing the category of the tool.
	*/
	string GetCategory() const;

	/**
	 * @brief Setter for the category of the tool.
	 * @param category - the desired category of the tool.
	*/
	void SetCategory(string category);

	/**
	 * @brief Getter for the position of the tool.
	 * @return A reference to the position of the tool.
	*/
	Position& GetPosition() const;

	/**
	 * @brief Setter for the position of the tool.
	 * @param position - the desired position of the tool.
	*/
	void SetPosition(Position* position);

	/**
	 * @brief This method enables the player to upgrade the tool.
	*/
	virtual void Upgrade();

	/**
	 * @brief This method enables the player to use the tool.
	*/
	virtual void Use();
};