#include <iostream>
#include <fstream>
#include "Pair.h"
using namespace std;

Pair::Pair() {
	second = 0.0;
	first = 0;
}

Pair::Pair(int f, double s) {
	first = f;
	second = s;
}

Pair::Pair(Pair& T) {
	first = T.first;
	second = T.second;
}

Pair::~Pair() {
}

void Pair::get_first(int a) {
	first = a;
}

void Pair::get_second(double b) {
	second = b;
}

//перегрузка операции присваивания
Pair& Pair::operator=(const Pair& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	return *this;
}
Pair Pair::operator+(int a)
{
	first += a;
	return *this;
}
Pair Pair::operator+(double a)
{
	second += a;
	return *this;
}

Pair Pair::operator-(const Pair& P)
{
	int temp1 = first - P.first;
	double temp2 = second - P.second;
	Pair p;
	p.first = temp1;
	p.second = temp2;
	return p;
}


istream& operator>>(istream& in, Pair& p) {
	cout << "first? "; in >> p.first;
	cout << "second? "; in >> p.second;
	return in;
}
ostream& operator<<(ostream& out, const Pair& p)
{
	return (out << p.first << " : " << p.second << endl);
}
fstream& operator>>(fstream& fin, Pair& P) {
	fin >> P.first;
	fin >> P.second;
	return fin;

}
fstream& operator<<(fstream& fout, const Pair& P) {
	fout << P.first << "\n" << P.second << '\n';
	return fout;
}


