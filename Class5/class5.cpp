#include "Vector.h"
#include <string>
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "RUS");
	New_Person a;
	cin >> a;
	cout << "����� a � ������� ������������� ��������:\n";
	cout << a << endl;//����� � ������� ������������� ��������
	Object* p = &a;
	cout << "����� a � ������� ������ Show() � ���������\n";
	p->Show();
	New_Student b;
	cin >> b;
	cout << "����� b � ������� ������������� ��������:\n";
	cout << b << endl;//����� � ������� ������������� ��������
	p = &b;
	cout << "����� b � ������� ������ Show() � ���������\n";
	p->Show(); //����� � ������� ������ Show() � ���������
	Vector v(5);//������ �� 5 ���������
	cin >> a;
	cin >> b;
	p = &a;//������ ��������� �� ������ ������ Car
	v.Add(p);//��������� ������ � ������
	p = &b;//������ ��������� �� ������ ������ Lorry
	v.Add(p); //��������� ������ � ������
	cout << "����� �������:\n";
	cout << v;//����� �������
}