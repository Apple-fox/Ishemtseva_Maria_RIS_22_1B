#include <iostream>
using namespace std;
const int MAX_SIZE = 5;
class Node {
public:
	int data;
	Node* next;
	Node* prev;
};



class List {
	Node* head;
	Node* tail;
	int size;
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
	List& operator*(List&);
	List& operator=(List&);
	int front() { return head->data; };
	int back() { return tail->data; };
	friend ostream& operator<<(ostream&, const List&);
	friend istream& operator>>(istream&, const List&);
	int& operator+(int n);
};