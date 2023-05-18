#include <iostream>
using namespace std;
class Pair {

	int first;
	double second;


public:
	Pair();
	Pair(int, double);

	Pair(Pair&);

	~Pair();

	void get_first(int);

	void get_second(double);

	//перегрузка операции присваивания
	Pair& operator=(const Pair&);
	Pair operator+(int);
	Pair operator+(double);

	Pair operator-(const Pair&);
	friend istream& operator>>(istream& in, Pair&);
	friend ostream& operator<<(ostream& out, Pair&);
};

