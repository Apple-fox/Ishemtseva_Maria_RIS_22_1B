#include <iostream>
#include "Progression.h"
using namespace std;

void Progression::Init(double a0, int r) {
	first = a0;
	second = r;
}
double Progression::element(int j) {
	return first * pow(second, j);
}
void Progression::Read() {
	cout << "������� ������ ������� ������������������: ";
	cin >> first;
	cout << "������� ���������� ���������: ";
	cin >> second;
}

void Progression::Show() {
	cout << "������ ������� ������������������ - " << first;
	cout << "\n���������� ��������� - " << second << endl;
}
