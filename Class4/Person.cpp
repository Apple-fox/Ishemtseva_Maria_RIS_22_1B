#include <iostream>
#include "Person.h"
using namespace std;

Person::Person() {
	name = "";
	age = 0;
	cout << "����������� ��� ���������� ��� " << this << endl;
}

Person::Person(string f, double s) {
	name = f;
	age = s;
	cout << "����������� � ����������� ��� - " << this << endl;
}

Person::Person(Person& T) {
	name = T.name;
	age = T.age;
	cout << "����������� ����������� ��� - " << this << endl;
}

Person::~Person() {
	cout << "���������� ��� - " << this << endl;
}

void Person::set_name(string n) {
	name = n;
}

void Person::set_age(int a) {
	age = a;
}

Person& Person::operator=(const Person& t)
{
	//�������� �� ����������������
	if (&t == this) return *this;
	name = t.name;
	age = t.age;
	return *this;
}

istream& operator>>(istream& in, Person& p) {
	cout << "name? "; in >> p.name;
	cout << "age? "; in >> p.age;
	return in;
}
ostream& operator<<(ostream& out, Person& p)
{
	return (out << "���: " << p.name << endl << "�������: " << p.age << endl);
}