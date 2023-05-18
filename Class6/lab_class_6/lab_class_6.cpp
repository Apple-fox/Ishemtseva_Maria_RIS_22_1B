#include <iostream>
#include "Spisok.h"
using namespace std;

int main() {
	setlocale(0, "RUS");
	srand(time(NULL));
	List a(10);
	List c(10);
	cout << a << endl;
	cout << c << endl;
	cout << "Вывод произведения списка на список\n";
	List ac = a * c;
	cout << ac << endl;
	cout << a << endl;
	cout << "Первый элемент: " << a.front() << endl;
	cout << a[1] << endl;
	a[1] = 10;
	cout << a[1] << endl;
	for (int i = 0; i < a(); i++) a[i] = 40 + rand() % 60;
	cout << a << endl;
	List b(a);
	cout << "Списки скопированы\n";
	cout << b << endl;
	int num;
	cout << "Введите элемент, который хотите добавить в конец: "; cin >> num;
	b.pushback(num);
	cout << b << endl;
	cout << "Из списка удален первый элемент\n";
	b.popfront();
	cout << "Вывод списка с помощью итератора\n";
	for (Iterator iter = b.first(); iter != b.last(); ++iter)
		cout << *iter << " ";
	return 0;
}