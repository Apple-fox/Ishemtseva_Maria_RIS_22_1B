#pragma once
#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int make_file(const char* f_name) {
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Pair P;
	cout << "N? ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> P;
		stream << P << '\n';
	}
	stream.close();
	return n;
}
int print_file(const char* f_name) {
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair P;
	int i = 0;

	while (stream >> P) {
		cout << P;
		i++;
	}
	cout << i;
	stream.close();
	return i;
 }

int del_file(const char* f_name, int k) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Pair p;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		if (i != k) temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}
int add_file(const char* f_name, int k, Pair pp) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0, l = 0;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		if (i == k) {
			temp << pp;
			l++;
		}
		temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}
int add_end(const char* f_name, Pair pp) {
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	stream << pp;
	return 1;
}

int del_less(const char* f_name, Pair pp) { //удаление записей меньше заданного значения
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Pair p;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		if (p.set_first() > pp.set_first() || p.set_second() > pp.set_second()) temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int boost_L(const char* f_name, Pair pp, int L) { //увеличить все записи с заданным значением на число L
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Pair p;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		if (p.set_first() == pp.set_first() && p.set_second() == pp.set_second()) {
			int a = p.set_first();
			a += L;
			p.get_first(a);
		}
		temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}
int boost_L(const char* f_name, Pair pp, double L) { //увеличить все записи с заданным значением на число L
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Pair p;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		if (p.set_first() == pp.set_first() && p.set_second() == pp.set_second()) {
			int a = p.set_second();
			a += L;
			p.get_second(a);
		}
		temp << p;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_k(const char* f_name, int n, int k) { // добавить k записей после элемента с заданным номером
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -2;
	int i = -1; Pair p;
	while (stream >> p) {
		if (stream.eof()) break;
		i++;
		temp << p;
		if (i == n-1) {
			for (int j = 0; j < k; j++) {
				Pair tt;
				cout << "Введите элемент\n";
				cin >> tt;
				temp << tt;
			}
		}
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

