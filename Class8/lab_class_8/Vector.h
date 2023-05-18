#pragma once
#include "Event.h"
#include "Object.h"
class Vector
{
protected:
	Object** beg;
	int size;
	int cur;
public:
	Vector(int);
	Vector();
	~Vector();
	void Add();
	void Del();
	void Show();
	int operator()();
	void HandleEvent(const TEvent& y) {
		if (y.what == evMessage) {
			Object** p = this->beg;
			for (int i = 0; i < this->cur; i++) {
				(*p)->HandleEvent(y);
				p++;
			}
		}
	};
};

