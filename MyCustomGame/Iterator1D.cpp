#include "Iterator1D.h"

using namespace std;

Iterator1D::Iterator1D()
{
	_array = nullptr;
	_size = 0;
	_index = 0;
}

Iterator1D::Iterator1D(string* array, int size)
{
	_array = array;
	_size = size;
	_index = 0;
}

Iterator1D::Iterator1D(const Iterator1D& iterator)
{
	_array = iterator._array;
	_size = iterator._size;
	_index = iterator._index;
}

Iterator1D::~Iterator1D() = default;

void Iterator1D::MoveNext()
{
	// increment the index and return the object at the new position
	++_index;
	if (_index >= _size)
	{
		// Reached the end of the array, so reset the index to the beginning
		_index = 0;
	}
}

void Iterator1D::MovePrevious()
{
	// decrement the index and return the object at the new position
	--_index;
	if (_index < 0)
	{
		// Reached the beginning of the array, so reset the index to the end
		_index = _size - 1;
	}
}

std::string* Iterator1D::GetArray() const
{
	return _array;
}

int Iterator1D::GetSize() const
{
	return _size;
}

int Iterator1D::GetIndex() const
{
	return _index;
}

void Iterator1D::SetArray(string* array)
{
	_array = array;
}

void Iterator1D::SetSize(int size)
{
	_size = size;
}

void Iterator1D::SetIndex(int index)
{
	_index = index;
}

std::string& Iterator1D::GetCurrentItem() const
{
	return _array[_index];
}

Iterator1D Iterator1D::begin()
{
	_index = 0;
	return *this;
}

Iterator1D Iterator1D::end()
{
	_index = _size;
	return *this;
}

std::string& Iterator1D::operator[](int index) const
{
	return _array[index];
}


const string& Iterator1D::operator*() const
{
	return _array[_index];
}

Iterator1D& Iterator1D::operator++()
{
	// increment the index and return the object at the new position
	MoveNext();
	return *this;
}

Iterator1D Iterator1D::operator++(int)
{
	Iterator1D temp(*this); // copy the current object
	MoveNext(); // increment the index
	return temp;
}

Iterator1D& Iterator1D::operator--()
{
	// decrement the index and return the object at the new position
	MovePrevious();
	return *this;
}

Iterator1D Iterator1D::operator--(int)
{
	Iterator1D temp(*this);
	MovePrevious();
	return temp;
}

bool Iterator1D::operator==(const Iterator1D& rightHandSide) const
{
	return _array == rightHandSide._array && _size == rightHandSide._size && _index == rightHandSide._index;
}

bool Iterator1D::operator!=(const Iterator1D& rightHandSide) const
{
	return !(*this == rightHandSide);
}

Iterator1D& Iterator1D::operator=(const Iterator1D& rightHandSide)
{
	if (this != &rightHandSide)
	{
		_array = rightHandSide._array;
		_size = rightHandSide._size;
		_index = rightHandSide._index;
	}
	return *this;
}

bool Iterator1D::ReachedEnd() const
{
	return _index >= _size - 1;
}

bool Iterator1D::AtBeginning() const
{
	return _index <= 0;
}