#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node* prev;
};

class Iterator {
	friend class List;
	Node* elem;
public:
	Iterator() { elem = nullptr; };
	Iterator(const Iterator& T) { elem = T.elem; };
	bool operator==(const Iterator& T) {
		return elem == T.elem;
	};
	bool operator!=(const Iterator& T) {
		return elem != T.elem;
	};
	Iterator& operator++() {
		elem = elem->next;
		return *this;
	};
	Iterator& operator--() {
		elem = elem->prev;
		return *this;
	};
	int& operator*() {
		return elem->data;
	};
	Iterator& operator+(int n) {
		for (int i = 0; i < n; i++) {
			elem = elem->next;
		}
		return *this;
	};
	Iterator& operator-(int n) {
		for (int i = 0; i < n; i++) {
			elem = elem->prev;
		}
		return *this;
	};
	Iterator& operator=(const Iterator& T) {
		elem = T.elem;
		return *this;
	};
};

class List {
	Node* head;
	Node* tail;
	int size;
	Iterator beg, end;
	friend class Node;
public:
	List();
	List(int);
	List(const List&);
	~List(void);
	void pushback(int data);
	void pushfront(int data);
	void popback();
	void popfront();
	bool empty();
	int& operator[](int);
	int& operator()();
	List operator*(List&);
	List& operator=(List&);
	int front() { return head->data; };
	int back() { return tail->data; };
	Iterator first() { return beg; };
	Iterator last() { return end; };
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, const List&);
};