#include <iostream>
#include <windows.h>
#include "Student.h"
using namespace std;

void f1(Person& p) {
	p.set_name("Иван");
}

Person f2() {
	Student s("Роман", 18, "Информатика", 4);
	return s;

}

int main() {
	setlocale(0, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person a;
	cin >> a;
	cout << "а - \n";
	cout << a;
	Person b("Катя", 18);
	cout << "b -\n";
	cout << b;
	a = b;
	cout << "Теперь а это b\n";
	cout << "Вывод а\n";
	cout << a;
	Student c;
	cin >> c;
	cout << "Данные студента до изменения имени:\n";
	cout << c;
	c.n_c();
	f1(c);
	cout << "Данные студента после изменения имени\n" << c;
	a = f2();
	cout << a;
	return 0;
}