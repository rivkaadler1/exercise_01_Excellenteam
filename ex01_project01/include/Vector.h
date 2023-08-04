#pragma once
class Vector 
{
private:
	int * _data = nullptr;
	int _size;
	int _capacity;
public:
	explicit Vector(size_t mySize = 0, int value = 0);
	Vector(const Vector& other);
	Vector(Vector&& other);
	~Vector();
	Vector& operator= (const Vector& other);
	Vector& operator=(Vector&& other);
	int& operator[] (size_t index);
	const int & operator[] (size_t index) const;
	int* getData() const;
	bool empty() const;
	int getSize() const;
	int getCapacity() const;
	void clear();
	void resize(size_t count, const int& value=0);
	void swap(Vector& other);
	void push_back(const int value);
	void pop_back();
	friend bool operator==(const Vector& lhs,const Vector& rhs);
	friend bool operator!=(const Vector& lhs,const Vector& rhs);
	friend bool operator<(const Vector& lhs, const Vector& rhs);
	friend bool operator>(const Vector& lhs, const Vector& rhs);
	friend bool operator<=(const Vector& lhs, const Vector& rhs);
	friend bool operator>=(const Vector& lhs, const Vector& rhs);
	void insert(size_t index, int value);
	void erase(int index);
	void printVector();
};
