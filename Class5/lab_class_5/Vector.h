#pragma once
#include "New_Student.h"
#include <string>
#include <iostream>

using namespace std;

class Vector {
	Object** beg;
	int size;
	int cur;
public:
	Vector(void);
	Vector(int);
	~Vector(void);
	void Add(Object *);
	friend ostream& operator<<(ostream& out, const Vector&);
};