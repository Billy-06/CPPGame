#include "Iterator2D.h"

using namespace std;


Iterator2D::Iterator2D() : _array(nullptr), _rows(0), _cols(0) {}

Iterator2D::Iterator2D(string** array, int rows, int cols) :
	_array(array), _rows(rows), _cols(cols) {}

Iterator2D::Iterator2D(const Iterator2D& other)
{
	// copy the other iterator
	_array = other._array;
	_rows = other._rows;
	_cols = other._cols;
	_i = other._i;
	_j = other._j;
}

Iterator2D::~Iterator2D()
{
	// delete the array
	delete[] _array;
}

void Iterator2D::MoveNext()
{
	if (_i < _rows && _j < _cols)
	{
		// increment the current iterator
		++_j;
		if (_j == _cols)
		{
			// if at the end of the row, go to the next row
			_j = 0;
			++_i;

			if (_i == _rows)
			{
				// if at the end of the array, go to the beginning of the array
				_i = 0;
				_j = 0;
			}
		}
	}
}

void Iterator2D::MovePrevious()
{
	// decrement the current iterator
	if (_j > 0 || _i > 0)
	{
		--_j;
	}
	else if (_j <= 0 || _i <= 0)
	{
		// if at the beginning of the row, go to the previous row
		_j = _cols - 1;
		--_i;
		if (_i < 0)
		{
			// if at the beginning of the array, go to the end of the array
			_i = _rows - 1;
			_j = _cols - 1;
		}
	}
}

bool Iterator2D::ReachedEnd() const
{
	// return true if the current iterator is at the end of the array
	return _i == _rows - 1 && _j == _cols - 1;
}

bool Iterator2D::AtBeginning() const
{
	// return true if the current iterator is at the beginning of the array
	return _i == 0 && _j == 0;
}

void Iterator2D::MoveTo(int i, int j)
{
	// move the current iterator to the specified position
	_i = i;
	_j = j;
}

Iterator2D Iterator2D::begin()
{
	StartPoint();
	return *this;
}

Iterator2D Iterator2D::end()
{
	EndPoint();
	return *this;
}

std::string** Iterator2D::GetArray() const
{
	return _array;
}

void Iterator2D::SetArray(std::string** array)
{
	_array = array;
}

int Iterator2D::GetRows() const
{
	return _rows;
}

void Iterator2D::SetRows(int rows)
{
	_rows = rows;
}

int Iterator2D::GetCols() const
{
	return _cols;
}

void Iterator2D::SetCols(int cols)
{
	_cols = cols;
}

std::string& Iterator2D::GetCurrentItem() const
{
	return _array[_i][_j];
}

void Iterator2D::SetCurrentItem(const std::string& item) const
{
	_array[_i][_j] = item;
}

const string& Iterator2D::operator*() const
{
	return **_array;
}

Iterator2D& Iterator2D::operator++()
{
	// increment the current iterator and return it
	MoveNext();
	return *this;
}

Iterator2D Iterator2D::operator++(int)
{
	// create a copy of the current iterator
	// create a copy of the current iterator
	Iterator2D temp(*this);
	// increment the current iterator
	MoveNext();

	// return the old value
	return temp;
}

Iterator2D& Iterator2D::operator+=(int n)
{
	// increment the current iterator by n and return it
	for(int i = 0; i < n; i++)
	{
		MoveNext();
	}
	return *this;
}

Iterator2D& Iterator2D::operator--()
{
	// decrement the current iterator and return it
	MovePrevious();
	return *this;
}

Iterator2D Iterator2D::operator--(int)
{
	// create a copy of the current iterator
	Iterator2D temp(*this);
	// decrement the current iterator
	MovePrevious();
	// return the old value
	return temp;
}

Iterator2D& Iterator2D::operator-=(int n)
{
	// decrement the current iterator by n and return it
	for(int i=n; i>0; i--)
	{
		MovePrevious();
	}
	return *this;
}

bool Iterator2D::operator==(const Iterator2D& other) const
{
	// return true if the current iterator is equal to the other iterator
	return _array == other._array && _rows == other._rows && _cols == other._cols;
}

bool Iterator2D::operator!=(const Iterator2D& other) const
{
	// return true if the current iterator is not equal to the other iterator
	return _array != other._array || _rows != other._rows || _cols != other._cols;
}

void Iterator2D::StartPoint()
{
	// move the current iterator to the beginning of the array
	_i = 0;
	_j = 0;
}

void Iterator2D::EndPoint()
{
	// move the current iterator to the end of the array
	_i = _rows - 1;
	_j = _cols - 1;
}