#include <iostream>
#include "Spisok.h"
#include "Pair.h"
using namespace std;

int main() {
	setlocale(0, "RUS");
	srand(time(NULL));
	Pair par(1, 1.2);
	cout << par;
	List<Pair> a(1, par);
	cout << a << endl;
	cout << a.front() << endl;
	cout << a[0] << endl;
	a[0] = 10;
	cout << a[0] << endl;
	cout << a << endl;
	List<Pair> b(a);
	cout << "Списки скопированы\n";
	cout << b << endl;
	Pair num;
	cout << "Введите элемент, который хотите добавить в конец: "; cin >> num;
	b.pushback(num);
	cout << b << endl;
	cout << "Из списка удален первый элемент\n";
	b.popfront();
	return 0;
}