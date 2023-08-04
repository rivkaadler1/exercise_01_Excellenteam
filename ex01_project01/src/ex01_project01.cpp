// ex01_project01.cpp : Defines the entry point for the application.
//


#include <iostream>
#include <vector>
#include "Vector.h"
using namespace std;


int main()
{
	cout << "Hello CMake." << endl;
	Vector a1(3, 2);
	Vector a2(4, 4);
	a1.swap(a2);
	Vector a3(5,4);
	a3.resize(5, 0);
	a3.printVector();
	a3.resize(2, 0);
	a3.printVector();
	a3.resize(6, 9);
	a3.printVector();
	return 0;
}
