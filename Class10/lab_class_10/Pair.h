#include <iostream>
#include <fstream>
using namespace std;
class Pair {
protected:
	int first;
	double second;


public:
	Pair();
	Pair(int, double);

	Pair(Pair&);

	~Pair();

	void get_first(int);

	void get_second(double);
	int set_first() { return first; };
	double set_second() { return second; };
	//перегрузка операции присваивания
	Pair& operator=(const Pair&);
	Pair operator+(int);
	Pair operator+(double);

	Pair operator-(const Pair&);
	friend istream& operator>>(istream& in, Pair&);
	friend ostream& operator<<(ostream& out, const Pair&);
	friend fstream& operator>>(fstream& fin, Pair&);
	friend fstream& operator<<(fstream& fout, const Pair&);
};

