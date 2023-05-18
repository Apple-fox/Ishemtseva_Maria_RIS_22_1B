#include <iostream>
#include "List.h"
using namespace std;

List::List() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}
List::List(int s) {
	if (s > MAX_SIZE) throw 1;
	size = s;
	Node* node = new Node;
	node->data = rand() % 50;
	head = node;
	tail = node;
	for (int i = 0; i < size - 1; i++) {
		Node* node = new Node;
		node->data = rand() % 50;
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	tail->next = nullptr;
}
List::List(const List& L) {
	Node* node = L.head;
	while (node != nullptr) {
		pushback(node->data);
		node = node->next;
	}
	tail->next = nullptr;
}
List::~List(void) {
	Node* curr = head;
	while (curr != nullptr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
}
void List::pushback(int data) {

	if (size + 1 == MAX_SIZE) throw 4;
	Node* curr = new Node;
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
void List::pushfront(int data) {
	if (size + 1 == MAX_SIZE) throw 4;
	Node* curr = new Node;
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
void List::popback() {
	if (size == 1) throw 5;
	Node* curr = tail;
	if (head != nullptr) {
		tail = curr->prev;
		delete curr;
		tail->next = nullptr;
		size--;
	}
}
void List::popfront() {
	if (size == 0) throw 5;
	if (head != nullptr) {
		Node* curr = head;
		head = curr->next;
		delete curr;
		head->prev = nullptr;
		size--;
	}
}
bool List::empty() {
	return size == 0;
}
int& List::operator[](int index) {
	if (index < 0) throw 2;
	if (index >= size) throw 3;
	Node* curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->data;
}
int& List::operator()() {
	return size;
}
List& List::operator*(List& L) {
	List newlist(min(size, L.size));
	for (int i = 0; i < min(size, L.size); i++) {
		newlist[i] = L[i] * (*this)[i];
	}
	return newlist;
}

List& List::operator=(List& L) {
	Node* node = head;
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
ostream& operator<<(ostream& out, const List& L) {
	Node* curr = L.head;
	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	return out;
}
istream& operator>>(istream& in, const List& L) {
	Node* curr = L.head;
	while (curr != nullptr) {
		in >> curr->data;
		curr = curr->next;
	}
	return in;
}
int& List::operator+(int n) {
	if (n > size || n < 1) throw 9;
	else {
		Node* curr = head;
		for (int i = 1; i <= n; i++) {
			if (i == n) {
				return curr->data;
			}
			curr = curr->next;
		}
	}
}
