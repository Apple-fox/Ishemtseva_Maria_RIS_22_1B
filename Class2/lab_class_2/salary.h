#pragma once
#include <iostream>
using namespace std;


class salary {

	double second;
	int first;

public:

	string fio;
	salary();
	salary(string, double, int);
	salary(salary& T);
	~salary();
	void Init(string, double, int);
	void show();
	double get_prize();
};