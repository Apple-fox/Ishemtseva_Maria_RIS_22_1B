#include <iostream>
#include "salary.h"
using namespace std;

salary::salary() {
		fio = "";
		second = 0;
		first = 0;
		cout << "����������� ��� ���������� ��� " << this << endl;
}

salary::salary(string f, double s, int p) {
		fio = f;
		second = s;
		first = p;
		cout << "����������� � ����������� ��� - " << this << endl;
}

salary::salary(salary& T) {
		fio = T.fio;
		second = T.second;
		first = T.first;
		cout << "����������� ����������� ��� - " << this << endl;
}

salary::~salary() {
		cout << "���������� ��� - " << this << endl;
}

void salary::Init(string foi, double sale, int poc) {
		fio = foi;
		second = sale;
		first = poc;
}

void salary::show() {
	cout << "��� - " << fio;
	cout << "\n����� - " << second;
	cout << "\n������� - " << first;
	cout << endl;
}

double salary::get_prize() {
		return first * 0.01 * second;
}