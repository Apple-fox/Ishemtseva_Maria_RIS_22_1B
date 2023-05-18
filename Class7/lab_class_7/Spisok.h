#pragma once
#include <iostream>

template <class T>
class Node {
public:
	T data;
	Node<T>* next = nullptr;
	Node<T>* prev = nullptr;
};

template <class T>
class List {
	Node<T>* head;
	Node<T>* tail;
	int size;
	friend class Node<T>;
public:
	List() {
		size = 0;
		head = nullptr;
		tail = nullptr;
	};
	List(int s, const T k) {
		size = s;
		Node<T>* node = new Node<T>;
		node->data = k;
		head = node;
		tail = node;
		for (int i = 0; i < size - 1; i++) {
			Node<T>* node = new Node<T>;
			node->data = k;
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
		tail->next = nullptr;
	};
	List(const List<T>& L) {
		Node<T>* node = L.head;
		while (node != nullptr) {
			pushback(node->data);
			node = node->next;
		}
		tail->next = nullptr;
	};
	~List(void) {
		Node<T>* curr = head;
		while (curr != nullptr) {
			head = curr->next;
			delete curr;
			curr = head;
		}
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
	void pushfront(T data) {
		Node<T>* curr = new Node<T>;
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
	;
	void popback() {
		Node<T>* curr = tail;
		if (head != nullptr) {
			tail = curr->prev;
			delete curr;
			tail->next = nullptr;
			size--;
		}
	}
	;
	void popfront() {
		if (head != nullptr) {
			Node<T>* curr = head;
			head = curr->next;
			delete curr;
			head->prev = nullptr;
			size--;
		}
	};
	bool empty() {
		return size == 0;
	};
	T& operator[](int index) {
		Node<T>* curr = head;
		for (int i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr->data;
	};
	int& operator()() {
		return size;
	};
	List operator*(List<T>& L) {
		List newlist(std::min(size, L.size), L[0]);
		for (int i = 0; i < std::min(size, L.size); i++) {
			newlist[i] = L[i] * (*this)[i];
		}
		return newlist;
	};
	List& operator=(List<T>& L) {
		Node<T>* node = head;
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
	};
	T& front() { return head->data; };
	T& back() { return tail->data; };
	friend std::ostream& operator<<(std::ostream& out, const List<T>& L) {
		Node<T>* curr = L.head;
		while (curr != nullptr) {
			std::cout << curr->data << " ";
			curr = curr->next;
		}
		return out;
	};
	friend std::istream& operator>>(std::istream& in, const List<T>& L) {
		Node<T>* curr = L.head;
		while (curr != nullptr) {
			in >> curr->data;
			curr = curr->next;
		}
		return in;
	};
};
//
//template <class T>
//inline List<T>::List() {
//	size = 0;
//	head = nullptr;
//	tail = nullptr;
//}
//
//template <class T>
//inline List<T>::List(int s, const T k) {
//	size = s;
//	Node<T>* node = new Node<T>;
//	node->data = k;
//	head = node;
//	tail = node;
//	for (int i = 0; i < size - 1; i++) {
//		Node<T>* node = new Node<T>;
//		node->data = k;
//		tail->next = node;
//		node->prev = tail;
//		tail = node;
//	}
//	tail->next = nullptr;
//}
//
//template <class T>
//inline List<T>::List(const List<T>& L) {
//	Node<T>* node = L.head;
//	while (node != nullptr) {
//		pushback(node->data);
//		node = node->next;
//	}
//	tail->next = nullptr;
//}
//
//template <class T>
//inline List<T>::~List(void) {
//	Node<T>* curr = head;
//	while (curr != nullptr) {
//		head = curr->next;
//		delete curr;
//		curr = head;
//	}
//}
//
//template <class T>
//inline void List<T>::pushback(T data) {
//	Node<T>* curr = new Node<T>;
//	curr->data = data;
//	if (head != nullptr) {
//		tail->next = curr;
//		curr->prev = tail;
//		tail = curr;
//		tail->next = nullptr;
//		size++;
//	}
//	else {
//		head = curr;
//		tail = curr;
//		tail->next = nullptr;
//		size++;
//	}
//}
//
//template <class T>
//inline void List<T>::pushfront(T data) {
//	Node<T>* curr = new Node<T>;
//	curr->data = data;
//	if (head == nullptr) {
//		head = curr;
//		tail = curr;
//		size++;
//	}
//	else {
//		head->prev = curr;
//		curr->next = head;
//		head = curr;
//		size++;
//	}
//}
//
//template <class T>
//inline void List<T>::popback() {
//	Node<T>* curr = tail;
//	if (head != nullptr) {
//		tail = curr->prev;
//		delete curr;
//		tail->next = nullptr;
//		size--;
//	}
//}
//
//template <class T>
//inline void List<T>::popfront() {
//	if (head != nullptr) {
//		Node<T>* curr = head;
//		head = curr->next;
//		delete curr;
//		head->prev = nullptr;
//		size--;
//	}
//}
//
//template <class T>
//inline bool List<T>::empty() {
//	return size == 0;
//}
//
//template <class T>
//inline T& List<T>::operator[](int index) {
//	Node<T>* curr = head;
//	for (int i = 0; i < index; i++) {
//		curr = curr->next;
//	}
//	return curr->data;
//}
//
//template <class T>
//inline int& List<T>::operator()() {
//	return size;
//}
//
//template <class T>
//inline List<T>& List<T>::operator*(List<T>& L) {
//	List newlist(std::min(size, L.size), L[0]);
//	for (int i = 0; i < std::min(size, L.size); i++) {
//		newlist[i] = L[i] * (*this)[i];
//	}
//	return newlist;
//}
//
//template <class T>
//inline List<T>& List<T>::operator=(List<T>& L) {
//	Node<T>* node = head;
//	while (node != nullptr) {
//		head = node->next;
//		delete node;
//		node = head;
//		size--;
//	}
//	node = L.head;
//	while (node != nullptr) {
//		pushback(node->data);
//		node = node->next;
//	}
//	return *this;
//}
//
//template <class T>
//inline std::ostream& operator<< (std::ostream& out, const List<T>& L) {
//	Node<T>* curr = L.head;
//	while (curr != nullptr) {
//		std::cout << curr->data << " ";
//		curr = curr->next;
//	}
//	return out;
//}
//
//template <class T>
//inline std::istream& operator>> (std::istream& in, const List<T>& L) {
//	Node<T>* curr = L.head;
//	while (curr != nullptr) {
//		in >> curr->data;
//		curr = curr->next;
//	}
//	return in;
//}
//
//template class List<class Pair>;