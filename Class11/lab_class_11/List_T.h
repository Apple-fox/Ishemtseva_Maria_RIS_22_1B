#pragma once
#include <iostream>
#include <queue>
template <class T>
class Node {
public:
	T data;
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
};

template <class T>
class List_T
{
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int size;
	friend class Node<T>;
public:
	List_T() {
		size = 0;
		head = nullptr;
		tail = nullptr;
	};
	List_T(int s) {
		T k;
		k = k.random();
		size = s;
		Node<T>* node = new Node<T>;
		node->data = k;
		head = node;
		tail = node;
		for (int i = 0; i < size - 1; i++) {
			Node<T>* node = new Node<T>;
			k = k.random();
			node->data = k;
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
		tail->next = nullptr;
	};
	Node<T>* get_head() { return head; };
	List_T(const List_T<T>& L) {
		Node<T>* node = L.head;
		while (node != nullptr) {
			pushback(node->data);
			node = node->next;
		}
		tail->next = nullptr;
	};
	~List_T(void) {
		Node<T>* curr = head;
		while (curr != nullptr) {
			head = curr->next;
			delete curr;
			curr = head;
		}
	};

	T& operator[](int index) {
		Node<T>* curr = head;
		for (int i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr->data;
	};
	void pushback(T data) {
		Node<T>* curr = new Node<T>;
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
	};

	void erase(T dat) {
		size--;
		bool er = false;
		Node<T>* curr = head;
		for (int i = 0; i < size && !er; i++) {
			if (curr->data == dat) er = true;
			else curr = curr->next;
		}
		if (curr->next != nullptr) {
			Node<T>* temp = curr->next;
			if (temp) {
				if (curr->prev != nullptr) {
					temp->prev = curr->prev;
					curr->prev->next = temp;
				}
				else {
					head = temp;
					temp->prev = nullptr;
				}
				curr->next = nullptr;
				curr->prev = nullptr;
				delete curr;
			}
		}
		else {
			tail = curr->prev;
			tail->next = nullptr;
			delete curr;
		}
	};
	T average_T(List_T<T>& l) {
		T sum;
		int c = 0;
		Node<T>* curr = l.head;
		while (curr != nullptr) {
			sum = sum + curr->data;
			curr = curr->next;
			c++;
		}
		sum = sum / c;
		return sum;
	};

	void set_range_T(List_T<T>& l, T a, T b) {
		T* ab = new T[l.size];
		int t = 0;
		for (int i = 0; i < l.size; i++) {
			if (l[i] >= a && l[i] <= b) {
				ab[t] = l[i];
				t++;
			}
		}
		for (int i = 0; i < t; i++) {
			l.erase(ab[i]);
		}
	};

	T min_max_T(List_T<T>& l) {
		T min = l.head->data, max;
		for (int i = 0; i < l.size; i++) {
			if (l[i] > max) max = l[i];
			if (l[i] < min) min = l[i];
		}
		return min + max;
	};

	void more_on_sum_T(List_T<T>& l, T t) {
		for (int i = 0; i < l.size; i++) {
			l[i] = l[i] + t;
		}
	};

	T average_queue_T(std::priority_queue<T>& qup) {
		List_T<T> l;
		while (!qup.empty()) {
			l.pushback(qup.top());
			qup.pop();
		}
		Node<T>* curr = l.head;
		while (curr != nullptr) {
			qup.push(curr->data);
			curr = curr->next;
		}
		T sum;
		int c = 0;
		curr = l.head;
		while (curr != nullptr) {
			sum = sum + curr->data;
			curr = curr->next;
			c++;
		}
		sum = sum / c;
		return sum;
	};

	void set_range_queue_T(std::priority_queue<T>& qup, T a, T b) {
		List_T<T> l;
		while (!qup.empty()) {
			l.pushback(qup.top());
			qup.pop();
		}
		T* ab = new T[l.size];
		int t = 0;
		for (int i = 0; i < l.size; i++) {
			if (l[i] > a && l[i] < b) {
				ab[t] = l[i];
				t++;
			}
		}
		for (int i = 0; i < t; i++) {
			l.erase(ab[i]);
		}
		Node<T>* curr = l.head;
		while (curr) {
			qup.push(curr->data);
			curr = curr->next;
		}
	};

	T min_max_queue_T(std::priority_queue<T>& qup) {
		List_T<T> l;
		while (!qup.empty()) {
			l.pushback(qup.top());
			qup.pop();
		}
		Node<T>* curr = l.head;
		while (curr != nullptr) {
			qup.push(curr->data);
			curr = curr->next;
		}
		T min = l.head->data, max;
		for (int i = 0; i < l.size; i++) {
			if (l[i] > max) max = l[i];
			if (l[i] < min) min = l[i];
		}
		return min + max;
	};

	void more_on_sum_queue_T(std::priority_queue<T>& qup, T t) {
		List_T<T> l;
		while (!qup.empty()) {
			l.pushback(qup.top());
			qup.pop();
		}
		for (int i = 0; i < l.size; i++) {
			l[i] = l[i] + t;
		}
		Node<T>* curr = l.head;
		while (curr != nullptr) {
			qup.push(curr->data);
			curr = curr->next;
		}
	};
	
	friend std::ostream& operator<<(std::ostream& out, const List_T<T>& L) {
		Node<T>* curr = L.head;
		while (curr != nullptr) {
			std::cout << curr->data << " ";
			curr = curr->next;
		}
		return out;
	};
	friend std::istream& operator>>(std::istream& in, const List_T<T>& L) {
		Node<T>* curr = L.head;
		while (curr != nullptr) {
			in >> curr->data;
			curr = curr->next;
		}
		return in;
	};
};

