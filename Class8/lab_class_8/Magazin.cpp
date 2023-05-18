#include "Magazin.h"
#include <iostream>
using namespace std;

Magazin::Magazin(){
	count = 0;
}
Magazin::Magazin(int c) {
	count = c;
}
Magazin::Magazin(const Magazin& M) {
	name = M.name;
	author = M.author;
	count = M.count;
}
Magazin::~Magazin() {
}
void Magazin::set_count(int c) {
	count = c;
}
int Magazin::get_count() {
	return count;
}
Magazin& Magazin::operator=(const Magazin& M) {
	name = M.name;
	author = M.author;
	count = M.count;
	return *this;
}
void Magazin::Show() {
	cout << "name: " << name << '\n' << "author: " << author << '\n' << "count: " << count << '\n';
}
void Magazin::Input() {
	cout << "name? ";
	cin >> name;
	cout << "author? ";
	cin >> author;
	cout << "count? ";
	cin >> count;
}