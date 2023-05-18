//#pragma once
//#include "Magazin.h"
//class Tree
//{
//public:
//	Object* beg;
//	int size;
//	int cur;
//	Tree* left;
//	Tree* right;
//	Tree* parent;
//	Tree* find;
//public:
//	Tree();
//	Tree(int);
//	Tree(const Tree&);
//	~Tree();
//	void Add();
//	void Add_left();
//	void Add_right();
//	void Del(Magazin data1) {
//		Tree* to_erase = find_node(this, data1);
//		size--;
//		if (to_erase->left == nullptr && to_erase->right == nullptr) {
//			std::cout << "Нет потомков!\n";
//			if (to_erase->parent->left == to_erase) {
//				to_erase->parent->left = nullptr;
//				to_erase->parent = nullptr;
//			}
//			else {
//				to_erase->parent->right = nullptr;
//				to_erase->parent = nullptr;
//			}
//		}
//		else if ((to_erase->left == nullptr && to_erase->right != nullptr) || (to_erase->left != nullptr && to_erase->right == nullptr)) {
//			std::cout << "Один потомок\n";
//			if (to_erase->parent->left == to_erase) {
//				if (to_erase->left != nullptr) {
//					std::cout << "Потомок слева\n";
//					to_erase->parent->left = to_erase->left;
//					to_erase->left->parent = to_erase->parent;
//					to_erase->parent = nullptr;
//					to_erase->left = nullptr;
//				}
//				else {
//					std::cout << "Потомок справа\n";
//					to_erase->parent->left = to_erase->right;
//					to_erase->right->parent = to_erase->parent;
//					to_erase->parent = nullptr;
//					to_erase->right = nullptr;
//				}
//			}
//			else {
//				std::cout << "Элемент справа\n";
//				if (to_erase->left != nullptr) {
//					std::cout << "Потомок слева\n";
//					to_erase->parent->right = to_erase->left;
//					to_erase->left->parent = to_erase->parent;
//					to_erase->parent = nullptr;
//					to_erase->left = nullptr;
//				}
//				else {
//					std::cout << "Потомок справа\n";
//					to_erase->parent->right = to_erase->right;
//					to_erase->right->parent = to_erase->parent;
//					to_erase->parent = nullptr;
//					to_erase->right = nullptr;
//				}
//			}
//		}
//		else {
//			std::cout << "Два потомка\n";
//			Tree* next = find_empty(to_erase);
//			to_erase->beg = next->beg;
//			if (next == next->parent->left) {
//				next->parent->left = nullptr;
//			}
//			else {
//				next->parent->right = nullptr;
//			}
//			if (to_erase->parent->left == to_erase) {
//				to_erase->parent->left = next;
//			}
//			else {
//				to_erase->parent->right = next;
//			}
//			to_erase->parent = nullptr;
//			if (to_erase->left != nullptr) {
//				next->left = to_erase->left;
//				to_erase->left = nullptr;
//			}
//			if (to_erase->right != nullptr) {
//				next->right = to_erase->right;
//				to_erase->right = nullptr;
//			}
//		}
//	};
//	void Show(Tree*);
//	Tree* find_node(Tree* s, Magazin node) {
//		if ((s->beg->get_name() != node.get_name()) && (s->beg->get_author() != node.get_author()) && (s->beg->get_count() != node.get_count())) {
//			if(s->left) find_node(s->left, node);
//			if (s->right) find_node(s->right, node);
//		}
//		else {
//			find = s;
//		}
//		return find;
//	};
//	Tree* find_empty(Tree*); // ищет узел не содержащий потомков
//	int operator()();
//};
//
