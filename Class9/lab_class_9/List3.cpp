#include <iostream>
#include "List3.h"
#include "Error.h"
using namespace std;

List3::List3() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}
List3::List3(int s) {
	if (s > MAX_SIZE1) throw MaxSizeError();
	size = s;
	Node3* node = new Node3;
	node->data = rand() % 50;
	head = node;
	tail = node;
	for (int i = 0; i < size - 1; i++) {
		Node3* node = new Node3;
		node->data = rand() % 50;
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	tail->next = nullptr;
}
List3::List3(const List3& L) {
	Node3* node = L.head;
	while (node != nullptr) {
		pushback(node->data);
		node = node->next;
	}
	tail->next = nullptr;
}
List3::~List3(void) {
	Node3* curr = head;
	while (curr != nullptr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
}
void List3::pushback(int data) {

	if (size + 1 == MAX_SIZE1) throw 4;
	Node3* curr = new Node3;
	curr->data = data;
	if (head != nullptr) {
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
		tail->next = nullptr;
		size++;
	}
	else {
		head = curr;
		tail = curr;
		tail->next = nullptr;
		size++;
	}
}
void List3::pushfront(int data) {
	if (size + 1 == MAX_SIZE1) throw 4;
	Node3* curr = new Node3;
	curr->data = data;
	if (head == nullptr) {
		head = curr;
		tail = curr;
		size++;
	}
	else {
		head->prev = curr;
		curr->next = head;
		head = curr;
		size++;
	}
}
void List3::popback() {
	if (size == 1) throw SizeError();
	Node3* curr = tail;
	if (head != nullptr) {
		tail = curr->prev;
		delete curr;
		tail->next = nullptr;
		size--;
	}
}
void List3::popfront() {
	if (size == 0) throw 5;
	if (head != nullptr) {
		Node3* curr = head;
		head = curr->next;
		delete curr;
		head->prev = nullptr;
		size--;
	}
}
bool List3::empty() {
	return size == 0;
}
int& List3::operator[](int index) {
	if (index < 0) throw IndexError1();
	if (index >= size) throw IndexError2();
	Node3* curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->data;
}
int& List3::operator()() {
	return size;
}
List3& List3::operator*(List3& L) {
	List3 newlist(min(size, L.size));
	for (int i = 0; i < min(size, L.size); i++) {
		newlist[i] = L[i] * (*this)[i];
	}
	return newlist;
}

List3& List3::operator=(List3& L) {
	Node3* node = head;
	while (node != nullptr) {
		head = node->next;
		delete node;
		node = head;
		size--;
	}
	node = L.head;
	while (node != nullptr) {
		pushback(node->data);
		node = node->next;
	}
	return *this;
}
ostream& operator<<(ostream& out, const List3& L) {
	Node3* curr = L.head;
	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	return out;
}
istream& operator>>(istream& in, const List3& L) {
	Node3* curr = L.head;
	while (curr != nullptr) {
		in >> curr->data;
		curr = curr->next;
	}
	return in;
}

int& List3::operator+(int n) {
	if (n > size || n < 1) throw SizeError();
	else {
		Node3* curr = head;
		for (int i = 1; i <= n; i++) {
			if (i == n) {
				return curr->data;
			}
			curr = curr->next;
		}
	}
}
