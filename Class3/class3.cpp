#include <iostream>
#include "Pair.h"
using namespace std;
int mdfsdfain()
{
	setlocale(0, "RUS");
	Pair a;
	Pair b;
	cout << "Ввод пар чисел" << endl;
	cin >> a;
	cin >> b;
	cout << "Вывод пар чисел" << endl;
	cout << a;
	cout << b;
	Pair c;
	cout << "Вычитание одной пары из другой" << endl;
	c = a - b;
	cout << c;
	cout << "Первая пара" << endl;
	cout << a;
	a = a + 10;
	cout << "Первая пара после прибавления 10" << endl;
	cout << a;
	cout << "Первая пара после прибавления 1.5" << endl;
	a = a + 1.5;
	cout << a;
	return 0;
}
//списки, стеки, очереди, хэши и классы на гит