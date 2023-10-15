#pragma once
#include <list>
#include <string>
/**
 * @file Iterator2D.h
 * @author Billy Ndegwah Micah
 * @brief This is an iterator designed to iterate over the 2D array passed to it. It'll
 * be used in helping the player access tools an item in a like manner as an inventory.
 *
*/
class Iterator2D
{
private:
	std::string** _array;
	int _rows;
	int _cols;
	int _i=0, _j=0;

	/**
	 * @brief This function facilitate forward traversal within the 2D array.
	*/
	void MoveNext();

	/**
	 * @brief This function facilitate backward traversal within the 2D array.
	*/
	void MovePrevious();

	/**
	 * @brief This function resets the iterator to the start of the 2D array.
	 * It is used inside the begin function.
	*/
	void StartPoint();

	/**
	 * @brief This function resets the iterator to the end of the 2D array.
	 * It is used inside the end function.
	*/
	void EndPoint();

public:
	/**
	 * @brief This is the default constructor for the 2D array iterator.
	*/
	Iterator2D();

	/**
	 * @brief This is the overloaded constructor for the 2D array iterator.
	 * @param array - This is the 2D array to be iterated over.
	 * @param rows - This is the number of rows in the 2D array.
	 * @param cols - This is the number of columns in the 2D array.
	*/
	Iterator2D(std::string** array, int rows, int cols);

	/**
	 * @brief Copy constructor for the 2D array iterator.
	 * @param other - This is the 2D array iterator to be copied.
	 * @return a copy of the 2D array iterator.
	*/
	Iterator2D(const Iterator2D& other);

	/**
	 * @brief The destructor for the 2D Iterator, to free up memory.
	*/
	~Iterator2D();

	/**
	 * @brief The range-based begin iterator overload for the 2D array iterator.
	 * @return an iterator pointing to the first item in the 2D array.
	*/
	Iterator2D begin();

	/**
	 * @brief The range-based end iterator overload for the 2D array iterator.
	 * @return an iterator pointing to the last item in the 2D array.
	*/
	Iterator2D end();

	/**
	 * @brief The getter for the 2D array.
	 * @return a pointer to the 2D array's first item.
	*/
	std::string** GetArray() const;

	/**
	 * @brief The setter for the 2D array.
	 * @param array - This is the 2D array to be iterated over.
	*/
	void SetArray(std::string** array);

	/**
	 * @brief The getter for the number of rows in the 2D array.
	 * @return an integer representing the number of rows in the 2D array.
	*/
	int GetRows() const;

	/**
	 * @brief The setter for the number of rows in the 2D array.
	 * @param rows - an integer representing the number of rows in the 2D array.
	*/
	void SetRows(int rows);

	/**
	 * @brief The getter for the number of columns in the 2D array.
	 * @return an integer representing the number of columns in the 2D array.
	*/
	int GetCols() const;

	/**
	 * @brief Setter for the number of columns in the 2D array.
	 * @param cols - an integer representing the number of columns in the 2D array.
	*/
	void SetCols(int cols);

	/**
	 * @brief This method returns the current item in the 2D array.
	 * @return a string representing the current item in the 2D array.
	*/
	std::string& GetCurrentItem() const;

	/**
	 * @brief This method sets the current item in the 2D array.
	 * @param item - a string representing the current item in the 2D array.
	*/
	void SetCurrentItem(const std::string& item) const;

	/**
	 * @brief This method allows the iterator to move to a specific position in the array.
	 * @param i - the row to move to.
	 * @param j - the column to move to.
	*/
	void MoveTo(int i, int j);

	/**
	 * @brief The operator overload for the 2D array Iterator's pointer operator.
	*/
	const std::string& operator*() const;

	/**
	 * @brief The operator overload for the 2D array Iterator's post-increment operator.
	*/
	Iterator2D& operator++();

	/**
	 * @brief The operator overload for the 2D array Iterator's pre-increment operator.
	*/
	Iterator2D operator++(int);

	/**
	 * @brief The operator overload for the 2D array Iterator's addition operator.
	*/
	Iterator2D& operator+=(int n);

	/**
	 * @brief The operator overload for the 2D array Iterator's post-decrement operator.
	*/
	Iterator2D& operator--();

	/**
	 * @brief The operator overload for the 2D array Iterator's pre-decrement operator.
	*/
	Iterator2D operator--(int);

	/**
	 * @brief The operator overload for the 2D array Iterator's subtraction operator.
	*/
	Iterator2D& operator-=(int n);

	/**
	 * @brief The operator overload for the 2D array Iterator's comparator operator.
	*/
	bool operator==(const Iterator2D& other) const;

	/**
	 * @brief The operator overload for the 2D array Iterator's negation comparator operator.
	*/
	bool operator!=(const Iterator2D& other) const;

	/**
	 * @brief This method is used to check if the iterator has reached the end of the array.
	 * @return a boolean value representing whether the iterator has reached the end of the array
	*/
	bool ReachedEnd() const;

	/**
	 * @brief This method is use to check if the iterator is at the beginning of the array.
	 * @return a boolean value representing whether the iterator is at the beginning of the array
	*/
	bool AtBeginning() const;

};

