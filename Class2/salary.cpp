#include <iostream>
#include "salary.h"
using namespace std;

salary::salary() {
		fio = "";
		second = 0;
		first = 0;
		cout << "Конструктор без параметров для " << this << endl;
}

salary::salary(string f, double s, int p) {
		fio = f;
		second = s;
		first = p;
		cout << "Коснтруктор с параметрами для - " << this << endl;
}

salary::salary(salary& T) {
		fio = T.fio;
		second = T.second;
		first = T.first;
		cout << "Конструктор копирования для - " << this << endl;
}

salary::~salary() {
		cout << "Дуструктор для - " << this << endl;
}

void salary::Init(string foi, double sale, int poc) {
		fio = foi;
		second = sale;
		first = poc;
}

void salary::show() {
	cout << "ФИО - " << fio;
	cout << "\nОклад - " << second;
	cout << "\nПроцент - " << first;
	cout << endl;
}

double salary::get_prize() {
		return first * 0.01 * second;
}