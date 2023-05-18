#include <iostream>
#include "Pair.h"
using namespace std;

Pair::Pair() {
		second = 0.0;
		first = 0;
		cout << "����������� ��� ���������� ��� " << this << endl;
	}

Pair::Pair(int f, double s) {
	first = f;
	second = s;
	cout << "����������� � ����������� ��� - " << this << endl;
}

Pair::Pair(Pair& T) {
	first = T.first;
	second = T.second;
	cout << "����������� ����������� ��� - " << this << endl;
}

Pair::~Pair() {
	cout << "���������� ��� - " << this << endl;
}

void Pair::get_first(int a) {
	first = a;
}

void Pair::get_second(double b) {
	second = b;
}

	//���������� �������� ������������
Pair& Pair::operator=(const Pair& t)
{
	//�������� �� ����������������
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
ostream& operator<<(ostream& out, Pair& p)
{
	return (out << p.first << " : " << p.second << endl);
}
