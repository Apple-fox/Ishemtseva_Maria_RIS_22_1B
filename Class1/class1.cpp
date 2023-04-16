#include <iostream>
#include <Windows.h>
#include "Progression.h"
using namespace std;

int mgfgfgfain() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Progression A;
	A.Init(0.1, 3);
	A.Show();
	cout << A.first  << "*" << A.second << "^2 =" << A.element(2) << endl;
	Progression B;
	B.Read();
	B.Show();
	int j;
	cout << "¬ведите номер элемента последовательсности: ";
	cin >> j;
	cout << B.first << "*" << B.second << "^" << j << "=" << B.element(j) << endl;
	return 0;
}