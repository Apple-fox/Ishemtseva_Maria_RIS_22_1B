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
	cout << "Введите первый элемент последовательности: ";
	cin >> first;
	cout << "Введите постоянное отношение: ";
	cin >> second;
}

void Progression::Show() {
	cout << "Первый элемент последовательности - " << first;
	cout << "\nПостоянное отношение - " << second << endl;
}
