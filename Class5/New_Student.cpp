#include <iostream>
#include "New_Student.h"
//#include "Person.h"
using namespace std;

New_Student::New_Student() {
	obj = "";
	score = 0;
	cout << "����������� ��� ���������� ��� " << this << endl;
}

New_Student::New_Student(string name, double age, string ob, int sco) :New_Person(name, age) {
	obj = ob;
	score = sco;
	cout << "����������� � ����������� ��� - " << this << endl;
}

New_Student::New_Student(New_Student& T) {
	name = T.name;
	age = T.age;
	obj = T.obj;
	score = T.score;
	cout << "����������� ����������� ��� - " << this << endl;
}

New_Student::~New_Student() {
	cout << "���������� ��� - " << this << endl;
}

void New_Student::Show() {
	cout << "���: " << name;
	cout << "\n�������: " << age;
	cout << "\n�������: " << obj;
	cout << "\n������: " << score << endl;
}
void New_Student::set_obj(string j) {
	obj = j;
}

void New_Student::set_score(int s) {
	score = s;
}

void New_Student::n_c() {
	if (score >= 3) {
		cout << "������ ������������������ ��� ����\n";
	}
	else {
		cout << "������ ��������������������\n";
	}
}

New_Student New_Student::operator=(const New_Student& t)
{
	//�������� �� ����������������
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
	out << "���: " << p.name << endl;
	out << "�������: " << p.age << endl;
	out << "�������: " << p.obj << endl;
	out << "������: " << p.score << endl;
	return out;
}