#include <iostream>
#include "Pair.h"
using namespace std;
int mdfsdfain()
{
	setlocale(0, "RUS");
	Pair a;
	Pair b;
	cout << "���� ��� �����" << endl;
	cin >> a;
	cin >> b;
	cout << "����� ��� �����" << endl;
	cout << a;
	cout << b;
	Pair c;
	cout << "��������� ����� ���� �� ������" << endl;
	c = a - b;
	cout << c;
	cout << "������ ����" << endl;
	cout << a;
	a = a + 10;
	cout << "������ ���� ����� ����������� 10" << endl;
	cout << a;
	cout << "������ ���� ����� ����������� 1.5" << endl;
	a = a + 1.5;
	cout << a;
	return 0;
}
//������, �����, �������, ���� � ������ �� ���