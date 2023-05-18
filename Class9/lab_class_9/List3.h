#include <iostream>
using namespace std;
const int MAX_SIZE1 = 5;
class Node3 {
public:
	int data;
	Node3* next;
	Node3* prev;
};


class List3 {
	Node3* head;
	Node3* tail;
	int size;
	friend class Node3;
public:
	List3();
	List3(int);
	List3(const List3&);
	~List3(void);
	void pushback(int data);
	void pushfront(int data);
	void popback();
	void popfront();
	bool empty();
	int& operator[](int);
	int& operator()();
	List3& operator*(List3&);
	List3& operator=(List3&);
	int front() { return head->data; };
	int back() { return tail->data; };
	friend ostream& operator<<(ostream&, const List3&);
	friend istream& operator>>(istream&, const List3&);
	int& operator+(int n);
};