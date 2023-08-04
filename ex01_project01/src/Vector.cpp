#include "Vector.h"
#include <iostream>

Vector::Vector(size_t mySize ,int value)
{
	_capacity = mySize;
     _size = mySize;
	_data = new int[_size];
	for (int index = 0; index < _size; index++)
		_data[index] = value;
}

Vector::Vector(const Vector& other)
{
	_capacity = other._capacity;
	_size = other.getSize();
	_data = new int[_capacity];
	for (int index = 0; index < _size; index++)
		_data[index] = (int)other._data[index];
}

Vector::Vector(Vector&& other)
{
	_capacity = other._capacity;
	_size = other.getSize();
	_data = other._data;
	other._data = nullptr;
}

Vector::~Vector()
{
	if (_data != nullptr) {
		delete[] _data;
		_data = nullptr;
	}
}

Vector& Vector::operator=(const Vector& other)
{
	_size = other.getSize();
	_capacity = other._capacity;
	if (_data)
		delete[] _data;
	if (other._data) {
		_data = new int[_capacity];
		for (int index = 0; index < _size; index++)
			_data[index] = (int)other._data[index];
	}
	else
		_data = nullptr;
	return *this;
}

Vector& Vector::operator=(Vector&& other)
{
	if (_data) {
		delete[]_data;
	}
	_capacity = other._capacity;
	_size = other.getSize();
	_data = other._data;
	other._data = nullptr;
	return *this;
}

int& Vector::operator[](size_t index)
{
	if (index >= _size)
		throw "vector overflow";
	return _data[index];
}

const int& Vector::operator[](size_t index) const
{
	if (index >= _size)
		throw "vector overflow";
	return _data[index];
}

int* Vector::getData() const
{
	return _data;
}

bool Vector::empty() const
{
	return _data == nullptr;
}

int Vector::getSize() const
{
	return _size;
}

int Vector::getCapacity() const
{
	return _capacity;
}

void Vector::clear()
{
	if (_data)
		delete[] _data;
	_size = 0;
}


void Vector::resize(size_t count, const int& value)
{
	if (count == _size)
	{
		return;
	}
	if (_data)
	{
		if (count < _size)
		{
			int* temp = new int[count];
			for (int index = 0; index < count; index++)
				temp[index] = _data[index];
			_size = count;
			delete[]_data;
			_data = temp;
		}			
		else
		{
		    int* temp = new int[count];
			for (int index = 0; index < _size; index++)
				temp[index] = _data[index];
			for (int index = _size; index < count; index++)
				temp[index] = value;
			_size = count;
			delete[]_data;
			_data = temp;
			if (_size > _capacity)
			{
				_capacity = _size;
			}
		}
	}
	else 
	{
		_data = new int[count];
		_size = count;
		_capacity = count;
		for (int index = 0; index < _size; index++)
			_data[index] = value;
		
	}
}

void Vector::swap(Vector& other)
{
	Vector tempVector = other;
	other = *this;
	*this = tempVector;
}

void Vector::push_back(const int value)
{
	if (_size == _capacity)
	{
		int* temp = _data;
		delete[]_data;
		_data = nullptr;
		if (_capacity * 2 <= 128)
			_capacity = _capacity * 2;
		else
			_capacity = _capacity * 1.5;
		_data = new int[_capacity];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = temp[i];
		}
	}	
	_data[_size] = value;
	_size++;
}

void Vector::pop_back()
{
	if (_size>0)
	{
		--_size;
	}
}

void Vector::insert(size_t index, int value)
{
	if (index == _size)
		push_back(value);
	else
	{
		if (_size == _capacity)
		{
			if (_capacity * 2 <= 128)
				_capacity = _capacity * 2;
			else
				_capacity = _capacity * 1.5;
		}

		int* temp = _data;
		delete[]_data;
		_data = nullptr;
		_data = new int[_capacity];
		_size++;
		for (size_t i = 0; i < index; i++)
		{
			_data[i] = temp[i];
		}
		_data[index] = value;
		for (int i = index + 1; i < _size; i++)
		{
			_data[i] = (int)temp[i - 1];
		}
	}
}

void Vector::erase(int index)
{
	if (index == int(_size - 1))
		pop_back();
	else if (index < int(_size - 1))
	{
		for (size_t i = index; i < _size; i++)
		{
			_data[i] = _data[i + 1];
		}
		_size--;
	}
	else
		throw "index out of range";
}

void Vector::printVector() {
	for (int i = 0; i < _size; i++)
	{
		std::cout << _data[i] << " ";
	}
	std::cout << std::endl;
}

bool operator==(const Vector& lhs, const Vector& rhs)
{
	bool flag = true;
	if (lhs.getSize() == rhs.getSize())
	{
		int* lhsData = lhs.getData();
		int* rhsData = rhs.getData();
		for (size_t i = 0; i < lhs.getSize(); i++)
		{
			if (lhsData[i] != rhsData[i])
			{
				flag = false;
				break;
			}
		}
	}
	else
		flag = false;
	return flag;
}

bool operator!=(const Vector& lhs, const Vector& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Vector& lhs, const Vector& rhs)
{
	bool flag = true;
	int length = lhs.getSize() < rhs.getSize() ? lhs.getSize() : rhs.getSize();
	int* lhsData = lhs.getData();
	int* rhsData = rhs.getData();
	for (int i = 0;  i< length; i++)
	{
		if (lhsData[i] > rhsData[i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}

bool operator>(const Vector& lhs, const Vector& rhs)
{
	return lhs != rhs && !(lhs < rhs);
}

bool operator<=(const Vector& lhs, const Vector& rhs)
{
	return lhs<rhs || lhs == rhs;
}

bool operator>=(const Vector& lhs, const Vector& rhs)
{
	return lhs>rhs || lhs==rhs;
}


