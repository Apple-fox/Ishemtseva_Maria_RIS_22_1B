#include <iostream>
#include <string>
#include <windows.h>
#include "salary.h"
using namespace std;

void sal(salary S) {
	S.show();
}

salary make_prize() {
	string s;
	double sca;
	int pro;
	cout << "������� ���: ";
	getline(cin, s);
	cout << "������� �����: ";
	cin >> sca;
	cout << "�������, ����� ������� �� ������ - ������: ";
	cin >> pro;
	salary Sa(s, sca, pro);
	return Sa;
}

int maasin() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	salary s1;
	s1.show();

	salary s2("Ivanov Ivan Ivanovich", 10000, 50);
	s2.show();
	cout << "������ = " << s2.get_prize() << endl;


	salary s3 = s2;
	s3.Init("Petrov Petr Petrovich", 20000, 20);
	sal(s3);
	cout << "������ = " << s3.get_prize() << endl;

	s1 = make_prize();
	s1.show();
	cout << "������ = " << s1.get_prize() << endl;
	return 0;
}