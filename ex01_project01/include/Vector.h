#pragma once

class Vector
{
private:
	int* _data = nullptr; // Pointer to the dynamically allocated array to hold the vector elements
	int _size;           // Number of elements currently stored in the vector
	int _capacity;       // Capacity of the vector (maximum number of elements it can hold)

public:
	// Default constructor and constructor with size and default value
	explicit Vector(size_t mySize = 0, int value = 0);

	// Copy constructor
	Vector(const Vector& other);

	// Move constructor
	Vector(Vector&& other);

	// Destructor
	~Vector();

	// Copy assignment operator
	Vector& operator=(const Vector& other);

	// Move assignment operator
	Vector& operator=(Vector&& other);

	// Access element at the specified index (non-const version)
	int& operator[] (size_t index);

	// Access element at the specified index (const version)
	const int& operator[] (size_t index) const;

	// Get a pointer to the internal array
	int* getData() const;

	// Check if the vector is empty
	bool empty() const;

	// Get the number of elements in the vector
	int getSize() const;

	// Get the current capacity of the vector
	int getCapacity() const;

	// Clear the vector, removing all elements and deallocating memory
	void clear();

	// Resize the vector to the specified size and fill with the given value
	void resize(size_t count, const int& value = 0);

	// Swap the contents of this vector with another vector
	void swap(Vector& other);

	// Add an element to the end of the vector
	void push_back(const int value);

	// Remove the last element from the vector
	void pop_back();

	// Compare vectors for equality
	friend bool operator==(const Vector& lhs, const Vector& rhs);

	// Compare vectors for inequality
	friend bool operator!=(const Vector& lhs, const Vector& rhs);

	// Compare vectors lexicographically (less than)
	friend bool operator<(const Vector& lhs, const Vector& rhs);

	// Compare vectors lexicographically (greater than)
	friend bool operator>(const Vector& lhs, const Vector& rhs);

	// Compare vectors lexicographically (less than or equal to)
	friend bool operator<=(const Vector& lhs, const Vector& rhs);

	// Compare vectors lexicographically (greater than or equal to)
	friend bool operator>=(const Vector& lhs, const Vector& rhs);

	// Insert an element at the specified index
	void insert(size_t index, int value);

	// Erase the element at the specified index
	void erase(int index);

	// Print the elements of the vector
	void printVector();
};
