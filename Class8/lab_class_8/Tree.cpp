//#include "Tree.h"
//#include <iostream>
//using namespace std;
//Tree::Tree() {
//	size = 0;
//	cur = 0;
//	right = nullptr;
//	left = nullptr;
//	parent = nullptr;
//}
//Tree::Tree(int s) {
//	size = s;
//	Magazin* a = new Magazin;
//	a->Input();
//	beg = a;
//	right = nullptr;
//	left = nullptr;
//	parent = this;
//}
//Tree::Tree(const Tree& Tr) {
//	beg = Tr.beg;
//	right = Tr.right;
//	left = Tr.left;
//	parent = Tr.parent;
//	size = Tr.size;
//	cur = Tr.cur;
//}
//Tree::~Tree() {
//	size = 0;
//	//if (left) delete left;
//	//if (right) delete right;
//}
//void Tree::Add_left() {
//	Object *p;
//	Magazin a;
//	cout << "������� �������, ������� ������ ��������\n";
//	a.Input();
//	p = &a;
//	Tree* node = new Tree;
//	node->beg = p;
//	if (left) {//���� ����� ���� �������
//		cout << "����� ���� �������\n";
//		left->parent = node;
//		node->left = this->left;
//		this->left = node;
//		node->parent = this;
//	}
//	else {
//		cout << "����� ��� ��������\n";
//		this->left = node;
//		this->left->beg->Show();
//		node->parent = this;
//		node->beg->Show();
//	}
//}
//
//void Tree::Add_right() {
//	Object* p;
//	Magazin a;
//	cout << "������� �������, ������� ������ ��������\n";
//	a.Input();
//	p = &a;
//	Tree* node = new Tree;
//	node->beg = p;
//	if (right) {
//		right->parent = node;
//		node->right = this->right;
//		this->right = node;
//		node->parent = this;
//	}
//	else {
//		right= node;
//		node->parent = this;
//	}
//}
//void Tree::Add() {
//	cout << "left - ������� �������� �����, right - ������� �������� ������: ";
//	string a = "sfdb";
//	size++;
//	while (a != "left" && a != "right"){
//		cin >> a;
//		if (a == "right") Add_right();
//		else if (a == "left") Add_left();
//		else cout << "������� ����������� �������";
//	}
//}
////void Tree::Del(Magazin data) 
//void Tree::Show(Tree* node) {
//	if (node) {
//		node->parent->beg->Show();
//		node->beg->Show();
//		if(node->left) Show(node->left);
//		if(node->right) Show(node->right);
//	}
//}
//Tree* Tree::find_empty(Tree *node) {
//	if (!node->left && !node->right && node) { //���� �� ���������� ������ ����
//		return node;
//	}
//	else {
//		if (node->left) find_empty(node->left); //����������� ������� ��� ������ ���������
//		if (node->right) find_empty(node->right); //����������� ������� ��� ������� ���������
//	}
//}
////Tree* find_node(Tree* s, Magazin node) 
//int Tree::operator()() {
//	return size;
//}