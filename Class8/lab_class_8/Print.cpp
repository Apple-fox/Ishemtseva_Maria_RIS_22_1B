#include "Print.h"
#include <iostream>
using namespace std;
Print::Print() {
	name = "";
	author = "";
}
Print::Print(const Print& P) {
	name = P.name;
	author = P.author;
}
Print::Print(string n, string a) {
	name = n;
	author = a;
}
Print::~Print() {

}
void Print::Show() {
	cout << "name: " << name << '\n' << "author: " << author << '\n';
}
void Print::Input() {
	cout << "name? ";
	cin >> name;
	cout << "author? ";
	cin >> author;
}
string Print::get_name() {
	return name;
}
string Print::get_author() {
	return author;
}
void Print::set_name(string n) {
	name = n;
}
void Print::set_author(string a) {
	author = a;
}
Print& Print::operator=(const Print& P) {
	name = P.name;
	author = P.author;
	return *this;
}

void Print::HandleEvent(const TEvent& r) {
	if (r.what == evMessage) {
		switch (r.command) {
		case cmGet:cout << "author = " << this->get_author() << endl;
			cout << "name = " << this->get_name() << endl;
			break;
		}
	}
}