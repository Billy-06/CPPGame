#pragma once
#include <list>
#include <string>
/**
 * @file Iterator1D.h
 * @author Billy Ndegwah Micah
 *
 * @brief The Iterator1D is used in iterating through the 1D array passed to it.
 * It'll be used by the Character entity to access certain accessories in the array.
 *
*/
class Iterator1D
{
	private:
		std::string* _array;
		int _size;
		int _index;

	/**
	 * @brief This function facilitate forward traversal within the 1D array.
	*/
	void MoveNext();

	/**
	 * @brief This function facilitate backward traversal within the 1D array.
	*/
	void MovePrevious();


	public:
	/**
	 * @brief This is the default constructor for the Iterator1D class.
	*/
	Iterator1D();

	/**
	 * @brief This is the overloaded constructor for the Iterator1D class.
	 * @param array - the array to be iterated over
	 * @param size - the size of the array
	*/
	Iterator1D(std::string* array, int size);

	/**
	 * @brief The copy constructor for the Iterator1D class.
	 * @param iterator - the iterator to be copied
	*/
	Iterator1D(const Iterator1D& iterator);

	/**
	 * @brief The destructor for the Iterator1D class.
	*/
	~Iterator1D();

	/**
	 * @brief The Getter for the Iterator1D array field
	 * @return a pointer to the array
	*/
	std::string* GetArray() const;

	/**
	 * @brief The Getter for the Iterator1D size field
	 * @return an integer representing the size of the array
	*/
	int GetSize() const;

	/**
	 * @brief The Getter for the Iterator1D index field
	 * @return an integer representing the index of the current element in the array
	*/
	int GetIndex() const;

	/**
	 * @brief Setter for the Iterator1D array field
	 * @param array - the array to be iterated over
	*/
	void SetArray(std::string* array);

	/**
	 * @brief Setter for the Iterator1D size field
	 * @param size - The size of the array
	*/
	void SetSize(int size);

	/**
	 * @brief Setter for the Iterator1D index field
	 * @param index - the index of the current element in the array
	*/
	void SetIndex(int index);

	/**
	 * @brief This method is used to get the current item in the array
	 * @return a string representing the current item in the array
	*/
	std::string& GetCurrentItem() const;

	/**
	 * @brief The range-based for loop begin method for the Iterator1D class
	 * @return an iterator to the first element in the array
	*/
	Iterator1D begin();

	/**
	 * @brief The range-based for loop end method for the Iterator1D class
	 * @return an iterator to the last element in the array
	*/
	Iterator1D end();

	std::string& operator[](int index) const;

	/**
	 * @brief Pointer operator for the Iterator1D class
	 * @return the reference to the current element in the array
	*/
	const std::string& operator*() const;

	/**
	 * @brief The prefix increment operator for the Iterator1D class
	 * @return reference to the current element in the array which has been incremented
	*/
	Iterator1D& operator++();

	/**
	 * @brief The postfix increment operator for the Iterator1D class
	 * @return previous element in the array
	*/
	Iterator1D operator++(int);

	/**
	 * @brief The prefix decrement operator for the Iterator1D class
	 * @return reference to the current element in the array which has been decremented
	*/
	Iterator1D& operator--();

	/**
	 * @brief The prefix decrement operator for the Iterator1D class
	 * @param the iterator to be decremented
	 * @return previous element in the array
	*/
	Iterator1D operator--(int);

	/**
	 * @brief Comparator operator for the Iterator1D class
	 * @param rightHandSide - the item to compare the iterator to
	 * @return a boolean value representing whether the iterator is equal to the item
	*/
	bool operator==(const Iterator1D& rightHandSide) const;

	/**
	 * @brief Negated comparator operator for the Iterator1D class
	 * @param rightHandSide - the item to compare the iterator to
	 * @return a boolean value representing whether the iterator is not equal to the item
	*/
	bool operator!=(const Iterator1D& rightHandSide) const;

	/**
	 * @brief Assignment operator for the Iterator1D class
	 * @param rightHandSide - the iterator to be assigned to the current iterator
	 * @return reference to the current iterator
	*/
	Iterator1D& operator=(const Iterator1D& rightHandSide);

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