#include <iostream>
#include <fstream>
//#include "Pair.h"
#include "file_work.h"
int main(){
	setlocale(0, "RUS");
	Pair p, p1, p2;
	int k, c, L1, a; int nom, count;
	double L2;
	char file_name[30];
	do {
		cout << "\n1. Создать файл";
		cout << "\n2. Вывести файл";
		cout << "\n3. Удалить из файла";
		cout << "\n4. Добавить в файл";
		cout << "\n5. Добавить k элементов после заданного элемента";
		cout << "\n6. Удалить все записи меньше заданного элемента";
		cout << "\n7. Увеличить все записи с заданным значением на число L";
		cout << "\n8. Выход\n";
		cin >> c;
		switch (c) {
		case 1: cout << "Название файла: "; cin >> file_name;
			k = make_file(file_name);
			if (k < 0) cout << "Не удалось создать файл\n";
			break;
		case 2: cout << "Название файла: "; cin >> file_name;
			k = print_file(file_name);
			if (k == 0) cout << "Файл пуст\n";
			if (k < 0) cout << "Не удалось прочитать файл\n";
			break;
		case 3: cout << "Название файла: "; cin >> file_name;
			cout << "Номер элемента: "; cin >> nom;
			k = del_file(file_name, nom);
			if (k < 0) cout << "Не удалось прочитать файл";
			break;
		case 4: cout << "Название файла: "; cin >> file_name;
			cout << "Номер элемента: "; cin >> nom;
			cout << "Новая пара: ";
			cin >> p1;
			k = add_file(file_name, nom, p1);
			if (k < 0) cout << "Не удалось прочитать файл";
			if (k == 0) k = add_end(file_name, p1);
			break;
		case 5: cout << "Название файла: "; cin >> file_name;
			cout << "Номер элемента, после которого нужно добавить элементы: "; cin >> nom;
			cout << "Введите количество элементов: "; cin >> count;
			k = add_k(file_name, nom, count);
			if (k == -2) cout << "Не удалось прочитать файл";
			break;
		case 6: cout << "Название файла: "; cin >> file_name;
			cout << "Введите элемент:\n"; cin >> p2;
			k = del_less(file_name, p2);
			if (k < 0) cout << "Не удалось прочитать файл";
			break;
		case 7: cout << "Название файла: "; cin >> file_name;
			cout << "Введите элемент: "; cin >> p2;
			cout << "1 - целое, 2 - вещественное\n";
			cin >> a;
			cout << "Введите на сколько нужно увеличить: ";
			if (a == 1) {
				cin >> L1;
				k = boost_L(file_name, p2, L1);
			}
			else if (a == 2) {
				cin >> L2;
				k = boost_L(file_name, p2, L2);
			}
			else {
				cout << "Команда не распознана";
			}
			if (k < 0) cout << "Не удалось прочитать файл";
			break;

		}
	} while (c != 8);
	return 0;
}

