#include <iostream>
#include "Person.h"
using namespace std;

Person::Person() {
	name = "";
	age = 0;
	cout << "Конструктор без параметров для " << this << endl;
}

Person::Person(string f, double s) {
	name = f;
	age = s;
	cout << "Коснтруктор с параметрами для - " << this << endl;
}

Person::Person(Person& T) {
	name = T.name;
	age = T.age;
	cout << "Конструктор копирования для - " << this << endl;
}

Person::~Person() {
	cout << "Деструктор для - " << this << endl;
}

void Person::set_name(string n) {
	name = n;
}

void Person::set_age(int a) {
	age = a;
}

Person& Person::operator=(const Person& t)
{
	//проверка на самоприсваивание
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
	return (out << "Имя: " << p.name << endl << "Возраст: " << p.age << endl);
}