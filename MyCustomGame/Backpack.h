#pragma once
#include <vector>

#include "Environ.h"
#include "Tool.h"


/**
 * @file Backpack.h
 * @author Billy Ndegwah Micah
 *
 * Backpack.h (Definition of the backpack to be used by the player)
 * Definition: A backpack is a container that can hold items
 *
 * Propterties:
 * ------------
 * > size_ {int}: The size of the backpack
 * > items_ {vector<Tool*>}: A vector of pointers to items or tools
 *
 * Methods:
 * --------
 * > Backpack(int size): Constructor
 * > ~Backpack(): Destructor
 * > int getSize(): Returns the size of the backpack
 * > void setSize(int size): Sets the size of the backpack
 * > vector<Tool*> getItems(): Returns the items in the backpack
 * > void setItems(vector<Tool*> items): Sets the items in the backpack
 * > void addItem(Tool* item): Adds an item to the backpack
 * > void addItem(Environ* item): Adds an environ to the backpack
 * > void removeItem(Tool* item): Removes an item from the backpack
 * > Tool* getItem(int index): Gets an item from the backpack
 * > void removeItem(int index): Removes an item from the backpack
 * > void ShowItems(): Displays the items in the backpack
 * > void clear(): Clears the backpack
 *
 */
class Backpack
{
protected:
	int size_;
	std::vector<Tool*> items_;

public:
	/**
	 * @brief This is the default constructor for the Backpack class
	*/
	Backpack();

	/**
	 * @brief This is the overloaded constructor for the Backpack class
	 * @param size - the intended size of the backpack
	*/
	Backpack(int size);

	/**
	 * @brief This is the destructor for the Backpack class
	*/
	~Backpack();

	/**
	 * @brief Getter for the size of the backpack
	 * @return an Integer representing the size of the backpack
	*/
	int GetSize() const;

	/**
	 * @brief Setter for the size of the backpack
	 * @param size - the intended size of the backpack
	*/
	void SetSize(int size);

	/**
	 * @brief Getter for the items in the backpack
	 * @return A vector of pointers to items in the backpack
	*/
	std::vector<Tool*> GetItems() const;

	/**
	 * @brief Setter for the items in the backpack
	 * @param items - the intended items in the backpack
	*/
	void SetItems(std::vector<Tool*>& items);

	/**
	 * @brief This function is used to add an item to the backpack
	 * @param item - A pointer to the item to be added
	*/
	void AddItem(Tool* item);

	/**
	 * @brief This function is used to add an environ to the backpack
	 * @param environ_ - the pointer to the environ to be added 
	*/
	void AddItem(Environ* environ_);

	/**
	 * @brief This function is used to remove an item from the backpack
	 * @param item - the item to be removed from the backpack
	*/
	void RemoveItem(Tool* item) const;

	/**
	 * @brief This function takes the index of the item and is used to remove an item from the backpack
	 * @param index - the index of the item to be removed from the backpack
	*/
	void RemoveItem(int index);

	/**
	 * @brief This function is used to display the items in the backpack
	*/
	void ShowItems() const;

	/**
	 * @brief This function takes an index value and is used to get an item from the backpack
	 * @param index - the index of the item to be retrieved from the backpack
	 * @return A pointer to the item to be retrieved from the backpack
	*/
	Tool* GetItem(int index) const;

	/**
	 * @brief This function is used to clear the backpack
	*/
	void Clear();

};