#include "Vector.h"
#include "Magazin.h"
#include <iostream>
using namespace std;

Vector::Vector(int s) {
	beg = new Object * [s];
	cur = 0;
	size = s;
}

Vector::Vector() {
	beg = nullptr;
	cur = 0;
	size = 0;
}

Vector::~Vector() {
	if (beg != 0) delete[] beg;
	beg = 0;
}

void Vector::Add() {
	Object* p;
	int y;
	cout << "1 - Print, 2 - Magazin\n";
	cin >> y;
	if (y == 1) {
		Print* a = new Print();
		a->Input();
		p = a;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else if (y == 2) {
		Magazin* b = new Magazin();
		b->Input();
		p = b;
		if (cur < size) {
			beg[cur] = p;
			cur++;
		}
	}
	else return;
}

void Vector::Show() {
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++) {
		(*p)->Show();
		p++;
	}
}

int Vector::operator()() {
	return cur;
}
void Vector::Del() {
	if (cur == 0) return;
	cur--;
}

