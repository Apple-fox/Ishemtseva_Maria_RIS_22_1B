#include <iostream>
#include <windows.h>
#include "Student.h"
using namespace std;

void f1(Person& p) {
	p.set_name("����");
}

Person f2() {
	Student s("�����", 18, "�����������", 4);
	return s;

}

int maaain() {
	setlocale(0, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person a;
	cin >> a;
	cout << "� - \n";
	cout << a;
	Person b("����", 18);
	cout << "b -\n";
	cout << b;
	a = b;
	cout << "������ � ��� b\n";
	cout << "����� �\n";
	cout << a;
	Student c;
	cin >> c;
	cout << "������ �������� �� ��������� �����:\n";
	cout << c;
	c.n_c();
	f1(c);
	cout << "������ �������� ����� ��������� �����\n" << c;
	a = f2();
	cout << a;
	return 0;
}