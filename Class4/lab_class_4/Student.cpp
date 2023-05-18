#include <iostream>
#include "Student.h"
//#include "Person.h"
using namespace std;

Student::Student() {
	obj = "";
	score = 0;
	cout << "����������� ��� ���������� ��� " << this << endl;
}

Student::Student(string name, double age, string ob, int sco) :Person(name, age) {
	obj = ob;
	score = sco;
	cout << "����������� � ����������� ��� - " << this << endl;
}

Student::Student(Student& T) {
	name = T.name;
	age = T.age;
	obj = T.obj;
	score = T.score;
	cout << "����������� ����������� ��� - " << this << endl;
}

Student::~Student() {
	cout << "���������� ��� - " << this << endl;
}

void Student::set_obj(string j) {
	obj = j;
}

void Student::set_score(int s) {
	score = s;
}

void Student::n_c() {
	if (score >= 3) {
		cout << "������ ������������������ ��� ����\n";
	}
	else {
		cout << "������ ��������������������\n";
	}
}

Student Student::operator=(const Student& t)
{
	//�������� �� ����������������
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
	out << "���: " << p.name << endl;
	out << "�������: " << p.age << endl;
	out << "�������: " << p.obj << endl;
	out << "������: " << p.score << endl;
	return out;
}