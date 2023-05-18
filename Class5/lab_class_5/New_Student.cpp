#include <iostream>
#include "New_Student.h"
//#include "Person.h"
using namespace std;

New_Student::New_Student() {
	obj = "";
	score = 0;
	cout << "Конструктор без параметров для " << this << endl;
}

New_Student::New_Student(string name, double age, string ob, int sco) :New_Person(name, age) {
	obj = ob;
	score = sco;
	cout << "Коснтруктор с параметрами для - " << this << endl;
}

New_Student::New_Student(New_Student& T) {
	name = T.name;
	age = T.age;
	obj = T.obj;
	score = T.score;
	cout << "Конструктор копирования для - " << this << endl;
}

New_Student::~New_Student() {
	cout << "Деструктор для - " << this << endl;
}

void New_Student::Show() {
	cout << "Имя: " << name;
	cout << "\nВозраст: " << age;
	cout << "\nПредмет: " << obj;
	cout << "\nОценка: " << score << endl;
}
void New_Student::set_obj(string j) {
	obj = j;
}

void New_Student::set_score(int s) {
	score = s;
}

void New_Student::n_c() {
	if (score >= 3) {
		cout << "Оценка удовлетворительная или выше\n";
	}
	else {
		cout << "Оценка неудовлетворительная\n";
	}
}

New_Student New_Student::operator=(const New_Student& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	name = t.name;
	age = t.age;
	obj = t.obj;
	score = t.score;
	return *this;
}

istream& operator>>(istream& in, New_Student& p) {
	cout << "name? "; in >> p.name;
	cout << "age? "; in >> p.age;
	cout << "obj? "; in >> p.obj;
	cout << "score? "; in >> p.score;
	return in;
}
ostream& operator<<(ostream& out, New_Student& p)
{
	out << "Имя: " << p.name << endl;
	out << "Возраст: " << p.age << endl;
	out << "Предмет: " << p.obj << endl;
	out << "Оценка: " << p.score << endl;
	return out;
}