#include <iostream>
#include "New_Person.h"
using namespace std;

New_Person::New_Person() {
	name = "";
	age = 0;
	cout << "Конструктор без параметров для " << this << endl;
}

New_Person::New_Person(string f, double s) {
	name = f;
	age = s;
	cout << "Коснтруктор с параметрами для - " << this << endl;
}

New_Person::New_Person(New_Person& T) {
	name = T.name;
	age = T.age;
	cout << "Конструктор копирования для - " << this << endl;
}

New_Person::~New_Person() {
	cout << "Деструктор для - " << this << endl;
}

void New_Person::Show() {
	cout << "Имя: " << name;
	cout << "\nВозраст: " << age << endl;
}

void New_Person::set_name(string n) {
	name = n;
}

void New_Person::set_age(int a) {
	age = a;
}

New_Person& New_Person::operator=(const New_Person& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	name = t.name;
	age = t.age;
	return *this;
}

istream& operator>>(istream& in, New_Person& p) {
	cout << "name? "; in >> p.name;
	cout << "age? "; in >> p.age;
	return in;
}
ostream& operator<<(ostream& out, New_Person& p)
{
	return (out << "Имя: " << p.name << endl << "Возраст: " << p.age << endl);
}