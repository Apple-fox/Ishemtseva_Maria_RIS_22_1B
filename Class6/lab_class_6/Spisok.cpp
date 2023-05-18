#include <iostream>
#include "Spisok.h"
using namespace std;

List::List(){
	size = 0;
	head = nullptr;
	tail = nullptr;
}
List::List(int s){
	size = s;
	Node* node = new Node;
	node->data = rand() % 50;
	head = node;
	tail = node;
	for (int i = 0; i < size-1; i++) {
		Node* node = new Node;
		node->data = rand() % 50;
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	tail->next = nullptr;
	beg.elem = head;
	end.elem = tail->next;
}
List::List(const List& L){
	Node* node = L.head;
	while (node != nullptr) {
		pushback(node->data);
		node = node->next;
	}
	tail->next = nullptr;
	beg = L.beg;
	end = L.end;
}
List::~List(void){
	Node* curr = head;
	while (curr != nullptr) {
		head = curr->next;
		delete curr;
		curr = head;
	}
}
void List::pushback(int data){
	Node* curr = new Node;
	curr->data = data;
	if (head != nullptr) {
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
		tail->next = nullptr;
		size++;
		end.elem = tail->next;
	}
	else {
		head = curr;
		tail = curr;
		tail->next = nullptr;
		size++;
		end.elem = tail->next;
	}
}
void List::pushfront(int data){
	Node* curr = new Node;
	curr->data = data;
	if (head == nullptr) {
		head = curr;
		tail = curr;
		size++;
		beg.elem = head;
	}
	else {
		head->prev = curr;
		curr->next = head;
		head = curr;
		size++;
		beg.elem = head;
	}
}
void List::popback(){
	Node* curr = tail;
	if (head != nullptr) {
		tail = curr->prev;
		delete curr;
		tail->next = nullptr;
		size--;
		end.elem = tail->next;
	}
}
void List::popfront(){
	if (head != nullptr) {
		Node* curr = head;
		head = curr->next;
		delete curr;
		head->prev = nullptr;
		size--;
		beg.elem = head;
	}
}
bool List::empty() {
	return size == 0;
}
int& List::operator[](int index){
	Node* curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}
	return curr->data;
}
int& List::operator()(){
	return size;
}
List List::operator*(List& L){
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
	beg = L.beg;
	end = L.end;
	return *this;
}
ostream& operator<<(ostream& out, const List& L){
	Node* curr = L.head;
	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	return out;
}
istream& operator>>(istream& in, const List& L){
	Node* curr = L.head;
	while (curr != nullptr) {
		in >> curr->data;
		curr = curr->next;
	}
	return in;
}