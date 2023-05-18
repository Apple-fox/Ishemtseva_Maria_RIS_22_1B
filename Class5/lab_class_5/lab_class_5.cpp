#include "Vector.h"
#include <string>
#include <iostream>
using namespace std;
void main()
{
	setlocale(0, "RUS");
	New_Person a;
	cin >> a;
	cout << "вывод a с помощью перегруженной операции:\n";
	cout << a << endl;//вывод с помощью перегруженной операции
	Object* p = &a;
	cout << "Вывод a с помощью метода Show() и указателя\n";
	p->Show();
	New_Student b;
	cin >> b;
	cout << "Вывод b с помощью перегруженной операции:\n";
	cout << b << endl;//вывод с помощью перегруженной операции
	p = &b;
	cout << "Вывод b с помощью метода Show() и указателя\n";
	p->Show(); //вывод с помощью метода Show() и указателя
	Vector v(5);//вектор из 5 элементов
	cin >> a;
	cin >> b;
	p = &a;//ставим указатель на объект класса Car
	v.Add(p);//добавляем объект в вектор
	p = &b;//ставим указатель на объект класса Lorry
	v.Add(p); //добавляем объект в вектор
	cout << "Вывод вектора:\n";
	cout << v;//вывод вектора
}