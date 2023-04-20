#include <iostream>
#include "Student.h"
//#include "Person.h"
using namespace std;

Student::Student() {
	obj = "";
	score = 0;
	cout << "Конструктор без параметров для " << this << endl;
}

Student::Student(string name, double age, string ob, int sco) :Person(name, age) {
	obj = ob;
	score = sco;
	cout << "Коснтруктор с параметрами для - " << this << endl;
}

Student::Student(Student& T) {
	name = T.name;
	age = T.age;
	obj = T.obj;
	score = T.score;
	cout << "Конструктор копирования для - " << this << endl;
}

Student::~Student() {
	cout << "Деструктор для - " << this << endl;
}

void Student::set_obj(string j) {
	obj = j;
}

void Student::set_score(int s) {
	score = s;
}

void Student::n_c() {
	if (score >= 3) {
		cout << "Оценка удовлетворительная или выше\n";
	}
	else {
		cout << "Оценка неудовлетворительная\n";
	}
}

Student Student::operator=(const Student& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	name = t.name;
	age = t.age;
	obj = t.obj;
	score = t.score;
	return *this;
}

istream& operator>>(istream& in, Student& p) {
	cout << "name? "; in >> p.name;
	cout << "age? "; in >> p.age;
	cout << "obj? "; in >> p.obj;
	cout << "score? "; in >> p.score;
	return in;
}
ostream& operator<<(ostream& out,const Student& p)
{
	out << "Имя: " << p.name << endl;
	out << "Возраст: " << p.age << endl;
	out << "Предмет: " << p.obj << endl;
	out << "Оценка: " << p.score << endl;
	return out;
}